/*
* Copyright (c) 2020-2021 (https://github.com/phase1geo/Annotator)
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA 02110-1301 USA
*
* Authored by: Trevor Williams <phase1geo@gmail.com>
*/

using Gtk;
using Gee;

public class MainWindow : Hdy.ApplicationWindow {

  private Hdy.HeaderBar     _header;
  private FontButton        _font;
  private Button            _open_btn;
  private Button            _undo_btn;
  private Button            _redo_btn;
  private MenuButton        _pref_btn;
  private MenuButton        _export_btn;
  private MenuButton        _zoom_btn;
  private ZoomWidget        _zoom;
  private Box               _box;
  private Editor            _editor;
  private Stack             _stack;
  private SList<FileFilter> _image_filters;

  private const GLib.ActionEntry[] action_entries = {
    { "action_open",            do_open },
    { "action_save",            do_save },
    { "action_quit",            do_quit },
    { "action_undo",            do_undo },
    { "action_redo",            do_redo },
    { "action_copy",            do_copy },
    { "action_cut",             do_cut },
    { "action_paste",           do_paste },
    { "action_zoom_in",         do_zoom_in },
    { "action_zoom_out",        do_zoom_out },
    { "action_zoom_actual",     do_zoom_actual },
    { "action_zoom_fit",        do_zoom_fit },
    { "action_shortcuts",       do_shortcuts },
    { "action_contextual_menu", do_contextual_menu },
    { "action_print",           do_print }
  };

  /* Constructor */
  public MainWindow( Gtk.Application app ) {

    Object( application: app );

    /* Add the application CSS */
    var provider = new Gtk.CssProvider ();
    provider.load_from_resource( "/com/github/phase1geo/annotator/css/style.css" );
    StyleContext.add_provider_for_screen( Gdk.Screen.get_default(), provider, STYLE_PROVIDER_PRIORITY_APPLICATION );

    var box = new Box( Orientation.HORIZONTAL, 0 );

    /* Handle any changes to the dark mode preference setting */
    handle_prefer_dark_changes();

    /* Position the window size and position */
    position_window();

    /* Create the header */
    create_header();

    /* Create editor */
    create_editor( box );

    var top_box = new Box( Orientation.VERTICAL, 0 );
    top_box.pack_start( _header, false, true, 0 );
    top_box.pack_start( box, true, true, 0 );

    add( top_box );
    show_all();

    /* Set the stage for menu actions */
    var actions = new SimpleActionGroup ();
    actions.add_action_entries( action_entries, this );
    insert_action_group( "win", actions );

    /* Add keyboard shortcuts */
    add_keyboard_shortcuts( app );

    /* Gather the image filters */
    gather_image_filters();

    /* Handle the application closing */
    destroy.connect( Gtk.main_quit );

  }

  static construct {
    Hdy.init();
  }

  /* Adds keyboard shortcuts for the menu actions */
  private void add_keyboard_shortcuts( Gtk.Application app ) {
    app.set_accels_for_action( "win.action_open",            { "<Control>o" } );
    app.set_accels_for_action( "win.action_save",            { "<Control>s" } );
    app.set_accels_for_action( "win.action_quit",            { "<Control>q" } );
    app.set_accels_for_action( "win.action_undo",            { "<Control>z" } );
    app.set_accels_for_action( "win.action_redo",            { "<Control><Shift>z" } );
    app.set_accels_for_action( "win.action_paste",           { "<Control>v" } );
    app.set_accels_for_action( "win.action_zoom_in",         { "<Control>plus" } );
    app.set_accels_for_action( "win.action_zoom_in",         { "<Control>equal" } );
    app.set_accels_for_action( "win.action_zoom_out",        { "<Control>minus" } );
    app.set_accels_for_action( "win.action_zoom_actual",     { "<Control>0" } );
    app.set_accels_for_action( "win.action_zoom_fit",        { "<Control>1" } );
    app.set_accels_for_action( "win.action_shortcuts",       { "<Control>question" } );
    app.set_accels_for_action( "win.action_contextual_menu", { "<Shift>F10", "Menu" } );
    app.set_accels_for_action( "win.action_print",           { "<Control>p" } );
  }

  /* Handles any changes to the dark mode preference gsettings for the desktop */
  private void handle_prefer_dark_changes() {
    var granite_settings = Granite.Settings.get_default();
    var gtk_settings     = Gtk.Settings.get_default();
    gtk_settings.gtk_application_prefer_dark_theme = granite_settings.prefers_color_scheme == Granite.Settings.ColorScheme.DARK;
    granite_settings.notify["prefers-color-scheme"].connect (() => {
      gtk_settings.gtk_application_prefer_dark_theme = granite_settings.prefers_color_scheme == Granite.Settings.ColorScheme.DARK;
    });
  }

  /* Positions the window based on the settings */
  private void position_window() {

    var window_x = Annotator.settings.get_int( "window-x" );
    var window_y = Annotator.settings.get_int( "window-y" );
    var window_w = Annotator.settings.get_int( "window-w" );
    var window_h = Annotator.settings.get_int( "window-h" );

    /* Set the main window data */
    if( (window_x == -1) && (window_y == -1) ) {
      set_position( Gtk.WindowPosition.CENTER );
    } else {
      move( window_x, window_y );
    }
    set_default_size( window_w, window_h );

  }

  /* Create the header bar */
  private void create_header() {

    _header = new Hdy.HeaderBar();
    _header.set_show_close_button( true );

    _open_btn = new Button.from_icon_name( "document-open", IconSize.LARGE_TOOLBAR );
    _open_btn.set_tooltip_markup( Utils.tooltip_with_accel( _( "Open Image" ), "<Control>o" ) );
    _open_btn.clicked.connect( do_open );
    _header.pack_start( _open_btn );

    /*
    _save_btn = new Button.from_icon_name( "document-save", IconSize.LARGE_TOOLBAR );
    _save_btn.set_tooltip_markup( Utils.tooltip_with_accel( _( "Save File" ), "<Control>s" ) );
    _save_btn.clicked.connect( do_save );
    _header.pack_start( _save_btn );

    _paste_btn = new Button.from_icon_name( "edit-paste", IconSize.LARGE_TjOOLBAR );
    _paste_btn.set_tooltip_markup( Utils.tooltip_with_accel( _( "Paste Over" ), "<Shift><Control>v" ) );
    _paste_btn.clicked.connect( do_paste_over );
    _header.pack_start( _paste_btn );

    _copy_btn = new Button.from_icon_name( "edit-copy", IconSize.LARGE_TOOLBAR );
    _copy_btn.set_tooltip_markup( Utils.tooltip_with_accel( _( "Copy All" ), "<Shift><Control>c" ) );
    _copy_btn.clicked.connect( do_copy_all );
    _header.pack_start( _copy_btn );
    */

    _undo_btn = new Button.from_icon_name( "edit-undo", IconSize.LARGE_TOOLBAR );
    _undo_btn.set_tooltip_markup( Utils.tooltip_with_accel( _( "Undo" ), "<Control>z" ) );
    _undo_btn.set_sensitive( false );
    _undo_btn.clicked.connect( do_undo );
    _header.pack_start( _undo_btn );

    _redo_btn = new Button.from_icon_name( "edit-redo", IconSize.LARGE_TOOLBAR );
    _redo_btn.set_tooltip_markup( Utils.tooltip_with_accel( _( "Redo" ), "<Control><Shift>z" ) );
    _redo_btn.set_sensitive( false );
    _redo_btn.clicked.connect( do_redo );
    _header.pack_start( _redo_btn );

    _pref_btn = create_preferences();
    _header.pack_end( _pref_btn );

    _export_btn = create_exports();
    _header.pack_end( _export_btn );

    _zoom_btn = create_zoom();
    _header.pack_end( _zoom_btn );

    set_title( _( "Annotator" ) );

  }

  private MenuButton create_preferences() {

    var pref_btn = new MenuButton();
    pref_btn.image = new Image.from_icon_name( "open-menu", IconSize.LARGE_TOOLBAR );
    pref_btn.set_tooltip_text( _( "Properties" ) );
    pref_btn.popover = new Popover( null );

    var box = new Box( Orientation.VERTICAL, 0 );

    var shortcuts = new ModelButton();
    shortcuts.get_child().destroy();
    shortcuts.add( new Granite.AccelLabel( _( "Shortcuts Cheatsheet" ), "<Control>question" ) );
    shortcuts.action_name = "win.action_shortcuts";

    box.pack_start( shortcuts );

    box.show_all();
    pref_btn.popover.add( box );

    return( pref_btn );

  }

  /* Create the exports menubutton and associated menu */
  private MenuButton create_exports() {

    var export_btn = new MenuButton();
    export_btn.image   = new Image.from_icon_name( "document-export", IconSize.LARGE_TOOLBAR );
    export_btn.set_tooltip_text( _( "Export Image" ) );
    export_btn.popover = new Popover( null );
    export_btn.set_sensitive( false );

    var box = new Box( Orientation.VERTICAL, 0 );

    for( int i=0; i<ExportType.NUM; i++ ) {
      var type = (ExportType)i;
      var btn  = new ModelButton();
      btn.halign = Align.START;
      btn.text   = type.label();
      btn.clicked.connect(() => {
        _editor.canvas.image.export_image( type );
      });
      box.pack_start( btn );
    }

    box.pack_start( new Separator( Orientation.HORIZONTAL ) );

    /* Copy to clipboard option */
    var clip_btn = new ModelButton();
    clip_btn.halign = Align.START;
    clip_btn.text   = _( "Copy To Clipboard" );
    clip_btn.clicked.connect(() => {
      _editor.canvas.image.export_clipboard();
    });
    box.pack_start( clip_btn );

    /* Print option */
    var print_btn = new ModelButton();
    print_btn.get_child().destroy();
    print_btn.add( new Granite.AccelLabel( _( "Print…" ), "<Control>p" ) );
    print_btn.action_name = "win.action_print";
    print_btn.clicked.connect(() => {
      _editor.canvas.image.export_print();
    });
    box.pack_start( print_btn );

    /* Add contracts */
    add_contracts( box );

    box.show_all();
    export_btn.popover.add( box );

    return( export_btn );

  }

  /* Creates the zoom menu */
  private MenuButton create_zoom() {

    /* Add the button */
    var zoom_btn = new MenuButton();
    zoom_btn.set_image( new Image.from_icon_name( "zoom-fit-best", IconSize.LARGE_TOOLBAR ) );
    zoom_btn.set_tooltip_text( _( "Zoom (%d%%)".printf( 100 ) ) );
    zoom_btn.popover = new Popover( null );
    zoom_btn.set_sensitive( false );

    _zoom = new ZoomWidget( (int)(_editor.canvas.zoom_min * 100), (int)(_editor.canvas.zoom_max * 100), (int)(_editor.canvas.zoom_step * 100) );
    _zoom.margin = 10;
    _zoom.zoom_changed.connect((factor) => {
      _editor.canvas.zoom_set( factor );
    });

    var zoom_fit = new ModelButton();
    zoom_fit.get_child().destroy();
    zoom_fit.add( new Granite.AccelLabel( _( "Zoom to Fit Window" ), "<Control>1" ) );
    zoom_fit.action_name = "win.action_zoom_fit";

    var box = new Box( Orientation.VERTICAL, 0 );
    box.pack_start( _zoom,    false, false );
    box.pack_start( zoom_fit, false, false );

    box.show_all();

    zoom_btn.popover.add( box );

    return( zoom_btn );

  }

  /* Adds the Contractor items that can operate on pixbufs */
  private void add_contracts( Box box ) {

    var contracts = Granite.Services.ContractorProxy.get_contracts_by_mime( "image/png" );

    if( contracts.size > 0 ) {
      box.pack_start( new Separator( Orientation.HORIZONTAL ) );
    }

    foreach( Granite.Services.Contract contract in contracts ) {
      var name = contract.get_display_name();
      if( (name != _( "Send by Email")) && (name != _( "Send files via Bluetooth" )) ) continue;
      var ct  = contract;
      var btn = new ModelButton();
      btn.halign = Align.START;
      btn.text   = contract.get_display_name();
      btn.clicked.connect(() => {
        run_contract( ct );
      });
      box.pack_start( btn );
    }

  }

  /* Runs the given contract with a generated PNG file */
  private void run_contract( Granite.Services.Contract contract ) {

    try {

      /* Create a filename to store the PNG image data */
      FileIOStream iostream;
      var file = File.new_tmp( "annotator-XXXXXX.png", out iostream );

      /* Create a PNG file */
      _editor.canvas.image.export_image( ExportType.PNG, file.get_path() );

      /* Run the contract with the generated file */
      contract.execute_with_file( file );

    } catch( Error e ) {
      stdout.printf( e.message );
    }

  }

  private void create_editor( Box box ) {

    /* Create the welcome screen */
    var welcome = new Granite.Widgets.Welcome( _( "Welcome to Annotator" ), _( "Let's get started annotating an image" ) );
    welcome.append( "document-open", _( "Open Image From File" ), _( "Open a PNG, JPEG, TIFF or BMP file" ) );
    welcome.append( "edit-paste", _( "Paste Image From Clipboard" ), _( "Open an image from the clipboard" ) );
    welcome.activated.connect((index) => {
      switch( index ) {
        case 0  :  do_open();   break;
        case 1  :  do_paste();  break;
        default :  assert_not_reached();
      }
    });

    /* Create the editor */
    _editor = new Editor( this );
    _editor.image_loaded.connect(() => {
      _stack.visible_child_name = "editor";
    });
    _editor.canvas.undo_buffer.buffer_changed.connect( do_undo_changed );
    _editor.canvas.undo_text.buffer_changed.connect( do_undo_changed );
    _editor.canvas.zoom_changed.connect( do_zoom_changed );

    /* Add the elements to the stack */
    _stack = new Stack();
    _stack.transition_type = StackTransitionType.NONE;
    _stack.add_named( welcome, "welcome" );
    _stack.add_named( _editor,  "editor" );

    box.pack_start( _stack, true, true, 0 );
    box.show_all();

    _stack.visible_child_name = "welcome";

  }

  /* Create font selection box */
  private Box create_font_selection() {

    var box = new Box( Orientation.HORIZONTAL, 0 );
    var lbl = new Label( _( "Font:" ) );

    _font = new FontButton();
    _font.show_style = false;
    _font.set_filter_func( (family, face) => {
      var fd     = face.describe();
      var weight = fd.get_weight();
      var style  = fd.get_style();
      return( (weight == Pango.Weight.NORMAL) && (style == Pango.Style.NORMAL) );
    });
    _font.font_set.connect(() => {
      var name = _font.get_font_family().get_name();
      var size = _font.get_font_size() / Pango.SCALE;
      // TBD - _editor.change_name_font( name, size );
      Annotator.settings.set_string( "default-font-family", name );
      Annotator.settings.set_int( "default-font-size", size );
    });

    /* Set the font button defaults */
    var fd = _font.get_font_desc();
    fd.set_family( Annotator.settings.get_string( "default-font-family" ) );
    fd.set_size( Annotator.settings.get_int( "default-font-size" ) * Pango.SCALE );
    _font.set_font_desc( fd );

    box.pack_start( lbl,   false, false, 10 );
    box.pack_end(   _font, false, false, 10 );

    return( box );

  }

  /* Creates a list of image filters that can be used in the open dialog */
  private void gather_image_filters() {

    _image_filters = new SList<FileFilter>();

    string[] patterns = {};

    foreach( Gdk.PixbufFormat format in Gdk.Pixbuf.get_formats() ) {
      var filter = new FileFilter();
      filter.set_filter_name( format.get_description() + "  (" + format.get_name() + ")" );
      foreach( string ext in format.get_extensions() ) {
        var pattern = "*" + ext;
        filter.add_pattern( pattern );
        patterns += pattern;
      }
      _image_filters.append( filter );
    }

    /* Add the 'all image formats' filter first */
    var filter = new FileFilter();
    filter.set_filter_name( _( "All Image Formats  (*)" ) );
    foreach( string pattern in patterns ) {
      filter.add_pattern( pattern );
    }
    _image_filters.prepend( filter );

  }

  /* Opens an image file for loading */
  private void do_open() {

    /* Get the file to open from the user */
    var dialog   = new FileChooserNative( _( "Open Image File" ), this, FileChooserAction.OPEN, _( "Open" ), _( "Cancel" ) );
    Utils.set_chooser_folder( dialog );

    /* Create file filters for each supported format */
    foreach( FileFilter filter in _image_filters ) {
      dialog.add_filter( filter );
    }

    if( dialog.run() == ResponseType.ACCEPT ) {
      var filename = dialog.get_filename();
      open_file( filename );
      Utils.store_chooser_folder( filename );
    }

  }

  /*
   Opens the given image file in the canvas and displays the canvas if the
   image is successfully read and displayed.
  */
  public void open_file( string filename ) {
    _editor.open_image( filename );
    _zoom_btn.set_sensitive( true );
    _export_btn.set_sensitive( true );
  }

  public void do_copy() {
    // TBD - AnnotatorClipboard.copy_
  }

  public void do_cut() {
    // TBD
  }

  /* Pastes text or images to the editor */
  public void do_paste() {
    AnnotatorClipboard.paste( _editor );
    _zoom_btn.set_sensitive( true );
    _export_btn.set_sensitive( true );
  }

  private void do_save() {

    /* TBD */

  }

  /* Quits the application */
  private void do_quit() {
    destroy();
  }

  /* Performs an undo operation */
  private void do_undo() {
    _editor.canvas.undo_buffer.undo();
    _editor.canvas.grab_focus();
  }

  /* Performs a redo operation */
  private void do_redo() {
    _editor.canvas.undo_buffer.redo();
    _editor.canvas.grab_focus();
  }

  /* Zooms in by one */
  private void do_zoom_in() {
    _editor.canvas.zoom_in();
  }

  /* Zooms out by one */
  private void do_zoom_out() {
    _editor.canvas.zoom_out();
  }

  /* Zooms to 1:1 */
  private void do_zoom_actual() {
    _editor.canvas.zoom_actual();
  }

  /* Zooms in/out to fit image to window width */
  private void do_zoom_fit() {
    _editor.canvas.zoom_fit();
  }

  /* Displays the keyboard shortcuts cheatsheet */
  private void do_shortcuts() {

    var builder = new Builder.from_resource( "/com/github/phase1geo/annotator/shortcuts/shortcuts.ui" );
    var win     = builder.get_object( "shortcuts" ) as ShortcutsWindow;

    win.transient_for = this;
    win.view_name     = null;

    /* Display the most relevant information based on the current state */
    if( _editor.canvas.items.in_edit_mode() ) {
      win.section_name = "text-editing";
    } else if( _editor.canvas.items.is_item_selected() ) {
      win.section_name = "items";
    } else {
      win.section_name = "general";
    }

    win.show();

  }

  /* Displays the contextual menu for the item under the cursor */
  private void do_contextual_menu() {
    _editor.canvas.show_contextual_menu();
  }

  /* Prints the current image */
  private void do_print() {
    _editor.canvas.image.export_print();
  }

  /* Called whenever the undo buffer changes */
  private void do_undo_changed( UndoBuffer buffer ) {
    _undo_btn.set_sensitive( buffer.undoable() );
    _undo_btn.set_tooltip_markup( Utils.tooltip_with_accel( buffer.undo_tooltip(), "<Control>z" ) );
    _redo_btn.set_sensitive( buffer.redoable() );
    _redo_btn.set_tooltip_markup( Utils.tooltip_with_accel( buffer.redo_tooltip(), "<Control><Shift>z" ) );
  }

  /* Called whenever the zoom value changes */
  private void do_zoom_changed( double zoom_factor ) {
    _zoom.value = (int)(zoom_factor * 100);
    _zoom_btn.set_tooltip_text( "Zoom (%d%%)".printf( (int)_zoom.value ) );
  }

  /* Generate a notification */
  public void notification( string title, string msg, NotificationPriority priority = NotificationPriority.NORMAL ) {
    GLib.Application? app = null;
    @get( "application", ref app );
    if( app != null ) {
      var notification = new Notification( title );
      notification.set_body( msg );
      notification.set_priority( priority );
      app.send_notification( "com.github.phase1geo.minder", notification );
    }
  }

}


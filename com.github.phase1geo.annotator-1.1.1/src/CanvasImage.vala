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
using Gdk;
using Cairo;

public class CanvasImage {

  private const int selector_size = 10;
  private double selector_width {
    get {
      return( selector_size / width_scale );
    }
  }
  private double selector_height {
    get {
      return( selector_size / height_scale );
    }
  }

  private Canvas        _canvas;
  private Pixbuf?       _buf        = null;  // Currently displayed pixbuf
  private ImageSurface? _surface    = null;
  private int           _crop_index = -2;
  private double        _last_x     = 0;
  private double        _last_y     = 0;

  public Pixbuf?          pixbuf        { get; private set; default = null; }  // Original pixbuf of image
  public bool             cropping      { get; private set; default = false; }
  public Exporter         exporter      { get; private set; }
  public CanvasRect       crop_rect     { get; private set; default = new CanvasRect(); }
  public RGBA             average_color { get; private set; default = {1.0, 1.0, 1.0, 1.0}; }
  public CanvasImageInfo? info          { get; private set; default = null; }
  public double           width_scale   { get; private set; default = 1.0; }
  public double           height_scale  { get; private set; default = 1.0; }

  public signal void crop_started();
  public signal void crop_ended();
  public signal void image_changed();

  /* Constructor */
  public CanvasImage( Canvas canvas ) {
    _canvas  = canvas;
    exporter = new Exporter( canvas );
  }

  /* Returns true if the surface image has been set */
  public bool is_surface_set() {
    return( _surface != null );
  }

  /* Returns a surface which contains the given rectangle area of the base image */
  public Cairo.Surface get_surface_for_rect( CanvasRect rect ) {
    var buf_rect = new CanvasRect.from_coords( 0, 0, _buf.width, _buf.height );
    rect.intersection( rect, buf_rect );
    var sub = new Pixbuf.subpixbuf( _buf, (int)rect.x, (int)rect.y, (int)rect.width, (int)rect.height );
    return( cairo_surface_create_from_pixbuf( sub, 1, null ) );
  }

  /* Returns the RGBA color value that averages the colors in the given rectangle */
  public RGBA average_color_of_rect( CanvasRect rect ) {

    var x     = (rect.x < 0) ? 0 : (int)rect.x;
    var y     = (rect.y < 0) ? 0 : (int)rect.y;
    var w     = ((rect.x + rect.width)  >= pixbuf.width)  ? (pixbuf.width  - (int)rect.x) : (int)rect.width;
    var h     = ((rect.y + rect.height) >= pixbuf.height) ? (pixbuf.height - (int)rect.y) : (int)rect.height;
    var sub   = new Pixbuf.subpixbuf( pixbuf, x, y, w, h );
    var color = Granite.Drawing.Utilities.average_color( sub );

    RGBA rgba = {color.R, color.G, color.B, color.A};
    return( rgba );

  }

  /* Changes the stored image to the given pixbuf and performs other related tasks */
  public void change_image( Pixbuf buf, string? undo_name = _( "change image" ) ) {

    if( (undo_name != null) && (_buf != null) ) {
      _canvas.undo_buffer.add_item( new UndoImageChange( undo_name, _buf, buf ) );
    }

    pixbuf   = buf.copy();
    _buf     = buf.copy();
    _surface = (ImageSurface)cairo_surface_create_from_pixbuf( _buf, 1, null );
    _canvas.set_size_request( _buf.width, _buf.height );

    /* Create the image information */
    info = new CanvasImageInfo( _buf );

    /* Store the average color value for faster lookups */
    average_color = average_color_of_rect( new CanvasRect.from_coords( 0, 0, _buf.width, _buf.height ) );

    /* Indicate that the image changed to anyone listening */
    image_changed();

  }

  /* Pastes an image from the given pixbuf to the canvas */
  public void set_image( Pixbuf buf, string? undo_name = _( "change image" ) ) {

    /* Delete the canvas items */
    _canvas.items.clear();

    /* Update the image */
    change_image( buf, undo_name );

  }

  /* Resizes the current image */
  public void resize_image() {

    var dialog = new Resizer( _canvas, info );

    if( dialog.run() == ResponseType.ACCEPT ) {

      /* Get the information from the resizer */
      var old_info = new CanvasImageInfo.from_info( info );
      var new_info = dialog.get_image_info();

      /* Add the resize to the undo buffer */
      _canvas.undo_buffer.add_item( new UndoImageResize( old_info, new_info ) );

      /* Perform resize */
      do_resize( old_info, new_info );

    }

    dialog.close();

  }

  /* This is the function that performs the actual resize */
  public void do_resize( CanvasImageInfo old_info, CanvasImageInfo new_info ) {

    /* Copy the new info into our info */
    info.copy( new_info );

    /* Create a new buffer with the added margin */
    var sbuf = pixbuf.scale_simple( (int)info.pixbuf_rect.width, (int)info.pixbuf_rect.height, InterpType.BILINEAR );
    _buf = new Pixbuf( pixbuf.colorspace, pixbuf.has_alpha, pixbuf.bits_per_sample, info.width, info.height );
    _buf.fill( (uint32)0xffffffff );
    sbuf.copy_area( 0, 0, (int)info.pixbuf_rect.width, (int)info.pixbuf_rect.height, _buf, (int)info.pixbuf_rect.x, (int)info.pixbuf_rect.y );

    /* Set the surface that will be drawn */
    _surface = (ImageSurface)cairo_surface_create_from_pixbuf( _buf, 1, null );

    /* Calculate the scaling factors */
    width_scale  = info.pixbuf_rect.width  / pixbuf.width;
    height_scale = info.pixbuf_rect.height / pixbuf.height;

    /* Resize the canvas */
    _canvas.resize( old_info, new_info );

  }

  /****************************************************************************/
  //  KEY EVENT HANDLER
  /****************************************************************************/

  /* Handles a keypress event */
  public bool key_pressed( uint keyval, ModifierType state ) {

    switch( keyval ) {
      case Key.Return :  return( end_crop() );
      case Key.Escape :  return( cancel_crop() );
    }

    return( false );

  }

  /****************************************************************************/
  //  MOUSE EVENT HANDLER
  /****************************************************************************/

  /* Handles a cursor press event */
  public bool cursor_pressed( double x, double y, ModifierType state, int press_count ) {

    var rect = new CanvasRect();

    _last_x     = x;
    _last_y     = y;
    _crop_index = -2;

    if( cropping ) {
      for( int i=0; i<8; i++ ) {
        selector_bbox( i, rect );
        if( rect.contains( x, y ) ) {
          _crop_index = i;
          return( true );
        }
      }
      if( crop_rect.contains( x, y ) ) {
        _crop_index = -1;
        _canvas.set_cursor_from_name( "grabbing" );
      } else {
        cancel_crop();
      }
    }

    return( false );

  }

  /* Handles a cursor motion event */
  public bool cursor_moved( double x, double y, ModifierType state ) {

    var diffx = x - _last_x;
    var diffy = y - _last_y;
    var box   = new CanvasRect.from_rect( crop_rect );

    _last_x = x;
    _last_y = y;

    /* If we clicked into the crop rectangle, move the rectangle */
    if( _crop_index == -1 ) {
      box.x += diffx;
      box.y += diffy;
      if( (box.x >= 0) &&
          (box.y >= 0) &&
          ((box.x + box.width)  <= (info.width  / width_scale)) &&
          ((box.y + box.height) <= (info.height / height_scale)) ) {
        crop_rect.copy( box );
        return( true );
      }

    /* If we are dragging a selector box, handle the move and resize */
    } else if( _crop_index >= 0 ) {
      switch( _crop_index ) {
        case 0  :  box.x += diffx;  box.y += diffy;  box.width -= diffx;  box.height -= diffy;  break;
        case 1  :                   box.y += diffy;  box.width += diffx;  box.height -= diffy;  break;
        case 2  :  box.x += diffx;                   box.width -= diffx;  box.height += diffy;  break;
        case 3  :                                    box.width += diffx;  box.height += diffy;  break;
        case 4  :                   box.y += diffy;                       box.height -= diffy;  break;
        case 5  :                                                         box.height += diffy;  break;
        case 6  :  box.x += diffx;                   box.width -= diffx;                        break;
        case 7  :                                    box.width += diffx;                        break;
        default :  assert_not_reached();
      }
      if( (box.x >= 0) &&
          (box.y >= 0) &&
          (box.width  >= (selector_width  * 3)) &&
          (box.height >= (selector_height * 3)) &&
          ((box.x + box.width)  <= (info.width  / width_scale)) &&
          ((box.y + box.height) <= (info.height / height_scale)) ) {
        crop_rect.copy( box );
        return( true );
      }

    /* If we are hovering over a crop selector, change the cursor */
    } else {
      var rect = new CanvasRect();
      for( int i=0; i<8; i++ ) {
        selector_bbox( i, rect );
        if( rect.contains( x, y ) ) {
          switch( i ) {
            case 0 :  _canvas.set_cursor( CursorType.UL_ANGLE );     return( false );
            case 1 :  _canvas.set_cursor( CursorType.UR_ANGLE );     return( false );
            case 2 :  _canvas.set_cursor( CursorType.LL_ANGLE );     return( false );
            case 3 :  _canvas.set_cursor( CursorType.LR_ANGLE );     return( false );
            case 4 :  _canvas.set_cursor( CursorType.TOP_SIDE );     return( false );
            case 5 :  _canvas.set_cursor( CursorType.BOTTOM_SIDE );  return( false );
            case 6 :  _canvas.set_cursor( CursorType.LEFT_SIDE );    return( false );
            case 7 :  _canvas.set_cursor( CursorType.RIGHT_SIDE );   return( false );
          }
        }
      }
      _canvas.set_cursor( null );
    }

    return( false );

  }

  /* Handles a cursor release event */
  public bool cursor_released( double x, double y, ModifierType state ) {

    _crop_index = -2;
    _canvas.set_cursor( null );

    return( false );

  }

  /****************************************************************************/
  //  CROP HANDLING CODE
  /****************************************************************************/

  /* Start the cropping function */
  public void start_crop() {
    int width, height;
    cropping = true;
    // crop_rect.copy_coords( 0, 0, (width / width_scale), (height / height_scale) );
    crop_rect.copy_coords( 0, 0, info.width, info.height );
    crop_started();
  }

  /* Cancels the crop operation */
  public bool cancel_crop() {
    cropping = false;
    _canvas.queue_draw();
    crop_ended();
    return( true );
  }

  /* Completes the cropping operation */
  public bool end_crop() {
    cropping = false;
    var buf = new Pixbuf.subpixbuf( _buf, (int)crop_rect.x, (int)crop_rect.y, (int)crop_rect.width, (int)crop_rect.height );
    change_image( buf, _( "image crop" ) );
    _canvas.items.adjust_items( (0 - crop_rect.x), (0 - crop_rect.y), false );
    _canvas.queue_draw();
    crop_ended();
    return( true );
  }

  /****************************************************************************/
  //  EXPORTING
  /****************************************************************************/

  /* Make sure that everything is cleared from the image */
  private void clean_image() {
    cropping = false;
    _canvas.items.clear_selection();
    _canvas.queue_draw();
  }

  /* Exports to the given image type */
  public void export_image( ExportType type, string? filename = null ) {
    clean_image();
    exporter.export_image( _surface, type, filename );
  }

  /* Exports the image to the clipboard */
  public void export_clipboard() {
    clean_image();
    exporter.export_clipboard( _surface );
  }

  /* Exports the image to the printer */
  public void export_print() {
    clean_image();
    exporter.export_print( _surface );
  }

  /****************************************************************************/
  //  DRAWING
  /****************************************************************************/

  /* Calculates the box for the given selector */
  private void selector_bbox( int index, CanvasRect rect ) {

    switch( index ) {
      case 0 :  // UL
      case 1 :  // UR
      case 2 :  // LL
      case 3 :  // LR
        rect.x = ((index & 1) == 0) ? crop_rect.x1() : (crop_rect.x2() - selector_size);
        rect.y = ((index & 2) == 0) ? crop_rect.y1() : (crop_rect.y2() - selector_size);
        break;
      case 4 :  // TOP
      case 5 :  // BOTTOM
        rect.x = crop_rect.mid_x() - (selector_size / 2);
        rect.y = (index == 4) ? crop_rect.y1() : (crop_rect.y2() - selector_size);
        break;
      case 6 :  // LEFT
      case 7 :  // RIGHT
        rect.x = (index == 6) ? crop_rect.x1() : (crop_rect.x2() - selector_size);
        rect.y = crop_rect.mid_y() - (selector_size / 2);
        break;
    }

    rect.width  = selector_size;
    rect.height = selector_size;

  }

  /* Draw the image being annotated */
  private void draw_image( Context ctx ) {

    ctx.set_source_surface( _surface, 0, 0 );
    ctx.paint();

  }

  /* Draws the drop_outline */
  private void draw_crop_outline( Context ctx ) {

    Utils.set_context_color_with_alpha( ctx, average_color, 0.5 );

    ctx.rectangle( 0, 0, crop_rect.x1(), info.height );
    ctx.fill();

    ctx.rectangle( crop_rect.x1(), 0, crop_rect.width, crop_rect.y1() );
    ctx.fill();

    ctx.rectangle( crop_rect.x1(), crop_rect.y2(), crop_rect.width, (info.height - crop_rect.y2()) );
    ctx.fill();

    ctx.rectangle( crop_rect.x2(), 0, (info.width - crop_rect.x2()), info.height );
    ctx.fill();

  }

  /* Draws the thirds dividers when cropping */
  private void draw_crop_dividers( Context ctx ) {

    var third_width  = crop_rect.width  / 3;
    var third_height = crop_rect.height / 3;

    Utils.set_context_color_with_alpha( ctx, average_color, 0.5 );
    ctx.set_line_width( 1 );

    /* Draw vertical lines */
    ctx.move_to( (crop_rect.x1() + third_width), crop_rect.y1() );
    ctx.line_to( (crop_rect.x1() + third_width), crop_rect.y2() );
    ctx.stroke();

    ctx.move_to( (crop_rect.x2() - third_width), crop_rect.y1() );
    ctx.line_to( (crop_rect.x2() - third_width), crop_rect.y2() );
    ctx.stroke();

    /* Draw horizontal lines */
    ctx.move_to( crop_rect.x1(), (crop_rect.y1() + third_height) );
    ctx.line_to( crop_rect.x2(), (crop_rect.y1() + third_height) );
    ctx.stroke();

    ctx.move_to( crop_rect.x1(), (crop_rect.y2() - third_height) );
    ctx.line_to( crop_rect.x2(), (crop_rect.y2() - third_height) );
    ctx.stroke();

  }

  /* Draws the cropping selectors */
  private void draw_crop_selectors( Context ctx ) {

    var blue  = Utils.color_from_string( "light blue" );
    var black = Utils.color_from_string( "black" );
    var rect  = new CanvasRect();

    for( int i=0; i<8; i++ ) {

      selector_bbox( i, rect );

      Utils.set_context_color( ctx, blue );
      ctx.rectangle( rect.x, rect.y, rect.width, rect.height );
      ctx.fill_preserve();

      Utils.set_context_color( ctx, black );
      ctx.set_line_width( 1 );
      ctx.stroke();

    }

  }

  /* Draw the cropping area if we are in that mode */
  private void draw_cropping( Context ctx ) {
    if( !cropping ) return;
    draw_crop_outline( ctx );
    draw_crop_dividers( ctx );
    draw_crop_selectors( ctx );
  }

  /* Draws the image */
  public void draw( Context ctx ) {
    draw_image( ctx );
    draw_cropping( ctx );
    ctx.scale( width_scale, height_scale );
  }

}



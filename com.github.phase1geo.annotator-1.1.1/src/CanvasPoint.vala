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

public enum CanvasPointType {
  NONE,
  RESIZER0,
  RESIZER1,
  RESIZER2,
  RESIZER3,
  HIDDEN0,   // This is a resizer that is currently hidden from view
  HIDDEN1,   // This is a resizer that is currently hidden from view
  HIDDEN2,   // This is a resizer that is currently hidden from view
  HIDDEN3,   // This is a resizer that is currently hidden from view
  CONTROL,
  SELECTOR;

  /* Returns the string version of this type */
  public string to_string() {
    switch( this ) {
      case RESIZER0 :  return( "resizer0" );
      case RESIZER1 :  return( "resizer1" );
      case RESIZER2 :  return( "resizer2" );
      case RESIZER3 :  return( "resizer3" );
      case HIDDEN0  :  return( "hidden0" );
      case HIDDEN1  :  return( "hidden1" );
      case HIDDEN2  :  return( "hidden2" );
      case HIDDEN3  :  return( "hidden3" );
      case CONTROL  :  return( "control" );
      case SELECTOR :  return( "selector" );
      default       :  return( "none" );
    }
  }

  /* Returns the hidden/shown version of the current type */
  public CanvasPointType version( bool hide ) {
    switch( this ) {
      case RESIZER0 :  return( hide ? HIDDEN0 : RESIZER0 );
      case RESIZER1 :  return( hide ? HIDDEN1 : RESIZER1 );
      case RESIZER2 :  return( hide ? HIDDEN2 : RESIZER2 );
      case RESIZER3 :  return( hide ? HIDDEN3 : RESIZER3 );
      case HIDDEN0  :  return( hide ? HIDDEN0 : RESIZER0 );
      case HIDDEN1  :  return( hide ? HIDDEN1 : RESIZER1 );
      case HIDDEN2  :  return( hide ? HIDDEN2 : RESIZER2 );
      case HIDDEN3  :  return( hide ? HIDDEN3 : RESIZER3 );
      default       :  return( this );
    }
  }

  /* Returns true if this point should be drawn */
  public bool draw() {
    return( (this == RESIZER0) || (this == RESIZER1) || (this == RESIZER2) || (this == RESIZER3) || (this == CONTROL) || (this == SELECTOR) );
  }

  /* Returns the color to draw the given point */
  public Gdk.RGBA color() {
    switch( this ) {
      case SELECTOR :
      case HIDDEN0  :
      case HIDDEN1  :
      case HIDDEN2  :
      case HIDDEN3  :
      case RESIZER0 :
      case RESIZER1 :
      case RESIZER2 :
      case RESIZER3 :  return( Utils.color_from_string( "light blue" ) );
      case CONTROL  :  return( Utils.color_from_string( "yellow" ) );
      default       :  return( Utils.color_from_string( "white" ) );
    }
  }
}

public class CanvasPoint {

  public double          x    { get; set; default = 0.0; }
  public double          y    { get; set; default = 0.0; }
  public CanvasPointType kind { get; private set; default = CanvasPointType.NONE; }

  /* Constructor */
  public CanvasPoint( CanvasPointType kind = CanvasPointType.NONE ) {
    this.kind = kind;
  }

  /* Copy constructor */
  public CanvasPoint.from_point( CanvasPoint point ) {
    copy( point );
  }

  /* Constructor */
  public CanvasPoint.from_coords( double x, double y, CanvasPointType kind = CanvasPointType.NONE ) {
    copy_coords( x, y );
    this.kind = kind;
  }

  /* Copies the point information to this instance */
  public void copy( CanvasPoint point ) {
    this.x    = point.x;
    this.y    = point.y;
    this.kind = point.kind;
  }

  /* Copies the x,y coordinates to this instance */
  public void copy_coords( double x, double y ) {
    this.x = x;
    this.y = y;
  }

  /* Adjust the point by the given amounts */
  public void adjust( double diffx, double diffy ) {
    this.x += diffx;
    this.y += diffy;
  }

  /* Updates the visual status of this point kind */
  public void set_visual( CanvasPointType point_kind, bool hide ) {
    if( point_kind != kind ) {
      kind = kind.version( hide );
    }
  }

  /* Returns a printable version of this point */
  public string to_string() {
    return( "x: %g, y: %g, kind: %s".printf( x, y, kind.to_string() ) );
  }

}


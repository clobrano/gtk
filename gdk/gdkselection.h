/* GDK - The GIMP Drawing Kit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __GDK_SELECTION_H__
#define __GDK_SELECTION_H__

#if !defined (__GDK_H_INSIDE__) && !defined (GDK_COMPILATION)
#error "Only <gdk/gdk.h> can be included directly."
#endif

#include <gdk/gdktypes.h>
#include <gdk/gdkversionmacros.h>

G_BEGIN_DECLS

/* Predefined atoms relating to selections. In general, one will need to use
 * gdk_intern_atom
 */
/**
 * GDK_SELECTION_PRIMARY:
 *
 * A #GdkAtom representing the `PRIMARY` selection.
 */
#define GDK_SELECTION_PRIMARY 		gdk_atom_intern_static_string ("PRIMARY")

/**
 * GDK_SELECTION_SECONDARY:
 *
 * A #GdkAtom representing the `SECONDARY` selection.
 */
#define GDK_SELECTION_SECONDARY 	gdk_atom_intern_static_string ("SECONDARY")

/**
 * GDK_SELECTION_CLIPBOARD:
 *
 * A #GdkAtom representing the `CLIPBOARD` selection.
 */
#define GDK_SELECTION_CLIPBOARD 	gdk_atom_intern_static_string ("CLIPBOARD")

/**
 * GDK_TARGET_BITMAP:
 *
 * A #GdkAtom representing the `BITMAP` selection target.
 */
#define GDK_TARGET_BITMAP 		gdk_atom_intern_static_string ("BITMAP")

/**
 * GDK_TARGET_COLORMAP:
 *
 * A #GdkAtom representing the `COLORMAP` selection target.
 */
#define GDK_TARGET_COLORMAP 		gdk_atom_intern_static_string ("COLORMAP")

/**
 * GDK_TARGET_DRAWABLE:
 *
 * A #GdkAtom representing the `DRAWABLE` selection target.
 */
#define GDK_TARGET_DRAWABLE 		gdk_atom_intern_static_string ("DRAWABLE")

/**
 * GDK_TARGET_PIXMAP:
 *
 * A #GdkAtom representing the `PIXMAP` selection target.
 */
#define GDK_TARGET_PIXMAP 		gdk_atom_intern_static_string ("PIXMAP")

/**
 * GDK_TARGET_STRING:
 *
 * A #GdkAtom representing the `STRING` selection target.
 */
#define GDK_TARGET_STRING 		gdk_atom_intern_static_string ("STRING")

/**
 * GDK_SELECTION_TYPE_ATOM:
 *
 * A #GdkAtom representing the `ATOM` selection type.
 */
#define GDK_SELECTION_TYPE_ATOM 	gdk_atom_intern_static_string ("ATOM")

/**
 * GDK_SELECTION_TYPE_BITMAP:
 *
 * A #GdkAtom representing the `BITMAP` selection type.
 */
#define GDK_SELECTION_TYPE_BITMAP 	gdk_atom_intern_static_string ("BITMAP")

/**
 * GDK_SELECTION_TYPE_COLORMAP:
 *
 * A #GdkAtom representing the `COLORMAP` selection type.
 */
#define GDK_SELECTION_TYPE_COLORMAP 	gdk_atom_intern_static_string ("COLORMAP")

/**
 * GDK_SELECTION_TYPE_DRAWABLE:
 *
 * A #GdkAtom representing the `DRAWABLE` selection type.
 */
#define GDK_SELECTION_TYPE_DRAWABLE 	gdk_atom_intern_static_string ("DRAWABLE")

/**
 * GDK_SELECTION_TYPE_INTEGER:
 *
 * A #GdkAtom representing the `INTEGER` selection type.
 */
#define GDK_SELECTION_TYPE_INTEGER 	gdk_atom_intern_static_string ("INTEGER")

/**
 * GDK_SELECTION_TYPE_PIXMAP:
 *
 * A #GdkAtom representing the `PIXMAP` selection type.
 */
#define GDK_SELECTION_TYPE_PIXMAP 	gdk_atom_intern_static_string ("PIXMAP")

/**
 * GDK_SELECTION_TYPE_WINDOW:
 *
 * A #GdkAtom representing the `WINDOW` selection type.
 */
#define GDK_SELECTION_TYPE_WINDOW 	gdk_atom_intern_static_string ("WINDOW")

/**
 * GDK_SELECTION_TYPE_STRING:
 *
 * A #GdkAtom representing the `STRING` selection type.
 */
#define GDK_SELECTION_TYPE_STRING 	gdk_atom_intern_static_string ("STRING")

/* Selections
 */

GDK_AVAILABLE_IN_ALL
gboolean   gdk_selection_owner_set (GdkWindow	 *owner,
				    GdkAtom	  selection,
				    guint32	  time_,
				    gboolean      send_event);
GDK_AVAILABLE_IN_ALL
GdkWindow* gdk_selection_owner_get (GdkAtom	  selection);
GDK_AVAILABLE_IN_ALL
gboolean   gdk_selection_owner_set_for_display (GdkDisplay *display,
						GdkWindow  *owner,
						GdkAtom     selection,
						guint32     time_,
						gboolean    send_event);
GDK_AVAILABLE_IN_ALL
GdkWindow *gdk_selection_owner_get_for_display (GdkDisplay *display,
						GdkAtom     selection);

/**
 * gdk_selection_convert:
 * @requestor: a #GdkWindow.
 * @selection: an atom identifying the selection to get the
 *   contents of.
 * @target: the form in which to retrieve the selection.
 * @time_: the timestamp to use when retrieving the
 *   selection. The selection owner may refuse the
 *   request if it did not own the selection at
 *   the time indicated by the timestamp.
 *
 * Retrieves the contents of a selection in a given
 * form.
 */
GDK_AVAILABLE_IN_ALL
void	   gdk_selection_convert   (GdkWindow	 *requestor,
				    GdkAtom	  selection,
				    GdkAtom	  target,
				    guint32	  time_);
GDK_AVAILABLE_IN_ALL
gint       gdk_selection_property_get (GdkWindow  *requestor,
				       guchar	 **data,
				       GdkAtom	  *prop_type,
				       gint	  *prop_format);

GDK_AVAILABLE_IN_ALL
void	   gdk_selection_send_notify (GdkWindow      *requestor,
				      GdkAtom	      selection,
				      GdkAtom	      target,
				      GdkAtom	      property,
				      guint32	      time_);

GDK_AVAILABLE_IN_ALL
void       gdk_selection_send_notify_for_display (GdkDisplay      *display,
						  GdkWindow       *requestor,
						  GdkAtom     	   selection,
						  GdkAtom     	   target,
						  GdkAtom     	   property,
						  guint32     	   time_);

GDK_AVAILABLE_IN_3_94
void       gdk_selection_clear_targets           (GdkDisplay      *display,
                                                  GdkAtom          selection);

GDK_AVAILABLE_IN_3_94
void       gdk_selection_add_targets             (GdkWindow       *window,
                                                  GdkAtom          selection,
                                                  GdkAtom         *targets,
                                                  guint            n_targets);

G_END_DECLS

#endif /* __GDK_SELECTION_H__ */

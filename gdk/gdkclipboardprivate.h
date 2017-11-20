/*
 * Copyright (C) 2014 Red Hat, Inc.
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

#ifndef __GDK_CLIPBOARD_PRIVATE_H__
#define __GDK_CLIPBOARD_PRIVATE_H__

#include <gdk/gdkclipboard.h>

G_BEGIN_DECLS

#define GDK_CLIPBOARD_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_CLIPBOARD, GdkClipboardClass))
#define GDK_IS_CLIPBOARD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_CLIPBOARD))
#define GDK_CLIPBOARD_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_CLIPBOARD, GdkClipboardClass))

typedef struct _GdkClipboardClass GdkClipboardClass;

struct _GdkClipboard
{
  GObject parent;
};

struct _GdkClipboardClass
{
  GObjectClass parent_class;

  /* signals */
  void          (* changed)          (GdkClipboard           *clipboard);

  /* vfuncs */
};

GdkClipboard *          gdk_clipboard_new                       (GdkDisplay             *display);


G_END_DECLS

#endif /* __GDK_CLIPBOARD_PRIVATE_H__ */

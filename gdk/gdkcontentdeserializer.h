/* GTK - The GIMP Toolkit
 * Copyright (C) 2017 Benjamin Otte
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

#ifndef __GTK_CONTENT_DESERIALIZER_H__
#define __GTK_CONTENT_DESERIALIZER_H__

#if !defined (__GDK_H_INSIDE__) && !defined (GDK_COMPILATION)
#error "Only <gdk/gdk.h> can be included directly."
#endif


#include <gdk/gdkversionmacros.h>
#include <gdk/gdktypes.h>
#include <gio/gio.h>

G_BEGIN_DECLS

#define GDK_TYPE_CONTENT_DESERIALIZER         (gdk_content_deserializer_get_type ())
#define GDK_CONTENT_DESERIALIZER(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GDK_TYPE_CONTENT_DESERIALIZER, GdkContentDeserializer))
#define GDK_IS_CONTENT_DESERIALIZER(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GDK_TYPE_CONTENT_DESERIALIZER))

typedef struct _GdkContentDeserializer GdkContentDeserializer;

typedef void (* GdkContentDeserializeFunc) (GdkContentDeserializer *deserializer);

GDK_AVAILABLE_IN_3_94
GType                   gdk_content_deserializer_get_type               (void) G_GNUC_CONST;

GDK_AVAILABLE_IN_3_94
const char *            gdk_content_deserializer_get_mime_type          (GdkContentDeserializer *deserializer);
GDK_AVAILABLE_IN_3_94
GType                   gdk_content_deserializer_get_gtype              (GdkContentDeserializer *deserializer);
GDK_AVAILABLE_IN_3_94
GValue *                gdk_content_deserializer_get_value              (GdkContentDeserializer *deserializer);
GDK_AVAILABLE_IN_3_94
GInputStream *          gdk_content_deserializer_get_input_stream       (GdkContentDeserializer *deserializer);
GDK_AVAILABLE_IN_3_94
int                     gdk_content_deserializer_get_priority           (GdkContentDeserializer *deserializer);
GDK_AVAILABLE_IN_3_94
GCancellable *          gdk_content_deserializer_get_cancellable        (GdkContentDeserializer *deserializer);
GDK_AVAILABLE_IN_3_94
gpointer                gdk_content_deserializer_get_user_data          (GdkContentDeserializer *deserializer);

GDK_AVAILABLE_IN_3_94
void                    gdk_content_deserializer_return_success         (GdkContentDeserializer *deserializer);
GDK_AVAILABLE_IN_3_94
void                    gdk_content_deserializer_return_error           (GdkContentDeserializer *deserializer,
                                                                         GError                 *error);

GDK_AVAILABLE_IN_3_94
GdkContentFormats *     gdk_content_formats_union_deserialize_gtypes    (GdkContentFormats      *formats);
GDK_AVAILABLE_IN_3_94
GdkContentFormats *     gdk_content_formats_union_deserialize_mime_types(GdkContentFormats      *formats);

GDK_AVAILABLE_IN_3_94
void                    gdk_content_register_deserializer               (const char             *mime_type,
                                                                         GType                   type,
                                                                         GdkContentDeserializeFunc deserialize,
                                                                         gpointer                data,
                                                                         GDestroyNotify          notify);
GDK_AVAILABLE_IN_3_94
void                    gdk_content_deserialize_async                   (GInputStream           *stream,
                                                                         const char             *mime_type,
                                                                         GType                   type,
                                                                         int                     io_priority,
                                                                         GCancellable           *cancellable,
                                                                         GAsyncReadyCallback     callback,
                                                                         gpointer                user_data);
GDK_AVAILABLE_IN_3_94
const GValue *          gdk_content_deserialize_finish                  (GAsyncResult           *result,
                                                                         GError                **error);


G_END_DECLS

#endif /* __GDK_CONTENT_DESERIALIZER_H__ */

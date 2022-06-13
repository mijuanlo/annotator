/* parsercallback.c generated by valac, the Vala compiler
 * generated from parsercallback.vala, do not modify */

/* parsercallback.vala
 *
 * Copyright (C) 2008-2009 Florian Brosch, Didier Villevalois
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Didier 'Ptitjes Villevalois <ptitjes@free.fr>
 */

#include "valadoc.h"
#include <glib-object.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>

static GType valadoc_parser_callback_get_type_once (void);

GObject*
valadoc_parser_callback_get_rule_state (ValadocParserCallback* self)
{
	g_return_val_if_fail (self != NULL, NULL);
	return VALADOC_PARSER_CALLBACK_GET_INTERFACE (self)->get_rule_state (self);
}

void
valadoc_parser_callback_set_rule_state (ValadocParserCallback* self,
                                        GObject* state)
{
	g_return_if_fail (self != NULL);
	VALADOC_PARSER_CALLBACK_GET_INTERFACE (self)->set_rule_state (self, state);
}

void
valadoc_parser_callback_push_rule (ValadocParserCallback* self,
                                   ValadocRule* rule)
{
	g_return_if_fail (self != NULL);
	VALADOC_PARSER_CALLBACK_GET_INTERFACE (self)->push_rule (self, rule);
}

void
valadoc_parser_callback_reduce (ValadocParserCallback* self)
{
	g_return_if_fail (self != NULL);
	VALADOC_PARSER_CALLBACK_GET_INTERFACE (self)->reduce (self);
}

gboolean
valadoc_parser_callback_would_parent_accept_token (ValadocParserCallback* self,
                                                   ValadocToken* token)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return VALADOC_PARSER_CALLBACK_GET_INTERFACE (self)->would_parent_accept_token (self, token);
}

gboolean
valadoc_parser_callback_would_parent_reduce_to_rule (ValadocParserCallback* self,
                                                     ValadocToken* token,
                                                     ValadocRule* rule)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return VALADOC_PARSER_CALLBACK_GET_INTERFACE (self)->would_parent_reduce_to_rule (self, token, rule);
}

void
valadoc_parser_callback_warning (ValadocParserCallback* self,
                                 ValadocToken* token,
                                 const gchar* message)
{
	g_return_if_fail (self != NULL);
	VALADOC_PARSER_CALLBACK_GET_INTERFACE (self)->warning (self, token, message);
}

void
valadoc_parser_callback_error (ValadocParserCallback* self,
                               ValadocToken* token,
                               const gchar* message,
                               GError** error)
{
	g_return_if_fail (self != NULL);
	VALADOC_PARSER_CALLBACK_GET_INTERFACE (self)->error (self, token, message, error);
}

static void
valadoc_parser_callback_default_init (ValadocParserCallbackIface * iface,
                                      gpointer iface_data)
{
}

static GType
valadoc_parser_callback_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValadocParserCallbackIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) valadoc_parser_callback_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType valadoc_parser_callback_type_id;
	valadoc_parser_callback_type_id = g_type_register_static (G_TYPE_INTERFACE, "ValadocParserCallback", &g_define_type_info, 0);
	return valadoc_parser_callback_type_id;
}

GType
valadoc_parser_callback_get_type (void)
{
	static volatile gsize valadoc_parser_callback_type_id__volatile = 0;
	if (g_once_init_enter (&valadoc_parser_callback_type_id__volatile)) {
		GType valadoc_parser_callback_type_id;
		valadoc_parser_callback_type_id = valadoc_parser_callback_get_type_once ();
		g_once_init_leave (&valadoc_parser_callback_type_id__volatile, valadoc_parser_callback_type_id);
	}
	return valadoc_parser_callback_type_id__volatile;
}

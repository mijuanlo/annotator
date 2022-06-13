/* valareferencetype.c generated by valac, the Vala compiler
 * generated from valareferencetype.vala, do not modify */

/* valareferencetype.vala
 *
 * Copyright (C) 2007  Jürg Billeter
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Jürg Billeter <j@bitron.ch>
 */

#include "vala.h"

static gpointer vala_reference_type_parent_class = NULL;

static GType vala_reference_type_get_type_once (void);

ValaReferenceType*
vala_reference_type_construct (GType object_type,
                               ValaSymbol* symbol)
{
	ValaReferenceType* self = NULL;
	self = (ValaReferenceType*) vala_data_type_construct_with_symbol (object_type, symbol);
	return self;
}

static void
vala_reference_type_class_init (ValaReferenceTypeClass * klass,
                                gpointer klass_data)
{
	vala_reference_type_parent_class = g_type_class_peek_parent (klass);
}

static void
vala_reference_type_instance_init (ValaReferenceType * self,
                                   gpointer klass)
{
}

/**
 * A reference type, i.e. a class, interface, or array type.
 */
static GType
vala_reference_type_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaReferenceTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_reference_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaReferenceType), 0, (GInstanceInitFunc) vala_reference_type_instance_init, NULL };
	GType vala_reference_type_type_id;
	vala_reference_type_type_id = g_type_register_static (VALA_TYPE_DATA_TYPE, "ValaReferenceType", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	return vala_reference_type_type_id;
}

GType
vala_reference_type_get_type (void)
{
	static volatile gsize vala_reference_type_type_id__volatile = 0;
	if (g_once_init_enter (&vala_reference_type_type_id__volatile)) {
		GType vala_reference_type_type_id;
		vala_reference_type_type_id = vala_reference_type_get_type_once ();
		g_once_init_leave (&vala_reference_type_type_id__volatile, vala_reference_type_type_id);
	}
	return vala_reference_type_type_id__volatile;
}


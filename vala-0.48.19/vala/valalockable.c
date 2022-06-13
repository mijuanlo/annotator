/* valalockable.c generated by valac, the Vala compiler
 * generated from valalockable.vala, do not modify */

/* valalockable.vala
 *
 * Copyright (C) 2006-2007  Raffaele Sandrini, Jürg Billeter
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
 * 	Raffaele Sandrini <raffaele@sandrini.ch>
 * 	Jürg Billeter <j@bitron.ch>
 */

#include "vala.h"
#include <glib.h>

static GType vala_lockable_get_type_once (void);

gboolean
vala_lockable_get_lock_used (ValaLockable* self)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return VALA_LOCKABLE_GET_INTERFACE (self)->get_lock_used (self);
}

void
vala_lockable_set_lock_used (ValaLockable* self,
                             gboolean value)
{
	g_return_if_fail (self != NULL);
	VALA_LOCKABLE_GET_INTERFACE (self)->set_lock_used (self, value);
}

static void
vala_lockable_default_init (ValaLockableIface * iface,
                            gpointer iface_data)
{
}

/**
 * Represents a lockable object.
 */
static GType
vala_lockable_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaLockableIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_lockable_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType vala_lockable_type_id;
	vala_lockable_type_id = g_type_register_static (G_TYPE_INTERFACE, "ValaLockable", &g_define_type_info, 0);
	return vala_lockable_type_id;
}

GType
vala_lockable_get_type (void)
{
	static volatile gsize vala_lockable_type_id__volatile = 0;
	if (g_once_init_enter (&vala_lockable_type_id__volatile)) {
		GType vala_lockable_type_id;
		vala_lockable_type_id = vala_lockable_get_type_once ();
		g_once_init_leave (&vala_lockable_type_id__volatile, vala_lockable_type_id);
	}
	return vala_lockable_type_id__volatile;
}

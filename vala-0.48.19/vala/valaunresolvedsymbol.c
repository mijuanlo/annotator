/* valaunresolvedsymbol.c generated by valac, the Vala compiler
 * generated from valaunresolvedsymbol.vala, do not modify */

/* valaunresolvedsymbol.vala
 *
 * Copyright (C) 2008-2009  Jürg Billeter
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
#include <glib.h>
#include <stdlib.h>
#include <string.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaUnresolvedSymbolPrivate {
	ValaUnresolvedSymbol* _inner;
	gboolean _qualified;
};

static gint ValaUnresolvedSymbol_private_offset;
static gpointer vala_unresolved_symbol_parent_class = NULL;

static gchar* vala_unresolved_symbol_real_to_string (ValaCodeNode* base);
static void vala_unresolved_symbol_finalize (ValaCodeNode * obj);
static GType vala_unresolved_symbol_get_type_once (void);

static inline gpointer
vala_unresolved_symbol_get_instance_private (ValaUnresolvedSymbol* self)
{
	return G_STRUCT_MEMBER_P (self, ValaUnresolvedSymbol_private_offset);
}

ValaUnresolvedSymbol*
vala_unresolved_symbol_get_inner (ValaUnresolvedSymbol* self)
{
	ValaUnresolvedSymbol* result;
	ValaUnresolvedSymbol* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_inner;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

void
vala_unresolved_symbol_set_inner (ValaUnresolvedSymbol* self,
                                  ValaUnresolvedSymbol* value)
{
	ValaUnresolvedSymbol* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_inner);
	self->priv->_inner = _tmp0_;
}

gboolean
vala_unresolved_symbol_get_qualified (ValaUnresolvedSymbol* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_qualified;
	return result;
}

void
vala_unresolved_symbol_set_qualified (ValaUnresolvedSymbol* self,
                                      gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_qualified = value;
}

ValaUnresolvedSymbol*
vala_unresolved_symbol_construct (GType object_type,
                                  ValaUnresolvedSymbol* inner,
                                  const gchar* name,
                                  ValaSourceReference* source_reference)
{
	ValaUnresolvedSymbol* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	self = (ValaUnresolvedSymbol*) vala_symbol_construct (object_type, name, source_reference, NULL);
	vala_unresolved_symbol_set_inner (self, inner);
	return self;
}

ValaUnresolvedSymbol*
vala_unresolved_symbol_new (ValaUnresolvedSymbol* inner,
                            const gchar* name,
                            ValaSourceReference* source_reference)
{
	return vala_unresolved_symbol_construct (VALA_TYPE_UNRESOLVED_SYMBOL, inner, name, source_reference);
}

ValaUnresolvedSymbol*
vala_unresolved_symbol_new_from_expression (ValaExpression* expr)
{
	ValaMemberAccess* ma = NULL;
	ValaMemberAccess* _tmp0_;
	ValaSourceReference* _tmp24_;
	ValaSourceReference* _tmp25_;
	ValaUnresolvedSymbol* result = NULL;
	g_return_val_if_fail (expr != NULL, NULL);
	ma = VALA_IS_MEMBER_ACCESS (expr) ? ((ValaMemberAccess*) expr) : NULL;
	_tmp0_ = ma;
	if (_tmp0_ != NULL) {
		ValaMemberAccess* _tmp1_;
		ValaExpression* _tmp2_;
		ValaExpression* _tmp3_;
		_tmp1_ = ma;
		_tmp2_ = vala_member_access_get_inner (_tmp1_);
		_tmp3_ = _tmp2_;
		if (_tmp3_ != NULL) {
			ValaMemberAccess* _tmp4_;
			ValaExpression* _tmp5_;
			ValaExpression* _tmp6_;
			ValaUnresolvedSymbol* _tmp7_;
			ValaUnresolvedSymbol* _tmp8_;
			ValaMemberAccess* _tmp9_;
			const gchar* _tmp10_;
			const gchar* _tmp11_;
			ValaMemberAccess* _tmp12_;
			ValaSourceReference* _tmp13_;
			ValaSourceReference* _tmp14_;
			ValaUnresolvedSymbol* _tmp15_;
			ValaUnresolvedSymbol* _tmp16_;
			_tmp4_ = ma;
			_tmp5_ = vala_member_access_get_inner (_tmp4_);
			_tmp6_ = _tmp5_;
			_tmp7_ = vala_unresolved_symbol_new_from_expression (_tmp6_);
			_tmp8_ = _tmp7_;
			_tmp9_ = ma;
			_tmp10_ = vala_member_access_get_member_name (_tmp9_);
			_tmp11_ = _tmp10_;
			_tmp12_ = ma;
			_tmp13_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp12_);
			_tmp14_ = _tmp13_;
			_tmp15_ = vala_unresolved_symbol_new (_tmp8_, _tmp11_, _tmp14_);
			_tmp16_ = _tmp15_;
			_vala_code_node_unref0 (_tmp8_);
			result = _tmp16_;
			return result;
		} else {
			ValaMemberAccess* _tmp17_;
			const gchar* _tmp18_;
			const gchar* _tmp19_;
			ValaMemberAccess* _tmp20_;
			ValaSourceReference* _tmp21_;
			ValaSourceReference* _tmp22_;
			ValaUnresolvedSymbol* _tmp23_;
			_tmp17_ = ma;
			_tmp18_ = vala_member_access_get_member_name (_tmp17_);
			_tmp19_ = _tmp18_;
			_tmp20_ = ma;
			_tmp21_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp20_);
			_tmp22_ = _tmp21_;
			_tmp23_ = vala_unresolved_symbol_new (NULL, _tmp19_, _tmp22_);
			result = _tmp23_;
			return result;
		}
	}
	_tmp24_ = vala_code_node_get_source_reference ((ValaCodeNode*) expr);
	_tmp25_ = _tmp24_;
	vala_report_error (_tmp25_, "Type reference must be simple name or member access expression");
	result = NULL;
	return result;
}

static gchar*
vala_unresolved_symbol_real_to_string (ValaCodeNode* base)
{
	ValaUnresolvedSymbol * self;
	ValaUnresolvedSymbol* _tmp0_;
	gchar* result = NULL;
	self = (ValaUnresolvedSymbol*) base;
	_tmp0_ = self->priv->_inner;
	if (_tmp0_ == NULL) {
		const gchar* _tmp1_;
		const gchar* _tmp2_;
		gchar* _tmp3_;
		_tmp1_ = vala_symbol_get_name ((ValaSymbol*) self);
		_tmp2_ = _tmp1_;
		_tmp3_ = g_strdup (_tmp2_);
		result = _tmp3_;
		return result;
	} else {
		ValaUnresolvedSymbol* _tmp4_;
		gchar* _tmp5_;
		gchar* _tmp6_;
		const gchar* _tmp7_;
		const gchar* _tmp8_;
		gchar* _tmp9_;
		gchar* _tmp10_;
		_tmp4_ = self->priv->_inner;
		_tmp5_ = vala_code_node_to_string ((ValaCodeNode*) _tmp4_);
		_tmp6_ = _tmp5_;
		_tmp7_ = vala_symbol_get_name ((ValaSymbol*) self);
		_tmp8_ = _tmp7_;
		_tmp9_ = g_strdup_printf ("%s.%s", _tmp6_, _tmp8_);
		_tmp10_ = _tmp9_;
		_g_free0 (_tmp6_);
		result = _tmp10_;
		return result;
	}
}

ValaUnresolvedSymbol*
vala_unresolved_symbol_copy (ValaUnresolvedSymbol* self)
{
	ValaUnresolvedSymbol* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	ValaSourceReference* _tmp3_;
	ValaSourceReference* _tmp4_;
	ValaUnresolvedSymbol* _tmp5_;
	ValaUnresolvedSymbol* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_inner;
	_tmp1_ = vala_symbol_get_name ((ValaSymbol*) self);
	_tmp2_ = _tmp1_;
	_tmp3_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp4_ = _tmp3_;
	_tmp5_ = vala_unresolved_symbol_new (_tmp0_, _tmp2_, _tmp4_);
	result = _tmp5_;
	return result;
}

static void
vala_unresolved_symbol_class_init (ValaUnresolvedSymbolClass * klass,
                                   gpointer klass_data)
{
	vala_unresolved_symbol_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_unresolved_symbol_finalize;
	g_type_class_adjust_private_offset (klass, &ValaUnresolvedSymbol_private_offset);
	((ValaCodeNodeClass *) klass)->to_string = (gchar* (*) (ValaCodeNode*)) vala_unresolved_symbol_real_to_string;
}

static void
vala_unresolved_symbol_instance_init (ValaUnresolvedSymbol * self,
                                      gpointer klass)
{
	self->priv = vala_unresolved_symbol_get_instance_private (self);
}

static void
vala_unresolved_symbol_finalize (ValaCodeNode * obj)
{
	ValaUnresolvedSymbol * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_UNRESOLVED_SYMBOL, ValaUnresolvedSymbol);
	_vala_code_node_unref0 (self->priv->_inner);
	VALA_CODE_NODE_CLASS (vala_unresolved_symbol_parent_class)->finalize (obj);
}

/**
 * An unresolved reference to a symbol.
 */
static GType
vala_unresolved_symbol_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaUnresolvedSymbolClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_unresolved_symbol_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaUnresolvedSymbol), 0, (GInstanceInitFunc) vala_unresolved_symbol_instance_init, NULL };
	GType vala_unresolved_symbol_type_id;
	vala_unresolved_symbol_type_id = g_type_register_static (VALA_TYPE_SYMBOL, "ValaUnresolvedSymbol", &g_define_type_info, 0);
	ValaUnresolvedSymbol_private_offset = g_type_add_instance_private (vala_unresolved_symbol_type_id, sizeof (ValaUnresolvedSymbolPrivate));
	return vala_unresolved_symbol_type_id;
}

GType
vala_unresolved_symbol_get_type (void)
{
	static volatile gsize vala_unresolved_symbol_type_id__volatile = 0;
	if (g_once_init_enter (&vala_unresolved_symbol_type_id__volatile)) {
		GType vala_unresolved_symbol_type_id;
		vala_unresolved_symbol_type_id = vala_unresolved_symbol_get_type_once ();
		g_once_init_leave (&vala_unresolved_symbol_type_id__volatile, vala_unresolved_symbol_type_id);
	}
	return vala_unresolved_symbol_type_id__volatile;
}

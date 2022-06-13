/* valaexpression.c generated by valac, the Vala compiler
 * generated from valaexpression.vala, do not modify */

/* valaexpression.vala
 *
 * Copyright (C) 2006-2010  Jürg Billeter
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

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _vala_target_value_unref0(var) ((var == NULL) ? NULL : (var = (vala_target_value_unref (var), NULL)))

struct _ValaExpressionPrivate {
	ValaDataType* _value_type;
	ValaDataType* _formal_value_type;
	ValaDataType* _target_type;
	ValaDataType* _formal_target_type;
	ValaSymbol* _symbol_reference;
	gboolean _lvalue;
	ValaTargetValue* _target_value;
};

static gint ValaExpression_private_offset;
static gpointer vala_expression_parent_class = NULL;

static gboolean vala_expression_real_is_constant (ValaExpression* self);
static gboolean vala_expression_real_is_pure (ValaExpression* self);
static gboolean vala_expression_real_is_non_null (ValaExpression* self);
static gboolean vala_expression_real_is_accessible (ValaExpression* self,
                                             ValaSymbol* sym);
static void vala_expression_finalize (ValaCodeNode * obj);
static GType vala_expression_get_type_once (void);

static inline gpointer
vala_expression_get_instance_private (ValaExpression* self)
{
	return G_STRUCT_MEMBER_P (self, ValaExpression_private_offset);
}

ValaDataType*
vala_expression_get_value_type (ValaExpression* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_value_type;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

void
vala_expression_set_value_type (ValaExpression* self,
                                ValaDataType* value)
{
	ValaDataType* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_value_type);
	self->priv->_value_type = _tmp0_;
}

ValaDataType*
vala_expression_get_formal_value_type (ValaExpression* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_formal_value_type;
	result = _tmp0_;
	return result;
}

void
vala_expression_set_formal_value_type (ValaExpression* self,
                                       ValaDataType* value)
{
	ValaDataType* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_formal_value_type);
	self->priv->_formal_value_type = _tmp0_;
}

ValaDataType*
vala_expression_get_target_type (ValaExpression* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_target_type;
	result = _tmp0_;
	return result;
}

void
vala_expression_set_target_type (ValaExpression* self,
                                 ValaDataType* value)
{
	ValaDataType* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_target_type);
	self->priv->_target_type = _tmp0_;
}

ValaDataType*
vala_expression_get_formal_target_type (ValaExpression* self)
{
	ValaDataType* result;
	ValaDataType* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_formal_target_type;
	result = _tmp0_;
	return result;
}

void
vala_expression_set_formal_target_type (ValaExpression* self,
                                        ValaDataType* value)
{
	ValaDataType* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_formal_target_type);
	self->priv->_formal_target_type = _tmp0_;
}

ValaSymbol*
vala_expression_get_symbol_reference (ValaExpression* self)
{
	ValaSymbol* result;
	ValaSymbol* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_symbol_reference;
	result = _tmp0_;
	return result;
}

void
vala_expression_set_symbol_reference (ValaExpression* self,
                                      ValaSymbol* value)
{
	g_return_if_fail (self != NULL);
	self->priv->_symbol_reference = value;
}

gboolean
vala_expression_get_lvalue (ValaExpression* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_lvalue;
	return result;
}

void
vala_expression_set_lvalue (ValaExpression* self,
                            gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_lvalue = value;
}

ValaTargetValue*
vala_expression_get_target_value (ValaExpression* self)
{
	ValaTargetValue* result;
	ValaTargetValue* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_target_value;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_target_value_ref0 (gpointer self)
{
	return self ? vala_target_value_ref (self) : NULL;
}

void
vala_expression_set_target_value (ValaExpression* self,
                                  ValaTargetValue* value)
{
	ValaTargetValue* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_target_value_ref0 (value);
	_vala_target_value_unref0 (self->priv->_target_value);
	self->priv->_target_value = _tmp0_;
}

/**
 * Returns whether this expression is constant, i.e. whether this
 * expression only consists of literals and other constants.
 */
static gboolean
vala_expression_real_is_constant (ValaExpression* self)
{
	gboolean result = FALSE;
	result = FALSE;
	return result;
}

gboolean
vala_expression_is_constant (ValaExpression* self)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return VALA_EXPRESSION_GET_CLASS (self)->is_constant (self);
}

/**
 * Returns whether this expression is pure, i.e. whether this expression
 * is free of side-effects.
 */
static gboolean
vala_expression_real_is_pure (ValaExpression* self)
{
	gboolean _tmp0_ = FALSE;
	g_critical ("Type `%s' does not implement abstract method `vala_expression_is_pure'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return _tmp0_;
}

gboolean
vala_expression_is_pure (ValaExpression* self)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return VALA_EXPRESSION_GET_CLASS (self)->is_pure (self);
}

/**
 * Returns whether this expression is guaranteed to be non-null.
 */
static gboolean
vala_expression_real_is_non_null (ValaExpression* self)
{
	gboolean result = FALSE;
	result = FALSE;
	return result;
}

gboolean
vala_expression_is_non_null (ValaExpression* self)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return VALA_EXPRESSION_GET_CLASS (self)->is_non_null (self);
}

/**
 * Check whether symbol_references in this expression are at least
 * as accessible as the specified symbol.
 */
static gboolean
vala_expression_real_is_accessible (ValaExpression* self,
                                    ValaSymbol* sym)
{
	gboolean result = FALSE;
	g_return_val_if_fail (sym != NULL, FALSE);
	result = TRUE;
	return result;
}

gboolean
vala_expression_is_accessible (ValaExpression* self,
                               ValaSymbol* sym)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return VALA_EXPRESSION_GET_CLASS (self)->is_accessible (self, sym);
}

ValaStatement*
vala_expression_get_parent_statement (ValaExpression* self)
{
	ValaStatement* result;
	ValaExpression* expr = NULL;
	ValaCodeNode* _tmp0_;
	ValaCodeNode* _tmp1_;
	ValaStatement* stmt = NULL;
	ValaCodeNode* _tmp2_;
	ValaCodeNode* _tmp3_;
	ValaLocalVariable* local = NULL;
	ValaCodeNode* _tmp4_;
	ValaCodeNode* _tmp5_;
	ValaMemberInitializer* initializer = NULL;
	ValaCodeNode* _tmp6_;
	ValaCodeNode* _tmp7_;
	ValaStatement* _tmp8_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	expr = VALA_IS_EXPRESSION (_tmp1_) ? ((ValaExpression*) _tmp1_) : NULL;
	_tmp2_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
	_tmp3_ = _tmp2_;
	stmt = VALA_IS_STATEMENT (_tmp3_) ? ((ValaStatement*) _tmp3_) : NULL;
	_tmp4_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
	_tmp5_ = _tmp4_;
	local = VALA_IS_LOCAL_VARIABLE (_tmp5_) ? ((ValaLocalVariable*) _tmp5_) : NULL;
	_tmp6_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
	_tmp7_ = _tmp6_;
	initializer = VALA_IS_MEMBER_INITIALIZER (_tmp7_) ? ((ValaMemberInitializer*) _tmp7_) : NULL;
	_tmp8_ = stmt;
	if (_tmp8_ != NULL) {
		ValaCodeNode* _tmp9_;
		ValaCodeNode* _tmp10_;
		_tmp9_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
		_tmp10_ = _tmp9_;
		result = G_TYPE_CHECK_INSTANCE_CAST (_tmp10_, VALA_TYPE_STATEMENT, ValaStatement);
		return result;
	} else {
		ValaExpression* _tmp11_;
		_tmp11_ = expr;
		if (_tmp11_ != NULL) {
			ValaExpression* _tmp12_;
			ValaStatement* _tmp13_;
			ValaStatement* _tmp14_;
			_tmp12_ = expr;
			_tmp13_ = vala_expression_get_parent_statement (_tmp12_);
			_tmp14_ = _tmp13_;
			result = _tmp14_;
			return result;
		} else {
			ValaLocalVariable* _tmp15_;
			_tmp15_ = local;
			if (_tmp15_ != NULL) {
				ValaLocalVariable* _tmp16_;
				ValaCodeNode* _tmp17_;
				ValaCodeNode* _tmp18_;
				_tmp16_ = local;
				_tmp17_ = vala_code_node_get_parent_node ((ValaCodeNode*) _tmp16_);
				_tmp18_ = _tmp17_;
				result = G_TYPE_CHECK_INSTANCE_CAST (_tmp18_, VALA_TYPE_STATEMENT, ValaStatement);
				return result;
			} else {
				ValaMemberInitializer* _tmp19_;
				_tmp19_ = initializer;
				if (_tmp19_ != NULL) {
					ValaMemberInitializer* _tmp20_;
					ValaCodeNode* _tmp21_;
					ValaCodeNode* _tmp22_;
					ValaStatement* _tmp23_;
					ValaStatement* _tmp24_;
					_tmp20_ = initializer;
					_tmp21_ = vala_code_node_get_parent_node ((ValaCodeNode*) _tmp20_);
					_tmp22_ = _tmp21_;
					_tmp23_ = vala_expression_get_parent_statement (G_TYPE_CHECK_INSTANCE_CAST (_tmp22_, VALA_TYPE_EXPRESSION, ValaExpression));
					_tmp24_ = _tmp23_;
					result = _tmp24_;
					return result;
				} else {
					result = NULL;
					return result;
				}
			}
		}
	}
}

void
vala_expression_insert_statement (ValaExpression* self,
                                  ValaBlock* block,
                                  ValaStatement* stmt)
{
	ValaStatement* _tmp0_;
	ValaStatement* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (block != NULL);
	g_return_if_fail (stmt != NULL);
	_tmp0_ = vala_expression_get_parent_statement (self);
	_tmp1_ = _tmp0_;
	vala_block_insert_before (block, _tmp1_, stmt);
}

ValaExpression*
vala_expression_construct (GType object_type)
{
	ValaExpression* self = NULL;
	self = (ValaExpression*) vala_code_node_construct (object_type);
	return self;
}

static void
vala_expression_class_init (ValaExpressionClass * klass,
                            gpointer klass_data)
{
	vala_expression_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_expression_finalize;
	g_type_class_adjust_private_offset (klass, &ValaExpression_private_offset);
	((ValaExpressionClass *) klass)->is_constant = (gboolean (*) (ValaExpression*)) vala_expression_real_is_constant;
	((ValaExpressionClass *) klass)->is_pure = (gboolean (*) (ValaExpression*)) vala_expression_real_is_pure;
	((ValaExpressionClass *) klass)->is_non_null = (gboolean (*) (ValaExpression*)) vala_expression_real_is_non_null;
	((ValaExpressionClass *) klass)->is_accessible = (gboolean (*) (ValaExpression*, ValaSymbol*)) vala_expression_real_is_accessible;
}

static void
vala_expression_instance_init (ValaExpression * self,
                               gpointer klass)
{
	self->priv = vala_expression_get_instance_private (self);
}

static void
vala_expression_finalize (ValaCodeNode * obj)
{
	ValaExpression * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_EXPRESSION, ValaExpression);
	_vala_code_node_unref0 (self->priv->_value_type);
	_vala_code_node_unref0 (self->priv->_formal_value_type);
	_vala_code_node_unref0 (self->priv->_target_type);
	_vala_code_node_unref0 (self->priv->_formal_target_type);
	_vala_target_value_unref0 (self->priv->_target_value);
	VALA_CODE_NODE_CLASS (vala_expression_parent_class)->finalize (obj);
}

/**
 * Base class for all code nodes that might be used as an expression.
 */
static GType
vala_expression_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaExpression), 0, (GInstanceInitFunc) vala_expression_instance_init, NULL };
	GType vala_expression_type_id;
	vala_expression_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaExpression", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	ValaExpression_private_offset = g_type_add_instance_private (vala_expression_type_id, sizeof (ValaExpressionPrivate));
	return vala_expression_type_id;
}

GType
vala_expression_get_type (void)
{
	static volatile gsize vala_expression_type_id__volatile = 0;
	if (g_once_init_enter (&vala_expression_type_id__volatile)) {
		GType vala_expression_type_id;
		vala_expression_type_id = vala_expression_get_type_once ();
		g_once_init_leave (&vala_expression_type_id__volatile, vala_expression_type_id);
	}
	return vala_expression_type_id__volatile;
}


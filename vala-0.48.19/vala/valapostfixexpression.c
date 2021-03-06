/* valapostfixexpression.c generated by valac, the Vala compiler
 * generated from valapostfixexpression.vala, do not modify */

/* valapostfixexpression.vala
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
#include <valagee.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaPostfixExpressionPrivate {
	gboolean _increment;
	ValaExpression* _inner;
};

static gint ValaPostfixExpression_private_offset;
static gpointer vala_postfix_expression_parent_class = NULL;

static void vala_postfix_expression_real_accept (ValaCodeNode* base,
                                          ValaCodeVisitor* visitor);
static void vala_postfix_expression_real_accept_children (ValaCodeNode* base,
                                                   ValaCodeVisitor* visitor);
static gboolean vala_postfix_expression_real_is_pure (ValaExpression* base);
static gboolean vala_postfix_expression_real_is_accessible (ValaExpression* base,
                                                     ValaSymbol* sym);
static void vala_postfix_expression_real_get_defined_variables (ValaCodeNode* base,
                                                         ValaCollection* collection);
static void vala_postfix_expression_real_get_used_variables (ValaCodeNode* base,
                                                      ValaCollection* collection);
static void vala_postfix_expression_real_replace_expression (ValaCodeNode* base,
                                                      ValaExpression* old_node,
                                                      ValaExpression* new_node);
static gboolean vala_postfix_expression_real_check (ValaCodeNode* base,
                                             ValaCodeContext* context);
static void vala_postfix_expression_real_emit (ValaCodeNode* base,
                                        ValaCodeGenerator* codegen);
static gchar* vala_postfix_expression_real_to_string (ValaCodeNode* base);
static void vala_postfix_expression_finalize (ValaCodeNode * obj);
static GType vala_postfix_expression_get_type_once (void);

static inline gpointer
vala_postfix_expression_get_instance_private (ValaPostfixExpression* self)
{
	return G_STRUCT_MEMBER_P (self, ValaPostfixExpression_private_offset);
}

ValaExpression*
vala_postfix_expression_get_inner (ValaPostfixExpression* self)
{
	ValaExpression* result;
	ValaExpression* _tmp0_;
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
vala_postfix_expression_set_inner (ValaPostfixExpression* self,
                                   ValaExpression* value)
{
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_inner);
	self->priv->_inner = _tmp0_;
	_tmp1_ = self->priv->_inner;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

gboolean
vala_postfix_expression_get_increment (ValaPostfixExpression* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_increment;
	return result;
}

void
vala_postfix_expression_set_increment (ValaPostfixExpression* self,
                                       gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_increment = value;
}

/**
 * Creates a new postfix expression.
 *
 * @param _inner  operand expression
 * @param inc     true for increment, false for decrement
 * @param source  reference to source code
 * @return newly  created postfix expression
 */
ValaPostfixExpression*
vala_postfix_expression_construct (GType object_type,
                                   ValaExpression* _inner,
                                   gboolean inc,
                                   ValaSourceReference* source)
{
	ValaPostfixExpression* self = NULL;
	g_return_val_if_fail (_inner != NULL, NULL);
	self = (ValaPostfixExpression*) vala_expression_construct (object_type);
	vala_postfix_expression_set_inner (self, _inner);
	vala_postfix_expression_set_increment (self, inc);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source);
	return self;
}

ValaPostfixExpression*
vala_postfix_expression_new (ValaExpression* _inner,
                             gboolean inc,
                             ValaSourceReference* source)
{
	return vala_postfix_expression_construct (VALA_TYPE_POSTFIX_EXPRESSION, _inner, inc, source);
}

static void
vala_postfix_expression_real_accept (ValaCodeNode* base,
                                     ValaCodeVisitor* visitor)
{
	ValaPostfixExpression * self;
	self = (ValaPostfixExpression*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_postfix_expression (visitor, self);
	vala_code_visitor_visit_expression (visitor, (ValaExpression*) self);
}

static void
vala_postfix_expression_real_accept_children (ValaCodeNode* base,
                                              ValaCodeVisitor* visitor)
{
	ValaPostfixExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPostfixExpression*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_postfix_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, visitor);
}

static gboolean
vala_postfix_expression_real_is_pure (ValaExpression* base)
{
	ValaPostfixExpression * self;
	gboolean result = FALSE;
	self = (ValaPostfixExpression*) base;
	result = FALSE;
	return result;
}

static gboolean
vala_postfix_expression_real_is_accessible (ValaExpression* base,
                                            ValaSymbol* sym)
{
	ValaPostfixExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	gboolean result = FALSE;
	self = (ValaPostfixExpression*) base;
	g_return_val_if_fail (sym != NULL, FALSE);
	_tmp0_ = vala_postfix_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	result = vala_expression_is_accessible (_tmp1_, sym);
	return result;
}

static void
vala_postfix_expression_real_get_defined_variables (ValaCodeNode* base,
                                                    ValaCollection* collection)
{
	ValaPostfixExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	ValaLocalVariable* local = NULL;
	ValaExpression* _tmp2_;
	ValaExpression* _tmp3_;
	ValaSymbol* _tmp4_;
	ValaSymbol* _tmp5_;
	ValaParameter* param = NULL;
	ValaExpression* _tmp6_;
	ValaExpression* _tmp7_;
	ValaSymbol* _tmp8_;
	ValaSymbol* _tmp9_;
	ValaLocalVariable* _tmp10_;
	self = (ValaPostfixExpression*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_postfix_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_defined_variables ((ValaCodeNode*) _tmp1_, collection);
	_tmp2_ = vala_postfix_expression_get_inner (self);
	_tmp3_ = _tmp2_;
	_tmp4_ = vala_expression_get_symbol_reference (_tmp3_);
	_tmp5_ = _tmp4_;
	local = VALA_IS_LOCAL_VARIABLE (_tmp5_) ? ((ValaLocalVariable*) _tmp5_) : NULL;
	_tmp6_ = vala_postfix_expression_get_inner (self);
	_tmp7_ = _tmp6_;
	_tmp8_ = vala_expression_get_symbol_reference (_tmp7_);
	_tmp9_ = _tmp8_;
	param = VALA_IS_PARAMETER (_tmp9_) ? ((ValaParameter*) _tmp9_) : NULL;
	_tmp10_ = local;
	if (_tmp10_ != NULL) {
		ValaLocalVariable* _tmp11_;
		_tmp11_ = local;
		vala_collection_add (collection, (ValaVariable*) _tmp11_);
	} else {
		gboolean _tmp12_ = FALSE;
		ValaParameter* _tmp13_;
		_tmp13_ = param;
		if (_tmp13_ != NULL) {
			ValaParameter* _tmp14_;
			ValaParameterDirection _tmp15_;
			ValaParameterDirection _tmp16_;
			_tmp14_ = param;
			_tmp15_ = vala_parameter_get_direction (_tmp14_);
			_tmp16_ = _tmp15_;
			_tmp12_ = _tmp16_ == VALA_PARAMETER_DIRECTION_OUT;
		} else {
			_tmp12_ = FALSE;
		}
		if (_tmp12_) {
			ValaParameter* _tmp17_;
			_tmp17_ = param;
			vala_collection_add (collection, (ValaVariable*) _tmp17_);
		}
	}
}

static void
vala_postfix_expression_real_get_used_variables (ValaCodeNode* base,
                                                 ValaCollection* collection)
{
	ValaPostfixExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPostfixExpression*) base;
	g_return_if_fail (collection != NULL);
	_tmp0_ = vala_postfix_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_get_used_variables ((ValaCodeNode*) _tmp1_, collection);
}

static void
vala_postfix_expression_real_replace_expression (ValaCodeNode* base,
                                                 ValaExpression* old_node,
                                                 ValaExpression* new_node)
{
	ValaPostfixExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPostfixExpression*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_postfix_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_postfix_expression_set_inner (self, new_node);
	}
}

static gboolean
vala_postfix_expression_real_check (ValaCodeNode* base,
                                    ValaCodeContext* context)
{
	ValaPostfixExpression * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	ValaExpression* _tmp6_;
	ValaExpression* _tmp7_;
	gboolean _tmp8_ = FALSE;
	gboolean _tmp9_ = FALSE;
	ValaExpression* _tmp10_;
	ValaExpression* _tmp11_;
	ValaDataType* _tmp12_;
	ValaDataType* _tmp13_;
	ValaExpression* _tmp24_;
	ValaExpression* _tmp25_;
	ValaExpression* _tmp60_;
	ValaExpression* _tmp61_;
	ValaExpression* _tmp88_;
	ValaExpression* _tmp89_;
	ValaDataType* _tmp90_;
	ValaDataType* _tmp91_;
	gboolean _tmp92_;
	gboolean _tmp93_;
	gboolean result = FALSE;
	self = (ValaPostfixExpression*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = vala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	vala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp4_ = vala_postfix_expression_get_inner (self);
	_tmp5_ = _tmp4_;
	vala_expression_set_lvalue (_tmp5_, TRUE);
	_tmp6_ = vala_postfix_expression_get_inner (self);
	_tmp7_ = _tmp6_;
	if (!vala_code_node_check ((ValaCodeNode*) _tmp7_, context)) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	_tmp10_ = vala_postfix_expression_get_inner (self);
	_tmp11_ = _tmp10_;
	_tmp12_ = vala_expression_get_value_type (_tmp11_);
	_tmp13_ = _tmp12_;
	if (!VALA_IS_INTEGER_TYPE (_tmp13_)) {
		ValaExpression* _tmp14_;
		ValaExpression* _tmp15_;
		ValaDataType* _tmp16_;
		ValaDataType* _tmp17_;
		_tmp14_ = vala_postfix_expression_get_inner (self);
		_tmp15_ = _tmp14_;
		_tmp16_ = vala_expression_get_value_type (_tmp15_);
		_tmp17_ = _tmp16_;
		_tmp9_ = !VALA_IS_FLOATING_TYPE (_tmp17_);
	} else {
		_tmp9_ = FALSE;
	}
	if (_tmp9_) {
		ValaExpression* _tmp18_;
		ValaExpression* _tmp19_;
		ValaDataType* _tmp20_;
		ValaDataType* _tmp21_;
		_tmp18_ = vala_postfix_expression_get_inner (self);
		_tmp19_ = _tmp18_;
		_tmp20_ = vala_expression_get_value_type (_tmp19_);
		_tmp21_ = _tmp20_;
		_tmp8_ = !VALA_IS_POINTER_TYPE (_tmp21_);
	} else {
		_tmp8_ = FALSE;
	}
	if (_tmp8_) {
		ValaSourceReference* _tmp22_;
		ValaSourceReference* _tmp23_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp22_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp23_ = _tmp22_;
		vala_report_error (_tmp23_, "unsupported lvalue in postfix expression");
		result = FALSE;
		return result;
	}
	_tmp24_ = vala_postfix_expression_get_inner (self);
	_tmp25_ = _tmp24_;
	if (VALA_IS_MEMBER_ACCESS (_tmp25_)) {
		ValaMemberAccess* ma = NULL;
		ValaExpression* _tmp26_;
		ValaExpression* _tmp27_;
		ValaMemberAccess* _tmp28_;
		gboolean _tmp29_;
		gboolean _tmp30_;
		gboolean _tmp40_ = FALSE;
		ValaMemberAccess* _tmp41_;
		gboolean _tmp42_;
		gboolean _tmp43_;
		_tmp26_ = vala_postfix_expression_get_inner (self);
		_tmp27_ = _tmp26_;
		ma = G_TYPE_CHECK_INSTANCE_CAST (_tmp27_, VALA_TYPE_MEMBER_ACCESS, ValaMemberAccess);
		_tmp28_ = ma;
		_tmp29_ = vala_member_access_get_prototype_access (_tmp28_);
		_tmp30_ = _tmp29_;
		if (_tmp30_) {
			ValaSourceReference* _tmp31_;
			ValaSourceReference* _tmp32_;
			ValaMemberAccess* _tmp33_;
			ValaSymbol* _tmp34_;
			ValaSymbol* _tmp35_;
			gchar* _tmp36_;
			gchar* _tmp37_;
			gchar* _tmp38_;
			gchar* _tmp39_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp31_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp32_ = _tmp31_;
			_tmp33_ = ma;
			_tmp34_ = vala_expression_get_symbol_reference ((ValaExpression*) _tmp33_);
			_tmp35_ = _tmp34_;
			_tmp36_ = vala_symbol_get_full_name (_tmp35_);
			_tmp37_ = _tmp36_;
			_tmp38_ = g_strdup_printf ("Access to instance member `%s' denied", _tmp37_);
			_tmp39_ = _tmp38_;
			vala_report_error (_tmp32_, _tmp39_);
			_g_free0 (_tmp39_);
			_g_free0 (_tmp37_);
			result = FALSE;
			return result;
		}
		_tmp41_ = ma;
		_tmp42_ = vala_code_node_get_error ((ValaCodeNode*) _tmp41_);
		_tmp43_ = _tmp42_;
		if (_tmp43_) {
			_tmp40_ = TRUE;
		} else {
			ValaMemberAccess* _tmp44_;
			ValaSymbol* _tmp45_;
			ValaSymbol* _tmp46_;
			_tmp44_ = ma;
			_tmp45_ = vala_expression_get_symbol_reference ((ValaExpression*) _tmp44_);
			_tmp46_ = _tmp45_;
			_tmp40_ = _tmp46_ == NULL;
		}
		if (_tmp40_) {
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			result = FALSE;
			return result;
		}
	} else {
		ValaExpression* _tmp47_;
		ValaExpression* _tmp48_;
		_tmp47_ = vala_postfix_expression_get_inner (self);
		_tmp48_ = _tmp47_;
		if (VALA_IS_ELEMENT_ACCESS (_tmp48_)) {
			ValaElementAccess* ea = NULL;
			ValaExpression* _tmp49_;
			ValaExpression* _tmp50_;
			ValaElementAccess* _tmp51_;
			ValaExpression* _tmp52_;
			ValaExpression* _tmp53_;
			ValaDataType* _tmp54_;
			ValaDataType* _tmp55_;
			_tmp49_ = vala_postfix_expression_get_inner (self);
			_tmp50_ = _tmp49_;
			ea = G_TYPE_CHECK_INSTANCE_CAST (_tmp50_, VALA_TYPE_ELEMENT_ACCESS, ValaElementAccess);
			_tmp51_ = ea;
			_tmp52_ = vala_element_access_get_container (_tmp51_);
			_tmp53_ = _tmp52_;
			_tmp54_ = vala_expression_get_value_type (_tmp53_);
			_tmp55_ = _tmp54_;
			if (!VALA_IS_ARRAY_TYPE (_tmp55_)) {
				ValaSourceReference* _tmp56_;
				ValaSourceReference* _tmp57_;
				vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
				_tmp56_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
				_tmp57_ = _tmp56_;
				vala_report_error (_tmp57_, "unsupported lvalue in postfix expression");
				result = FALSE;
				return result;
			}
		} else {
			ValaSourceReference* _tmp58_;
			ValaSourceReference* _tmp59_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp58_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp59_ = _tmp58_;
			vala_report_error (_tmp59_, "unsupported lvalue in postfix expression");
			result = FALSE;
			return result;
		}
	}
	_tmp60_ = vala_postfix_expression_get_inner (self);
	_tmp61_ = _tmp60_;
	if (VALA_IS_MEMBER_ACCESS (_tmp61_)) {
		ValaMemberAccess* ma = NULL;
		ValaExpression* _tmp62_;
		ValaExpression* _tmp63_;
		ValaMemberAccess* _tmp64_;
		ValaSymbol* _tmp65_;
		ValaSymbol* _tmp66_;
		_tmp62_ = vala_postfix_expression_get_inner (self);
		_tmp63_ = _tmp62_;
		ma = G_TYPE_CHECK_INSTANCE_CAST (_tmp63_, VALA_TYPE_MEMBER_ACCESS, ValaMemberAccess);
		_tmp64_ = ma;
		_tmp65_ = vala_expression_get_symbol_reference ((ValaExpression*) _tmp64_);
		_tmp66_ = _tmp65_;
		if (VALA_IS_PROPERTY (_tmp66_)) {
			ValaProperty* prop = NULL;
			ValaMemberAccess* _tmp67_;
			ValaSymbol* _tmp68_;
			ValaSymbol* _tmp69_;
			gboolean _tmp70_ = FALSE;
			ValaProperty* _tmp71_;
			ValaPropertyAccessor* _tmp72_;
			ValaPropertyAccessor* _tmp73_;
			_tmp67_ = ma;
			_tmp68_ = vala_expression_get_symbol_reference ((ValaExpression*) _tmp67_);
			_tmp69_ = _tmp68_;
			prop = G_TYPE_CHECK_INSTANCE_CAST (_tmp69_, VALA_TYPE_PROPERTY, ValaProperty);
			_tmp71_ = prop;
			_tmp72_ = vala_property_get_set_accessor (_tmp71_);
			_tmp73_ = _tmp72_;
			if (_tmp73_ == NULL) {
				_tmp70_ = TRUE;
			} else {
				ValaProperty* _tmp74_;
				ValaPropertyAccessor* _tmp75_;
				ValaPropertyAccessor* _tmp76_;
				gboolean _tmp77_;
				gboolean _tmp78_;
				_tmp74_ = prop;
				_tmp75_ = vala_property_get_set_accessor (_tmp74_);
				_tmp76_ = _tmp75_;
				_tmp77_ = vala_property_accessor_get_writable (_tmp76_);
				_tmp78_ = _tmp77_;
				_tmp70_ = !_tmp78_;
			}
			if (_tmp70_) {
				ValaMemberAccess* _tmp79_;
				ValaMemberAccess* _tmp80_;
				ValaSourceReference* _tmp81_;
				ValaSourceReference* _tmp82_;
				ValaProperty* _tmp83_;
				gchar* _tmp84_;
				gchar* _tmp85_;
				gchar* _tmp86_;
				gchar* _tmp87_;
				_tmp79_ = ma;
				vala_code_node_set_error ((ValaCodeNode*) _tmp79_, TRUE);
				_tmp80_ = ma;
				_tmp81_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp80_);
				_tmp82_ = _tmp81_;
				_tmp83_ = prop;
				_tmp84_ = vala_symbol_get_full_name ((ValaSymbol*) _tmp83_);
				_tmp85_ = _tmp84_;
				_tmp86_ = g_strdup_printf ("Property `%s' is read-only", _tmp85_);
				_tmp87_ = _tmp86_;
				vala_report_error (_tmp82_, _tmp87_);
				_g_free0 (_tmp87_);
				_g_free0 (_tmp85_);
				result = FALSE;
				return result;
			}
		}
	}
	_tmp88_ = vala_postfix_expression_get_inner (self);
	_tmp89_ = _tmp88_;
	_tmp90_ = vala_expression_get_value_type (_tmp89_);
	_tmp91_ = _tmp90_;
	vala_expression_set_value_type ((ValaExpression*) self, _tmp91_);
	_tmp92_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp93_ = _tmp92_;
	result = !_tmp93_;
	return result;
}

static void
vala_postfix_expression_real_emit (ValaCodeNode* base,
                                   ValaCodeGenerator* codegen)
{
	ValaPostfixExpression * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaPostfixExpression*) base;
	g_return_if_fail (codegen != NULL);
	_tmp0_ = vala_postfix_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	vala_code_node_emit ((ValaCodeNode*) _tmp1_, codegen);
	vala_code_visitor_visit_postfix_expression ((ValaCodeVisitor*) codegen, self);
	vala_code_visitor_visit_expression ((ValaCodeVisitor*) codegen, (ValaExpression*) self);
}

static gchar*
vala_postfix_expression_real_to_string (ValaCodeNode* base)
{
	ValaPostfixExpression * self;
	const gchar* _tmp0_ = NULL;
	gboolean _tmp1_;
	ValaExpression* _tmp2_;
	ValaExpression* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* result = NULL;
	self = (ValaPostfixExpression*) base;
	_tmp1_ = self->priv->_increment;
	if (_tmp1_) {
		_tmp0_ = "++";
	} else {
		_tmp0_ = "--";
	}
	_tmp2_ = vala_postfix_expression_get_inner (self);
	_tmp3_ = _tmp2_;
	_tmp4_ = vala_code_node_to_string ((ValaCodeNode*) _tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = g_strdup_printf ("(%s%s)", _tmp5_, _tmp0_);
	_tmp7_ = _tmp6_;
	_g_free0 (_tmp5_);
	result = _tmp7_;
	return result;
}

static void
vala_postfix_expression_class_init (ValaPostfixExpressionClass * klass,
                                    gpointer klass_data)
{
	vala_postfix_expression_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_postfix_expression_finalize;
	g_type_class_adjust_private_offset (klass, &ValaPostfixExpression_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_postfix_expression_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_postfix_expression_real_accept_children;
	((ValaExpressionClass *) klass)->is_pure = (gboolean (*) (ValaExpression*)) vala_postfix_expression_real_is_pure;
	((ValaExpressionClass *) klass)->is_accessible = (gboolean (*) (ValaExpression*, ValaSymbol*)) vala_postfix_expression_real_is_accessible;
	((ValaCodeNodeClass *) klass)->get_defined_variables = (void (*) (ValaCodeNode*, ValaCollection*)) vala_postfix_expression_real_get_defined_variables;
	((ValaCodeNodeClass *) klass)->get_used_variables = (void (*) (ValaCodeNode*, ValaCollection*)) vala_postfix_expression_real_get_used_variables;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_postfix_expression_real_replace_expression;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_postfix_expression_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) vala_postfix_expression_real_emit;
	((ValaCodeNodeClass *) klass)->to_string = (gchar* (*) (ValaCodeNode*)) vala_postfix_expression_real_to_string;
}

static void
vala_postfix_expression_instance_init (ValaPostfixExpression * self,
                                       gpointer klass)
{
	self->priv = vala_postfix_expression_get_instance_private (self);
}

static void
vala_postfix_expression_finalize (ValaCodeNode * obj)
{
	ValaPostfixExpression * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_POSTFIX_EXPRESSION, ValaPostfixExpression);
	_vala_code_node_unref0 (self->priv->_inner);
	VALA_CODE_NODE_CLASS (vala_postfix_expression_parent_class)->finalize (obj);
}

/**
 * Represents a postfix increment or decrement expression.
 */
static GType
vala_postfix_expression_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaPostfixExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_postfix_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaPostfixExpression), 0, (GInstanceInitFunc) vala_postfix_expression_instance_init, NULL };
	GType vala_postfix_expression_type_id;
	vala_postfix_expression_type_id = g_type_register_static (VALA_TYPE_EXPRESSION, "ValaPostfixExpression", &g_define_type_info, 0);
	ValaPostfixExpression_private_offset = g_type_add_instance_private (vala_postfix_expression_type_id, sizeof (ValaPostfixExpressionPrivate));
	return vala_postfix_expression_type_id;
}

GType
vala_postfix_expression_get_type (void)
{
	static volatile gsize vala_postfix_expression_type_id__volatile = 0;
	if (g_once_init_enter (&vala_postfix_expression_type_id__volatile)) {
		GType vala_postfix_expression_type_id;
		vala_postfix_expression_type_id = vala_postfix_expression_get_type_once ();
		g_once_init_leave (&vala_postfix_expression_type_id__volatile, vala_postfix_expression_type_id);
	}
	return vala_postfix_expression_type_id__volatile;
}


/* valawhilestatement.c generated by valac, the Vala compiler
 * generated from valawhilestatement.vala, do not modify */

/* valawhilestatement.vala
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

struct _ValaWhileStatementPrivate {
	ValaExpression* _condition;
	ValaBlock* _body;
};

static gint ValaWhileStatement_private_offset;
static gpointer vala_while_statement_parent_class = NULL;
static ValaStatementIface * vala_while_statement_vala_statement_parent_iface = NULL;

static void vala_while_statement_real_accept (ValaCodeNode* base,
                                       ValaCodeVisitor* visitor);
static void vala_while_statement_real_accept_children (ValaCodeNode* base,
                                                ValaCodeVisitor* visitor);
static gboolean vala_while_statement_always_true (ValaWhileStatement* self,
                                           ValaExpression* condition);
static gboolean vala_while_statement_always_false (ValaWhileStatement* self,
                                            ValaExpression* condition);
static void vala_while_statement_real_replace_expression (ValaCodeNode* base,
                                                   ValaExpression* old_node,
                                                   ValaExpression* new_node);
static gboolean vala_while_statement_real_check (ValaCodeNode* base,
                                          ValaCodeContext* context);
static void vala_while_statement_finalize (ValaCodeNode * obj);
static GType vala_while_statement_get_type_once (void);

static inline gpointer
vala_while_statement_get_instance_private (ValaWhileStatement* self)
{
	return G_STRUCT_MEMBER_P (self, ValaWhileStatement_private_offset);
}

ValaExpression*
vala_while_statement_get_condition (ValaWhileStatement* self)
{
	ValaExpression* result;
	ValaExpression* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_condition;
	result = _tmp0_;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

void
vala_while_statement_set_condition (ValaWhileStatement* self,
                                    ValaExpression* value)
{
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_condition);
	self->priv->_condition = _tmp0_;
	_tmp1_ = self->priv->_condition;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

ValaBlock*
vala_while_statement_get_body (ValaWhileStatement* self)
{
	ValaBlock* result;
	ValaBlock* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_body;
	result = _tmp0_;
	return result;
}

void
vala_while_statement_set_body (ValaWhileStatement* self,
                               ValaBlock* value)
{
	ValaBlock* _tmp0_;
	ValaBlock* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _vala_code_node_ref0 (value);
	_vala_code_node_unref0 (self->priv->_body);
	self->priv->_body = _tmp0_;
	_tmp1_ = self->priv->_body;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp1_, (ValaCodeNode*) self);
}

/**
 * Creates a new while statement.
 *
 * @param condition         loop condition
 * @param body              loop body
 * @param source_reference  reference to source code
 * @return                  newly created while statement
 */
ValaWhileStatement*
vala_while_statement_construct (GType object_type,
                                ValaExpression* condition,
                                ValaBlock* body,
                                ValaSourceReference* source_reference)
{
	ValaWhileStatement* self = NULL;
	g_return_val_if_fail (condition != NULL, NULL);
	g_return_val_if_fail (body != NULL, NULL);
	self = (ValaWhileStatement*) vala_code_node_construct (object_type);
	vala_while_statement_set_body (self, body);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	vala_while_statement_set_condition (self, condition);
	return self;
}

ValaWhileStatement*
vala_while_statement_new (ValaExpression* condition,
                          ValaBlock* body,
                          ValaSourceReference* source_reference)
{
	return vala_while_statement_construct (VALA_TYPE_WHILE_STATEMENT, condition, body, source_reference);
}

static void
vala_while_statement_real_accept (ValaCodeNode* base,
                                  ValaCodeVisitor* visitor)
{
	ValaWhileStatement * self;
	self = (ValaWhileStatement*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_while_statement (visitor, self);
}

static void
vala_while_statement_real_accept_children (ValaCodeNode* base,
                                           ValaCodeVisitor* visitor)
{
	ValaWhileStatement * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	ValaExpression* _tmp2_;
	ValaExpression* _tmp3_;
	ValaBlock* _tmp4_;
	ValaBlock* _tmp5_;
	self = (ValaWhileStatement*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_while_statement_get_condition (self);
	_tmp1_ = _tmp0_;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, visitor);
	_tmp2_ = vala_while_statement_get_condition (self);
	_tmp3_ = _tmp2_;
	vala_code_visitor_visit_end_full_expression (visitor, _tmp3_);
	_tmp4_ = vala_while_statement_get_body (self);
	_tmp5_ = _tmp4_;
	vala_code_node_accept ((ValaCodeNode*) _tmp5_, visitor);
}

static gboolean
vala_while_statement_always_true (ValaWhileStatement* self,
                                  ValaExpression* condition)
{
	ValaBooleanLiteral* literal = NULL;
	gboolean _tmp0_ = FALSE;
	ValaBooleanLiteral* _tmp1_;
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (condition != NULL, FALSE);
	literal = VALA_IS_BOOLEAN_LITERAL (condition) ? ((ValaBooleanLiteral*) condition) : NULL;
	_tmp1_ = literal;
	if (_tmp1_ != NULL) {
		ValaBooleanLiteral* _tmp2_;
		gboolean _tmp3_;
		gboolean _tmp4_;
		_tmp2_ = literal;
		_tmp3_ = vala_boolean_literal_get_value (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp0_ = _tmp4_;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static gboolean
vala_while_statement_always_false (ValaWhileStatement* self,
                                   ValaExpression* condition)
{
	ValaBooleanLiteral* literal = NULL;
	gboolean _tmp0_ = FALSE;
	ValaBooleanLiteral* _tmp1_;
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (condition != NULL, FALSE);
	literal = VALA_IS_BOOLEAN_LITERAL (condition) ? ((ValaBooleanLiteral*) condition) : NULL;
	_tmp1_ = literal;
	if (_tmp1_ != NULL) {
		ValaBooleanLiteral* _tmp2_;
		gboolean _tmp3_;
		gboolean _tmp4_;
		_tmp2_ = literal;
		_tmp3_ = vala_boolean_literal_get_value (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp0_ = !_tmp4_;
	} else {
		_tmp0_ = FALSE;
	}
	result = _tmp0_;
	return result;
}

static void
vala_while_statement_real_replace_expression (ValaCodeNode* base,
                                              ValaExpression* old_node,
                                              ValaExpression* new_node)
{
	ValaWhileStatement * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaWhileStatement*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_while_statement_get_condition (self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_while_statement_set_condition (self, new_node);
	}
}

static gboolean
vala_while_statement_real_check (ValaCodeNode* base,
                                 ValaCodeContext* context)
{
	ValaWhileStatement * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* _tmp4_;
	ValaExpression* _tmp5_;
	ValaLoop* loop = NULL;
	ValaBlock* _tmp45_;
	ValaBlock* _tmp46_;
	ValaSourceReference* _tmp47_;
	ValaSourceReference* _tmp48_;
	ValaLoop* _tmp49_;
	ValaBlock* parent_block = NULL;
	ValaCodeNode* _tmp50_;
	ValaCodeNode* _tmp51_;
	ValaBlock* _tmp52_;
	ValaLoop* _tmp53_;
	ValaLoop* _tmp54_;
	gboolean _tmp55_;
	gboolean _tmp56_;
	gboolean result = FALSE;
	self = (ValaWhileStatement*) base;
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
	_tmp4_ = vala_while_statement_get_condition (self);
	_tmp5_ = _tmp4_;
	if (vala_while_statement_always_true (self, _tmp5_)) {
	} else {
		ValaExpression* _tmp6_;
		ValaExpression* _tmp7_;
		_tmp6_ = vala_while_statement_get_condition (self);
		_tmp7_ = _tmp6_;
		if (vala_while_statement_always_false (self, _tmp7_)) {
			ValaBlock* _tmp8_;
			ValaBlock* _tmp9_;
			ValaExpression* _tmp10_;
			ValaExpression* _tmp11_;
			ValaSourceReference* _tmp12_;
			ValaSourceReference* _tmp13_;
			ValaBreakStatement* _tmp14_;
			ValaBreakStatement* _tmp15_;
			_tmp8_ = vala_while_statement_get_body (self);
			_tmp9_ = _tmp8_;
			_tmp10_ = vala_while_statement_get_condition (self);
			_tmp11_ = _tmp10_;
			_tmp12_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp11_);
			_tmp13_ = _tmp12_;
			_tmp14_ = vala_break_statement_new (_tmp13_);
			_tmp15_ = _tmp14_;
			vala_block_insert_statement (_tmp9_, 0, (ValaStatement*) _tmp15_);
			_vala_code_node_unref0 (_tmp15_);
		} else {
			ValaUnaryExpression* if_condition = NULL;
			ValaExpression* _tmp16_;
			ValaExpression* _tmp17_;
			ValaExpression* _tmp18_;
			ValaExpression* _tmp19_;
			ValaSourceReference* _tmp20_;
			ValaSourceReference* _tmp21_;
			ValaUnaryExpression* _tmp22_;
			ValaBlock* true_block = NULL;
			ValaExpression* _tmp23_;
			ValaExpression* _tmp24_;
			ValaSourceReference* _tmp25_;
			ValaSourceReference* _tmp26_;
			ValaBlock* _tmp27_;
			ValaBlock* _tmp28_;
			ValaExpression* _tmp29_;
			ValaExpression* _tmp30_;
			ValaSourceReference* _tmp31_;
			ValaSourceReference* _tmp32_;
			ValaBreakStatement* _tmp33_;
			ValaBreakStatement* _tmp34_;
			ValaIfStatement* if_stmt = NULL;
			ValaUnaryExpression* _tmp35_;
			ValaBlock* _tmp36_;
			ValaExpression* _tmp37_;
			ValaExpression* _tmp38_;
			ValaSourceReference* _tmp39_;
			ValaSourceReference* _tmp40_;
			ValaIfStatement* _tmp41_;
			ValaBlock* _tmp42_;
			ValaBlock* _tmp43_;
			ValaIfStatement* _tmp44_;
			_tmp16_ = vala_while_statement_get_condition (self);
			_tmp17_ = _tmp16_;
			_tmp18_ = vala_while_statement_get_condition (self);
			_tmp19_ = _tmp18_;
			_tmp20_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp19_);
			_tmp21_ = _tmp20_;
			_tmp22_ = vala_unary_expression_new (VALA_UNARY_OPERATOR_LOGICAL_NEGATION, _tmp17_, _tmp21_);
			if_condition = _tmp22_;
			_tmp23_ = vala_while_statement_get_condition (self);
			_tmp24_ = _tmp23_;
			_tmp25_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp24_);
			_tmp26_ = _tmp25_;
			_tmp27_ = vala_block_new (_tmp26_);
			true_block = _tmp27_;
			_tmp28_ = true_block;
			_tmp29_ = vala_while_statement_get_condition (self);
			_tmp30_ = _tmp29_;
			_tmp31_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp30_);
			_tmp32_ = _tmp31_;
			_tmp33_ = vala_break_statement_new (_tmp32_);
			_tmp34_ = _tmp33_;
			vala_block_add_statement (_tmp28_, (ValaStatement*) _tmp34_);
			_vala_code_node_unref0 (_tmp34_);
			_tmp35_ = if_condition;
			_tmp36_ = true_block;
			_tmp37_ = vala_while_statement_get_condition (self);
			_tmp38_ = _tmp37_;
			_tmp39_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp38_);
			_tmp40_ = _tmp39_;
			_tmp41_ = vala_if_statement_new ((ValaExpression*) _tmp35_, _tmp36_, NULL, _tmp40_);
			if_stmt = _tmp41_;
			_tmp42_ = vala_while_statement_get_body (self);
			_tmp43_ = _tmp42_;
			_tmp44_ = if_stmt;
			vala_block_insert_statement (_tmp43_, 0, (ValaStatement*) _tmp44_);
			_vala_code_node_unref0 (if_stmt);
			_vala_code_node_unref0 (true_block);
			_vala_code_node_unref0 (if_condition);
		}
	}
	_tmp45_ = vala_while_statement_get_body (self);
	_tmp46_ = _tmp45_;
	_tmp47_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp48_ = _tmp47_;
	_tmp49_ = vala_loop_new (_tmp46_, _tmp48_);
	loop = _tmp49_;
	_tmp50_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
	_tmp51_ = _tmp50_;
	parent_block = G_TYPE_CHECK_INSTANCE_CAST (_tmp51_, VALA_TYPE_BLOCK, ValaBlock);
	_tmp52_ = parent_block;
	_tmp53_ = loop;
	vala_block_replace_statement (_tmp52_, (ValaStatement*) self, (ValaStatement*) _tmp53_);
	_tmp54_ = loop;
	if (!vala_code_node_check ((ValaCodeNode*) _tmp54_, context)) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
	}
	_tmp55_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp56_ = _tmp55_;
	result = !_tmp56_;
	_vala_code_node_unref0 (loop);
	return result;
}

static void
vala_while_statement_class_init (ValaWhileStatementClass * klass,
                                 gpointer klass_data)
{
	vala_while_statement_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_while_statement_finalize;
	g_type_class_adjust_private_offset (klass, &ValaWhileStatement_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_while_statement_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_while_statement_real_accept_children;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_while_statement_real_replace_expression;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_while_statement_real_check;
}

static void
vala_while_statement_vala_statement_interface_init (ValaStatementIface * iface,
                                                    gpointer iface_data)
{
	vala_while_statement_vala_statement_parent_iface = g_type_interface_peek_parent (iface);
}

static void
vala_while_statement_instance_init (ValaWhileStatement * self,
                                    gpointer klass)
{
	self->priv = vala_while_statement_get_instance_private (self);
}

static void
vala_while_statement_finalize (ValaCodeNode * obj)
{
	ValaWhileStatement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_WHILE_STATEMENT, ValaWhileStatement);
	_vala_code_node_unref0 (self->priv->_condition);
	_vala_code_node_unref0 (self->priv->_body);
	VALA_CODE_NODE_CLASS (vala_while_statement_parent_class)->finalize (obj);
}

/**
 * Represents a while iteration statement in the source code.
 */
static GType
vala_while_statement_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaWhileStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_while_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaWhileStatement), 0, (GInstanceInitFunc) vala_while_statement_instance_init, NULL };
	static const GInterfaceInfo vala_statement_info = { (GInterfaceInitFunc) vala_while_statement_vala_statement_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType vala_while_statement_type_id;
	vala_while_statement_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaWhileStatement", &g_define_type_info, 0);
	g_type_add_interface_static (vala_while_statement_type_id, VALA_TYPE_STATEMENT, &vala_statement_info);
	ValaWhileStatement_private_offset = g_type_add_instance_private (vala_while_statement_type_id, sizeof (ValaWhileStatementPrivate));
	return vala_while_statement_type_id;
}

GType
vala_while_statement_get_type (void)
{
	static volatile gsize vala_while_statement_type_id__volatile = 0;
	if (g_once_init_enter (&vala_while_statement_type_id__volatile)) {
		GType vala_while_statement_type_id;
		vala_while_statement_type_id = vala_while_statement_get_type_once ();
		g_once_init_leave (&vala_while_statement_type_id__volatile, vala_while_statement_type_id);
	}
	return vala_while_statement_type_id__volatile;
}


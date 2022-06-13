/* valatemplate.c generated by valac, the Vala compiler
 * generated from valatemplate.vala, do not modify */

/* valatemplate.vala
 *
 * Copyright (C) 2009-2010  Jürg Billeter
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
#include <valagee.h>
#include <glib-object.h>
#include <glib.h>

#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))
#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

struct _ValaTemplatePrivate {
	ValaList* expression_list;
};

static gint ValaTemplate_private_offset;
static gpointer vala_template_parent_class = NULL;

static void vala_template_real_accept (ValaCodeNode* base,
                                ValaCodeVisitor* visitor);
static void vala_template_real_accept_children (ValaCodeNode* base,
                                         ValaCodeVisitor* visitor);
static gboolean vala_template_real_is_pure (ValaExpression* base);
static ValaExpression* vala_template_stringify (ValaTemplate* self,
                                         ValaExpression* expr);
static void vala_template_real_replace_expression (ValaCodeNode* base,
                                            ValaExpression* old_node,
                                            ValaExpression* new_node);
static gboolean vala_template_real_check (ValaCodeNode* base,
                                   ValaCodeContext* context);
static void vala_template_finalize (ValaCodeNode * obj);
static GType vala_template_get_type_once (void);

static inline gpointer
vala_template_get_instance_private (ValaTemplate* self)
{
	return G_STRUCT_MEMBER_P (self, ValaTemplate_private_offset);
}

ValaTemplate*
vala_template_construct (GType object_type,
                         ValaSourceReference* source_reference)
{
	ValaTemplate* self = NULL;
	self = (ValaTemplate*) vala_expression_construct (object_type);
	vala_code_node_set_source_reference ((ValaCodeNode*) self, source_reference);
	return self;
}

ValaTemplate*
vala_template_new (ValaSourceReference* source_reference)
{
	return vala_template_construct (VALA_TYPE_TEMPLATE, source_reference);
}

static void
vala_template_real_accept (ValaCodeNode* base,
                           ValaCodeVisitor* visitor)
{
	ValaTemplate * self;
	self = (ValaTemplate*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_template (visitor, self);
}

static gpointer
_vala_iterable_ref0 (gpointer self)
{
	return self ? vala_iterable_ref (self) : NULL;
}

static void
vala_template_real_accept_children (ValaCodeNode* base,
                                    ValaCodeVisitor* visitor)
{
	ValaTemplate * self;
	self = (ValaTemplate*) base;
	g_return_if_fail (visitor != NULL);
	{
		ValaList* _expr_list = NULL;
		ValaList* _tmp0_;
		ValaList* _tmp1_;
		gint _expr_size = 0;
		ValaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _expr_index = 0;
		_tmp0_ = self->priv->expression_list;
		_tmp1_ = _vala_iterable_ref0 (_tmp0_);
		_expr_list = _tmp1_;
		_tmp2_ = _expr_list;
		_tmp3_ = vala_collection_get_size ((ValaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_expr_size = _tmp4_;
		_expr_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			ValaExpression* expr = NULL;
			ValaList* _tmp7_;
			gpointer _tmp8_;
			ValaExpression* _tmp9_;
			_expr_index = _expr_index + 1;
			_tmp5_ = _expr_index;
			_tmp6_ = _expr_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _expr_list;
			_tmp8_ = vala_list_get (_tmp7_, _expr_index);
			expr = (ValaExpression*) _tmp8_;
			_tmp9_ = expr;
			vala_code_node_accept ((ValaCodeNode*) _tmp9_, visitor);
			_vala_code_node_unref0 (expr);
		}
		_vala_iterable_unref0 (_expr_list);
	}
}

void
vala_template_add_expression (ValaTemplate* self,
                              ValaExpression* expr)
{
	ValaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (expr != NULL);
	_tmp0_ = self->priv->expression_list;
	vala_collection_add ((ValaCollection*) _tmp0_, expr);
	vala_code_node_set_parent_node ((ValaCodeNode*) expr, (ValaCodeNode*) self);
}

ValaList*
vala_template_get_expressions (ValaTemplate* self)
{
	ValaList* _tmp0_;
	ValaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->expression_list;
	result = _tmp0_;
	return result;
}

static gboolean
vala_template_real_is_pure (ValaExpression* base)
{
	ValaTemplate * self;
	gboolean result = FALSE;
	self = (ValaTemplate*) base;
	result = FALSE;
	return result;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static ValaExpression*
vala_template_stringify (ValaTemplate* self,
                         ValaExpression* expr)
{
	ValaExpression* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (expr != NULL, NULL);
	if (VALA_IS_STRING_LITERAL (expr)) {
		ValaExpression* _tmp0_;
		_tmp0_ = _vala_code_node_ref0 (expr);
		result = _tmp0_;
		return result;
	} else {
		ValaSourceReference* _tmp1_;
		ValaSourceReference* _tmp2_;
		ValaMemberAccess* _tmp3_;
		ValaMemberAccess* _tmp4_;
		ValaSourceReference* _tmp5_;
		ValaSourceReference* _tmp6_;
		ValaMethodCall* _tmp7_;
		ValaExpression* _tmp8_;
		_tmp1_ = vala_code_node_get_source_reference ((ValaCodeNode*) expr);
		_tmp2_ = _tmp1_;
		_tmp3_ = vala_member_access_new (expr, "to_string", _tmp2_);
		_tmp4_ = _tmp3_;
		_tmp5_ = vala_code_node_get_source_reference ((ValaCodeNode*) expr);
		_tmp6_ = _tmp5_;
		_tmp7_ = vala_method_call_new ((ValaExpression*) _tmp4_, _tmp6_);
		_tmp8_ = (ValaExpression*) _tmp7_;
		_vala_code_node_unref0 (_tmp4_);
		result = _tmp8_;
		return result;
	}
}

static void
vala_template_real_replace_expression (ValaCodeNode* base,
                                       ValaExpression* old_node,
                                       ValaExpression* new_node)
{
	ValaTemplate * self;
	gint index = 0;
	ValaList* _tmp0_;
	self = (ValaTemplate*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = self->priv->expression_list;
	index = vala_list_index_of (_tmp0_, old_node);
	if (index >= 0) {
		ValaList* _tmp1_;
		_tmp1_ = self->priv->expression_list;
		vala_list_set (_tmp1_, index, new_node);
		vala_code_node_set_parent_node ((ValaCodeNode*) new_node, (ValaCodeNode*) self);
	}
}

static gboolean
vala_template_real_check (ValaCodeNode* base,
                          ValaCodeContext* context)
{
	ValaTemplate * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaExpression* expr = NULL;
	ValaList* _tmp4_;
	gint _tmp5_;
	gint _tmp6_;
	ValaExpression* _tmp39_;
	ValaDataType* _tmp40_;
	ValaDataType* _tmp41_;
	ValaSemanticAnalyzer* _tmp42_;
	ValaSemanticAnalyzer* _tmp43_;
	ValaList* _tmp44_;
	ValaCodeNode* _tmp45_;
	ValaCodeNode* _tmp46_;
	ValaExpression* _tmp47_;
	ValaExpression* _tmp48_;
	gboolean result = FALSE;
	self = (ValaTemplate*) base;
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
	_tmp4_ = self->priv->expression_list;
	_tmp5_ = vala_collection_get_size ((ValaCollection*) _tmp4_);
	_tmp6_ = _tmp5_;
	if (_tmp6_ == 0) {
		ValaSourceReference* _tmp7_;
		ValaSourceReference* _tmp8_;
		ValaStringLiteral* _tmp9_;
		_tmp7_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp8_ = _tmp7_;
		_tmp9_ = vala_string_literal_new ("\"\"", _tmp8_);
		_vala_code_node_unref0 (expr);
		expr = (ValaExpression*) _tmp9_;
	} else {
		ValaList* _tmp10_;
		gpointer _tmp11_;
		ValaExpression* _tmp12_;
		ValaExpression* _tmp13_;
		ValaList* _tmp14_;
		gint _tmp15_;
		gint _tmp16_;
		_tmp10_ = self->priv->expression_list;
		_tmp11_ = vala_list_get (_tmp10_, 0);
		_tmp12_ = (ValaExpression*) _tmp11_;
		_tmp13_ = vala_template_stringify (self, _tmp12_);
		_vala_code_node_unref0 (expr);
		expr = _tmp13_;
		_vala_code_node_unref0 (_tmp12_);
		_tmp14_ = self->priv->expression_list;
		_tmp15_ = vala_collection_get_size ((ValaCollection*) _tmp14_);
		_tmp16_ = _tmp15_;
		if (_tmp16_ > 1) {
			ValaMethodCall* concat = NULL;
			ValaExpression* _tmp17_;
			ValaSourceReference* _tmp18_;
			ValaSourceReference* _tmp19_;
			ValaMemberAccess* _tmp20_;
			ValaMemberAccess* _tmp21_;
			ValaSourceReference* _tmp22_;
			ValaSourceReference* _tmp23_;
			ValaMethodCall* _tmp24_;
			ValaMethodCall* _tmp25_;
			ValaMethodCall* _tmp37_;
			ValaExpression* _tmp38_;
			_tmp17_ = expr;
			_tmp18_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp19_ = _tmp18_;
			_tmp20_ = vala_member_access_new (_tmp17_, "concat", _tmp19_);
			_tmp21_ = _tmp20_;
			_tmp22_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp23_ = _tmp22_;
			_tmp24_ = vala_method_call_new ((ValaExpression*) _tmp21_, _tmp23_);
			_tmp25_ = _tmp24_;
			_vala_code_node_unref0 (_tmp21_);
			concat = _tmp25_;
			{
				gint i = 0;
				i = 1;
				{
					gboolean _tmp26_ = FALSE;
					_tmp26_ = TRUE;
					while (TRUE) {
						ValaList* _tmp28_;
						gint _tmp29_;
						gint _tmp30_;
						ValaMethodCall* _tmp31_;
						ValaList* _tmp32_;
						gpointer _tmp33_;
						ValaExpression* _tmp34_;
						ValaExpression* _tmp35_;
						ValaExpression* _tmp36_;
						if (!_tmp26_) {
							gint _tmp27_;
							_tmp27_ = i;
							i = _tmp27_ + 1;
						}
						_tmp26_ = FALSE;
						_tmp28_ = self->priv->expression_list;
						_tmp29_ = vala_collection_get_size ((ValaCollection*) _tmp28_);
						_tmp30_ = _tmp29_;
						if (!(i < _tmp30_)) {
							break;
						}
						_tmp31_ = concat;
						_tmp32_ = self->priv->expression_list;
						_tmp33_ = vala_list_get (_tmp32_, i);
						_tmp34_ = (ValaExpression*) _tmp33_;
						_tmp35_ = vala_template_stringify (self, _tmp34_);
						_tmp36_ = _tmp35_;
						vala_method_call_add_argument (_tmp31_, _tmp36_);
						_vala_code_node_unref0 (_tmp36_);
						_vala_code_node_unref0 (_tmp34_);
					}
				}
			}
			_tmp37_ = concat;
			_tmp38_ = _vala_code_node_ref0 ((ValaExpression*) _tmp37_);
			_vala_code_node_unref0 (expr);
			expr = _tmp38_;
			_vala_code_node_unref0 (concat);
		}
	}
	_tmp39_ = expr;
	_tmp40_ = vala_expression_get_target_type ((ValaExpression*) self);
	_tmp41_ = _tmp40_;
	vala_expression_set_target_type (_tmp39_, _tmp41_);
	_tmp42_ = vala_code_context_get_analyzer (context);
	_tmp43_ = _tmp42_;
	_tmp44_ = _tmp43_->replaced_nodes;
	vala_collection_add ((ValaCollection*) _tmp44_, (ValaCodeNode*) self);
	_tmp45_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
	_tmp46_ = _tmp45_;
	_tmp47_ = expr;
	vala_code_node_replace_expression (_tmp46_, (ValaExpression*) self, _tmp47_);
	_tmp48_ = expr;
	result = vala_code_node_check ((ValaCodeNode*) _tmp48_, context);
	_vala_code_node_unref0 (expr);
	return result;
}

static void
vala_template_class_init (ValaTemplateClass * klass,
                          gpointer klass_data)
{
	vala_template_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_template_finalize;
	g_type_class_adjust_private_offset (klass, &ValaTemplate_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_template_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_template_real_accept_children;
	((ValaExpressionClass *) klass)->is_pure = (gboolean (*) (ValaExpression*)) vala_template_real_is_pure;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_template_real_replace_expression;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_template_real_check;
}

static void
vala_template_instance_init (ValaTemplate * self,
                             gpointer klass)
{
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	self->priv = vala_template_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = vala_array_list_new (VALA_TYPE_EXPRESSION, (GBoxedCopyFunc) vala_code_node_ref, (GDestroyNotify) vala_code_node_unref, _tmp0_);
	self->priv->expression_list = (ValaList*) _tmp1_;
}

static void
vala_template_finalize (ValaCodeNode * obj)
{
	ValaTemplate * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_TEMPLATE, ValaTemplate);
	_vala_iterable_unref0 (self->priv->expression_list);
	VALA_CODE_NODE_CLASS (vala_template_parent_class)->finalize (obj);
}

static GType
vala_template_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaTemplateClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_template_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaTemplate), 0, (GInstanceInitFunc) vala_template_instance_init, NULL };
	GType vala_template_type_id;
	vala_template_type_id = g_type_register_static (VALA_TYPE_EXPRESSION, "ValaTemplate", &g_define_type_info, 0);
	ValaTemplate_private_offset = g_type_add_instance_private (vala_template_type_id, sizeof (ValaTemplatePrivate));
	return vala_template_type_id;
}

GType
vala_template_get_type (void)
{
	static volatile gsize vala_template_type_id__volatile = 0;
	if (g_once_init_enter (&vala_template_type_id__volatile)) {
		GType vala_template_type_id;
		vala_template_type_id = vala_template_get_type_once ();
		g_once_init_leave (&vala_template_type_id__volatile, vala_template_type_id);
	}
	return vala_template_type_id__volatile;
}

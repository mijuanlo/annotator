/* valafield.c generated by valac, the Vala compiler
 * generated from valafield.vala, do not modify */

/* valafield.vala
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
#include <stdlib.h>
#include <string.h>

#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _vala_source_file_unref0(var) ((var == NULL) ? NULL : (var = (vala_source_file_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ValaFieldPrivate {
	ValaMemberBinding _binding;
	gboolean _is_volatile;
	gboolean _lock_used;
};

static gint ValaField_private_offset;
static gpointer vala_field_parent_class = NULL;
static ValaLockableIface * vala_field_vala_lockable_parent_iface = NULL;

static void vala_field_real_accept (ValaCodeNode* base,
                             ValaCodeVisitor* visitor);
static void vala_field_real_accept_children (ValaCodeNode* base,
                                      ValaCodeVisitor* visitor);
static void vala_field_real_replace_expression (ValaCodeNode* base,
                                         ValaExpression* old_node,
                                         ValaExpression* new_node);
static void vala_field_real_replace_type (ValaCodeNode* base,
                                   ValaDataType* old_type,
                                   ValaDataType* new_type);
static gboolean vala_field_real_check (ValaCodeNode* base,
                                ValaCodeContext* context);
static void vala_field_finalize (ValaCodeNode * obj);
static GType vala_field_get_type_once (void);

static inline gpointer
vala_field_get_instance_private (ValaField* self)
{
	return G_STRUCT_MEMBER_P (self, ValaField_private_offset);
}

ValaMemberBinding
vala_field_get_binding (ValaField* self)
{
	ValaMemberBinding result;
	ValaMemberBinding _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_binding;
	result = _tmp0_;
	return result;
}

void
vala_field_set_binding (ValaField* self,
                        ValaMemberBinding value)
{
	g_return_if_fail (self != NULL);
	self->priv->_binding = value;
}

gboolean
vala_field_get_is_volatile (ValaField* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_is_volatile;
	return result;
}

void
vala_field_set_is_volatile (ValaField* self,
                            gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_is_volatile = value;
}

static gboolean
vala_field_real_get_lock_used (ValaLockable* base)
{
	gboolean result;
	ValaField* self;
	self = (ValaField*) base;
	result = self->priv->_lock_used;
	return result;
}

static void
vala_field_real_set_lock_used (ValaLockable* base,
                               gboolean value)
{
	ValaField* self;
	self = (ValaField*) base;
	self->priv->_lock_used = value;
}

/**
 * Creates a new field.
 *
 * @param name              field name
 * @param variable_type     field type
 * @param initializer       initializer expression
 * @param source_reference  reference to source code
 * @return                  newly created field
 */
ValaField*
vala_field_construct (GType object_type,
                      const gchar* name,
                      ValaDataType* variable_type,
                      ValaExpression* initializer,
                      ValaSourceReference* source_reference,
                      ValaComment* comment)
{
	ValaField* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (variable_type != NULL, NULL);
	self = (ValaField*) vala_variable_construct (object_type, variable_type, name, initializer, source_reference, comment);
	return self;
}

ValaField*
vala_field_new (const gchar* name,
                ValaDataType* variable_type,
                ValaExpression* initializer,
                ValaSourceReference* source_reference,
                ValaComment* comment)
{
	return vala_field_construct (VALA_TYPE_FIELD, name, variable_type, initializer, source_reference, comment);
}

static void
vala_field_real_accept (ValaCodeNode* base,
                        ValaCodeVisitor* visitor)
{
	ValaField * self;
	self = (ValaField*) base;
	g_return_if_fail (visitor != NULL);
	vala_code_visitor_visit_field (visitor, self);
}

static void
vala_field_real_accept_children (ValaCodeNode* base,
                                 ValaCodeVisitor* visitor)
{
	ValaField * self;
	ValaDataType* _tmp0_;
	ValaDataType* _tmp1_;
	ValaExpression* _tmp2_;
	ValaExpression* _tmp3_;
	self = (ValaField*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp1_ = _tmp0_;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, visitor);
	_tmp2_ = vala_variable_get_initializer ((ValaVariable*) self);
	_tmp3_ = _tmp2_;
	if (_tmp3_ != NULL) {
		ValaExpression* _tmp4_;
		ValaExpression* _tmp5_;
		_tmp4_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp5_ = _tmp4_;
		vala_code_node_accept ((ValaCodeNode*) _tmp5_, visitor);
	}
}

static void
vala_field_real_replace_expression (ValaCodeNode* base,
                                    ValaExpression* old_node,
                                    ValaExpression* new_node)
{
	ValaField * self;
	ValaExpression* _tmp0_;
	ValaExpression* _tmp1_;
	self = (ValaField*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_variable_get_initializer ((ValaVariable*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_node) {
		vala_variable_set_initializer ((ValaVariable*) self, new_node);
	}
}

static void
vala_field_real_replace_type (ValaCodeNode* base,
                              ValaDataType* old_type,
                              ValaDataType* new_type)
{
	ValaField * self;
	ValaDataType* _tmp0_;
	ValaDataType* _tmp1_;
	self = (ValaField*) base;
	g_return_if_fail (old_type != NULL);
	g_return_if_fail (new_type != NULL);
	_tmp0_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_ == old_type) {
		vala_variable_set_variable_type ((ValaVariable*) self, new_type);
	}
}

static gpointer
_vala_source_file_ref0 (gpointer self)
{
	return self ? vala_source_file_ref (self) : NULL;
}

static gpointer
_vala_code_node_ref0 (gpointer self)
{
	return self ? vala_code_node_ref (self) : NULL;
}

static gboolean
vala_field_real_check (ValaCodeNode* base,
                       ValaCodeContext* context)
{
	ValaField * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	ValaSourceFile* old_source_file = NULL;
	ValaSemanticAnalyzer* _tmp4_;
	ValaSemanticAnalyzer* _tmp5_;
	ValaSourceFile* _tmp6_;
	ValaSourceFile* _tmp7_;
	ValaSourceFile* _tmp8_;
	ValaSymbol* old_symbol = NULL;
	ValaSemanticAnalyzer* _tmp9_;
	ValaSemanticAnalyzer* _tmp10_;
	ValaSymbol* _tmp11_;
	ValaSymbol* _tmp12_;
	ValaSymbol* _tmp13_;
	ValaSourceReference* _tmp14_;
	ValaSourceReference* _tmp15_;
	ValaSemanticAnalyzer* _tmp22_;
	ValaSemanticAnalyzer* _tmp23_;
	ValaDataType* _tmp24_;
	ValaDataType* _tmp25_;
	ValaDataType* _tmp28_;
	ValaDataType* _tmp29_;
	ValaTypeSymbol* _tmp30_;
	ValaTypeSymbol* _tmp31_;
	ValaSemanticAnalyzer* _tmp32_;
	ValaSemanticAnalyzer* _tmp33_;
	ValaDataType* _tmp34_;
	ValaTypeSymbol* _tmp35_;
	ValaTypeSymbol* _tmp36_;
	ValaDataType* _tmp47_;
	ValaDataType* _tmp48_;
	gboolean _tmp49_;
	gboolean _tmp50_;
	ValaSemanticAnalyzer* _tmp67_;
	ValaSemanticAnalyzer* _tmp68_;
	ValaDataType* _tmp69_;
	ValaDataType* _tmp70_;
	ValaArrayType* variable_array_type = NULL;
	ValaDataType* _tmp81_;
	ValaDataType* _tmp82_;
	gboolean _tmp83_ = FALSE;
	gboolean _tmp84_ = FALSE;
	gboolean _tmp85_ = FALSE;
	ValaArrayType* _tmp86_;
	gboolean _tmp98_ = FALSE;
	gboolean _tmp99_ = FALSE;
	ValaArrayType* _tmp100_;
	ValaExpression* _tmp109_;
	ValaExpression* _tmp110_;
	gboolean _tmp233_ = FALSE;
	ValaMemberBinding _tmp234_;
	gboolean field_in_header = FALSE;
	ValaSymbol* _tmp239_;
	ValaSymbol* _tmp240_;
	gboolean _tmp249_ = FALSE;
	gboolean _tmp250_ = FALSE;
	gboolean _tmp251_;
	gboolean _tmp252_;
	ValaSemanticAnalyzer* _tmp267_;
	ValaSemanticAnalyzer* _tmp268_;
	ValaSourceFile* _tmp269_;
	ValaSemanticAnalyzer* _tmp270_;
	ValaSemanticAnalyzer* _tmp271_;
	ValaSymbol* _tmp272_;
	gboolean _tmp273_;
	gboolean _tmp274_;
	gboolean result = FALSE;
	self = (ValaField*) base;
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
	_tmp4_ = vala_code_context_get_analyzer (context);
	_tmp5_ = _tmp4_;
	_tmp6_ = vala_semantic_analyzer_get_current_source_file (_tmp5_);
	_tmp7_ = _tmp6_;
	_tmp8_ = _vala_source_file_ref0 (_tmp7_);
	old_source_file = _tmp8_;
	_tmp9_ = vala_code_context_get_analyzer (context);
	_tmp10_ = _tmp9_;
	_tmp11_ = vala_semantic_analyzer_get_current_symbol (_tmp10_);
	_tmp12_ = _tmp11_;
	_tmp13_ = _vala_code_node_ref0 (_tmp12_);
	old_symbol = _tmp13_;
	_tmp14_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp15_ = _tmp14_;
	if (_tmp15_ != NULL) {
		ValaSemanticAnalyzer* _tmp16_;
		ValaSemanticAnalyzer* _tmp17_;
		ValaSourceReference* _tmp18_;
		ValaSourceReference* _tmp19_;
		ValaSourceFile* _tmp20_;
		ValaSourceFile* _tmp21_;
		_tmp16_ = vala_code_context_get_analyzer (context);
		_tmp17_ = _tmp16_;
		_tmp18_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp19_ = _tmp18_;
		_tmp20_ = vala_source_reference_get_file (_tmp19_);
		_tmp21_ = _tmp20_;
		vala_semantic_analyzer_set_current_source_file (_tmp17_, _tmp21_);
	}
	_tmp22_ = vala_code_context_get_analyzer (context);
	_tmp23_ = _tmp22_;
	vala_semantic_analyzer_set_current_symbol (_tmp23_, (ValaSymbol*) self);
	_tmp24_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp25_ = _tmp24_;
	if (VALA_IS_VOID_TYPE (_tmp25_)) {
		ValaSourceReference* _tmp26_;
		ValaSourceReference* _tmp27_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp26_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp27_ = _tmp26_;
		vala_report_error (_tmp27_, "'void' not supported as field type");
		result = FALSE;
		_vala_code_node_unref0 (old_symbol);
		_vala_source_file_unref0 (old_source_file);
		return result;
	}
	_tmp28_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp29_ = _tmp28_;
	_tmp30_ = vala_data_type_get_type_symbol (_tmp29_);
	_tmp31_ = _tmp30_;
	_tmp32_ = vala_code_context_get_analyzer (context);
	_tmp33_ = _tmp32_;
	_tmp34_ = _tmp33_->va_list_type;
	_tmp35_ = vala_data_type_get_type_symbol (_tmp34_);
	_tmp36_ = _tmp35_;
	if (_tmp31_ == _tmp36_) {
		ValaSourceReference* _tmp37_;
		ValaSourceReference* _tmp38_;
		ValaDataType* _tmp39_;
		ValaDataType* _tmp40_;
		ValaTypeSymbol* _tmp41_;
		ValaTypeSymbol* _tmp42_;
		gchar* _tmp43_;
		gchar* _tmp44_;
		gchar* _tmp45_;
		gchar* _tmp46_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp37_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp38_ = _tmp37_;
		_tmp39_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp40_ = _tmp39_;
		_tmp41_ = vala_data_type_get_type_symbol (_tmp40_);
		_tmp42_ = _tmp41_;
		_tmp43_ = vala_symbol_get_full_name ((ValaSymbol*) _tmp42_);
		_tmp44_ = _tmp43_;
		_tmp45_ = g_strdup_printf ("`%s' not supported as field type", _tmp44_);
		_tmp46_ = _tmp45_;
		vala_report_error (_tmp38_, _tmp46_);
		_g_free0 (_tmp46_);
		_g_free0 (_tmp44_);
		result = FALSE;
		_vala_code_node_unref0 (old_symbol);
		_vala_source_file_unref0 (old_source_file);
		return result;
	}
	_tmp47_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp48_ = _tmp47_;
	vala_code_node_check ((ValaCodeNode*) _tmp48_, context);
	_tmp49_ = vala_symbol_get_external_package ((ValaSymbol*) self);
	_tmp50_ = _tmp49_;
	if (!_tmp50_) {
		ValaSemanticAnalyzer* _tmp51_;
		ValaSemanticAnalyzer* _tmp52_;
		ValaDataType* _tmp53_;
		ValaDataType* _tmp54_;
		ValaDataType* _tmp55_;
		ValaDataType* _tmp56_;
		ValaTypeSymbol* _tmp57_;
		ValaTypeSymbol* _tmp58_;
		_tmp51_ = vala_code_context_get_analyzer (context);
		_tmp52_ = _tmp51_;
		_tmp53_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp54_ = _tmp53_;
		vala_semantic_analyzer_check_type (_tmp52_, _tmp54_);
		_tmp55_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp56_ = _tmp55_;
		_tmp57_ = vala_data_type_get_type_symbol (_tmp56_);
		_tmp58_ = _tmp57_;
		if (_tmp58_ != NULL) {
			ValaDataType* _tmp59_;
			ValaDataType* _tmp60_;
			ValaTypeSymbol* _tmp61_;
			ValaTypeSymbol* _tmp62_;
			ValaVersionAttribute* _tmp63_;
			ValaVersionAttribute* _tmp64_;
			ValaSourceReference* _tmp65_;
			ValaSourceReference* _tmp66_;
			_tmp59_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp60_ = _tmp59_;
			_tmp61_ = vala_data_type_get_type_symbol (_tmp60_);
			_tmp62_ = _tmp61_;
			_tmp63_ = vala_symbol_get_version ((ValaSymbol*) _tmp62_);
			_tmp64_ = _tmp63_;
			_tmp65_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp66_ = _tmp65_;
			vala_version_attribute_check (_tmp64_, _tmp66_);
		}
	}
	_tmp67_ = vala_code_context_get_analyzer (context);
	_tmp68_ = _tmp67_;
	_tmp69_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp70_ = _tmp69_;
	if (!vala_semantic_analyzer_is_type_accessible (_tmp68_, (ValaSymbol*) self, _tmp70_)) {
		ValaSourceReference* _tmp71_;
		ValaSourceReference* _tmp72_;
		ValaDataType* _tmp73_;
		ValaDataType* _tmp74_;
		gchar* _tmp75_;
		gchar* _tmp76_;
		gchar* _tmp77_;
		gchar* _tmp78_;
		gchar* _tmp79_;
		gchar* _tmp80_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp71_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp72_ = _tmp71_;
		_tmp73_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp74_ = _tmp73_;
		_tmp75_ = vala_code_node_to_string ((ValaCodeNode*) _tmp74_);
		_tmp76_ = _tmp75_;
		_tmp77_ = vala_symbol_get_full_name ((ValaSymbol*) self);
		_tmp78_ = _tmp77_;
		_tmp79_ = g_strdup_printf ("field type `%s' is less accessible than field `%s'", _tmp76_, _tmp78_);
		_tmp80_ = _tmp79_;
		vala_report_error (_tmp72_, _tmp80_);
		_g_free0 (_tmp80_);
		_g_free0 (_tmp78_);
		_g_free0 (_tmp76_);
		result = FALSE;
		_vala_code_node_unref0 (old_symbol);
		_vala_source_file_unref0 (old_source_file);
		return result;
	}
	_tmp81_ = vala_variable_get_variable_type ((ValaVariable*) self);
	_tmp82_ = _tmp81_;
	variable_array_type = VALA_IS_ARRAY_TYPE (_tmp82_) ? ((ValaArrayType*) _tmp82_) : NULL;
	_tmp86_ = variable_array_type;
	if (_tmp86_ != NULL) {
		ValaArrayType* _tmp87_;
		gboolean _tmp88_;
		gboolean _tmp89_;
		_tmp87_ = variable_array_type;
		_tmp88_ = vala_array_type_get_inline_allocated (_tmp87_);
		_tmp89_ = _tmp88_;
		_tmp85_ = _tmp89_;
	} else {
		_tmp85_ = FALSE;
	}
	if (_tmp85_) {
		ValaExpression* _tmp90_;
		ValaExpression* _tmp91_;
		_tmp90_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp91_ = _tmp90_;
		_tmp84_ = VALA_IS_ARRAY_CREATION_EXPRESSION (_tmp91_);
	} else {
		_tmp84_ = FALSE;
	}
	if (_tmp84_) {
		ValaExpression* _tmp92_;
		ValaExpression* _tmp93_;
		ValaInitializerList* _tmp94_;
		ValaInitializerList* _tmp95_;
		_tmp92_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp93_ = _tmp92_;
		_tmp94_ = vala_array_creation_expression_get_initializer_list (G_TYPE_CHECK_INSTANCE_CAST (_tmp93_, VALA_TYPE_ARRAY_CREATION_EXPRESSION, ValaArrayCreationExpression));
		_tmp95_ = _tmp94_;
		_tmp83_ = _tmp95_ == NULL;
	} else {
		_tmp83_ = FALSE;
	}
	if (_tmp83_) {
		ValaSourceReference* _tmp96_;
		ValaSourceReference* _tmp97_;
		_tmp96_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp97_ = _tmp96_;
		vala_report_warning (_tmp97_, "Inline allocated arrays don't require an explicit instantiation");
		vala_variable_set_initializer ((ValaVariable*) self, NULL);
	}
	_tmp100_ = variable_array_type;
	if (_tmp100_ != NULL) {
		ValaArrayType* _tmp101_;
		gboolean _tmp102_;
		gboolean _tmp103_;
		_tmp101_ = variable_array_type;
		_tmp102_ = vala_array_type_get_inline_allocated (_tmp101_);
		_tmp103_ = _tmp102_;
		_tmp99_ = _tmp103_;
	} else {
		_tmp99_ = FALSE;
	}
	if (_tmp99_) {
		ValaArrayType* _tmp104_;
		gboolean _tmp105_;
		gboolean _tmp106_;
		_tmp104_ = variable_array_type;
		_tmp105_ = vala_array_type_get_fixed_length (_tmp104_);
		_tmp106_ = _tmp105_;
		_tmp98_ = !_tmp106_;
	} else {
		_tmp98_ = FALSE;
	}
	if (_tmp98_) {
		ValaSourceReference* _tmp107_;
		ValaSourceReference* _tmp108_;
		_tmp107_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp108_ = _tmp107_;
		vala_report_error (_tmp108_, "Inline allocated array as field requires to have fixed length");
	}
	_tmp109_ = vala_variable_get_initializer ((ValaVariable*) self);
	_tmp110_ = _tmp109_;
	if (_tmp110_ != NULL) {
		ValaExpression* _tmp111_;
		ValaExpression* _tmp112_;
		ValaDataType* _tmp113_;
		ValaDataType* _tmp114_;
		gboolean is_initializer_list = FALSE;
		gint initializer_size = 0;
		ValaExpression* _tmp115_;
		ValaExpression* _tmp116_;
		ValaExpression* _tmp121_;
		ValaExpression* _tmp122_;
		ValaExpression* _tmp123_;
		ValaExpression* _tmp124_;
		ValaDataType* _tmp125_;
		ValaDataType* _tmp126_;
		ValaExpression* _tmp129_;
		ValaExpression* _tmp130_;
		ValaDataType* _tmp131_;
		ValaDataType* _tmp132_;
		ValaDataType* _tmp133_;
		ValaDataType* _tmp134_;
		gboolean _tmp149_ = FALSE;
		gboolean _tmp150_ = FALSE;
		gboolean _tmp151_ = FALSE;
		ValaArrayType* _tmp152_;
		gboolean _tmp166_ = FALSE;
		gboolean _tmp167_ = FALSE;
		ValaArrayType* _tmp168_;
		ValaExpression* _tmp178_;
		ValaExpression* _tmp179_;
		ValaDataType* _tmp180_;
		ValaDataType* _tmp181_;
		gboolean _tmp191_ = FALSE;
		ValaSymbol* _tmp192_;
		ValaSymbol* _tmp193_;
		gboolean _tmp198_ = FALSE;
		gboolean _tmp199_ = FALSE;
		ValaSymbol* _tmp200_;
		ValaSymbol* _tmp201_;
		gboolean _tmp215_ = FALSE;
		gboolean _tmp216_ = FALSE;
		gboolean _tmp217_ = FALSE;
		ValaMemberBinding _tmp218_;
		gboolean _tmp229_;
		gboolean _tmp230_;
		_tmp111_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp112_ = _tmp111_;
		_tmp113_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp114_ = _tmp113_;
		vala_expression_set_target_type (_tmp112_, _tmp114_);
		is_initializer_list = FALSE;
		initializer_size = -1;
		_tmp115_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp116_ = _tmp115_;
		if (VALA_IS_INITIALIZER_LIST (_tmp116_)) {
			ValaExpression* _tmp117_;
			ValaExpression* _tmp118_;
			gint _tmp119_;
			gint _tmp120_;
			_tmp117_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp118_ = _tmp117_;
			_tmp119_ = vala_initializer_list_get_size (G_TYPE_CHECK_INSTANCE_CAST (_tmp118_, VALA_TYPE_INITIALIZER_LIST, ValaInitializerList));
			_tmp120_ = _tmp119_;
			initializer_size = _tmp120_;
			is_initializer_list = TRUE;
		}
		_tmp121_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp122_ = _tmp121_;
		if (!vala_code_node_check ((ValaCodeNode*) _tmp122_, context)) {
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			result = FALSE;
			_vala_code_node_unref0 (old_symbol);
			_vala_source_file_unref0 (old_source_file);
			return result;
		}
		_tmp123_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp124_ = _tmp123_;
		_tmp125_ = vala_expression_get_value_type (_tmp124_);
		_tmp126_ = _tmp125_;
		if (_tmp126_ == NULL) {
			ValaSourceReference* _tmp127_;
			ValaSourceReference* _tmp128_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp127_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp128_ = _tmp127_;
			vala_report_error (_tmp128_, "expression type not allowed as initializer");
			result = FALSE;
			_vala_code_node_unref0 (old_symbol);
			_vala_source_file_unref0 (old_source_file);
			return result;
		}
		_tmp129_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp130_ = _tmp129_;
		_tmp131_ = vala_expression_get_value_type (_tmp130_);
		_tmp132_ = _tmp131_;
		_tmp133_ = vala_variable_get_variable_type ((ValaVariable*) self);
		_tmp134_ = _tmp133_;
		if (!vala_data_type_compatible (_tmp132_, _tmp134_)) {
			ValaSourceReference* _tmp135_;
			ValaSourceReference* _tmp136_;
			ValaExpression* _tmp137_;
			ValaExpression* _tmp138_;
			ValaDataType* _tmp139_;
			ValaDataType* _tmp140_;
			gchar* _tmp141_;
			gchar* _tmp142_;
			ValaDataType* _tmp143_;
			ValaDataType* _tmp144_;
			gchar* _tmp145_;
			gchar* _tmp146_;
			gchar* _tmp147_;
			gchar* _tmp148_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp135_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp136_ = _tmp135_;
			_tmp137_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp138_ = _tmp137_;
			_tmp139_ = vala_expression_get_value_type (_tmp138_);
			_tmp140_ = _tmp139_;
			_tmp141_ = vala_code_node_to_string ((ValaCodeNode*) _tmp140_);
			_tmp142_ = _tmp141_;
			_tmp143_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp144_ = _tmp143_;
			_tmp145_ = vala_code_node_to_string ((ValaCodeNode*) _tmp144_);
			_tmp146_ = _tmp145_;
			_tmp147_ = g_strdup_printf ("Cannot convert from `%s' to `%s'", _tmp142_, _tmp146_);
			_tmp148_ = _tmp147_;
			vala_report_error (_tmp136_, _tmp148_);
			_g_free0 (_tmp148_);
			_g_free0 (_tmp146_);
			_g_free0 (_tmp142_);
			result = FALSE;
			_vala_code_node_unref0 (old_symbol);
			_vala_source_file_unref0 (old_source_file);
			return result;
		}
		_tmp152_ = variable_array_type;
		if (_tmp152_ != NULL) {
			ValaArrayType* _tmp153_;
			gboolean _tmp154_;
			gboolean _tmp155_;
			_tmp153_ = variable_array_type;
			_tmp154_ = vala_array_type_get_inline_allocated (_tmp153_);
			_tmp155_ = _tmp154_;
			_tmp151_ = _tmp155_;
		} else {
			_tmp151_ = FALSE;
		}
		if (_tmp151_) {
			ValaArrayType* _tmp156_;
			gboolean _tmp157_;
			gboolean _tmp158_;
			_tmp156_ = variable_array_type;
			_tmp157_ = vala_array_type_get_fixed_length (_tmp156_);
			_tmp158_ = _tmp157_;
			_tmp150_ = !_tmp158_;
		} else {
			_tmp150_ = FALSE;
		}
		if (_tmp150_) {
			_tmp149_ = is_initializer_list;
		} else {
			_tmp149_ = FALSE;
		}
		if (_tmp149_) {
			ValaArrayType* _tmp159_;
			gchar* _tmp160_;
			gchar* _tmp161_;
			ValaIntegerLiteral* _tmp162_;
			ValaIntegerLiteral* _tmp163_;
			ValaArrayType* _tmp164_;
			ValaArrayType* _tmp165_;
			_tmp159_ = variable_array_type;
			_tmp160_ = g_strdup_printf ("%i", initializer_size);
			_tmp161_ = _tmp160_;
			_tmp162_ = vala_integer_literal_new (_tmp161_, NULL);
			_tmp163_ = _tmp162_;
			vala_array_type_set_length (_tmp159_, (ValaExpression*) _tmp163_);
			_vala_code_node_unref0 (_tmp163_);
			_g_free0 (_tmp161_);
			_tmp164_ = variable_array_type;
			vala_array_type_set_fixed_length (_tmp164_, TRUE);
			_tmp165_ = variable_array_type;
			vala_data_type_set_nullable ((ValaDataType*) _tmp165_, FALSE);
		}
		_tmp168_ = variable_array_type;
		if (_tmp168_ != NULL) {
			ValaArrayType* _tmp169_;
			gboolean _tmp170_;
			gboolean _tmp171_;
			_tmp169_ = variable_array_type;
			_tmp170_ = vala_array_type_get_inline_allocated (_tmp169_);
			_tmp171_ = _tmp170_;
			_tmp167_ = _tmp171_;
		} else {
			_tmp167_ = FALSE;
		}
		if (_tmp167_) {
			ValaExpression* _tmp172_;
			ValaExpression* _tmp173_;
			ValaDataType* _tmp174_;
			ValaDataType* _tmp175_;
			_tmp172_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp173_ = _tmp172_;
			_tmp174_ = vala_expression_get_value_type (_tmp173_);
			_tmp175_ = _tmp174_;
			_tmp166_ = !VALA_IS_ARRAY_TYPE (_tmp175_);
		} else {
			_tmp166_ = FALSE;
		}
		if (_tmp166_) {
			ValaSourceReference* _tmp176_;
			ValaSourceReference* _tmp177_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp176_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp177_ = _tmp176_;
			vala_report_error (_tmp177_, "only arrays are allowed as initializer for arrays with fixed length");
			result = FALSE;
			_vala_code_node_unref0 (old_symbol);
			_vala_source_file_unref0 (old_source_file);
			return result;
		}
		_tmp178_ = vala_variable_get_initializer ((ValaVariable*) self);
		_tmp179_ = _tmp178_;
		_tmp180_ = vala_expression_get_value_type (_tmp179_);
		_tmp181_ = _tmp180_;
		if (vala_data_type_is_disposable (_tmp181_)) {
			gboolean _tmp182_ = FALSE;
			ValaDataType* _tmp183_;
			ValaDataType* _tmp184_;
			_tmp183_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp184_ = _tmp183_;
			if (!VALA_IS_POINTER_TYPE (_tmp184_)) {
				ValaDataType* _tmp185_;
				ValaDataType* _tmp186_;
				gboolean _tmp187_;
				gboolean _tmp188_;
				_tmp185_ = vala_variable_get_variable_type ((ValaVariable*) self);
				_tmp186_ = _tmp185_;
				_tmp187_ = vala_data_type_get_value_owned (_tmp186_);
				_tmp188_ = _tmp187_;
				_tmp182_ = !_tmp188_;
			} else {
				_tmp182_ = FALSE;
			}
			if (_tmp182_) {
				ValaSourceReference* _tmp189_;
				ValaSourceReference* _tmp190_;
				vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
				_tmp189_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
				_tmp190_ = _tmp189_;
				vala_report_error (_tmp190_, "Invalid assignment from owned expression to unowned variable");
				result = FALSE;
				_vala_code_node_unref0 (old_symbol);
				_vala_source_file_unref0 (old_source_file);
				return result;
			}
		}
		_tmp192_ = vala_symbol_get_parent_symbol ((ValaSymbol*) self);
		_tmp193_ = _tmp192_;
		if (VALA_IS_NAMESPACE (_tmp193_)) {
			ValaExpression* _tmp194_;
			ValaExpression* _tmp195_;
			_tmp194_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp195_ = _tmp194_;
			_tmp191_ = !vala_expression_is_constant (_tmp195_);
		} else {
			_tmp191_ = FALSE;
		}
		if (_tmp191_) {
			ValaSourceReference* _tmp196_;
			ValaSourceReference* _tmp197_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp196_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp197_ = _tmp196_;
			vala_report_error (_tmp197_, "Non-constant field initializers not supported in this context");
			result = FALSE;
			_vala_code_node_unref0 (old_symbol);
			_vala_source_file_unref0 (old_source_file);
			return result;
		}
		_tmp200_ = vala_symbol_get_parent_symbol ((ValaSymbol*) self);
		_tmp201_ = _tmp200_;
		if (VALA_IS_NAMESPACE (_tmp201_)) {
			ValaExpression* _tmp202_;
			ValaExpression* _tmp203_;
			_tmp202_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp203_ = _tmp202_;
			_tmp199_ = vala_expression_is_constant (_tmp203_);
		} else {
			_tmp199_ = FALSE;
		}
		if (_tmp199_) {
			ValaExpression* _tmp204_;
			ValaExpression* _tmp205_;
			_tmp204_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp205_ = _tmp204_;
			_tmp198_ = vala_expression_is_non_null (_tmp205_);
		} else {
			_tmp198_ = FALSE;
		}
		if (_tmp198_) {
			gboolean _tmp206_ = FALSE;
			ValaDataType* _tmp207_;
			ValaDataType* _tmp208_;
			_tmp207_ = vala_variable_get_variable_type ((ValaVariable*) self);
			_tmp208_ = _tmp207_;
			if (vala_data_type_is_disposable (_tmp208_)) {
				ValaDataType* _tmp209_;
				ValaDataType* _tmp210_;
				gboolean _tmp211_;
				gboolean _tmp212_;
				_tmp209_ = vala_variable_get_variable_type ((ValaVariable*) self);
				_tmp210_ = _tmp209_;
				_tmp211_ = vala_data_type_get_value_owned (_tmp210_);
				_tmp212_ = _tmp211_;
				_tmp206_ = _tmp212_;
			} else {
				_tmp206_ = FALSE;
			}
			if (_tmp206_) {
				ValaSourceReference* _tmp213_;
				ValaSourceReference* _tmp214_;
				vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
				_tmp213_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
				_tmp214_ = _tmp213_;
				vala_report_error (_tmp214_, "Owned namespace fields can only be initialized in a function or method");
				result = FALSE;
				_vala_code_node_unref0 (old_symbol);
				_vala_source_file_unref0 (old_source_file);
				return result;
			}
		}
		_tmp218_ = self->priv->_binding;
		if (_tmp218_ == VALA_MEMBER_BINDING_STATIC) {
			ValaSymbol* _tmp219_;
			ValaSymbol* _tmp220_;
			_tmp219_ = vala_symbol_get_parent_symbol ((ValaSymbol*) self);
			_tmp220_ = _tmp219_;
			_tmp217_ = VALA_IS_CLASS (_tmp220_);
		} else {
			_tmp217_ = FALSE;
		}
		if (_tmp217_) {
			ValaSymbol* _tmp221_;
			ValaSymbol* _tmp222_;
			gboolean _tmp223_;
			gboolean _tmp224_;
			_tmp221_ = vala_symbol_get_parent_symbol ((ValaSymbol*) self);
			_tmp222_ = _tmp221_;
			_tmp223_ = vala_class_get_is_compact (G_TYPE_CHECK_INSTANCE_CAST (_tmp222_, VALA_TYPE_CLASS, ValaClass));
			_tmp224_ = _tmp223_;
			_tmp216_ = _tmp224_;
		} else {
			_tmp216_ = FALSE;
		}
		if (_tmp216_) {
			ValaExpression* _tmp225_;
			ValaExpression* _tmp226_;
			_tmp225_ = vala_variable_get_initializer ((ValaVariable*) self);
			_tmp226_ = _tmp225_;
			_tmp215_ = !vala_expression_is_constant (_tmp226_);
		} else {
			_tmp215_ = FALSE;
		}
		if (_tmp215_) {
			ValaSourceReference* _tmp227_;
			ValaSourceReference* _tmp228_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp227_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp228_ = _tmp227_;
			vala_report_error (_tmp228_, "Static fields in compact classes cannot have non-constant initializers");
			result = FALSE;
			_vala_code_node_unref0 (old_symbol);
			_vala_source_file_unref0 (old_source_file);
			return result;
		}
		_tmp229_ = vala_symbol_get_external ((ValaSymbol*) self);
		_tmp230_ = _tmp229_;
		if (_tmp230_) {
			ValaSourceReference* _tmp231_;
			ValaSourceReference* _tmp232_;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp231_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp232_ = _tmp231_;
			vala_report_error (_tmp232_, "External fields cannot use initializers");
		}
	}
	_tmp234_ = self->priv->_binding;
	if (_tmp234_ == VALA_MEMBER_BINDING_INSTANCE) {
		ValaSymbol* _tmp235_;
		ValaSymbol* _tmp236_;
		_tmp235_ = vala_symbol_get_parent_symbol ((ValaSymbol*) self);
		_tmp236_ = _tmp235_;
		_tmp233_ = VALA_IS_INTERFACE (_tmp236_);
	} else {
		_tmp233_ = FALSE;
	}
	if (_tmp233_) {
		ValaSourceReference* _tmp237_;
		ValaSourceReference* _tmp238_;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp237_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp238_ = _tmp237_;
		vala_report_error (_tmp238_, "Interfaces may not have instance fields");
		result = FALSE;
		_vala_code_node_unref0 (old_symbol);
		_vala_source_file_unref0 (old_source_file);
		return result;
	}
	field_in_header = !vala_symbol_is_internal_symbol ((ValaSymbol*) self);
	_tmp239_ = vala_symbol_get_parent_symbol ((ValaSymbol*) self);
	_tmp240_ = _tmp239_;
	if (VALA_IS_CLASS (_tmp240_)) {
		ValaClass* cl = NULL;
		ValaSymbol* _tmp241_;
		ValaSymbol* _tmp242_;
		ValaClass* _tmp243_;
		gboolean _tmp244_ = FALSE;
		ValaClass* _tmp245_;
		gboolean _tmp246_;
		gboolean _tmp247_;
		_tmp241_ = vala_symbol_get_parent_symbol ((ValaSymbol*) self);
		_tmp242_ = _tmp241_;
		_tmp243_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp242_, VALA_TYPE_CLASS, ValaClass));
		cl = _tmp243_;
		_tmp245_ = cl;
		_tmp246_ = vala_class_get_is_compact (_tmp245_);
		_tmp247_ = _tmp246_;
		if (_tmp247_) {
			ValaClass* _tmp248_;
			_tmp248_ = cl;
			_tmp244_ = !vala_symbol_is_internal_symbol ((ValaSymbol*) _tmp248_);
		} else {
			_tmp244_ = FALSE;
		}
		if (_tmp244_) {
			field_in_header = TRUE;
		}
		_vala_code_node_unref0 (cl);
	}
	_tmp251_ = vala_symbol_get_external_package ((ValaSymbol*) self);
	_tmp252_ = _tmp251_;
	if (!_tmp252_) {
		gboolean _tmp253_;
		gboolean _tmp254_;
		_tmp253_ = vala_symbol_get_hides ((ValaSymbol*) self);
		_tmp254_ = _tmp253_;
		_tmp250_ = !_tmp254_;
	} else {
		_tmp250_ = FALSE;
	}
	if (_tmp250_) {
		ValaSymbol* _tmp255_;
		ValaSymbol* _tmp256_;
		_tmp255_ = vala_symbol_get_hidden_member ((ValaSymbol*) self);
		_tmp256_ = _tmp255_;
		_tmp249_ = _tmp256_ != NULL;
		_vala_code_node_unref0 (_tmp256_);
	} else {
		_tmp249_ = FALSE;
	}
	if (_tmp249_) {
		ValaSourceReference* _tmp257_;
		ValaSourceReference* _tmp258_;
		gchar* _tmp259_;
		gchar* _tmp260_;
		ValaSymbol* _tmp261_;
		ValaSymbol* _tmp262_;
		gchar* _tmp263_;
		gchar* _tmp264_;
		gchar* _tmp265_;
		gchar* _tmp266_;
		_tmp257_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp258_ = _tmp257_;
		_tmp259_ = vala_symbol_get_full_name ((ValaSymbol*) self);
		_tmp260_ = _tmp259_;
		_tmp261_ = vala_symbol_get_hidden_member ((ValaSymbol*) self);
		_tmp262_ = _tmp261_;
		_tmp263_ = vala_symbol_get_full_name (_tmp262_);
		_tmp264_ = _tmp263_;
		_tmp265_ = g_strdup_printf ("%s hides inherited field `%s'. Use the `new' keyword if hiding was int" \
"entional", _tmp260_, _tmp264_);
		_tmp266_ = _tmp265_;
		vala_report_warning (_tmp258_, _tmp266_);
		_g_free0 (_tmp266_);
		_g_free0 (_tmp264_);
		_vala_code_node_unref0 (_tmp262_);
		_g_free0 (_tmp260_);
	}
	_tmp267_ = vala_code_context_get_analyzer (context);
	_tmp268_ = _tmp267_;
	_tmp269_ = old_source_file;
	vala_semantic_analyzer_set_current_source_file (_tmp268_, _tmp269_);
	_tmp270_ = vala_code_context_get_analyzer (context);
	_tmp271_ = _tmp270_;
	_tmp272_ = old_symbol;
	vala_semantic_analyzer_set_current_symbol (_tmp271_, _tmp272_);
	_tmp273_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp274_ = _tmp273_;
	result = !_tmp274_;
	_vala_code_node_unref0 (old_symbol);
	_vala_source_file_unref0 (old_source_file);
	return result;
}

static void
vala_field_class_init (ValaFieldClass * klass,
                       gpointer klass_data)
{
	vala_field_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = vala_field_finalize;
	g_type_class_adjust_private_offset (klass, &ValaField_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_field_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) vala_field_real_accept_children;
	((ValaCodeNodeClass *) klass)->replace_expression = (void (*) (ValaCodeNode*, ValaExpression*, ValaExpression*)) vala_field_real_replace_expression;
	((ValaCodeNodeClass *) klass)->replace_type = (void (*) (ValaCodeNode*, ValaDataType*, ValaDataType*)) vala_field_real_replace_type;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) vala_field_real_check;
}

static void
vala_field_vala_lockable_interface_init (ValaLockableIface * iface,
                                         gpointer iface_data)
{
	vala_field_vala_lockable_parent_iface = g_type_interface_peek_parent (iface);
	iface->get_lock_used = vala_field_real_get_lock_used;
	iface->set_lock_used = vala_field_real_set_lock_used;
}

static void
vala_field_instance_init (ValaField * self,
                          gpointer klass)
{
	self->priv = vala_field_get_instance_private (self);
	self->priv->_binding = VALA_MEMBER_BINDING_INSTANCE;
}

static void
vala_field_finalize (ValaCodeNode * obj)
{
	ValaField * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_FIELD, ValaField);
	VALA_CODE_NODE_CLASS (vala_field_parent_class)->finalize (obj);
}

/**
 * Represents a type or namespace field.
 */
static GType
vala_field_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaFieldClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_field_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaField), 0, (GInstanceInitFunc) vala_field_instance_init, NULL };
	static const GInterfaceInfo vala_lockable_info = { (GInterfaceInitFunc) vala_field_vala_lockable_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType vala_field_type_id;
	vala_field_type_id = g_type_register_static (VALA_TYPE_VARIABLE, "ValaField", &g_define_type_info, 0);
	g_type_add_interface_static (vala_field_type_id, VALA_TYPE_LOCKABLE, &vala_lockable_info);
	ValaField_private_offset = g_type_add_instance_private (vala_field_type_id, sizeof (ValaFieldPrivate));
	return vala_field_type_id;
}

GType
vala_field_get_type (void)
{
	static volatile gsize vala_field_type_id__volatile = 0;
	if (g_once_init_enter (&vala_field_type_id__volatile)) {
		GType vala_field_type_id;
		vala_field_type_id = vala_field_get_type_once ();
		g_once_init_leave (&vala_field_type_id__volatile, vala_field_type_id);
	}
	return vala_field_type_id__volatile;
}


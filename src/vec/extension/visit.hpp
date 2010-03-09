/*##################################################################################################
	
	���x�N�g���ɑ΂��đ�����s���g���I�u�W�F�N�g�̐ڑ����s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/10/29
		�Eresult_of �� & ��t�����ēn���悤�ɕύX
		detail::result_of<F(T&)>::type;	// T& �� "&" �̕���
		�Evisit �ɑ΂��āAT���x�N�g���^�łȂ���΁A�n���Ȃ��悤�Ɏ����iSFINAE�j
		
		��2009/10/28
		�E�t�@�C�����쐬
		
																	����� 2009�N10��28�� 2��37��
																	�X�V�� 2009�N10��28�� 2��37��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_visit_hpp_
#define _kmt_ex_math_vec_extension_visit_hpp_


#include "../detail/include.hpp"
#include "../detail/result_of.hpp"
#include "../detail/enable_if.hpp"

#include "../type_traits/is_vec.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{


/**
	�x�N�g���^�ɑ΂��Ă̑�����s��
	
	�ȉ��̏�����F���������Ă���Ύg�p�\
	�P�D�֐����A�֐��I�u�W�F�N�g�ioperator()����`����Ă���N���X�j
	�Q�D�֐��I�u�W�F�N�g�̏ꍇ�́A�߂�l���`���Ă����K�v������
	�@�@result_type ���Atemplate<typename> struct result{ type };�̒�`
*/
template<
	typename T,
	typename F
>
typename detail::result_of<F(T&)>::type
visit(T& obj, F func, typename detail::enable_if<is_vec<T> >::type* = NULL){
	return func(obj);
};

template<
	typename T,
	typename F
>
typename detail::result_of<F(const T&)>::type
visit(const T& obj, F func, typename detail::enable_if<is_vec<T> >::type* = NULL){
	return func(obj);
};

template<
	typename T,
	typename F
>
typename detail::result_of<F(T&)>::type
operator |(T& obj, F func){
	return visit(obj, func);
};

template<
	typename T,
	typename F
>
typename detail::result_of<F(const T&)>::type
operator |(const T& obj, F func){
	return visit(obj, func);
};


}

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

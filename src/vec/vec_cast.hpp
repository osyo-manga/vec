/*##################################################################################################
	
	���C�ӂ̃x�N�g���^�փL���X�g���s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/11/12
		�E�t�@�C�����쐬
		
																	����� 2009�N11��12�� 3��2��
																	�X�V�� 2009�N11��12�� 3��2��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_vec_cast_hpp_
#define _kmt_ex_math_vec_vec_cast_hpp_


#include "detail/include.hpp"
#include "detail/static_assert.hpp"

#include "extension/initial_values.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

template<typename T>
struct has_ptr_or_ref{
	static const bool value = false;
};
template<typename T>
struct has_ptr_or_ref<T*>{
	static const bool value = true;
};
template<typename T>
struct has_ptr_or_ref<T&>{
	static const bool value = true;
};

/**
	���̃R�s�[�̏ꍇ�͂��������Ă΂��
*/
template<
	typename result_t,
	typename source_t
>
result_t
vec_cast(const source_t& source, typename detail::enable_if_c<!has_ptr_or_ref<result_t>::value>::type* = NULL){
	return initial_values(source);
}

/**
	�|�C���^�A�Q�Ƃ̏ꍇ�͂����炪�Ă΂��
*/
template<
	typename result_t,
	typename source_t
>
result_t
vec_cast(source_t source, typename detail::enable_if<has_ptr_or_ref<result_t> >::type* = NULL){
	// �T�C�Y���Ⴄ�ƃG���[
	KMT_EX_MATH_VEC_STATIC_ASSERT(sizeof(result_t) == sizeof(source_t), size_not_equal);
	return reinterpret_cast<result_t>(source);
}

}	// namespace detail{

using detail::vec_cast;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

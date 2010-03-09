/*##################################################################################################
	
	��vec �^���ǂ����̔��f���s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@#include "vec/vec.hpp"
	
	���X�V����
		��2009/11/16
		�ET::vec_value_type ����`����Ă���� value == true �ɂȂ�悤��
		�@������ǉ�
		
		��2009/10/21
		�E�t�@�C�����쐬
		
																	����� 2009�N10��21�� 18��17��
																	�X�V�� 2009�N10��21�� 18��17��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_type_traits_is_vec_hpp_
#define _kmt_ex_math_vec_type_traits_is_vec_hpp_


#include "../detail/include.hpp"
#include "../detail/has_vec_value_type.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

template<
	typename T,
	bool has_vec_value_type
>
struct is_vec_impl{
	static const bool value = has_vec_value_type;
};
template<
	typename T
>
struct is_vec_impl<T, false>{
	static const bool value = false;
};

/**
	vec::vec �p�̓��ꉻ
*/
template<
	unsigned int D,
	typename value_t
>
struct is_vec_impl< vec<D, value_t>, false>{
	static const bool value = true;
};

/**
	�x�N�g���^���ǂ����̔��f���s���܂�
	
	value == true	�x�N�g��
	value == false	�x�N�g������Ȃ�
	
	�ȉ��̏ꍇ�Ɏg�p���鎖���ł��܂��B
	
	�P�DT �� vec_value_type �������Ă���
	
		��j
		struct my_vec{
			typedef float vec_value_type;	// ���̖��O�̌^����`����Ă����
											// is_vec<T>::value == true �ɂȂ�
			vec_value_type x, y, z;
		};
	
	�Q�Dis_vec_impl �̓��ꉻ���s��
		KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC ���p�ӂ���Ă���̂�
		��������Q�Ƃ��Ă��������B
		
		vec/preprocessor/make_type_traits_is_vec.hpp
*/
template<
	typename T
>
struct is_vec{
	static const bool value = is_vec_impl<T, has_vec_value_type<T>::value>::value;
};

}		// namespace detail{

using detail::is_vec;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

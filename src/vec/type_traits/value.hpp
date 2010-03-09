/*##################################################################################################
	
	���x�N�g���̌^���̎擾���s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		��2009/11/16
		�ET::vec_value_type ����`����Ă���� value == vec_value_type �ɂȂ�悤��
		�@������ǉ�
		
		��2009/11/15
		�E���ꉻ���s���ĂȂ��ꍇ�́Atype == void �ɂȂ�悤�ɒǉ�
		
		��2009/10/29
		�ET*�AT&�Aconst T&�Aconst T* �ɑΉ�
		
		��2009/10/28
		�E�����N���X�Avalue_impl�@��
		�@��`����N���X�Avalue �ɕ���
		�ET �� const �������ꍇ�� const ��ǉ�����悤�ɏ�����ǉ�
		
		��2009/10/20
		�E�t�@�C�����쐬
		
																	����� 2009�N10��20�� 3��29��
																	�X�V�� 2009�N10��20�� 3��29��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_value_hpp_
#define _kmt_ex_math_vec_value_hpp_


#include "../detail/include.hpp"
#include "../detail/has_vec_value_type.hpp"
#include "../vec.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

/**
	value �̌^���̎擾���s��
*/
template<
	typename T,
	bool has_vec_value_type
>
struct value_impl{
	typedef void type;
};
template<
	typename T
>
struct value_impl<T, true>{
	typedef typename T::vec_value_type type;
};

template<
	unsigned int D,
	typename T
>
struct value_impl<vec<D, T>, false>{
	typedef T type;
};

template<
	typename T
>
struct value{
	typedef typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<T&>{
	typedef typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<T*>{
	typedef typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<const T>{
	typedef const typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<const T&>{
	typedef const typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<const T*>{
	typedef const typename value_impl<T, has_vec_value_type<T>::value>::type type;
};

}		// namespace detail{

using detail::value;


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

/*##################################################################################################
	
	���x�N�g���̎������̎擾���s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	#include "vec/vec.hpp"
	
	���X�V����
		��2009/11/15
		�ET���x�N�g���^�ȊO�̏ꍇ��-1��Ԃ��悤�ɒǉ�
		
		��2009/10/25
		�E���z�֐����������x�N�g���^�ɑΉ�
		
		��2009/10/23
		�E�t�@�C�����쐬
		
																	����� 2009�N10��23�� 22��51��
																	�X�V�� 2009�N10��23�� 22��51��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_type_traits_dimension_hpp_
#define _kmt_ex_math_vec_type_traits_dimension_hpp_


#include "../detail/include.hpp"
#include "value.hpp"
#include "is_vec.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{
	
	template<
		typename T
	>
	struct is_polymorphic{
		struct A : public T{};
		struct B : public T{
			virtual ~B(){};
		};
		static const bool value = (sizeof(A) == sizeof(B));
	};
	
	template<
		typename T,
		bool is_vec
	>
	struct dimension_impl{
		static const int value = -1;
	};
	
	template<
		typename T
	>
	struct dimension_impl<T, true>{
		
		template<
			typename T,
			bool is_polymorphic
		>
		struct size{
			static const int value = sizeof(T);
		};
		template<
			typename T
		>
		struct size<T, true>{
			struct vtable_size{ virtual ~vtable_size(); };
			static const int value = sizeof(T) - sizeof(vtable_size) ;
		};
		
		static const int value = size<T, is_polymorphic<T>::value>::value / sizeof(typename value<T>::type);
	};
}


/**
	�x�N�g���̎��������v�Z���܂��B
	
	�g�p����ׂɂ́Avec::value �� vec::is_vec �̓��ꉻ���s���K�v������܂��B
	
	�܂��AT�ɉ��z�֐����܂܂�Ă��Ă����Ȃ��v�Z����܂��B
	
	�� T ���x�N�g���^�łȂ��ꍇ�Avalue == -1 �ƂȂ�܂��B
*/
template<
	typename T
>
struct dimension{
	static const int value = 
		detail::dimension_impl<T, is_vec<T>::value>::value;
};


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

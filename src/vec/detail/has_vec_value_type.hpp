/*##################################################################################################
	
	���N���X�� vec_values_type �̌^�������Ă��邩�ǂ����̔�����s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/11/14
		�E�t�@�C�����쐬
		
																	����� 2009�N11��14�� 2��59��
																	�X�V�� 2009�N11��14�� 2��59��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_has_vec_value_type_hpp_
#define _kmt_ex_math_vec_has_vec_value_type_hpp_


#include "include.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{


template<
	typename T
>
struct has_vec_value_type{
	
	typedef struct{ char arr[2]; }	yes;
	typedef char					no;
	
	template<typename T>
	static yes test(typename T::vec_value_type*);
	
	template<typename T>
	static no test(...);
	
	static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

}		// namespace detail{


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

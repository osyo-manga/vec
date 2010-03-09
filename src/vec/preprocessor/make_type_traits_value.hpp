/*##################################################################################################
	
	��vec::value �̊ȈՐ������s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	#include "vec/type_traits/value.hpp"
	
	���X�V����
		
		��2009/10/28
		�Evalue -> value_impl �ɖ��O��ύX
		��2009/10/21
		�E�t�@�C�����쐬
		
																	����� 2009�N10��21�� 15��39��
																	�X�V�� 2009�N10��21�� 15��39��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_preprocessor_make_type_traits_value_hpp_
#define _kmt_ex_math_vec_preprocessor_make_type_traits_value_hpp_


#include "../detail/include.hpp"


/**
	vec::value �̃e���v���[�g�̓��ꉻ�̊ȈՐ������s��
	
	�������� namespace �ł������Ă���̂ŁA
	�@�O���[�o����Ԃł̒�`���s��
*/
#ifndef KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE

#define KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(class_t, value_t)	\
namespace kmt_ex{ namespace math{ namespace vec{					\
namespace detail{													\
																	\
template<>															\
struct value_impl<class_t, false>{									\
	typedef value_t type;											\
};																	\
																	\
}																	\
} } }			// namespace kmt_ex{ namespace math{ namespace vec{

#endif

#endif
//##########################################<< EOF >>###############################################

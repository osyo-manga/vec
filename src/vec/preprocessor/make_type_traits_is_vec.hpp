/*##################################################################################################
	
	��vec::is_vec �̊ȈՐ������s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	#include "vec/type_traits/is_vec.hpp"
	
	
	���X�V����
		��2009/10/23
		�E�}�N����`�̈������Ԉ���Ă����̂ŏC��
		
		��2009/10/21
		�E�t�@�C�����쐬
		
																	����� 2009�N10��21�� 15��39��
																	�X�V�� 2009�N10��21�� 15��39��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_preprocessor_make_type_traits_is_vec_hpp_
#define _kmt_ex_math_vec_preprocessor_make_type_traits_is_vec_hpp_


#include "../detail/include.hpp"


/**
	vec::value �̃e���v���[�g�̓��ꉻ�̊ȈՐ������s��
	
	struct my_vec{
		float x, y, z;
	};
	KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(my_vec);
	
	�������� namespace �ł������Ă���̂ŁA
	�@�O���[�o����Ԃł̒�`���s���K�v������
*/
#ifndef KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC

#define KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(class_t) \
namespace kmt_ex{ namespace math{ namespace vec{			\
namespace detail{											\
															\
template<>													\
struct is_vec_impl<class_t, false>{							\
	static const bool value = true;							\
};															\
															\
}															\
} } }			// namespace kmt_ex{ namespace math{ namespace vec{

#endif

#endif
//##########################################<< EOF >>###############################################

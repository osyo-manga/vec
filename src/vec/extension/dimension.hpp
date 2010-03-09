/*##################################################################################################
	
	���x�N�g���̎������̎擾���s���܂�
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/11/03
		�E�t�@�C�����쐬
		
																	����� 2009�N11��3�� 16��53��
																	�X�V�� 2009�N11��3�� 16��53��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_dimension_hpp_
#define _kmt_ex_math_vec_extension_dimension_hpp_


#include "../detail/include.hpp"
#include "visit.hpp"
#include "../type_traits/dimension.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

struct dimension_impl{
	
	typedef int result_type;
	
	template<
		typename T
	>
	result_type operator()(const T& t) const{
		return dimension<T>::value;
	}
};

/**
	�x�N�g���̎������̎擾����
	
	vec::dimension<T>�̃C���X�^���X��
	�g�p����ׂɂ́Avec::value �� vec::is_vec �̓��ꉻ���s���K�v������܂��B
*/
static const dimension_impl dimension_;

}

using extension::dimension_;


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

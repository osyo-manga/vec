/*##################################################################################################
	
	���x�N�g���̏��𕶎���ŕԂ��܂�
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/11/09
		�E�t�@�C�����쐬
		
																	����� 2009�N11��9�� 20��46��
																	�X�V�� 2009�N11��9�� 20��46��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_identities_hpp_
#define _kmt_ex_math_vec_extension_identities_hpp_

#include "../detail/include.hpp"

#include "at.hpp"
#include "dimension.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

struct identities_impl{
	
	typedef std::string result_type;
	
	template<
		typename T
	>
	result_type
	operator ()(T& v) const{
		std::ostringstream	oss;
		oss << "D:" << (v|dimension_) << " { ";
		for( int i = 0 ; i < dimension<T>::value ; i++ ){
			oss << (v|at(i)) << " ";
		}
		oss << "}";
		return oss.str();
	}
};

/**
	�x�N�g���̏��𕶎���ɂ��ĕԂ��܂�
*/
static const identities_impl identities;

}		// namespace extension{

using extension::identities;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

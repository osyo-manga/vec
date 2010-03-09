/*##################################################################################################
	
	���x�N�g���̗v�f�ւ̃A�N�Z�X���s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/10/29
		�E�t�@�C�����쐬
		
																	����� 2009�N10��29�� 7��40��
																	�X�V�� 2009�N10��29�� 7��40��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_at_hpp_
#define _kmt_ex_math_vec_extension_at_hpp_


#include "../detail/include.hpp"
#include "visit.hpp"
#include "pointer.hpp"
#include "../vec.hpp"
#include "../type_traits/value.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

/**
	�v�f�ɑ΂��āA�z��ł̃A�N�Z�X���s���܂��B
	�擪�|�C���^�́Avec::pointer �𗘗p���Ă���̂ŁA
	�g�p���邽�߂ɂ́Avec::pointer ���g�����Ԃɂ��Ă����K�v������܂��B
*/
struct at_impl{
	
	template<
		typename T
	>
	struct result{
		typedef typename value<T>::type& type;
	};
	
	at_impl(int index)
		: index(index){}
	
	template<
		typename T
	>
	typename result<T>::type
	operator ()(T& v) const{
		return (v|pointer)[index];
	}
private:
	int	index;
	
};

typedef at_impl	at;

}		// namespace extension{

using extension::at;

} } }		// namespace kmt_ex{ namespace math{ namespace vec{

#endif
//##########################################<< EOF >>###############################################

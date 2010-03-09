/*##################################################################################################
		
	�� enable_if �̒�`
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/10/28
		�E�t�@�C�����쐬
		
																	����� 2009�N10��28�� 2��49��
																	�X�V�� 2009�N10��28�� 2��49��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_detail_enable_if_hpp_
#define _kmt_ex_math_vec_detail_enable_if_hpp_


#include "include.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

/**
	enable_if �̃C�f�B�I���ɂ��Ă͉��L���Q�l��
	http://cpplover.blogspot.com/2008/01/boostenableif.html
*/
template<
	bool b,
	typename T = void
>
struct enable_if_c{
	typedef T type;
};

template<typename T>
struct enable_if_c<false, T>{};


template<
	typename Cond,
	typename T = void
>
struct enable_if
	: public enable_if_c<Cond::value, T>{};

}

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

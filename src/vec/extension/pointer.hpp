/*##################################################################################################
	
	���v�f�̌^�ɃL���X�g���s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/11/05
		�E�t�@�C�����쐬
		
																	����� 2009�N11��5�� 3��41��
																	�X�V�� 2009�N11��5�� 3��41��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extepsion_pointer_hpp_
#define _kmt_ex_math_vec_extepsion_pointer_hpp_


#include "../detail/include.hpp"

#include "visit.hpp"
#include "../type_traits/value.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

template<
	typename vec_t
>
struct pointer_impl{
	
	typedef vec_t vec_t;
	template<
		typename vec_t
	>
	struct result{
		typedef typename value<vec_t>::type* type;
	};
	
	typename result<vec_t>::type
	operator ()(vec_t& v) const{
		return reinterpret_cast<typename result<vec_t>::type>(&v);
	}
};

template<
	int D,
	typename T
>
struct pointer_impl< vec<D, T> >{
	
	typedef vec<D, T> vec_t;
	template<
		typename vec_t
	>
	struct result{
		typedef typename value<vec_t>::type* type;
	};
	
	typename result<vec_t>::type
	operator ()(vec_t& v) const{
		return v.value;
	}
	
};

struct pointer_t{
	
	template<
		typename vec_t
	>
	struct result{
		typedef typename value<vec_t>::type* type;
	};
	
	template<
		typename vec_t
	>
	typename result<vec_t>::type
	operator()(vec_t& v) const{
		return pointer_impl<vec_t>()(v);
	}
	
};

/**
	�v�f�̌^�ɃL���X�g���Ēl��Ԃ��B
	
	��j
	vec::vec<3, float> �^�Ȃ�΁A
	float* �Ƃ��āA�L���X�g���s��
	�܂��A�z��ɂ��A�N�Z�X���s���̂Łivec::at�����j
	�擪�|�C���^�ł��鎖��ۏႵ�Ȃ���΂Ȃ�܂���B
*/
static const pointer_t	pointer;

}		// namespace extension{

using extension::pointer;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

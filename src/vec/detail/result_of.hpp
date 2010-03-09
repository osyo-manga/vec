/*##################################################################################################
	
	��visit �Ŗ߂�l�𔻒肷��ׂ� result_of
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		��2009/10/28
		�EP0 �� const �������ꍇ�ɑΉ�
		
		��2009/10/26
		�E�t�@�C�����쐬
		
																	����� 2009�N10��26�� 4��10��
																	�X�V�� 2009�N10��26�� 4��10��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_detail_result_of_hpp_
#define _kmt_ex_math_vec_detail_result_of_hpp_


#include "include.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

template<
	typename T
>
struct has_result_class{
	
	typedef struct{ char arr[2]; }	yes;
	typedef char					no;
	
	template< typename C >
	static yes test(typename C::result<C>::type*);
	
	template< typename >
	static no test(...);
	
	static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

template<
	typename T
>
struct has_result_type{
	
	typedef struct{ char arr[2]; }	yes;
	typedef char					no;
	
	template< typename C >
	static yes test(typename C::result_type*);
	
	template< typename >
	static no test(...);
	
	static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

template<
	bool,
	typename then_,
	typename else_
>
struct if_{
	typedef then_ type;
};

template<
	typename then_,
	typename else_
>
struct if_<false, then_, else_>{
	typedef else_ type;
};

template<
	typename T,
	typename P0,
	bool has_result_t
>
struct result_of_impl{
	typedef typename T::result_type type;
};

template<
	typename T,
	typename P0
>
struct result_of_impl<T, P0, false>{
	typedef typename T::result<P0>::type type;
};

template<
	typename R,
	typename P0
>
struct result_of_impl<R (*)(P0), P0, false>{
	typedef R type;
};
template<
	typename R,
	typename P0
>
struct result_of_impl<R (*)(P0*), P0, false>{
	typedef R type;
};
template<
	typename R,
	typename P0
>
struct result_of_impl<R (*)(P0&), P0, false>{
	typedef R type;
};


/**
	visit �Ŏg�p����ׂ� result_of
	������1�̊֐��Ɗ֐��I�u�W�F�N�g�݂̂ɑΉ�
	           ~~~~~~~~~~~~~~~~~~~~~~
	�P�D�֐��Ȃ�Έ��������̂܂܎擾
	�Q�D�֐��I�u�W�F�N�g�Ȃ� T::result_type ���擾
	�R�D�Q�D���Ȃ���΁AT::result<P0>::type ���擾
	
	�ォ�珇�Ƀ`�F�b�N���s���Ă���
	��{�I�ȋ����� boost::result_of �Ɠ���
*/
template<typename T>
struct result_of;

template<
	typename R,
	typename P0
>
struct result_of<R(P0)>{
	typedef P0 type3;
	typedef typename result_of_impl<R, P0, has_result_type<R>::value>::type type;
};

}	// namespace detail{

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

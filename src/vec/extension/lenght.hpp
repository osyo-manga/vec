/*##################################################################################################
	
	���x�N�g���̒������v�Z���܂�
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/11/10
		�E�t�@�C�����쐬
		
																	����� 2009�N11��10�� 3��21��
																	�X�V�� 2009�N11��10�� 3��21��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_lenght_hpp_
#define _kmt_ex_math_vec_extension_lenght_hpp_


#include "../detail/include.hpp"

#include "visit.hpp"
#include "at.hpp"
#include "at_static.hpp"
#include "dimension.hpp"


namespace kmt_ex{ namespace math{ namespace vec{


namespace extension{

template<
	bool is_sqrt = true	// false �̏ꍇ�̓��[�g�v�Z���s���܂���
>
struct lenght_impl{
	
	template<
		typename T
	>
	struct result{
		typedef typename value<T>::type type;
	};
	
	template<
		typename T
	>
	typename result<T>::type
	operator ()(const T& v) const{
		return main(v, int2type<dimension<T>::value>(), int2type<is_sqrt>());
	}
	
private:
	
	template<int index> struct int2type{};
	
	// ���[�g�v�Z���s��
	template<
		typename T,
		int dimension
	>
	typename result<T>::type
	main(const T& v, int2type<dimension>, int2type<true>) const{
		return sqrt( sum(v, int2type<dimension>()) );
	}
	
	// ���[�g�v�Z���s��Ȃ�
	template<
		typename T,
		int dimension
	>
	typename result<T>::type
	main(const T& v, int2type<dimension>, int2type<false>) const{
		return sum(v, int2type<dimension>());
	}
	
	// ���[�g�v�Z���s�����v�l�̌v�Z
	template<
		typename T,
		int dimension
	>
	typename result<T>::type
	sum(const T& v, int2type<dimension>) const{
		typename result<T>::type	ret = 0.0f;
		for( int i = 0 ; i < (v|dimension_) ; i++ ){
			ret += ( (v|at(i)) * (v|at(i)) );
		}
		return ret;
	}
	
	// 2�����A3�����̏ꍇ�́A���[�v�ł͂Ȃ��A���ڌv�Z
	template<
		typename T
	>
	typename result<T>::type
	sum(const T& v, int2type<2>) const{
		return (v|at_static<0>()) * (v|at_static<0>())
			 + (v|at_static<1>()) * (v|at_static<1>());
	}
	template<
		typename T
	>
	typename result<T>::type
	sum(const T& v, int2type<3>) const{
		return (v|at_static<0>()) * (v|at_static<0>())
			 + (v|at_static<1>()) * (v|at_static<1>())
			 + (v|at_static<2>()) * (v|at_static<2>());
	}
};

/**
	�x�N�g���̒������v�Z���ĕԂ��܂��B
	
	�� lenght_non_sqrt �̓��[�g�v�Z���s���܂���
*/
static const lenght_impl<>		lenght;
static const lenght_impl<false>	lenght_non_sqrt;

}		// namespace extension{

using extension::lenght;
using extension::lenght_non_sqrt;


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

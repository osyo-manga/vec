/*##################################################################################################
	
	���x�N�g���̗v�f�̏��������s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/11/11
		�E�t�@�C�����쐬
		
																	����� 2009�N11��11�� 11��34��
																	�X�V�� 2009�N11��11�� 11��34��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_initial_values_hpp_
#define _kmt_ex_math_vec_extension_initial_values_hpp_


#include "../detail/include.hpp"

#include "copy.hpp"

namespace kmt_ex{ namespace math{ namespace vec{


namespace extension{

template<
	typename T
>
struct initial_values_impl{
	
	typedef void result_type;
	
	template<
		typename T
	>
	result_type
	operator ()(T& v){
		(v|copy(data, 16));
	}
	
	template<
		typename T
	>
	operator T(){
		T	v;
		v|copy(data, 16);
		return v;
	}
	
	initial_values_impl(
		const T  a0, const T  a1, const T  a2, const T  a3,
		const T  a4, const T  a5, const T  a6, const T  a7,
		const T  a8, const T  a9, const T a10, const T a11,
		const T a12, const T a13, const T a14, const T a15
	){
		data[ 0] =  a0; data[ 1] =  a1; data[ 2] =  a2; data[ 3] =  a3;
		data[ 4] =  a4; data[ 5] =  a5; data[ 6] =  a6; data[ 7] =  a7;
		data[ 8] =  a8; data[ 9] =  a9; data[10] = a10; data[11] = a11;
		data[12] = a12; data[13] = a13; data[14] = a14; data[15] = a15;
	}
	
	template<
		typename T
	>
	initial_values_impl(const T& v){
		memset(data, 0, sizeof(T) * 16);
		int	d = (dimension<T>::value < 16)
			? dimension<T>::value
			: 16;
		for( int i = 0 ; i < d ; i++ ){
			data[i] = (v|at(i));
		}
	}
	
private:
	T	data[16];
	
};

/**
	�x�N�g���̊e�v�f�ɑ΂��āA�l�̑�����s��
	�����݂́A16�̗v�f�܂őΉ�
*/
template<
	typename T
>
initial_values_impl<T>
initial_values(
	const T  a0,       const T  a1,       const T  a2 = T(), const T  a3 = T(),
	const T  a4 = T(), const T  a5 = T(), const T  a6 = T(), const T  a7 = T(),
	const T  a8 = T(), const T  a9 = T(), const T a10 = T(), const T a11 = T(),
	const T a12 = T(), const T a13 = T(), const T a14 = T(), const T a15 = T()
	){
	return initial_values_impl<T>(a0, a1, a2, a3, a4, a5, a6, a7,
								  a8, a9, a10, a11, a12, a13, a14, a15);
}

template<
	typename T
>
initial_values_impl<typename value<T>::type>
initial_values(const T& v, typename detail::enable_if<is_vec<T> >::type* = NULL){
	return initial_values_impl<typename value<T>::type>(v);
}

}		// namespace extension{

using extension::initial_values;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

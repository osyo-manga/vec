/*##################################################################################################
	
	���x�N�g���̗v�f�̃R�s�[���s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/11/10
		�E�t�@�C�����쐬
		
																	����� 2009�N11��10�� 1��29��
																	�X�V�� 2009�N11��10�� 1��29��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_copy_hpp_
#define _kmt_ex_math_vec_extension_copy_hpp_

#include "../detail/include.hpp"
#include "../detail/enable_if.hpp"

#include "at.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

template<
	typename source_t
>
struct copy_impl{
	
	typedef void result_type;
	
	copy_impl(const source_t& src, int size)
		: source(src)
		, size(size){}
	copy_impl(const copy_impl& src)
		: source(src.source)
		, size(src.size){}
	
	const copy_impl&
	operator =(const copy_impl rhs){
		source = rhs.source;
		return *this;
	}
	
	
	template<
		typename T
	>
	result_type
	operator ()(T& result) const{
		do_copy(result, source);
	}
	
private:
	const source_t& source;
	int	size;

	template<
		typename T
	>
	void do_copy(T& result, const T& source) const{
		memcpy( (result|pointer), (source|pointer), sizeof(T) );
	}
	
	
	template<
		typename T1,
		typename T2
	>
	struct is_same{
		static const bool value = false;
	};
	template<
		typename T
	>
	struct is_same<T, T>{
		static const bool value = true;
	};
	
	template<
		typename T1,
		typename T2
	>
	struct is_equal{
		static const bool value = (sizeof(T1) == sizeof(T2))
								&&(dimension<T1>::value == dimension<T2>::value)
								&&(is_same<value<T1>::type, value<T2>::type>::value);
	};
	
	template<
		typename T1,
		typename T2
	>
	void do_copy(T1& result, const T2& source, typename detail::enable_if<is_equal<T1, T2> >::type* = NULL) const{
		memcpy( (result|pointer), (source|pointer), sizeof(T1) );
	}
	
	template<
		typename T1,
		typename T2
	>
	void do_copy(T1& result, const T2& source, typename detail::enable_if_c<!is_equal<T1, T2>::value>::type* = NULL) const{
		int	d = (dimension<T1>::value < dimension<T2>::value)
				? dimension<T1>::value
				: dimension<T2>::value;
		for( int i = 0 ; i < d ; i++ ){
			(result|at(i)) = (source|at(i));
		}
	}
	
	template<
		typename T
	>
	void do_copy(T& result, typename const value<T>::type* source) const{
		int	d = (dimension<T>::value < size)
				? dimension<T>::value
				: size;
		for( int i = 0 ; i < d ; i++ ){
			(result|at(i)) = source[i];
		}
	}
};

/**
	�����̃x�N�g���̗v�f���R�s�[���܂��B
	�R�s�[���@�͈ȉ��̂Ƃ���
	
	�P�D�����x�N�g���^�̏ꍇ�A
		�������́A�x�N�g���^�̃T�C�Y�A�x�N�g���̗v�f�^�A�������������ꍇ
		memcpy �� vec::pointer ���g�p���āA�������P�ʂŃR�s�[
	
	�Q�D�P�D�ȊO�̏ꍇ�ŗ����Ƃ��x�N�g���^�̏ꍇ
		vec::at ���g�p���āA1���v�f�̃R�s�[���s���B
		�܂��A���������Ⴄ�ꍇ�ł��R�s�[�ł���B
		�i���ӂꂽ�������͂��̂܂܁j
	
	�R�D�R�s�[�Ώۂ��z��^�̏ꍇ
		vec::at ���g�p���āA1���v�f�̃R�s�[���s���B
		���̏ꍇ�́A�v�f����������ɓn���B
*/
template<
	typename source_t
>
copy_impl<source_t>
copy(const source_t& source, int size = 0){
	return copy_impl<source_t>(source, size);
}

}		// namespace extension{

using extension::copy;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

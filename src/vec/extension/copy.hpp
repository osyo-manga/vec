/*##################################################################################################
	
	★ベクトルの要素のコピーを行う
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/11/10
		・ファイルを作成
		
																	製作日 2009年11月10日 1時29分
																	更新日 2009年11月10日 1時29分
	横幅<100>、TAB<4>												製作者 小松大介
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
	引数のベクトルの要素をコピーします。
	コピー方法は以下のとおり
	
	１．同じベクトル型の場合、
		もしくは、ベクトル型のサイズ、ベクトルの要素型、次元数が同じ場合
		memcpy と vec::pointer を使用して、メモリ単位でコピー
	
	２．１．以外の場合で両方ともベクトル型の場合
		vec::at を使用して、1つずつ要素のコピーを行う。
		また、次元数が違う場合でもコピーできる。
		（あふれた次元数はそのまま）
	
	３．コピー対象が配列型の場合
		vec::at を使用して、1つずつ要素のコピーを行う。
		その場合は、要素数を第二引数に渡す。
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

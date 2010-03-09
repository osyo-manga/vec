/*##################################################################################################
	
	★vec 型かどうかの判断を行う
	
	★必要なヘッダーファイル
	　#include "vec/vec.hpp"
	
	★更新履歴
		●2009/11/16
		・T::vec_value_type が定義されていれば value == true になるように
		　処理を追加
		
		●2009/10/21
		・ファイルを作成
		
																	製作日 2009年10月21日 18時17分
																	更新日 2009年10月21日 18時17分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_type_traits_is_vec_hpp_
#define _kmt_ex_math_vec_type_traits_is_vec_hpp_


#include "../detail/include.hpp"
#include "../detail/has_vec_value_type.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

template<
	typename T,
	bool has_vec_value_type
>
struct is_vec_impl{
	static const bool value = has_vec_value_type;
};
template<
	typename T
>
struct is_vec_impl<T, false>{
	static const bool value = false;
};

/**
	vec::vec 用の特殊化
*/
template<
	unsigned int D,
	typename value_t
>
struct is_vec_impl< vec<D, value_t>, false>{
	static const bool value = true;
};

/**
	ベクトル型かどうかの判断を行います
	
	value == true	ベクトル
	value == false	ベクトルじゃない
	
	以下の場合に使用する事ができます。
	
	１．T が vec_value_type を持っている
	
		例）
		struct my_vec{
			typedef float vec_value_type;	// この名前の型が定義されていれば
											// is_vec<T>::value == true になる
			vec_value_type x, y, z;
		};
	
	２．is_vec_impl の特殊化を行う
		KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC が用意されているので
		そちらを参照してください。
		
		vec/preprocessor/make_type_traits_is_vec.hpp
*/
template<
	typename T
>
struct is_vec{
	static const bool value = is_vec_impl<T, has_vec_value_type<T>::value>::value;
};

}		// namespace detail{

using detail::is_vec;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

/*##################################################################################################
	
	★ベクトルの型情報の取得を行う
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		●2009/11/16
		・T::vec_value_type が定義されていれば value == vec_value_type になるように
		　処理を追加
		
		●2009/11/15
		・特殊化を行ってない場合は、type == void になるように追加
		
		●2009/10/29
		・T*、T&、const T&、const T* に対応
		
		●2009/10/28
		・実装クラス、value_impl　と
		　定義するクラス、value に分割
		・T が const だった場合に const を追加するように処理を追加
		
		●2009/10/20
		・ファイルを作成
		
																	製作日 2009年10月20日 3時29分
																	更新日 2009年10月20日 3時29分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_value_hpp_
#define _kmt_ex_math_vec_value_hpp_


#include "../detail/include.hpp"
#include "../detail/has_vec_value_type.hpp"
#include "../vec.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

/**
	value の型情報の取得を行う
*/
template<
	typename T,
	bool has_vec_value_type
>
struct value_impl{
	typedef void type;
};
template<
	typename T
>
struct value_impl<T, true>{
	typedef typename T::vec_value_type type;
};

template<
	unsigned int D,
	typename T
>
struct value_impl<vec<D, T>, false>{
	typedef T type;
};

template<
	typename T
>
struct value{
	typedef typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<T&>{
	typedef typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<T*>{
	typedef typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<const T>{
	typedef const typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<const T&>{
	typedef const typename value_impl<T, has_vec_value_type<T>::value>::type type;
};
template<
	typename T
>
struct value<const T*>{
	typedef const typename value_impl<T, has_vec_value_type<T>::value>::type type;
};

}		// namespace detail{

using detail::value;


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

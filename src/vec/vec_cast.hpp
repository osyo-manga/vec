/*##################################################################################################
	
	★任意のベクトル型へキャストを行う
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/11/12
		・ファイルを作成
		
																	製作日 2009年11月12日 3時2分
																	更新日 2009年11月12日 3時2分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_vec_cast_hpp_
#define _kmt_ex_math_vec_vec_cast_hpp_


#include "detail/include.hpp"
#include "detail/static_assert.hpp"

#include "extension/initial_values.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

template<typename T>
struct has_ptr_or_ref{
	static const bool value = false;
};
template<typename T>
struct has_ptr_or_ref<T*>{
	static const bool value = true;
};
template<typename T>
struct has_ptr_or_ref<T&>{
	static const bool value = true;
};

/**
	実体コピーの場合はこっちが呼ばれる
*/
template<
	typename result_t,
	typename source_t
>
result_t
vec_cast(const source_t& source, typename detail::enable_if_c<!has_ptr_or_ref<result_t>::value>::type* = NULL){
	return initial_values(source);
}

/**
	ポインタ、参照の場合はこちらが呼ばれる
*/
template<
	typename result_t,
	typename source_t
>
result_t
vec_cast(source_t source, typename detail::enable_if<has_ptr_or_ref<result_t> >::type* = NULL){
	// サイズが違うとエラー
	KMT_EX_MATH_VEC_STATIC_ASSERT(sizeof(result_t) == sizeof(source_t), size_not_equal);
	return reinterpret_cast<result_t>(source);
}

}	// namespace detail{

using detail::vec_cast;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

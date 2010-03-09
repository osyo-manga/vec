/*##################################################################################################
	
	★ベクトルに対して操作を行う拡張オブジェクトの接続を行う
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/10/29
		・result_of に & を付加して渡すように変更
		detail::result_of<F(T&)>::type;	// T& の "&" の部分
		・visit に対して、Tがベクトル型でなければ、渡せないように実装（SFINAE）
		
		●2009/10/28
		・ファイルを作成
		
																	製作日 2009年10月28日 2時37分
																	更新日 2009年10月28日 2時37分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_visit_hpp_
#define _kmt_ex_math_vec_extension_visit_hpp_


#include "../detail/include.hpp"
#include "../detail/result_of.hpp"
#include "../detail/enable_if.hpp"

#include "../type_traits/is_vec.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{


/**
	ベクトル型に対しての操作を行う
	
	以下の条件をFが満たしていれば使用可能
	１．関数か、関数オブジェクト（operator()が定義されているクラス）
	２．関数オブジェクトの場合は、戻り値を定義しておく必要がある
	　　result_type か、template<typename> struct result{ type };の定義
*/
template<
	typename T,
	typename F
>
typename detail::result_of<F(T&)>::type
visit(T& obj, F func, typename detail::enable_if<is_vec<T> >::type* = NULL){
	return func(obj);
};

template<
	typename T,
	typename F
>
typename detail::result_of<F(const T&)>::type
visit(const T& obj, F func, typename detail::enable_if<is_vec<T> >::type* = NULL){
	return func(obj);
};

template<
	typename T,
	typename F
>
typename detail::result_of<F(T&)>::type
operator |(T& obj, F func){
	return visit(obj, func);
};

template<
	typename T,
	typename F
>
typename detail::result_of<F(const T&)>::type
operator |(const T& obj, F func){
	return visit(obj, func);
};


}

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

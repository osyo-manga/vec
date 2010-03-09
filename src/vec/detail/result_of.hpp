/*##################################################################################################
	
	★visit で戻り値を判定する為の result_of
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		●2009/10/28
		・P0 が const だった場合に対応
		
		●2009/10/26
		・ファイルを作成
		
																	製作日 2009年10月26日 4時10分
																	更新日 2009年10月26日 4時10分
	横幅<100>、TAB<4>												製作者 小松大介
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
	visit で使用する為の result_of
	引数が1つの関数と関数オブジェクトのみに対応
	           ~~~~~~~~~~~~~~~~~~~~~~
	１．関数ならば引数をそのまま取得
	２．関数オブジェクトなら T::result_type を取得
	３．２．がなければ、T::result<P0>::type を取得
	
	上から順にチェックを行っていく
	基本的な挙動は boost::result_of と同じ
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

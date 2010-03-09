//##################################################################################################
//		
//		■ コンパイル時にエラーを出力するチェッカー
//		
//		基底クラス：なし
//		名前空間　：なし
//																	製作日 2009年1月20日 12時41分
//																	更新日 2009年1月20日 12時41分
//	横幅<100>、TAB<4>												製作者 小松大介
//==================================================================================================

#ifndef _kmt_ex_math_vec_static_assert_hpp_
#define _kmt_ex_math_vec_static_assert_hpp_


//======================================
// 定義
//======================================


/**
	名前空間
*/
namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

template<
	bool
>
struct CompileTimeChecker{
	typedef int Result;
};

template<>
struct CompileTimeChecker<false>{
	typedef int& Result;
};

}

/**
	コンパイル時にエラーを出力するマクロ
	
	expr が false ならば
	ERROR_##msgと出力してコンパイルエラーになる
	
	URL:http://naknet.jpn.ph/blog/sb.cgi?day=20050321
*/
#define KMT_EX_MATH_VEC_STATIC_ASSERT(expr, msg){	\
	typedef detail::CompileTimeChecker<(expr) != 0 >::Result* ERROR_##msg;	\
}	\

} } }			// namespace kmt{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

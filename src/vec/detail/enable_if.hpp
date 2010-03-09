/*##################################################################################################
		
	★ enable_if の定義
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/10/28
		・ファイルを作成
		
																	製作日 2009年10月28日 2時49分
																	更新日 2009年10月28日 2時49分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_detail_enable_if_hpp_
#define _kmt_ex_math_vec_detail_enable_if_hpp_


#include "include.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

/**
	enable_if のイディオムについては下記を参考に
	http://cpplover.blogspot.com/2008/01/boostenableif.html
*/
template<
	bool b,
	typename T = void
>
struct enable_if_c{
	typedef T type;
};

template<typename T>
struct enable_if_c<false, T>{};


template<
	typename Cond,
	typename T = void
>
struct enable_if
	: public enable_if_c<Cond::value, T>{};

}

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

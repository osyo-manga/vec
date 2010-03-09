/*##################################################################################################
	
	★ベクトルの次元数の取得を行います
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/11/03
		・ファイルを作成
		
																	製作日 2009年11月3日 16時53分
																	更新日 2009年11月3日 16時53分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_dimension_hpp_
#define _kmt_ex_math_vec_extension_dimension_hpp_


#include "../detail/include.hpp"
#include "visit.hpp"
#include "../type_traits/dimension.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

struct dimension_impl{
	
	typedef int result_type;
	
	template<
		typename T
	>
	result_type operator()(const T& t) const{
		return dimension<T>::value;
	}
};

/**
	ベクトルの次元数の取得する
	
	vec::dimension<T>のインスタンス版
	使用する為には、vec::value と vec::is_vec の特殊化を行う必要があります。
*/
static const dimension_impl dimension_;

}

using extension::dimension_;


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

/*##################################################################################################
	
	★ベクトルの情報を文字列で返します
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/11/09
		・ファイルを作成
		
																	製作日 2009年11月9日 20時46分
																	更新日 2009年11月9日 20時46分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_identities_hpp_
#define _kmt_ex_math_vec_extension_identities_hpp_

#include "../detail/include.hpp"

#include "at.hpp"
#include "dimension.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

struct identities_impl{
	
	typedef std::string result_type;
	
	template<
		typename T
	>
	result_type
	operator ()(T& v) const{
		std::ostringstream	oss;
		oss << "D:" << (v|dimension_) << " { ";
		for( int i = 0 ; i < dimension<T>::value ; i++ ){
			oss << (v|at(i)) << " ";
		}
		oss << "}";
		return oss.str();
	}
};

/**
	ベクトルの情報を文字列にして返します
*/
static const identities_impl identities;

}		// namespace extension{

using extension::identities;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

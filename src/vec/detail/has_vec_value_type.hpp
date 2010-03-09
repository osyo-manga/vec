/*##################################################################################################
	
	★クラスが vec_values_type の型を持っているかどうかの判定を行う
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/11/14
		・ファイルを作成
		
																	製作日 2009年11月14日 2時59分
																	更新日 2009年11月14日 2時59分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_has_vec_value_type_hpp_
#define _kmt_ex_math_vec_has_vec_value_type_hpp_


#include "include.hpp"

namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{


template<
	typename T
>
struct has_vec_value_type{
	
	typedef struct{ char arr[2]; }	yes;
	typedef char					no;
	
	template<typename T>
	static yes test(typename T::vec_value_type*);
	
	template<typename T>
	static no test(...);
	
	static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

}		// namespace detail{


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

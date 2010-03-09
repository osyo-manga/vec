/*##################################################################################################
	
	★vec::value の簡易生成を行う
	
	★必要なヘッダーファイル
	#include "vec/type_traits/value.hpp"
	
	★更新履歴
		
		●2009/10/28
		・value -> value_impl に名前を変更
		●2009/10/21
		・ファイルを作成
		
																	製作日 2009年10月21日 15時39分
																	更新日 2009年10月21日 15時39分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_preprocessor_make_type_traits_value_hpp_
#define _kmt_ex_math_vec_preprocessor_make_type_traits_value_hpp_


#include "../detail/include.hpp"


/**
	vec::value のテンプレートの特殊化の簡易生成を行う
	
	※内部で namespace でくくっているので、
	　グローバル空間での定義を行う
*/
#ifndef KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE

#define KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(class_t, value_t)	\
namespace kmt_ex{ namespace math{ namespace vec{					\
namespace detail{													\
																	\
template<>															\
struct value_impl<class_t, false>{									\
	typedef value_t type;											\
};																	\
																	\
}																	\
} } }			// namespace kmt_ex{ namespace math{ namespace vec{

#endif

#endif
//##########################################<< EOF >>###############################################

/*##################################################################################################
	
	★vec::is_vec の簡易生成を行う
	
	★必要なヘッダーファイル
	#include "vec/type_traits/is_vec.hpp"
	
	
	★更新履歴
		●2009/10/23
		・マクロ定義の引数が間違っていたので修正
		
		●2009/10/21
		・ファイルを作成
		
																	製作日 2009年10月21日 15時39分
																	更新日 2009年10月21日 15時39分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_preprocessor_make_type_traits_is_vec_hpp_
#define _kmt_ex_math_vec_preprocessor_make_type_traits_is_vec_hpp_


#include "../detail/include.hpp"


/**
	vec::value のテンプレートの特殊化の簡易生成を行う
	
	struct my_vec{
		float x, y, z;
	};
	KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(my_vec);
	
	※内部で namespace でくくっているので、
	　グローバル空間での定義を行う必要がある
*/
#ifndef KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC

#define KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(class_t) \
namespace kmt_ex{ namespace math{ namespace vec{			\
namespace detail{											\
															\
template<>													\
struct is_vec_impl<class_t, false>{							\
	static const bool value = true;							\
};															\
															\
}															\
} } }			// namespace kmt_ex{ namespace math{ namespace vec{

#endif

#endif
//##########################################<< EOF >>###############################################

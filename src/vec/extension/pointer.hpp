/*##################################################################################################
	
	★要素の型にキャストを行う
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/11/05
		・ファイルを作成
		
																	製作日 2009年11月5日 3時41分
																	更新日 2009年11月5日 3時41分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extepsion_pointer_hpp_
#define _kmt_ex_math_vec_extepsion_pointer_hpp_


#include "../detail/include.hpp"

#include "visit.hpp"
#include "../type_traits/value.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

template<
	typename vec_t
>
struct pointer_impl{
	
	typedef vec_t vec_t;
	template<
		typename vec_t
	>
	struct result{
		typedef typename value<vec_t>::type* type;
	};
	
	typename result<vec_t>::type
	operator ()(vec_t& v) const{
		return reinterpret_cast<typename result<vec_t>::type>(&v);
	}
};

template<
	int D,
	typename T
>
struct pointer_impl< vec<D, T> >{
	
	typedef vec<D, T> vec_t;
	template<
		typename vec_t
	>
	struct result{
		typedef typename value<vec_t>::type* type;
	};
	
	typename result<vec_t>::type
	operator ()(vec_t& v) const{
		return v.value;
	}
	
};

struct pointer_t{
	
	template<
		typename vec_t
	>
	struct result{
		typedef typename value<vec_t>::type* type;
	};
	
	template<
		typename vec_t
	>
	typename result<vec_t>::type
	operator()(vec_t& v) const{
		return pointer_impl<vec_t>()(v);
	}
	
};

/**
	要素の型にキャストして値を返す。
	
	例）
	vec::vec<3, float> 型ならば、
	float* として、キャストを行う
	また、配列によるアクセスを行うので（vec::at等が）
	先頭ポインタである事を保障しなければなりません。
*/
static const pointer_t	pointer;

}		// namespace extension{

using extension::pointer;

} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

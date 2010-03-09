/*##################################################################################################
	
	★ベクトルの長さを計算します
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/11/10
		・ファイルを作成
		
																	製作日 2009年11月10日 3時21分
																	更新日 2009年11月10日 3時21分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_lenght_hpp_
#define _kmt_ex_math_vec_extension_lenght_hpp_


#include "../detail/include.hpp"

#include "visit.hpp"
#include "at.hpp"
#include "at_static.hpp"
#include "dimension.hpp"


namespace kmt_ex{ namespace math{ namespace vec{


namespace extension{

template<
	bool is_sqrt = true	// false の場合はルート計算を行いません
>
struct lenght_impl{
	
	template<
		typename T
	>
	struct result{
		typedef typename value<T>::type type;
	};
	
	template<
		typename T
	>
	typename result<T>::type
	operator ()(const T& v) const{
		return main(v, int2type<dimension<T>::value>(), int2type<is_sqrt>());
	}
	
private:
	
	template<int index> struct int2type{};
	
	// ルート計算を行う
	template<
		typename T,
		int dimension
	>
	typename result<T>::type
	main(const T& v, int2type<dimension>, int2type<true>) const{
		return sqrt( sum(v, int2type<dimension>()) );
	}
	
	// ルート計算を行わない
	template<
		typename T,
		int dimension
	>
	typename result<T>::type
	main(const T& v, int2type<dimension>, int2type<false>) const{
		return sum(v, int2type<dimension>());
	}
	
	// ルート計算を行う合計値の計算
	template<
		typename T,
		int dimension
	>
	typename result<T>::type
	sum(const T& v, int2type<dimension>) const{
		typename result<T>::type	ret = 0.0f;
		for( int i = 0 ; i < (v|dimension_) ; i++ ){
			ret += ( (v|at(i)) * (v|at(i)) );
		}
		return ret;
	}
	
	// 2次元、3次元の場合は、ループではなく、直接計算
	template<
		typename T
	>
	typename result<T>::type
	sum(const T& v, int2type<2>) const{
		return (v|at_static<0>()) * (v|at_static<0>())
			 + (v|at_static<1>()) * (v|at_static<1>());
	}
	template<
		typename T
	>
	typename result<T>::type
	sum(const T& v, int2type<3>) const{
		return (v|at_static<0>()) * (v|at_static<0>())
			 + (v|at_static<1>()) * (v|at_static<1>())
			 + (v|at_static<2>()) * (v|at_static<2>());
	}
};

/**
	ベクトルの長さを計算して返します。
	
	※ lenght_non_sqrt はルート計算を行いません
*/
static const lenght_impl<>		lenght;
static const lenght_impl<false>	lenght_non_sqrt;

}		// namespace extension{

using extension::lenght;
using extension::lenght_non_sqrt;


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

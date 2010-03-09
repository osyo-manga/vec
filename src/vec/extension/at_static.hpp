/*##################################################################################################
	
	★要素に対して静的にアクセスを行う
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/11/09
		・ファイルを作成
		
																	製作日 2009年11月9日 14時6分
																	更新日 2009年11月9日 14時6分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_at_static_hpp_
#define _kmt_ex_math_vec_extension_at_static_hpp_


#include "../detail/include.hpp"
#include "../vec.hpp"
#include "visit.hpp"
#include "at.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

template<
	typename T,
	int index
>
struct at_static_impl{
	
	template<
		typename T
	>
	struct result{
		typedef typename value<T>::type& type;
	};
	
	template<
		typename T
	>
	typename result<T>::type
	operator ()(T& v) const{
		return (v|at(index));
	}
};


/**
	各要素に対して、静的にアクセスを行う
	
	内部では、vec::at を使用して要素に対し、アクセスを行っている。
	
	また、at(0) が、x要素へのアクセスでない場合は、
	at_static_impl のクラステンプレートの特殊化を行う事により、
	各要素へのアクセスを実装する事が出来る。
	
	例）
	struct my_vec{
		float	z, y, x;	// 配列順が違う
	};
	
	// こんな感じで特殊化を行う
	template<>
	struct at_static_impl<0, my_vec>{	// '0'とは、at_static<0>の'0'である
		
		template<
			typename T
		>
		struct result{
			typedef typename value<T>::type& type;
		};
		
		template<
			typename T
		>
		typename result<T>::type
		operator ()(T& v) const{
			return v.x;	// at_static<0>が呼ばれたときに x の要素を返す
		}
	};
	
*/
template<
	int index
>
struct at_static{
	
	template<
		typename T
	>
	struct result{
		typedef typename value<T>::type& type;
	};
	
	template<
		typename T
	>
	typename result<const T>::type
	operator ()(const T& v) const{
		return at_static_impl<T, index>()(v);
	}
	template<
		typename T
	>
	typename result<T>::type
	operator ()(T& v) const{
		return at_static_impl<T, index>()(v);
	}
	
};

static const at_static<0>	at_x;	// x 要素へアクセス
static const at_static<1>	at_y;	// y 要素へアクセス
static const at_static<2>	at_z;	// z 要素へアクセス
static const at_static<3>	at_w;	// w 要素へアクセス

}		// namespace extension{

using extension::at_static;
using extension::at_x;
using extension::at_y;
using extension::at_z;
using extension::at_w;


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

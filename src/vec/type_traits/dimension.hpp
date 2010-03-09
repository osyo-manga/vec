/*##################################################################################################
	
	★ベクトルの次元数の取得を行う
	
	★必要なヘッダーファイル
	#include "vec/vec.hpp"
	
	★更新履歴
		●2009/11/15
		・Tがベクトル型以外の場合に-1を返すように追加
		
		●2009/10/25
		・仮想関数を持ったベクトル型に対応
		
		●2009/10/23
		・ファイルを作成
		
																	製作日 2009年10月23日 22時51分
																	更新日 2009年10月23日 22時51分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_type_traits_dimension_hpp_
#define _kmt_ex_math_vec_type_traits_dimension_hpp_


#include "../detail/include.hpp"
#include "value.hpp"
#include "is_vec.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{
	
	template<
		typename T
	>
	struct is_polymorphic{
		struct A : public T{};
		struct B : public T{
			virtual ~B(){};
		};
		static const bool value = (sizeof(A) == sizeof(B));
	};
	
	template<
		typename T,
		bool is_vec
	>
	struct dimension_impl{
		static const int value = -1;
	};
	
	template<
		typename T
	>
	struct dimension_impl<T, true>{
		
		template<
			typename T,
			bool is_polymorphic
		>
		struct size{
			static const int value = sizeof(T);
		};
		template<
			typename T
		>
		struct size<T, true>{
			struct vtable_size{ virtual ~vtable_size(); };
			static const int value = sizeof(T) - sizeof(vtable_size) ;
		};
		
		static const int value = size<T, is_polymorphic<T>::value>::value / sizeof(typename value<T>::type);
	};
}


/**
	ベクトルの次元数を計算します。
	
	使用する為には、vec::value と vec::is_vec の特殊化を行う必要があります。
	
	また、Tに仮想関数が含まれていても問題なく計算されます。
	
	※ T がベクトル型でない場合、value == -1 となります。
*/
template<
	typename T
>
struct dimension{
	static const int value = 
		detail::dimension_impl<T, is_vec<T>::value>::value;
};


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

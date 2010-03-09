#include <iostream>

#include "sample.h"

#include <d3d9.h>
#include <math.h>

#include "vec/vec.hpp"
#include "vec/type_traits/dimension.hpp"

#include "vec/extension/visit.hpp"
#include "vec/extension/dimension.hpp"
#include "vec/extension/pointer.hpp"
#include "vec/extension/identities.hpp"
#include "vec/extension/at.hpp"
#include "vec/extension/lenght.hpp"
#include "vec/extension/copy.hpp"
#include "vec/extension/initial_values.hpp"

#include "vec/type_traits/value.hpp"
#include "vec/type_traits/dimension.hpp"

#include "vec/preprocessor/make_type_traits_value.hpp"
#include "vec/preprocessor/make_type_traits_is_vec.hpp"

#include "vec/vec_cast.hpp"

/**
	独自のベクトル型の場合は特殊化を行って下準備する
	D3DVECTOR の特殊化
*/
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(D3DVECTOR, float);
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(D3DVECTOR);


int
main(){
	
#if	0
	
	vec::sample::test_main();	// 個別に機能を動かす際のテスタ
	
#else
	
	/**
		各機能を列挙
		
		各機能の扱いは、以下の様な仕様になっている
		
		<ベクトルの実体> | <ベクトルに対する操作>
		"operator | "を使用してベクトルの実体に対して操作を行う
	*/
	namespace vec = kmt_ex::math::vec;
	
	
	// ベクトルの実体を作成
	vec::vec<3, float>	f_v3;	// float 型の3次元ベクトル
	vec::vec<4, double>	d_v4;	// double 型の4次元ベクトル
	D3DVECTOR			d3d_v;	// DirectXのベクトル
	
	
	// ベクトルの要素の初期化
	f_v3|vec::initial_values(4.0f, 3.0f, 1.0f);
	d_v4|vec::initial_values(-4.0, -2.5, 0.214, 1.0);
	d3d_v|vec::initial_values(1.4f, 0.54f, 4.4f);	// DirectXのベクトル型でもできる
	
	
	// ベクトルの要素を出力
	std::cout << "f_v3:"  << (f_v3|vec::identities) << "\n";
	std::cout << "d_v4:"  << (d_v4|vec::identities) << "\n";
	std::cout << "d3d_v:" << (d3d_v|vec::identities) << "\n";
	
	
	// ベクトルの要素を変更
	f_v3|vec::at_x = 1.0f;
	d_v4|vec::at_w = 0.0;
	d3d_v|vec::at_y = 2.0;
	
	
	// ベクトルの次元数を取得する
	int d = (f_v3|vec::dimension_);	// 最後の'_'に注意
	
	
	// ベクトルの各要素に対してループでアクセス
	for( int i = 0 ; i < (f_v3|vec::dimension_) ; i++ ){
		( f_v3|vec::at(i) ) = 0.0f;
	}
	
	// ベクトルの要素をコピー
	f_v3|vec::copy(d3d_v);
	
	
	// 配列をコピー
	float	v[3] = {3.0f, 2.0f, 1.0f};
	f_v3|vec::copy(v, 3);
	
	
	// 違うベクトル型にキャストする
	d3d_v = vec::vec_cast<D3DVECTOR>(f_v3);
	
	
	// ベクトルの長さを返す（※配列の長さではない）
	float	len = (f_v3|vec::lenght);
	
	
#endif
	
	getchar();
	return 0;
}



#include <iostream>
#include <assert.h>

#include <d3d9.h>

#include "vec/vec.hpp"
#include "vec/extension/copy.hpp"

#include "vec/extension/identities.hpp"

#include "vec/preprocessor/make_type_traits_value.hpp"
#include "vec/preprocessor/make_type_traits_is_vec.hpp"


/**
	D3DVECTOR の特殊化
*/
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(D3DVECTOR, float);
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(D3DVECTOR);


namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
copy_main(){
	
	using namespace vec;
	
	D3DVECTOR	dxVec;
	(dxVec|at(0)) = 57.0f;
	(dxVec|at(1)) = 0.3245f;
	(dxVec|at(2)) = -5.04f;
	std::cout << (dxVec|identities) << "\n";
	
	vec::vec<3, float>	v;
	v|copy(dxVec);
	std::cout << (v|identities) << "\n";	// dxVec と同じ
	
	
	// 次元数が違う場合でもコピーできる
	vec::vec<4, float>	v2;
	v2|copy(v);
	std::cout << (v2|identities) << "\n";	// 4つ目の要素のみ初期化時のまま
	
	
	// 配列をコピー
	vec::vec<3, float>	v3;
	float	v4[3] = {3.0f, 2.0f, 1.0f};
	v3|copy(v4, 3);
	std::cout << (v3|identities) << "\n";
	
}

}; };

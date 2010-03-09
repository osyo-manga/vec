#include <iostream>
#include <d3d9.h>

#include "vec/vec.hpp"
#include "vec/type_traits/dimension.hpp"
#include "vec/extension/dimension.hpp"

#include "vec/preprocessor/make_type_traits_value.hpp"
#include "vec/preprocessor/make_type_traits_is_vec.hpp"


/**
	D3DVECTOR の特殊化
*/
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(D3DVECTOR, float);
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(D3DVECTOR);

/**
	自前ベクトル型
*/
struct my_vec{
	float x, y, z, w;
	virtual ~my_vec(){}
};
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(my_vec, float);
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(my_vec);

#include "vec/preprocessor/undef_make_type_traits_value.hpp"	// #undef
#include "vec/preprocessor/undef_make_type_traits_is_vec.hpp"	// #undef


namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

typedef vec::vec<3, float>	vec3;

void
dimension_main(){
	
	/**
		型から次元数の取得
	*/
	std::cout << vec::dimension<vec3>::value << "\n";		// 3
	std::cout << vec::dimension<D3DVECTOR>::value << "\n";	// 3
	std::cout << vec::dimension<my_vec>::value << "\n";		// 4
	
	
	/**
		インスタンスから次元数の取得を行う
	*/
	using vec::dimension_;
	
	vec3	v;
	std::cout << (v|dimension_) << "\n";		// 3
	
	D3DVECTOR	vD3D;
	std::cout << (vD3D|dimension_) << "\n";		// 3
	
	my_vec	my_v;
	std::cout << (my_v|dimension_) << "\n";		// 4
	
}

} }

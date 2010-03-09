#include <iostream>
#include <d3d9.h>

#include "vec/vec.hpp"
#include "vec/type_traits/is_vec.hpp"
#include "vec/preprocessor/make_type_traits_is_vec.hpp"

/**
	D3DVECTOR ‚Ì“ÁŽê‰»
*/
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(D3DVECTOR);

#include "vec/preprocessor/undef_make_type_traits_is_vec.hpp"

namespace vec{ namespace sample{


namespace vec = kmt_ex::math::vec;

void
make_type_traits_is_vec_main(){
	
	typedef vec::vec<3, float>	vec3;
	std::cout << vec::is_vec<vec3>::value      << "\n";	// 1
	std::cout << vec::is_vec<D3DVECTOR>::value << "\n";	// 1
	std::cout << vec::is_vec<int>::value       << "\n";	// 0
	
}

}; };

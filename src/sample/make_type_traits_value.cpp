#include <iostream>
#include <d3d9.h>

#include "vec/type_traits/value.hpp"
#include "vec/preprocessor/make_type_traits_value.hpp"

/**
	D3DVECTOR の特殊化
*/
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(D3DVECTOR, float);

/**
	自前ベクトル
*/
struct my_vec{
	double x, y, z;
};
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(my_vec, double);

#include "vec/preprocessor/undef_make_type_traits_value.hpp"	// #undef

namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
make_type_traits_value_main(){
	
	std::cout << typeid(vec::value<D3DVECTOR>::type).name() << "\n";	// float
	std::cout << typeid(vec::value<my_vec>::type).name()     << "\n";	// double
	
}

}; };

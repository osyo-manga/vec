#include <iostream>

#include "vec/vec.hpp"
#include "vec/vec_cast.hpp"

#include "vec/extension/identities.hpp"

#include "vec/vec_cast.hpp"

namespace {

struct my_vec{
	typedef float vec_value_type;
	vec_value_type x, y, z;
};

}


namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
vec_cast_main(){
	
	using namespace vec;
	
	vec::vec<3, float>	v = initial_values(2.2f, 3.3f, 1.0f);
	std::cout << (v|identities) << "\n";
	
	// 任意のベクトル型にキャストする
	my_vec v2 = vec_cast<my_vec>(v);
	std::cout << (dimension<my_vec>::value) << "\n";
	
	// ポインタでキャストする
	
	
}

}; };

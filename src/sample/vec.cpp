#include <iostream>

#include "vec/vec.hpp"

namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
vec_main(){
	
	vec::vec<3, float>	v;
	
	v.value[0] = 0.0;
	v.value[1] = 0.034f;
	v.value[2] = -9.095f;
	
	std::cout << v.dimension << "ŽŸŒ³" << "\n";
	std::cout << v.value[0] << "\n";
	std::cout << v.value[1] << "\n";
	std::cout << v.value[2] << "\n";
	
}

}; };

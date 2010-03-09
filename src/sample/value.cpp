#include <iostream>

#include "vec/vec.hpp"
#include "vec/type_traits/value.hpp"

struct my_vec{
	typedef int vec_value_type;
	vec_value_type x, y, z;
};

namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
value_main(){
	
	typedef vec::vec<3, float>	vec_float;
	typedef vec::vec<3, double>	vec_double;
	
	std::cout << typeid(vec::value<vec_float>::type).name() << "\n";	// float
	std::cout << typeid(vec::value<vec_double>::type).name() << "\n";	// double
	
	std::cout << typeid(vec::value<my_vec>::type).name() << "\n";		// int
	
}

}; };

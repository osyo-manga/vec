#include <iostream>

#include "vec/vec.hpp"
#include "vec/type_traits/is_vec.hpp"

struct my_vec{
	typedef float	vec_value_type;
	vec_value_type	x, y, z;
};

namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;
typedef vec::vec<3, float>	vec3;

void
is_vec_main(){
	
	std::cout << vec::is_vec<vec3>::value << "\n";	// 1
	std::cout << vec::is_vec<int>::value << "\n";	// 0
	
	// vec_value_type ‚ª’è‹`‚³‚ê‚Ä‚¢‚é‚Ì‚Å true
	std::cout << vec::is_vec<my_vec>::value << "\n";
}

}; };

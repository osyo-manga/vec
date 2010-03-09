#include <iostream>

#include "vec/vec.hpp"
#include "vec/extension/identities.hpp"

namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
identities_main(){
	
	using namespace vec;
	
	vec::vec<3, float>	v;
	(v|at(0)) = 0.5f;
	(v|at(1)) = 1.5f;
	(v|at(2)) = 2.5f;
	
	std::cout << (v|identities) << "\n";
	
}

}; };

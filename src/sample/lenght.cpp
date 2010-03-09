#include <iostream>

#include "vec/vec.hpp"
#include "vec/extension/lenght.hpp"
#include "vec/extension/identities.hpp"

namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
lenght_main(){
	
	using namespace vec;
	
	vec::vec<3>	v;
	(v|at(0)) = 1.0f;
	(v|at(1)) = 1.0f;
	(v|at(2)) = 0.0f;
	
	std::cout << (v|identities) << "\n";
	std::cout << (v|lenght) << "\n";			// ベクトルの長さを計算
	std::cout << (v|lenght_non_sqrt) << "\n";	// ルート計算なし
	
}

}; };

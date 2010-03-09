#include <iostream>

#include "vec/vec.hpp"
#include "vec/extension/initial_values.hpp"

#include "vec/extension/identities.hpp"

namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
initial_values_main(){
	
	using namespace vec;
	
	// ベクトル型に対して代入することができる
	vec::vec<3, float>	v = initial_values(1.0f, 3.0f, 2.0f);
	std::cout << (v|identities) << "\n";
	
	// ほかの extension 同様 operator | の呼び出しもできる
	v|initial_values(-0.1f, -4.0f, 0.0f);
	std::cout << (v|identities) << "\n";
	
	// ベクトル型の代入も可能
	vec::vec<3, float> v2 = initial_values(v);
	std::cout << (v2|identities) << "\n";
	
}

}; };

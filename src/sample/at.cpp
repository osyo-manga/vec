#include <iostream>
#include <assert.h>

#include "vec/vec.hpp"
#include "vec/extension/at.hpp"
#include "vec/extension/dimension.hpp"


namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;
typedef vec::vec<3, float>	vec3;

void
at_main(){
	
	using namespace vec;
	
	/**
		要素に対して動的なアクセスを行う
	*/
	vec3	v;
	(v|at(0)) = 0.5f;
	(v|at(1)) = 1.5f;
	(v|at(2)) = 2.5f;
	
	assert( (v|at(0)) == 0.5f );
	assert( (v|at(1)) == 1.5f );
	assert( (v|at(2)) == 2.5f );
	
	std::cout << "at_main\n";
	for( int i = 0 ; i < (v|dimension_) ; i++ ){
		std::cout << (v|at(i)) << "\n";
	}
	
}

}; };

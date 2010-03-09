#include <iostream>
#include <assert.h>

#include "vec/vec.hpp"
#include "vec/extension/at_static.hpp"
#include "vec/extension/dimension.hpp"

namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
at_static_main(){
	
	using namespace vec;
	
	vec::vec<3, float>	v;
	
	
	/**
		静的なアクセスを行う
	*/
	(v|at_static<0>()) = 1.5f;
	(v|at_static<1>()) = 1.5f;
	(v|at_static<2>()) = 2.5f;
	
	assert( (v|at_static<0>()) == 0.5f);
	assert( (v|at_static<1>()) == 1.5f);
	assert( (v|at_static<2>()) == 2.5f);
	
	for( int i = 0 ; i < (v|dimension_) ; i++ ){
		std::cout << (v|at(i)) << "\n";
	}
	
	
	/**
		要素に対して直接アクセスを行う
	*/
	(v|at_x) = 2.5f;	// v.x = 2.5f;
	(v|at_y) = 1.5f;	// v.y = 1.5f;
	(v|at_z) = 0.5f;	// v.z = 0.5f;
	
	assert( (v|at_x) == 2.5f );
	assert( (v|at_y) == 1.5f );
	assert( (v|at_z) == 0.5f );
	
	for( int i = 0 ; i < (v|dimension_) ; i++ ){
		std::cout << (v|at(i)) << "\n";
	}
	
}

}; };

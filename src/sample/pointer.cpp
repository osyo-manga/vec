#include <iostream>

#include "vec/vec.hpp"
#include "vec/extension/pointer.hpp"
#include "vec/extension/dimension.hpp"


namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

typedef vec::vec<3, float>	vec3;

void
pointer_main(){
	
	vec3	v;
	
	// �z��ɂ��A�v�f�ւ̃A�N�Z�X
	(v|vec::pointer)[0] = 54.8f;
	(v|vec::pointer)[1] = 0.72f;
	(v|vec::pointer)[2] = 94.01f;
	
	// �l���o��
	for( int i = 0 ; i < (v|vec::dimension_) ; i++ ){
		std::cout << (v|vec::pointer)[i] << "\n";
	}
	
}

}; };

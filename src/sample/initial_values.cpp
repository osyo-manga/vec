#include <iostream>

#include "vec/vec.hpp"
#include "vec/extension/initial_values.hpp"

#include "vec/extension/identities.hpp"

namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;

void
initial_values_main(){
	
	using namespace vec;
	
	// �x�N�g���^�ɑ΂��đ�����邱�Ƃ��ł���
	vec::vec<3, float>	v = initial_values(1.0f, 3.0f, 2.0f);
	std::cout << (v|identities) << "\n";
	
	// �ق��� extension ���l operator | �̌Ăяo�����ł���
	v|initial_values(-0.1f, -4.0f, 0.0f);
	std::cout << (v|identities) << "\n";
	
	// �x�N�g���^�̑�����\
	vec::vec<3, float> v2 = initial_values(v);
	std::cout << (v2|identities) << "\n";
	
}

}; };

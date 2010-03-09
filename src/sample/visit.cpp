#include <iostream>
#include <string>
#include <sstream>

#include "vec/vec.hpp"

#include "vec/extension/visit.hpp"
#include "vec/type_traits/value.hpp"

namespace kmt_ex{ namespace math{ namespace vec{ namespace extension{

struct to_string_impl{
	
	typedef std::string result_type;
	
	template<
		int D,
		typename T
	>
	std::string operator ()(const vec<D, T>& vec) const{
		std::ostringstream	oss;
		oss << "{ ";
		for( int i = 0 ; i < D ; i++ ){
			oss << vec.value[i] << " ";
		}
		oss << "}";
		return oss.str();
	}
};
static const to_string_impl to_string;

} } } }		// namespace kmt_ex{ namespace math{ namespace vec{ namespace extension{


namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;
typedef vec::vec<3, float>	vec3;


void
visit_main(){
	
	using kmt_ex::math::vec::extension::to_string;
	
	vec3	v;
	v.value[0] = 0.5f;
	v.value[1] = 1.5f;
	v.value[2] = 2.5f;
	
	std::cout << vec::extension::visit(v, to_string) << "\n";
	std::cout << (v|to_string) << "\n";	// operator | ‚Å‚ÌŒÄ‚Ño‚µ
}

}; };

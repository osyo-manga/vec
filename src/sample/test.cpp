#include <iostream>

#include <d3d9.h>
#include <math.h>

#include "vec/vec.hpp"
#include "vec/type_traits/dimension.hpp"

#include "vec/extension/visit.hpp"
#include "vec/extension/dimension.hpp"
#include "vec/extension/pointer.hpp"
#include "vec/extension/identities.hpp"
#include "vec/extension/at.hpp"
#include "vec/extension/lenght.hpp"
#include "vec/extension/copy.hpp"
#include "vec/extension/initial_values.hpp"

#include "vec/type_traits/value.hpp"
#include "vec/type_traits/dimension.hpp"

#include "vec/preprocessor/make_type_traits_value.hpp"
#include "vec/preprocessor/make_type_traits_is_vec.hpp"

#include "vec/vec_cast.hpp"

/**
	D3DVECTOR の特殊化
*/
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(D3DVECTOR, float);
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(D3DVECTOR);


namespace kmt_ex{ namespace math{ namespace vec{


namespace extension{

/**
	同じ要素数のベクトルの要素の比較を行う
	true ：要素の値がすべて同じ
	false：true の反対
*/
template<
	typename T
>
struct equal_impl{
	
	typedef bool result_type;
	
	equal_impl(const T& rhs)
		: source(rhs){}
	
	template<
		typename T
	>
	bool operator ()(const T& rhs){
		
	}
	
private:
	const T& source;
	
};

}


namespace calculate{

}


} } }		// namespace kmt_ex{ namespace math{ namespace vec{



namespace vec{ namespace sample{

namespace vec = kmt_ex::math::vec;



void
test_main(){
	
	using namespace vec;
	
	typedef vec::vec<3, float>	vec3;
	
	vec3	v;
	(v|at(0)) = 1.0f;
	(v|at(1)) = 1.0f;
	(v|at(2)) = 0.0f;
	
	std::cout << (v|identities) << "\n";
	std::cout << (v|lenght) << "\n";
	std::cout << (v|lenght_non_sqrt) << "\n";
	
	
	D3DVECTOR	dxVec;
	(dxVec|at(0)) = 57.0f;
	(dxVec|at(1)) = 0.3245f;
	(dxVec|at(2)) = -5.04f;
	std::cout << (dxVec|identities) << "\n";
	
	
//	vec3	v2 = *vec_cast<vec3*>(dxVec);
//	std::cout << (v2|identities) << "\n";
	vec::vec<3, float>	v2;
	v2|copy(static_cast<const D3DVECTOR>(dxVec));
	std::cout << (v2|identities) << "\n";
	
	
	vec::vec<15, float>	v3 = initial_values(1.0f, 2.0f, 3.0f, 1.0f);
//	v3|initial_values(1.0f, 2.0f, 3.0f);
//	v3|initial_values(dxVec);
	std::cout << (v3|identities) << "\n";
	
	vec3*	v4 = vec_cast<vec3*>(&dxVec);
	std::cout << (*v4|identities) << "\n";
	
}

}; };

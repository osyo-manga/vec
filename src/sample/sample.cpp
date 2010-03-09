#include <iostream>

#include "sample.h"

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
	�Ǝ��̃x�N�g���^�̏ꍇ�͓��ꉻ���s���ĉ���������
	D3DVECTOR �̓��ꉻ
*/
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_VALUE(D3DVECTOR, float);
KMT_EX_PP_MATH_VEC_MAKE_TYPE_TRAITS_IS_VEC(D3DVECTOR);


int
main(){
	
#if	0
	
	vec::sample::test_main();	// �ʂɋ@�\�𓮂����ۂ̃e�X�^
	
#else
	
	/**
		�e�@�\���
		
		�e�@�\�̈����́A�ȉ��̗l�Ȏd�l�ɂȂ��Ă���
		
		<�x�N�g���̎���> | <�x�N�g���ɑ΂��鑀��>
		"operator | "���g�p���ăx�N�g���̎��̂ɑ΂��đ�����s��
	*/
	namespace vec = kmt_ex::math::vec;
	
	
	// �x�N�g���̎��̂��쐬
	vec::vec<3, float>	f_v3;	// float �^��3�����x�N�g��
	vec::vec<4, double>	d_v4;	// double �^��4�����x�N�g��
	D3DVECTOR			d3d_v;	// DirectX�̃x�N�g��
	
	
	// �x�N�g���̗v�f�̏�����
	f_v3|vec::initial_values(4.0f, 3.0f, 1.0f);
	d_v4|vec::initial_values(-4.0, -2.5, 0.214, 1.0);
	d3d_v|vec::initial_values(1.4f, 0.54f, 4.4f);	// DirectX�̃x�N�g���^�ł��ł���
	
	
	// �x�N�g���̗v�f���o��
	std::cout << "f_v3:"  << (f_v3|vec::identities) << "\n";
	std::cout << "d_v4:"  << (d_v4|vec::identities) << "\n";
	std::cout << "d3d_v:" << (d3d_v|vec::identities) << "\n";
	
	
	// �x�N�g���̗v�f��ύX
	f_v3|vec::at_x = 1.0f;
	d_v4|vec::at_w = 0.0;
	d3d_v|vec::at_y = 2.0;
	
	
	// �x�N�g���̎��������擾����
	int d = (f_v3|vec::dimension_);	// �Ō��'_'�ɒ���
	
	
	// �x�N�g���̊e�v�f�ɑ΂��ă��[�v�ŃA�N�Z�X
	for( int i = 0 ; i < (f_v3|vec::dimension_) ; i++ ){
		( f_v3|vec::at(i) ) = 0.0f;
	}
	
	// �x�N�g���̗v�f���R�s�[
	f_v3|vec::copy(d3d_v);
	
	
	// �z����R�s�[
	float	v[3] = {3.0f, 2.0f, 1.0f};
	f_v3|vec::copy(v, 3);
	
	
	// �Ⴄ�x�N�g���^�ɃL���X�g����
	d3d_v = vec::vec_cast<D3DVECTOR>(f_v3);
	
	
	// �x�N�g���̒�����Ԃ��i���z��̒����ł͂Ȃ��j
	float	len = (f_v3|vec::lenght);
	
	
#endif
	
	getchar();
	return 0;
}



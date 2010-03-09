//##################################################################################################
//		
//		�� �R���p�C�����ɃG���[���o�͂���`�F�b�J�[
//		
//		���N���X�F�Ȃ�
//		���O��ԁ@�F�Ȃ�
//																	����� 2009�N1��20�� 12��41��
//																	�X�V�� 2009�N1��20�� 12��41��
//	����<100>�ATAB<4>												����� �������
//==================================================================================================

#ifndef _kmt_ex_math_vec_static_assert_hpp_
#define _kmt_ex_math_vec_static_assert_hpp_


//======================================
// ��`
//======================================


/**
	���O���
*/
namespace kmt_ex{ namespace math{ namespace vec{

namespace detail{

template<
	bool
>
struct CompileTimeChecker{
	typedef int Result;
};

template<>
struct CompileTimeChecker<false>{
	typedef int& Result;
};

}

/**
	�R���p�C�����ɃG���[���o�͂���}�N��
	
	expr �� false �Ȃ��
	ERROR_##msg�Əo�͂��ăR���p�C���G���[�ɂȂ�
	
	URL:http://naknet.jpn.ph/blog/sb.cgi?day=20050321
*/
#define KMT_EX_MATH_VEC_STATIC_ASSERT(expr, msg){	\
	typedef detail::CompileTimeChecker<(expr) != 0 >::Result* ERROR_##msg;	\
}	\

} } }			// namespace kmt{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

/*##################################################################################################
	
	���v�f�ɑ΂��ĐÓI�ɃA�N�Z�X���s��
	
	���K�v�ȃw�b�_�[�t�@�C��
	�@�Ȃ�
	
	���X�V����
		
		��2009/11/09
		�E�t�@�C�����쐬
		
																	����� 2009�N11��9�� 14��6��
																	�X�V�� 2009�N11��9�� 14��6��
	����<100>�ATAB<4>												����� �������
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_at_static_hpp_
#define _kmt_ex_math_vec_extension_at_static_hpp_


#include "../detail/include.hpp"
#include "../vec.hpp"
#include "visit.hpp"
#include "at.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

template<
	typename T,
	int index
>
struct at_static_impl{
	
	template<
		typename T
	>
	struct result{
		typedef typename value<T>::type& type;
	};
	
	template<
		typename T
	>
	typename result<T>::type
	operator ()(T& v) const{
		return (v|at(index));
	}
};


/**
	�e�v�f�ɑ΂��āA�ÓI�ɃA�N�Z�X���s��
	
	�����ł́Avec::at ���g�p���ėv�f�ɑ΂��A�A�N�Z�X���s���Ă���B
	
	�܂��Aat(0) ���Ax�v�f�ւ̃A�N�Z�X�łȂ��ꍇ�́A
	at_static_impl �̃N���X�e���v���[�g�̓��ꉻ���s�����ɂ��A
	�e�v�f�ւ̃A�N�Z�X���������鎖���o����B
	
	��j
	struct my_vec{
		float	z, y, x;	// �z�񏇂��Ⴄ
	};
	
	// ����Ȋ����œ��ꉻ���s��
	template<>
	struct at_static_impl<0, my_vec>{	// '0'�Ƃ́Aat_static<0>��'0'�ł���
		
		template<
			typename T
		>
		struct result{
			typedef typename value<T>::type& type;
		};
		
		template<
			typename T
		>
		typename result<T>::type
		operator ()(T& v) const{
			return v.x;	// at_static<0>���Ă΂ꂽ�Ƃ��� x �̗v�f��Ԃ�
		}
	};
	
*/
template<
	int index
>
struct at_static{
	
	template<
		typename T
	>
	struct result{
		typedef typename value<T>::type& type;
	};
	
	template<
		typename T
	>
	typename result<const T>::type
	operator ()(const T& v) const{
		return at_static_impl<T, index>()(v);
	}
	template<
		typename T
	>
	typename result<T>::type
	operator ()(T& v) const{
		return at_static_impl<T, index>()(v);
	}
	
};

static const at_static<0>	at_x;	// x �v�f�փA�N�Z�X
static const at_static<1>	at_y;	// y �v�f�փA�N�Z�X
static const at_static<2>	at_z;	// z �v�f�փA�N�Z�X
static const at_static<3>	at_w;	// w �v�f�փA�N�Z�X

}		// namespace extension{

using extension::at_static;
using extension::at_x;
using extension::at_y;
using extension::at_z;
using extension::at_w;


} } }			// namespace kmt_ex{ namespace math{ namespace vec{


#endif
//##########################################<< EOF >>###############################################

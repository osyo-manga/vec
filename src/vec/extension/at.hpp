/*##################################################################################################
	
	★ベクトルの要素へのアクセスを行う
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/10/29
		・ファイルを作成
		
																	製作日 2009年10月29日 7時40分
																	更新日 2009年10月29日 7時40分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_math_vec_extension_at_hpp_
#define _kmt_ex_math_vec_extension_at_hpp_


#include "../detail/include.hpp"
#include "visit.hpp"
#include "pointer.hpp"
#include "../vec.hpp"
#include "../type_traits/value.hpp"


namespace kmt_ex{ namespace math{ namespace vec{

namespace extension{

/**
	要素に対して、配列でのアクセスを行います。
	先頭ポインタは、vec::pointer を利用しているので、
	使用するためには、vec::pointer が使える状態にしておく必要があります。
*/
struct at_impl{
	
	template<
		typename T
	>
	struct result{
		typedef typename value<T>::type& type;
	};
	
	at_impl(int index)
		: index(index){}
	
	template<
		typename T
	>
	typename result<T>::type
	operator ()(T& v) const{
		return (v|pointer)[index];
	}
private:
	int	index;
	
};

typedef at_impl	at;

}		// namespace extension{

using extension::at;

} } }		// namespace kmt_ex{ namespace math{ namespace vec{

#endif
//##########################################<< EOF >>###############################################

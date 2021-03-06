/*##################################################################################################
	
	★ベクトルクラス
	
	★必要なヘッダーファイル
	　なし
	
	★更新履歴
		
		●2009/10/28
		・operator =()内の処理が間違っていたので修正
		・引数を持たないコンストラクタ時に0で初期化
		
		●2009/10/19
		・ファイルを作成
		
																	製作日 2009年10月19日 23時6分
																	更新日 2009年10月19日 23時6分
	横幅<100>、TAB<4>												製作者 小松大介
//================================================================================================*/

#ifndef _kmt_ex_vec_vec_hpp_
#define _kmt_ex_vec_vec_hpp_


#include "detail/include.hpp"


namespace kmt_ex{ namespace math{ namespace vec{


/**
	数学のベクトルを定義するクラス
	
	次元数と型情報を設定して使用する
	
	visitor パターンを使用して挙動を制御するので、
	このクラスでは何も行わない
	
	また、std::vector と混同しないようにする為、
	「vec」と省略する
*/
template<
	unsigned int D,
	typename value_t = float
>
struct vec{
	
	typedef value_t value_t;
	enum{ dimension = D };
	
	value_t	value[ dimension ];
	
	vec(){
		memset(value, 0, sizeof(value_t) * dimension);
	}
	vec(const vec& rhs){
		(*this) = rhs;
	}
	const vec& operator =(const vec& rhs){
		memcpy(value, rhs.value, sizeof(value_t) * dimension);
		return *this;
	}
};


} } }			// namespace kmt_ex{ namespace math{ namespace vec{

#endif
//##########################################<< EOF >>###############################################

★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★
☆																									☆
★																									★
☆									汎用ベクトルクラス												☆
★																									★
☆																									☆
★																									★
☆																									☆
★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★

★　概要

	数学的なベクトルクラスの処理を行うライブラリ
	主にゲームプログラミングで使用する予定
	すべて、namespace kmt_ex::math::vec でくくられている


★　コンセプト

	・visitor を用いた拡張性、柔軟性。目指すところは p_stade ライブラリのような形
	・他のベクトルクラス（DirectXやPhysX等）との連携
	・式テンプレートを用いた高速性（未実装）


★　開発環境・動作確認
	
	Microsoft WindowsXP Professional Version 2002 Service Pack 3
	Microsoft Visual Studio 2008 Express Edition


★　使用する際の知識
	
	・C++の基本的な理解力（template の知識も含む）
	・template を使用したメタプログラミングの知識
	
	boost（もしくはp_stade）が使えるならば使用可能だと思います
	
	
☆　拡張関数オブジェクト

	visitor パターンを利用して、ベクトルに対して操作を行うことが出来る
	
	呼び出し方の例）
	
	vec::vec<3, float>	vec3;
	(vec3|vec::dimension_);		// 次元数の取得を行う
	
	operator |を利用して関数オブジェクトの呼び出しを行い、
	インスタンスの操作を行う。
	また、拡張用の関数オブジェクトはすべて、
	namespace kmt_ex::math::vec::extension で定義する必要がある。
	これは、(Argument Dependent name Lookup)を使用して、
	operator |の呼び出しを行う為である


★　サンプルファイル

	vec\src\sample\sample.cpp 内に機能が列挙されているのでそちらを参照して下さい


★　今後の課題

	・version 管理
	・サンプルの自動生成
	・第三者によるレビュー


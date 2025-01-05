// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sum/a.hpp

#pragma once
// verify:
// https://atcoder.jp/contests/abc379/submissions/61409472 (Sum, ArithmeticProgressionSum)
// https://yukicoder.me/submissions/1015838 (GeometricProgressionLinearCombinationSum)

// fが空でない場合にのみサポート。
// Tの要素の列のopeに関する左結合的総乗を愚直に計算し、その結果を返す。
template <typename T , template <typename...> typename V , typename OPR> T LeftConnectiveProd( const V<T>& f , OPR opr );
template <typename T , template <typename...> typename V> inline T Sum( const V<T>& f );
template <typename T , template <typename...> typename V> inline T Prod( const V<T>& f );
template <typename T , template <typename...> typename V> inline T Max( const V<T>& f );
template <typename T , template <typename...> typename V> inline T Min( const V<T>& f );

// init * ( t ^ exponent )を返す
template <typename T , typename UINT> T Power( T t , UINT exponent , T init = 1 );


// 初項l交差dの等差数列のr以下までの総和を取る。
// 0 <= l , r <= 4e9ならばINT = llでオーバーフローを避けられる。
// 0 <= l , r <= 6e9ならばINT = ullでオーバーフローを避けられる。
template <typename INT> inline INT ArithmeticProgressionSum( const INT& l , INT r , const INT& d = 1 );
template <typename INT> inline INT ArithmeticProgressionSum( const INT& r );


// 入力の範囲内で要件
// (1) Tがoperator+,operator-,operator*に関して単位的環をなす。
// (2) exponent_max >= 0である。
// (3) rate - 1は0でないならば(1)の単位的環構造に関して可逆である。
// を満たす場合にのみサポート。

// 等比数列init,init*rate,...,init*rate^exponent_maxの総和を
// O((log exponent_max)+逆元計算量)で求める。
template <typename T , typename UINT> inline T GeometricProgressionSum( T rate , UINT exponent_max , const T& init = 1 );

// 入力の範囲内で追加の要件
// (4) T{}が(1)の単位的可換環構造に関して加法的単位元である。
// を満たす場合にのみサポート。

// 等比数列の線形和の総和を単に等比数列の総和の線形和として求める。
template <typename T , typename UINT>
T GeometricProgressionLinearCombinationSum( vector<T> rate , vector<UINT> exponent_max , const vector<T>& init );

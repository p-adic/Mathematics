// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Iteration/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://atcoder.jp/contests/abc379/submissions/61409472 (Sum, ArithmeticProgressionSum<ll>)
// https://yukicoder.me/submissions/1064893 (ArithmeticProgressionSum<MP>)
// https://yukicoder.me/submissions/1065726 (GeometricProgression<MP>)
// https://yukicoder.me/submissions/1015838 (GeometricProgressionLinearCombinationSum<QuadraticExtension<MP>>)

// tとfのoprに関する左結合的総乗を愚直に計算し、その結果を返す。
template <typename T , typename U , template <typename...> typename V , typename OPR> T LeftConnectiveProd( T t , const V<U>& f , OPR opr );
// Sum<ll>( vector<int>() )などの構文はできないので、代わりにSum( 0LL , vector<int>() )を考える。
template <typename T , typename U , template <typename...> typename V> inline T Sum( const V<U>& f );
template <typename T , typename U , template <typename...> typename V> inline T Prod( const V<U>& f );

template <typename T> inline T& SetMax( T& n );
template <typename T , typename U , typename... Args> inline T& SetMax( T& t0 , const U& u1 , const Args&... args );
template <typename T> inline T& SetMin( T& n );
template <typename T , typename U , typename... Args> inline T& SetMin( T& t0 , const U& u1 , const Args&... args );
template <typename T , template <typename...> typename V> inline const T& Max( const V<T>& f );
template <typename T , typename U , typename...Args> inline T Max( T t0 , const U& t1 , const Args&... args );
template <typename T , template <typename...> typename V> inline const T& Min( const V<T>& f );
template <typename T , typename U , typename...Args> inline T Min( T t0 , const U& t1 , const Args&... args );

// init * ( t ^ exponent )を返す
template <typename T , typename UINT> T Power( const T& t , const UINT& exponent , T init = 1 );
template <typename T> inline T PowerMemorisation( const T& t , const int& exponent );


// 初項l交差dの等差数列のr以下までの総和を取る。
// 0 <= l , r <= 4e9ならばINT = llでオーバーフローを避けられる。
// 0 <= l , r <= 6e9ならばINT = ullでオーバーフローを避けられる。
template <typename INT> inline INT ArithmeticProgressionSum( const INT& l , const INT& r , const INT& d = 1 );
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

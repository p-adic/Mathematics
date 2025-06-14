// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/CRT/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1099258 (Garner)

// GCDやLCMは../../../Prime/Divisor/GCDで定義。

// u_0,u_1にu_0*b_0+u_1*b_1==GCD(b_0,b_1)を満たす値を格納し、
// GCD(b_0,b_1)を返す。（O(log min(b_0,b_1))）
template <typename INT> INT PartitionOfUnity( const INT& b_0 , const INT& b_1 , INT& u_0 ,  INT& u_1 );

// GCD(b,c)==1である場合にのみサポート。
// cの法b逆元を返す。（O(log b)）
template <typename INT> inline INT ModularInverse( const INT& b , const INT& c );

// LCM(b_0,b_1)^2がINTでオーバーフローしない場合にのみサポート。
// (x-c_0)%b_0==0かつ(x-c_1)%b_1==0を満たす非負整数xが存在すればそのようなxを返し、
// 存在しないならば-1を返す。（O(log min(b_0,b_1))）
template <typename INT> INT ChineseRemainderTheorem( const INT& b_0 , const INT& c_0 , const INT& b_1 , const INT& c_1 );

// bが互いに素かつ総乗がオーバーフローしない場合にのみサポート。
// b,cのサイズをsizeとして、size未満の任意の非負整数iに対し(x-c[i])%b[i]==0を満たす
// 最小の非負整数xを返す。（O(size(size+log max(b)))）
template <typename INT> INT Garner( const vector<INT>& b , const vector<INT>& c );


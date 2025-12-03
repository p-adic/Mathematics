// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/CRT/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1099258 (Garner)

// GCDやLCMは../../../Prime/Divisor/GCDで定義。

// u_0*b_0+u_1*b_1==GCD(b_0,b_1)を満たすu_0,u_1に対する
// {u_0,u_1,GCD(b_0,b_1)}を返す。（O(log min(b_0,b_1))）
// 計算過程のオーバーフローに注意。
template <typename RET , typename INT> tuple<RET,RET,INT> PartitionOfUnity( const INT& base_0 , const INT& base_1 );
// 逆元計算は
// ../Residue/
// のModularInverseの方が定数倍早い。

// LCM(b_0,b_1)^2がINTでオーバーフローしない場合にのみサポート。
// (x-c_0)%b_0==0かつ(x-c_1)%b_1==0を満たす非負整数xが存在すればそのようなxを返し、
// 存在しないならば-1を返す。（O(log min(b_0,b_1))）
template <typename INT> INT ChineseRemainderTheorem( const INT& b_0 , const INT& c_0 , const INT& b_1 , const INT& c_1 );

// bが互いに素かつ総乗がオーバーフローしない場合にのみサポート。
// b,cのサイズをsizeとして、size未満の任意の非負整数iに対し(x-c[i])%b[i]==0を満たす
// 最小の非負整数xを返す。（O(size(size+log max(b)))）
template <typename INT> INT Garner( const vector<INT>& b , const vector<INT>& c );


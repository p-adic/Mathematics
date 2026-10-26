// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/MultipleLength/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/937747 （Resdue, Division）

// 非負整数のみ対応。
// O(n.size()+m.size())
string Addition( const string& n , const string m );

// N回連続使用でO(n.size()+N)
string& Increment( string& n );
string& Decrement( string& n );

// 0 < m < 2^64/10 = 1844674407370955161.5 ≒ 1.8×10^{18}の場合のみサポート。
// O( n.size() )でn%mを計算。
ull Residue( const string& n , const ull& m );
// O( n.size() )でn/mとn%mを計算。
pair<string,ull> Division( const string& n , const ull& m );

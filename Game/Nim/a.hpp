// c:/Users/user/Documents/Programming/Mathematics/Game/Nim/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/972137（BoundedNim）

// O(a.size())でaのニム和を求める、
template <typename INT , template <typename...> typename V> inline INT Nim( const V<INT>& a );
template <typename INT1 , template <typename...> typename V , typename INT2> inline INT1 BoundedNim( const V<INT1>& a , INT2 bound );

// 先手必勝 <=> Nim( a ) > 0
// 先手敗北可能 <=>
// - aが2以上の成分を持つならば、Nim( a ) > 0
// - aが2以上の成分を持たないならば、a.size() % 2 == 0

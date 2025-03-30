// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/IteratedArithmetic/Constexpr/Powerise/a.hpp

#pragma once

// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144

// N以上である最小の2羃をコンパイル時計算する。
template <typename INT> inline constexpr INT Powerise( const INT& N );

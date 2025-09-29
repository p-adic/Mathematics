// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/GCD/LCM/a.hpp

#pragma once


// 絶対値A以下の整数N個のlcmをO(N log A)で求める。（オーバーフローに注意）
inline int LCM();
template <typename INT1 , typename...INT2> INT1 LCM( INT1 b_0 , INT2... args );
template <typename INT , template <typename...> typename V> INT LCM( V<INT> a );

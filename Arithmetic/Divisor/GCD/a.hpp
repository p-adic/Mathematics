// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/GCD/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/996609（GCD）

// 絶対値A以下の整数N個のgcdをO(N log A)で求める。
inline int GCD();
template <typename INT1 , typename...INT2> INT1 GCD( INT1 b_0 , INT2... args );
template <typename INT , template <typename...> typename V> INT GCD( V<INT> a );

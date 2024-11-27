// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/GCD/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/996609�iGCD�j

// ��ΒlA�ȉ��̐���N��gcd��O(N log A)�ŋ��߂�B
inline int GCD();
template <typename INT1 , typename...INT2> INT1 GCD( INT1 b_0 , INT2... args );
template <typename INT , template <typename...> typename V> INT GCD( V<INT> a );

// ��ΒlA�ȉ��̐���N��lcm��O(N log A)�ŋ��߂�B�i�I�[�o�[�t���[�ɒ��Ӂj
inline int LCM();
template <typename INT1 , typename...INT2> INT1 LCM( INT1 b_0 , INT2... args );
template <typename INT , template <typename...> typename V> INT LCM( V<INT> a );

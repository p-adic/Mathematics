// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/GCD/LCM/a.hpp

#pragma once


// ��ΒlA�ȉ��̐���N��lcm��O(N log A)�ŋ��߂�B�i�I�[�o�[�t���[�ɒ��Ӂj
inline int LCM();
template <typename INT1 , typename...INT2> INT1 LCM( INT1 b_0 , INT2... args );
template <typename INT , template <typename...> typename V> INT LCM( V<INT> a );

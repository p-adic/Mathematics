// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Count/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/970583�iCountDivisor�j

// O(��n)
template <typename INT> INT CountDivisor( INT n ) noexcept;
// PE��PrimeEnumeration/LeastDivisor�ȂǂŁA
// pe��sqrt( n )�ȉ��̑f��/n�ȉ��̐������̖񐔂��Ǘ����鎞�̂݃T�|�[�g�B
// O(��n/log n)/O(log n)
template <typename PE , typename INT> INT CountDivisor( const PE& pe , INT n ) noexcept;

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Enumeration/a.hpp

#pragma once
#include "../../Prime/Enumeration/SFINAE/a.hpp"

// verify:
// https://yukicoder.me/submissions/970639�iEnumerateDivisor�j

// O(��n)
template <typename INT> vector<INT> EnumerateDivisor( INT n ) noexcept;
// PE��PrimeEnumeration�ȂǂŁApe��sqrt( n )�ȉ��̑f�����Ǘ����鎞�̂݃T�|�[�g�B
// O(��n/log n)
template <typename PE , typename INT> auto EnumerateDivisor( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,vector<INT>>;
// LD��LeastDivisor�ȂǂŁAld��n�ȉ��̑f�����Ǘ����鎞�̂݃T�|�[�g�B
// O(d(n)) = O(log n/log log n)
template <typename LD , typename INT> auto EnumerateDivisor( const LD& ld , INT n ) -> enable_if_t<!IsPE<LD>,vector<INT>>;

// O(size log size)
template <typename INT> vector<vector<INT>> TotalEnumerateDivisor( const INT& size ) noexcept;

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Enumeration/a.hpp

#pragma once
#include "../../Prime/Enumeration/SFINAE/a.hpp"

// verify:
// https://yukicoder.me/submissions/970639�iEnumerateDivisor�j
// https://yukicoder.me/submissions/1027344�iTotalEnumerateDivisor�j

// O(��n)
template <typename INT> vector<INT> EnumerateDivisor( INT n ) noexcept;
// PE��PrimeEnumeration�ȂǂŁApe��sqrt( n )�ȉ��̑f�����Ǘ����鎞�̂݃T�|�[�g�B
// O(��n/log n)
template <typename PE , typename INT> auto EnumerateDivisor( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,vector<INT>>;
// LD��LeastDivisor�ȂǂŁAld��n�ȉ��̑f�����Ǘ����鎞�̂݃T�|�[�g�B
// O(d(n)) = O(n^{log 2/log log n})
template <typename LD , typename INT> auto EnumerateDivisor( const LD& ld , INT n ) -> enable_if_t<!IsPE<LD>,vector<INT>>;

// O(size log size)�i��Ԍv�Z�ʂ�O(size log size)�ł��邱�Ƃɒ��Ӂj
template <typename INT> vector<vector<INT>> TotalEnumerateDivisor( const INT& size ) noexcept;
// O(size log size)�i��Ԍv�Z�ʂ�O(size)�j
// answer[i]�Ɂuinit�ɑ΂�i�̖�d�������ɂ킽�点��f(-,d)��K�p�������́v���i�[�B
// �񐔃[�[�^�ϊ��̈�ʉ��B
template <typename INT , typename FUNC , typename U> vector<U> TotalEnumerateDivisor( const INT& size , FUNC f , const U& init ) noexcept;

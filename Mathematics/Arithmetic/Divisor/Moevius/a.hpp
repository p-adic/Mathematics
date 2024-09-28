// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Moevius/a.hpp

#pragma once
#include "../../Prime/Enumeration/SFINAE/a.hpp"

// O(��n)
template <typename INT> int MoeviusFunction( const INT& n ) noexcept;
// PE��PrimeEnumerationr�ȂǂŁApe��sqrt( n )�ȉ��̑f�����Ǘ����鎞�̂݃T�|�[�g�B
// O(��n/(log n))
template <typename PE , typename INT> auto MoeviusFunction( const PE& pe , INT n ) noexcept -> enable_if_t<IsPE<PE>,int>;
// LD��LeastDivisor�ȂǂŁAld��n�ȉ��̐������̍ŏ��̖񐔂��Ǘ����鎞�̂݃T�|�[�g�B
// O(d(n)) = O(log n / log log n)
template <typename LD , typename INT> auto MoeviusFunction( const LD& ld , INT n ) -> enable_if_t<!IsPE<LD>,int>;

// LD��LeastDivisor�ȂǂŁAld��n_max�ȉ��̐������̍ŏ��̖񐔂��Ǘ����鎞�̂݃T�|�[�g�B
// O(n_max)
template <typename LD , typename INT> vector<INT> TotalMoeviusFunction( const LD& ld , const INT& n_max );


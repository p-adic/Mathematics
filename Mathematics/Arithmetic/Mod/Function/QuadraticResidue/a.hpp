// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/QuadraticResidue/a.hpp

#pragma once

// p����f���̎���O(��|a%p|)�ŕ�����]�L��(a/p)��Ԃ��B
// ������p<1<<31�̎���O(log_2 p)�̃A���S���Y���Ōv�Z����B
template <typename INT> int QuadraticResidueSymbol( INT a , const ll& p , const bool& reduced = false );

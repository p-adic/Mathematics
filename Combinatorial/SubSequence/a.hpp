// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/a.hpp

#pragma once
#include "a.hpp"

// O(S.size() T.size())��T�Ɠ�����S�́i�A���Ƃ͌���Ȃ��j������̌������߂�B
INT CountSubSequence( const VEC& S , const VEC& T );

// - T�Ɠ������A��������̌������߂������͑����
//   RollingHash::CountContain()
//   O(S.size())��p����B

// - ������̎�ސ������߂������͕�����DP
//   https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd
//   O(S.size()*�����̎�ސ�)��p����B

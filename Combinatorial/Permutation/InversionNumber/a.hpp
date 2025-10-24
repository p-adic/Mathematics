// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/InversionNumber/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1030881�iInversionNumber�j

// ����Ƃ͌���Ȃ��z��A�̓]�|���v�ZO(N log N)
template <typename INT> ll InversionNumber( const vector<INT>& A );

// ����P�̋ɏ���{�݊��\���̔Z�x�v�ZO(N log N)
template <typename INT> inline ll LeastAdjacentSwapCount( const vector<INT>& P );

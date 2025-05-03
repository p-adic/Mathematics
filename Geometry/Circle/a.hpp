// c:/Users/user/Documents/Programming/Mathematics/Geometry/Circle/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1081998 (NoncrossingPartition, colour_edge=false)

// chord���~�����N�_�̌�M�{�ɂ������������^����Ƃ���B
// �����[�_�����L����{���̍ő�l��D�Ƃ��AO(N + M log D)�Ŋe���_i���A
// l<=i<r�𖞂����e��{l,r}�̂����ł������ɂ�����́i�ł�l���傫��r�����������́j
// �̌��ԍ��i1-indexed�j�ŐF��������B���̂悤�Ȍ������݂��Ȃ��ꍇ��0�ŐF��������B
// ������colour_edge��false�ł��鎞�͌��̒[�_��-1�ŐF��������B
template <template <typename...> typename PAIR , typename INT> vector<int> NoncrossingPartition( const int& N , const vector<PAIR<INT,INT>>& chord , const bool& colour_edge = false );

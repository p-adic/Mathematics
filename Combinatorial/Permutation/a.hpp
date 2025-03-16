// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/1030881�iInversionNumber�j

// 7! �� 5�~10^3"
// 8! �� 4�~10^4"
// 9! �� 4�~10^5"
// 10! �� 4�~10^6"
// 11! �� 4�~10^7"
// 12! �� 5�~10^8"
// 18! �� 6�~10^15
// 19! �� 1�~10^17
// 20! �� 2�~10^18

// �ꏄ�̍��v�v�Z��O(N(N!))
// �������Ō�҂����݂��Ȃ��ꍇ�͎������ōŏ��l�ɖ߂邱�Ƃɒ���
template <typename INT , int size_max> inline bool NextPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool NextPermutation( vector<INT>& P );
// �������őO�҂����݂��Ȃ��ꍇ�͎������ōő�l�ɖ߂邱�Ƃɒ���
template <typename INT , int size_max> inline bool PreviousPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool PreviousPermutation( vector<INT>& P );

// ����Ƃ͌���Ȃ��z��P�̓]�|���v�ZO(N log N)
template <typename INT> ll InversionNumber( const vector<INT>& P );

// ����P�̏���u���\��O(N)
template <typename INT> vector<vector<INT>> CyclicPermutationRepresentation( const vector<INT>& P , const bool& zero_indexed = true );

// ����P�̋ɏ��݊��\��O(N)
template <typename INT> vector<pair<INT,INT>> MinimalTranspositionRepresentation( const vector<INT>& P , const bool& zero_indexed = true );

// ����P�̋ɏ���{�݊��\��O(N^2)
template <typename INT> vector<pair<INT,INT>> MinimalAdjacentTranspositionRepresentation( vector<INT> P , const bool& zero_indexed = true );

// ����P�̈ʐ��v�ZO(N)
template <typename INT> ll PermutationOrder( const vector<INT>& P , const bool& zero_indexed = true );

// ����P�̋ɏ��݊��\���̔Z�x�v�ZO(N)
template <typename INT> INT LeastSwapCount( const vector<INT>& P , const bool& zero_indexed = true );

// ����P�̋ɏ���{�݊��\���̔Z�x�v�ZO(N log N)
template <typename INT> inline ll LeastAdjacentSwapCount( const vector<INT>& P );

// ����P�̕����v�ZO(N log N)
template <typename INT> inline int Signature( const vector<INT>& P );


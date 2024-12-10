// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942586�i�]�|���j

// 7! �� 5�~10^3"
// 8! �� 4�~10^4"
// 9! �� 4�~10^5"
// 10! �� 4�~10^6"
// 11! �� 4�~10^7"
// 12! �� 5�~10^8"
// 18! �� 6�~10^15
// 19! �� 1�~10^17
// 20! �� 2�~10^18

// �ꏄ�̍��v�v�Z��O(N(N!))�B
// �������Ō�҂����݂��Ȃ��ꍇ�͎������ōŏ��l�ɖ߂邱�Ƃɒ��ӁB
template <typename INT , int size_max> inline bool NextPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool NextPermutation( vector<INT>& P );
// �������őO�҂����݂��Ȃ��ꍇ�͎������ōő�l�ɖ߂邱�Ƃɒ��ӁB
template <typename INT , int size_max> inline bool PreviousPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool PreviousPermutation( vector<INT>& P );

// ����P�̓]�|���v�ZO(N log N)�B
template <typename INT> ll InversionNumber( const vector<INT>& P );
template <typename INT> ll InversionNumber( const vector<INT>& P , const vector<INT>& P_inv , const int& size );

// ����P�̏���u���\��O(N)�B
template <typename INT> vector<vector<INT>> CyclicPermutationRepresentation( const vector<INT>& P , const bool& zero_indexed = true );

// ����P�̋ɏ��݊��\��O(N)�B
template <typename INT> vector<pair<INT,INT>> MinimalTranspositionRepresentation( const vector<INT>& P , const bool& zero_indexed = true );

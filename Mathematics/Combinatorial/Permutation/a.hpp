// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a.hpp

#pragma once

// �ꏄ�̍��v�v�Z��O(N!)�B
// �������Ō�҂����݂��Ȃ��ꍇ�͎������ōŏ��l�ɖ߂邱�Ƃɒ��ӁB
template <typename INT , int size_max> inline bool NextPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool NextPermutation( vector<INT>& P );
// �������őO�҂����݂��Ȃ��ꍇ�͎������ōő�l�ɖ߂邱�Ƃɒ��ӁB
template <typename INT , int size_max> inline bool PreviousPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool PreviousPermutation( vector<INT>& P );

// P��0,...,size-1�̏���
template <int size_max> long long InversionNumber( const int ( &P )[size_max] const int& size );

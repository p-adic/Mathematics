// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a.hpp

#pragma once

// 7! à 5~10^3
// 8! à 4~10^4
// 9! à 4~10^5
// 10! à 4~10^6
// 11! à 4~10^7
// 12! à 5~10^8
// 18! à 6~10^15
// 19! à 1~10^17
// 20! à 2~10^18

// ˆê„‚Ì‡ŒvŒvZ—ÊO(N(N!))
// «‘‡‚ÅŒãÒ‚ª‘¶İ‚µ‚È‚¢ê‡‚Í«‘‡‚ÅÅ¬’l‚É–ß‚é‚±‚Æ‚É’ˆÓ
template <typename INT , int size_max> inline bool NextPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool NextPermutation( vector<INT>& P );
// «‘‡‚Å‘OÒ‚ª‘¶İ‚µ‚È‚¢ê‡‚Í«‘‡‚ÅÅ‘å’l‚É–ß‚é‚±‚Æ‚É’ˆÓ
template <typename INT , int size_max> inline bool PreviousPermutation( INT ( &P )[size_max] , const int& size );
template <typename INT> inline bool PreviousPermutation( vector<INT>& P );

// ‡—ñP‚Ì„‰ñ’uŠ·•\¦O(N)
template <typename INT> vector<vector<INT>> CyclicPermutationRepresentation( const vector<INT>& P , const bool& zero_indexed = true );

// ‡—ñP‚Ì‹É¬ŒİŠ·•\¦O(N)
template <typename INT> vector<pair<INT,INT>> MinimalTranspositionRepresentation( const vector<INT>& P , const bool& zero_indexed = true );

// ‡—ñP‚Ì‹É¬Šî–{ŒİŠ·•\¦O(N^2)
template <typename INT> vector<pair<INT,INT>> MinimalAdjacentTranspositionRepresentation( vector<INT> P , const bool& zero_indexed = true );

// ‡—ñP‚ÌˆÊ”ŒvZO(N)
template <typename INT> ll PermutationOrder( const vector<INT>& P , const bool& zero_indexed = true );

// ‡—ñP‚Ì‹É¬ŒİŠ·•\¦‚Ì”Z“xŒvZO(N)
template <typename INT> INT LeastSwapCount( const vector<INT>& P , const bool& zero_indexed = true );

// ‡—ñP‚Ì•„†ŒvZO(N log N)
template <typename INT> inline int Signature( const vector<INT>& P );

// “]“|”ŒvZ‚Æ‹É¬ŒİŠ·•\¦‚Ì”Z“xŒvZ‚Í
// ./InversionNumber/
// ‚Å’è‹`B

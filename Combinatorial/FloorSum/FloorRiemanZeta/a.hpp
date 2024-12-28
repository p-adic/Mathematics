// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/FloorRiemanZeta/a.hpp

#pragma once
// https://atcoder.jp/contests/abc230/submissions/57700207 (HarmonicFloorSum)
// https://yukicoder.me/submissions/1009595 (HarmonicFloorSum)

// n >= 0����exponent >= 0�̎�
// sum( int i = 1 ; i <= n ; i++ ){ ( n / i ) ^ exponent }
// ��O(��n)�ŋ��߂�B
template <typename INT> inline INT FloorRiemannZeta( const INT& n , const INT& exponent );

// sum( int i = 1 ; i <= n ; i++ ){ ( n / i ) }
// ��O(��|n|)�ŋ��߂�B����n>=0�̎��Axy���ʓ��̑�1�ی��i���܂܂��j��xy<=n�𖞂����i�q�_(x,y)��
// ���ƈ�v����B
template <typename INT> inline INT HarmonicFloorSum( const INT& n );


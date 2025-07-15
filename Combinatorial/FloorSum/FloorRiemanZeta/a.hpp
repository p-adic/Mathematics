// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/FloorRiemannZeta/a.hpp

#pragma once
// https://atcoder.jp/contests/abc230/submissions/67624908 (HarmonicFloorSum)
// https://yukicoder.me/submissions/1009595 (HarmonicFloorSum)

// n >= 0����exponent >= 0�̎�
// sum( int i = 1 ; i <= n ; i++ ){ floor( n / i ) ^ exponent }
// ��O((s(log(s)+1)^{s+2}n(log(s)log(n)+1))^{1/(s+1)})�ŋ��߂�B
template <typename INT1 , typename INT2> ll FloorRiemannZeta( const INT1& n , const INT2& s );

// sum( int i = 1 ; i <= n ; i++ ){ floor( n / i ) }
// ��O(��|n|)�ŋ��߂�B
// ����n>=0�̎��Axy���ʓ��̑�1�ی��i���܂܂��j��xy<=n�𖞂����i�q�_(x,y)�̌��ƈ�v����B
template <typename INT> inline INT HarmonicFloorSum( const INT& n );


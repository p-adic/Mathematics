// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/a.hpp

#pragma once

// verify:
// https://atcoder.jp/contests/practice2/submissions/44638653 (FloorSum)
// https://atcoder.jp/contests/abc230/submissions/57700207 (HarmonicFloorSum)
// https://yukicoder.me/submissions/1009595 (HarmonicFloorSum)

// e=0.1�ƒu�������Axy���ʓ��̂S�_(0,0),(0,y/q),(n-e,(y+d*(n-e))/q)),(n-e,0)������
// ��`���̊i�q�_�̌�
// sum( int i = 0 ; i < n ; i++ ){ ( y + d * i ) / q }
// ��O(log_2 min(d,q))�ŋ��߂�B
template <typename INT> INT FloorSum( const INT& y , const INT& d , const INT& q , const INT& n );

// n >= 0����exponent >= 0�̎�
// sum( int i = 1 ; i <= n ; i++ ){ ( n / i ) ^ exponent }
// ��O(��n)�ŋ��߂�B
template <typename INT> inline INT FloorRiemannZeta( const INT& n , const INT& exponent );

// sum( int i = 1 ; i <= n ; i++ ){ ( n / i ) }
// ��O(��|n|)�ŋ��߂�B����n>=0�̎��Axy���ʓ��̑�1�ی��i���܂܂��j��xy<=n�𖞂����i�q�_(x,y)��
// ���ƈ�v����B
template <typename INT> inline INT HarmonicFloorSum( const INT& n );


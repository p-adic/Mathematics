// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/LatticePoint/a.hpp

#pragma once

// verify: https://atcoder.jp/contests/practice2/submissions/44638653

// e=0.1�ƒu�������Axy���ʓ��̂S�_(0,0),(0,a_0/q),(n-e,(a_0+a_1*(n-e))/q)),(n-e,0)������
// ��`���̊i�q�_�̌�
// sum( int i = 0 ; i < n ; i++ ){ ( a_0 + a_1 * i ) / q }
// ��O(a_0+a_1+q+n)�ŋ��߂�B
template <typename INT>
INT FloorSum( const INT& a_0 , const INT& a_1 , const INT& q , const INT& n );

// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Counting/LatticePoint/a.hpp

#pragma once

// e=0.1�ƒu�������Axy���ʓ��̂S�_(0,0),(0,a_0/q),(n-e,(a_0+a_1*(n-e))/q)),(n-e,0)������
// ��`���̊i�q�_�̌�
// sum( i , 0 , n ){ ( a_0 + a_1 * i ) / q }
template <typename INT>
INT FloorSum( const INT& a_0 , const INT& a_1 , const INT& q , const INT& n );

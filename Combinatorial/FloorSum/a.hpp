// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/a.hpp

#pragma once

// verify:
// https://atcoder.jp/contests/practice2/submissions/44638653 (FloorSum)

// e=0.1�ƒu�������Axy���ʓ��̂S�_(0,0),(0,y/q),(n-e,(y+d*(n-e))/q)),(n-e,0)������
// ��`���̊i�q�_�̌�
// sum( int i = 0 ; i < n ; i++ ){ ( y + d * i ) / q }
// ��O(log_2 min(d,q))�ŋ��߂�B
template <typename INT> INT FloorSum( const INT& y , const INT& d , const INT& q , const INT& n );


// f.size()��D0�Af[0].size()��D1�ƒu����
// sum(int i=0;i<n;i++) sum(int j=0;j<D0;j++) sum(int k=0;k<D1;k++){
//   f[j][k]i^j((y+d*i)/q)^k
// }
// ��O�v�ZO((D0+(log_2 min(d,q))D1)^5)�A
// �ċA�v�ZO((D0+(log_2 min(d,q))D1)^4 log_2 min(d,q))�ŋ��߂�B
// https://qiita.com/sounansya/items/51b39e0d7bf5cc194081
// �����ƂɎ����B
template <typename T , typename INT , int deg_max = 100> T FloorSumComposition( const INT& y , const INT& d , const INT& q , const INT& n , const vector<vector<T>>& f );

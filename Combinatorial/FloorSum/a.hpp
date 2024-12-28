// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/a.hpp

#pragma once

// verify:
// https://atcoder.jp/contests/practice2/submissions/44638653 (FloorSum)

// e=0.1と置いた時、xy平面内の４点(0,0),(0,y/q),(n-e,(y+d*(n-e))/q)),(n-e,0)を結ぶ
// 台形内の格子点の個数
// sum( int i = 0 ; i < n ; i++ ){ ( y + d * i ) / q }
// をO(log_2 min(d,q))で求める。
template <typename INT> INT FloorSum( const INT& y , const INT& d , const INT& q , const INT& n );


// f.size()をD0、f[0].size()をD1と置いて
// sum(int i=0;i<n;i++) sum(int j=0;j<D0;j++) sum(int k=0;k<D1;k++){
//   f[j][k]i^j((y+d*i)/q)^k
// }
// を前計算O((D0+(log_2 min(d,q))D1)^5)、
// 再帰計算O((D0+(log_2 min(d,q))D1)^4 log_2 min(d,q))で求める。
// https://qiita.com/sounansya/items/51b39e0d7bf5cc194081
// をもとに実装。
template <typename T , typename INT , int deg_max = 100> T FloorSumComposition( const INT& y , const INT& d , const INT& q , const INT& n , const vector<vector<T>>& f );

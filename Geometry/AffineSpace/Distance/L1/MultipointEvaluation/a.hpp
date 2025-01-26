// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/MultipointEvaluation/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1002390（Multipoint_L1_Distance）

// x軸と平行な直線上の点と点群の距離（第length最小値まで）の多点評価
// （O(#x0(log #x0 + length) + #v1(log #v1 + (1+length)log(1+length)))）
template <typename INT> vector<set<pair<INT,int>>> Multipoint_L1_Distance( const vector<INT>& x0 , const INT& y0 , const vector<pair<INT,INT>>& v1 , const int& length = 1 );
// y軸と平行な直線上の点と点群の距離（第length最小値まで）の多点評価
// （O(#x0(log #x0 + length) + #v1(log #v1 + (1+length)log(1+length)))）
template <typename INT> inline vector<set<pair<INT,int>>> Multipoint_L1_Distance( const INT& x0 , const vector<INT>& y0 , vector<pair<INT,INT>> v1 , const int& length = 1 );

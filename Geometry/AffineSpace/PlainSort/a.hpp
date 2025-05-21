// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/PlainSort/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1087002 (ArgumentSort)

// 象限を計算する。（O(1)）
// ただし原点は0、x軸正方向は1、y軸正方向は2、x軸負方向は3、y軸負方向は4とする。
template <typename INT , template <typename...> typename PAIR> inline int Quadrant( const PAIR<INT,INT>& xy );

// centre中心の{象限,偏角,距離,添字番号}でソートする。
template <typename INT , template <typename...> typename PAIR> vector<int> ArgumentSort( const vector<PAIR<INT,INT>>& xy , const PAIR<INT,INT>& centre );

// xy_midから縱横長さ2Lの範囲の平面内の点群を再帰的に4分割してソートする。（O(size log L)）
template <typename INT , template <typename...> typename PAIR> vector<int> RecursiveDivisionSort( const vector<PAIR<INT,INT>>& xy , const PAIR<INT,INT>& xy_mid , const INT& L );

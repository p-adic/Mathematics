// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/PlainSort/a.hpp

#pragma once

// xy_midから縱横長さ2Lの範囲の平面内の点群を再帰的に4分割してソートする。（O(size log L)）
template <typename INT> vector<int> PlainSort( const vector<pair<INT,INT>>& xy , const pair<INT,INT>& xy_mid , const INT& L );

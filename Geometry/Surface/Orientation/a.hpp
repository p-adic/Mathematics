// c:/Users/user/Documents/Programming/Mathematics/Geometry/Surface/Orientation/a.hpp

#pragma once

// facesが曲面の三角形分割(V,E,F)の面である場合にのみサポート。

// O(|F| α(|F|))で{各連結成分の面番号,各連結成分の向き付け可能性}を返す。
template <typename T> pair<vector<vector<T>>,vector<bool>> Orientability( const vector<vector<T>>& faces );


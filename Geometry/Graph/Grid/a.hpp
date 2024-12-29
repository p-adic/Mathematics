// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

#include "a_Alias.hpp"

template <typename E>
class GridGraph :
  public EnumerationGraph<T2<int>,T2<int>(&)(const int&),int(&)(const T2<int>&),E>
{

public:
  inline GridGraph( E e );

};

int H , W , H_minus , W_minus;
ll HW;
vector<string> grid;
char walkable = '.' , unwalkable = '#';

inline T2<int> EnumHW( const int& v );
inline int EnumHW_inv( const T2<int>& ij );

vector<T2<int>> EdgeOnGrid( const T2<int>& v );
vector<pair<T2<int>,ll>> WEdgeOnGrid( const T2<int>& v );

inline void SetWallStringOnGrid( const int& i , vector<string>& S );

// xy_axis = true: 右と上を正軸方向とする座標
// (0,1) -> U
// (1,0) -> R
// (0,-1) -> D
// (-1,0) -> L
// xy_axis = false: 下と右を正軸方向とする座標
// (-1,0) -> U
// (0,1) -> R
// (1,0) -> D
// (0,-1) -> L
const string direction = "URDL";
bool grid_edge_i_plus = true;
bool grid_edge_j_plus = true;
bool grid_edge_i_minus = true;
bool grid_edge_j_minus = true;

inline int DirectionNumberOnGrid( const int& i , const int& j , const int& k , const int& h , const bool& xy_axis = false );
inline int DirectionNumberOnGrid( const T2<int>& v , const T2<int>& w , const bool& xy_axis = false );
inline int DirectionNumberOnGrid( const int& v , const int& w , const bool& xy_axis = false );
inline int DirectionNumberOnGrid( const char& c );
inline int ReverseDirectionNumberOnGrid( const int& n );

inline T2<int> DirectionVectorOnGrid( const char& c , const bool& xy_axis = false );

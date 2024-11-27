// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Double/Grid/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../Graph/Linear/a.hpp"
#include "../../../../Graph/Grid/a.hpp"

// verify:
// https://yukicoder.me/submissions/982907�idirection = 1�j
// https://yukicoder.me/submissions/982914�idirection = 2�j

template <typename E>
class GridDijkstra :
  public DoubleDijkstra<int,LinearGraph,int,decldecay_t(declval<E>()({0,0}).front().second),GridGraph<E>,vector<int>(&)(const int&)>
{

public:
  // 1: 0->1->...->H-1
  // 2: 0<-1<-...<-H-1
  inline GridDijkstra( E e , const int& direction = 1 );
  
};

inline vector<int> GridVertex( const int& i );

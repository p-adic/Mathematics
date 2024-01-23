// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/a.hpp

#pragma once
#include "../BreadthFirst/a.hpp"

// verify:
// https://yukicoder.me/submissions/945933�i���_DFS�ɂ��S�T���j
// https://yukicoder.me/submissions/945935�i���_DFS�ɂ��A�������擾�j

template <typename GRAPH>
class DepthFirstSearch :
  public VirtualBreadthFirstSearch<GRAPH>
{

public:
  template <typename...Args> inline DepthFirstSearch( GRAPH& G , const Args&... args );

private:
  inline void Push( list<int>& next , const int& i );

};

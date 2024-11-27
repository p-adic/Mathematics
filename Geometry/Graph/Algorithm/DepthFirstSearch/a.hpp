// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/a.hpp

#pragma once
#include "../BreadthFirstSearch/a.hpp"

// verify:
// https://yukicoder.me/submissions/955873�i��n�_��Shift�ɂ�鑽�_DFS�ł̑S�T���j
// https://yukicoder.me/submissions/953239�iSetConnectedComponent�j
// https://yukicoder.me/submissions/953242�iTopologicalSort�j

template <typename T , typename GRAPH>
class DepthFirstSearch :
  public VirtualBreadthFirstSearch<T,GRAPH>
{
  
public:
  // Args��T��list<T>
  template <typename...Args> inline DepthFirstSearch( GRAPH& G , const T& not_found , Args&&... args );

private:
  inline void Push( list<T>& next , const T& t );

};

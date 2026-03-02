// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/a.hpp

#pragma once

#ifdef DEBUG
  #include "../BreadthFirstSearch/Debug/a.hpp"
#else
  #include "../BreadthFirstSearch/a.hpp"
#endif

// verify:
// https://yukicoder.me/submissions/955873（一始点のShiftによる多点DFSでの全探索）
// https://yukicoder.me/submissions/953239（SetConnectedComponent）
// https://yukicoder.me/submissions/953242（TopologicalSort）

// GRAPHは辺Edge:T->(T \times ...)^{< \omega}を持つグラフに相当する型。

// 入力の範囲内で要件
// (1) Gは有向グラフである。
// (2) externalはGの頂点でない。
// を満たす場合にのみサポート。

template <typename T , typename GRAPH>
class DepthFirstSearch :
  public VirtualBreadthFirstSearch<T,GRAPH>
{
  
public:
  // ArgsはTやvector<T>など。
  template <typename...Args> inline DepthFirstSearch( GRAPH& G , const T& external , Args&&... args );

private:
  inline void Push( list<pair<T,T>>& next , const T& t , const T& p );

};

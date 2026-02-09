// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/LCA/DST/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1147592 (LCA, d)

#include "../../a.hpp"
#include "../../EulerTour/a.hpp"
#include "../../../../../../../SetTheory/DirectProduct/AffineSpace/DisjointSparseTable/a.hpp"

template <typename TREE>
class DSTOnTree :
  public DepthFirstSearchOnTree<TREE> ,
  public EulerTour<TREE>
{

private:
  // 頂点番号を深さ降順にソートしたもの
  vector<int> m_vertex;
  DisjointSparseTable<int> m_dst;
  
public:
  inline DSTOnTree( TREE& T , const int& root = 0 );
  inline int LCA( const int& i , const int& j );
  inline int d( const int& i , const int& j );

private:
  vector<int> HeightArray();
  
};

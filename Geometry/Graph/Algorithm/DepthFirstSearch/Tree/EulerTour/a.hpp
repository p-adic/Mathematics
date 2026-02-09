// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/EulerTour/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1147592 (Subtree, Vertex, Vertex_inv)

#include "../../../../../../Utility/Tuple/Wrap/a.hpp"

// TREEはGraph<Edge>と表せる、木T=(V_T,E_T)に相当する型。特にV_Tの型はintに限られる。
// ただしE_Tは辺V_T -> (V_T \times ...)^{< \omega}に相当する関数オブジェクト。

// 入力の範囲内で
// (1) Tが無向木である。
// を満たす場合にのみサポート。

// 構築O(|V_T|+|E_T|)
// 部分木に対応する区間取得O(1)
// オイラーツアー順の頂点列取得O(1)
template <typename TREE>
class EulerTour
{

private:
  TREE& m_T;
  int m_length;
  // オイラーツアーで取る頂点番号の列
  vector<int> m_vertex;
  vector<vector<int>> m_vertex_inv;

public:
  EulerTour( TREE& T , const int& root = 0 );

  // T.size()ではなくオイラーツアーの長さ。
  inline const int& Length() const noexcept;
  inline T2<int> Subtree( const int& t ) const;
  inline const vector<int>& Vertex() const noexcept;
  inline const vector<int>& Vertex_inv( const int& t ) const;

};

// DSTと組み合わせてクエリO(1)でLCA計算も可能。
// ..／LCA/DST/

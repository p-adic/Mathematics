// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/957468（Depth,Heaviness）

#include "../a.hpp"

// TREEはGraph<Edge>と表せる、木T=(V_T,E_T)に相当する型。特にV_Tの型はintに限られる。
// ただしE_Tは辺V_T -> (V_T \times ...)^{< \omega}に相当する関数オブジェクト。

// 入力の範囲内で
// (1) Tが無向木であるか、rootを根とし葉に向かう有向木である。
// を満たす場合にのみサポート。

// 構築O(|V_T|)

// 根からの辺の本数（深さ）取得O(|V_T|)（二度目以降はO(1)）
// 葉からの辺の本数の最大／最小値（高さ）取得O(|V_T|)（二度目以降はO(1)）
// 部分木の辺の本数（重さ）取得O(|V_T|)（二度目以降はO(1)）

// 半径: ./Diameter/
// HL分解: ./HeaviLightDecomposition/
// LCA: ./LCA/
// 最近傍探索: ./NearestNeighbour/
// 木DP: ./RootingDP/
// 重み付き木: ./Weighted/
// 根からの距離の総和および2点間距離の総和: ./WeightSum/
template <typename TREE>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<int,TREE> ,
  public PointedSet<int>
{

protected:
  // size()は祖先クラスのBreadFirstSearchに定義。
  
  // 根からのDFS順にノード番号を格納。
  vector<int> m_node_num;

  // 子ノードのノード番号を格納。
  vector<vector<int>> m_children;
  // 親ノードをjとした時m_children[j]の何番目の成分かを格納。
  // ただし親ノードが存在しない時は-1を格納。
  vector<int> m_children_num;
  bool m_set_children;

  // 根からの距離（深さ）を格納。
  vector<int> m_depth;
  bool m_set_depth;

  // 葉からの距離（高さ）を格納。
  vector<int> m_height_max;
  vector<int> m_height_min;
  bool m_set_height;

  // 部分木の辺の本数（サイズ）を格納。
  vector<int> m_heaviness;
  bool m_set_heaviness;

public:
  inline DepthFirstSearchOnTree( TREE& T , const int& root = 0 );
  inline void Initialise() = delete;
  inline void Initialise( const int& init ) = delete;
  inline void Shift( const int& init ) = delete;

  inline const int& Root() const;
  inline const int& Parent( const int& i );
  inline const vector<int>& Children( const int& i );
  inline const int& Depth( const int& i );
  inline const int& Height( const int& i , const bool& maximum = true );
  inline const int& Heaviness( const int& i );
  // 無向グラフとしての次数を返す。
  inline int Degree( const int& i );
  // rootを根とした時に葉であるか否かを返す。ただしroot=-1は現在の根にrootを置き換える。
  inline bool IsLeaf( const int& i , const int& root = -1 );

  // 根からのDFS順にノードを番号づける。
  // reversed = trueの場合は帰りがけ順ではなく行きがけ順の逆順であることに注意。
  inline const int& NodeNumber( const int& i , const bool& reversed = false ) const;
  // 共通の親を持つノード間で昇順に番号づける。
  inline const int& ChildrenNumber( const int& i );
  // Ordは全順序の族ord:N \times N^2 -> {0,1}に相当する型。
  // 各ノードiの子ノードの格納順をord( i , - , - )昇順に変更する。
  template <typename Ord> inline void ReorderChildren( Ord& ord );
    
private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetHeaviness();

};

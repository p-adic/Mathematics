// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/LCA/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/957468（Ancestor,LCA）

#include "../a.hpp"

// 以下、入力の範囲内で
// (2) 各ノードの葉からの辺の本数 < 2^digit
// を満たす場合にのみサポート。
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
// 先祖取得O(|V_T| digit)（二度目以降はO(digit)）
// 最近接共通先祖取得O(|V_T| digit)（二度目以降はO(digit)）
template <typename DFST>
class AncestorDoubling
{

protected:
  DFST* m_p_dfst;
  int m_size;
  vector<vector<int>> m_doubling;

public:
  inline AncestorDoubling( DFST& dfst );

  // n階の親Parent^n( i )を返す。
  int Ancestor( DFST& dfst , int i , int n );

  // {iとjの最近接共通祖先,LCAからi側に進める場合に進んだ先の頂点のラベル,同j側}を返す。
  tuple<int,int,int> LCA( DFST& dfst , int i , int j );

private:
  const vector<int>& Get( const int& d );
  
};

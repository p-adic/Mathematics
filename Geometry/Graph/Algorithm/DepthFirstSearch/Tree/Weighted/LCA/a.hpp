// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/Weighted/LCA/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../a.hpp"

// 先祖取得O(|V_T| digit)（二度目以降はO(digit)）
// 最近接共通先祖取得O(|V_T| digit)（二度目以降はO(digit)）
template <typename DFST , typename MONOID , typename U>
class WAncestorDoubling
{

protected:
  DFST* m_p_dfst;
  MONOID* m_p_M;
  int m_size;
  // {先祖ノード,辺の重さの右総乗,辺の重さの左総乗}を格納。
  vector<vector<tuple<int,U,U>>> m_wdoubling;

public:
  inline WAncestorDoubling( DFST& dfst );

  // {n階の親Parent^n( i ),そこまでのの辺の重みの右／左総乗}を返す。
  pair<int,U> WAncestor( DFST& dfst , int i , int n , const bool& right = true );

  // {iとjの最近接共通祖先,LCAからi側に進める場合に進んだ先の頂点のラベル,同j側,
  // iからの重みの右総乗,jからの重みの左総乗}を返す。
  tuple<int,int,int,U,U> WLCA( DFST& dfst , int i , int j );

private:
  const vector<int>& Get( const int& d );
  
};
template <typename DFSWT> WAncestorDoublng( DFSWT ) -> WAcestorDoubling<DFSWT,decldecay_t(declval<DSFWT>().Monoid()),decldecay_t(declval<DSFWT>().WDepth(0))>;

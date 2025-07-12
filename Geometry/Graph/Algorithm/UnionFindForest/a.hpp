// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/a.hpp

#pragma once
#include "../../Linear/a.hpp"
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/941558
// https://yukicoder.me/submissions/941553
// https://yukicoder.me/submissions/941556
// https://atcoder.jp/contests/abc087/submissions/50885973（ポテンシャル）

// GRAPHは辺Edge:T->(T \times ...)^{< \omega}を持つグラフに相当する型。

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。

// - 構築 O(|V_G| + |E_G| α(|V_G|))

// - 一点根取得 O(α(|V_G|))
// - 全根取得 O(|V_G|)
// - 根数取得 O(1)

// - 二点間ポテンシャル取得 O(α(|V_G|))
// - 二点接合 O(α(|V_G|))
template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
class AbstractUnionFindForest
{

private:
  GRAPH& m_G;
  ABEL_GROUP m_M;
  int m_root_size;
  vector<int> m_pred;
  vector<int> m_height;
  // m_w[num]はnum番目のnodeがrootならば0、rootでないならば親nodeからのパスの符号付き重みを返す。
  // Graftと整合的な解xが存在する場合にはx[num]-x[親node]を返すことと等価。
  vector<U> m_w;
  bool m_solvable;
  
public:
  AbstractUnionFindForest( GRAPH& G , ABEL_GROUP M );

  // tのrootを計算して返す。
  // Enumerationを介すのでconst参照にしない。
  const decltype( ( declval<GRAPH>().Enumeration(0) ) ) RootOfNode( const T& );
  // rootを全て返す。
  template <template <typename...> typename V> vector<T> GetRoot() const;

  // t1からt0へ向かうパスの符号付き重みを返す。
  // Graftと整合的な解xが存在する時のx[t0]-x[t1]の取得と等価。
  inline U Potential( const T& t0 , const T& t1 );

  // 頂点数を返す
  inline const int& NodeSize() const noexcept;
  // 連結成分数を返す
  inline const int& RootSize() const noexcept;

  // t1からt0へ符号付き重みwの有向辺を結ぶ操作と整合的に
  // なるようにrootを接合。符号付き重みの整合性が取れない場合はfalseを返す。
  // 返り値はx[t0]-x[t1]=wの解の有無と等価。
  const bool& Graft( const T& t0 , const T& t1 , const U& w = U() );
  template <typename PATH> inline const bool& Graft( const T& t0 , const PATH& t1 );
  const bool& Solvable() const noexcept;
  
};
template <typename GRAPH , typename ABEL_GROUP> AbstractUnionFindForest( GRAPH& G , ABEL_GROUP M ) -> AbstractUnionFindForest<inner_t<GRAPH>,GRAPH,inner_t<ABEL_GROUP>,ABEL_GROUP>;

template <typename U = int>
class UnionFindForest :
  public LinearGraph ,
  public AbstractUnionFindForest<int,LinearGraph,U,AdditiveGroup<U>>
{

public:
  inline UnionFindForest( const int& size );

};

// 連結時に演算を行う機能はなし。（2乗和の管理など、副作用を持たせたりしたいので）
// 外部に配列を用意し、連結成功か否かをRootOfNodeで判定しながら
// 演算を行うとよい。
// (1) 連結成分ごとの頂点数なら、vector<int> weight( N , 1 );と加算。
// (2) 連結成分ごとの頂点数の2乗和を管理するなら、(1)に加えて積の倍を引く副作用。
// (3) 連結成分ごとの頂点リストならvector<vector<int>> vertex = {{0},{1},...,{N-1}}とマージ。

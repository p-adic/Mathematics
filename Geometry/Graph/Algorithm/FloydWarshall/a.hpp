// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/FloydWarshall/a.hpp

#pragma once
#include "../../a.hpp"
#include "../../../../Algebra/Monoid/Semirng/MeetSemirng/a.hpp"

// verify:
// https://yukicoder.me/submissions/1108900（Get）

// 構築O(size^3)

// 一辺短縮O(size^2)

// 全経路の重みの下限取得O(1)
// 最短経路取得O(1)
template <typename U , typename IDEMPOTENT_SEMIRNG>
class AbstractFloydWarshall
{

private:
  IDEMPOTENT_SEMIRNG m_R;
  int m_size;
  vector<vector<U>> m_weight;
  vector<vector<int>> m_prev;

public:
  // dを関数テンプレートで置き換えてもメモリ削減は見込めない。
  inline AbstractFloydWarshall( IDEMPOTENT_SEMIRNG R , vector<vector<U>> d = {} );

  void Initialise( vector<vector<U>> d = {} );

  // 入力の範囲内で要件
  // (1) uはRの乗法に関してnon-negativeである。
  // (2) start != goalである。
  // が成り立つ場合のみサポート。
  // 無向グラフの場合は反対向きの辺も追加する必要があることに注意。
  void SetMeet( const int& start , const int& goal , U u );

  // 入力の範囲内で要件
  // (1) RはUの非単位的半環構造で加法が冪等的なもの。つまり
  //   (1-1)加法∧についてmeet半束（可換羃等半群）である。
  //   (1-2)乗法*について半群である。
  //   (1-3)乗法が加法に対し分配的である。
  //   を満たす。以下∧の定める等号つき半順序を<=と置き、∧に関する単位元をinftyと置く。
  // (2) dの値はRの乗法に関してnon-negative、つまり
  //     - Uの任意の要素sとdの任意の値tに対し
  //       - s<=s*t
  //       - s<=t*s
  //     である。
  // (3) inftyでないdの値size個以下のRに関する積でinftyが表せない。
  // (4) 「m_Rが単位的でありdの対角成分が単位元である」が成り立たないならばstart!=goalである。
  // が成り立つ場合にのみサポート。

  // ただし<=が等号つき全順序である場合、(1-3)は
  // (1-3)' *が<=に関する半順序半群演算、つまり
  //     - Uの任意の要素s,t,uに対しs<=tならば
  //       - u*s <= u*t
  //       - s*u <= t*u
  //     である。
  // と同値であることに注意。

  // 全経路の乗法的重み（edgeごとの重みのRに関する積）の
  // ∧に関する下限（多変数化した∧への適用値）を返す。
  inline const U& Get( const int& start , const int& goal ) const;

  // 入力の範囲内で要件
  // (1)' Rはbool operator<(const U&,const U&)に関するminトロピカル非単位的半環である。つまり
  //   (1-1)' <が最大元inftyを持つ全順序である。
  //     （以下<の定める等号つき全順序を<=と置く）
  //   (1-2)' Rの乗法*が半群演算である。
  //   (1-3)' *が<=に関する半順序半群演算、つまり
  //     - Uの任意の要素s,t,uに対しs<=tならば
  //       - u*s <= u*t
  //       - s*u <= t*u
  //   である。
  // (2) dの値はRの乗法に関してnon-negative、つまり
  //     - Uの任意の要素sとdの任意の値tに対し
  //       - s<=s*t
  //       - s<=t*s
  //     である。
  // (3) inftyでないdの値size個以下のRに関する積でinftyが表せない。
  // (4) start!=goalである。
  // が成り立つ場合にのみサポート。

  // 各２点間の最短経路におけるprevを返す。
  // ただし最短経路が存在しない場合のprevは-1と定める。
  inline const int& prev( const int& start , const int& goal ) const;

  inline const U& infty() const noexcept;
  
};
template <typename IDEMPOTENT_SEMIRNG> AbstractFloydWarshall( IDEMPOTENT_SEMIRNG ) -> AbstractFloydWarshall<inner_t<IDEMPOTENT_SEMIRNG>,IDEMPOTENT_SEMIRNG>;

// コストの和ではなく最大値を計算したい場合は
// AbstractMonoid M{ Max<ll> , 0LL };
// AbstractTropicalSemirng R{ ll(1e18) , M };
// AbstractFloydWarshall fw{ R , w }; vector<vector<ll>> d = fw.GetDistance();
// とすればよい。

template <typename U>
class FloydWarshall :
  public AbstractFloydWarshall<U,AdditiveTropicalSemirng<U>>
{

public:
  inline FloydWarshall( U infty_U , vector<vector<U>> d = {} );

};

// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Mo/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/954977（Get）
// https://atcoder.jp/contests/abc174/submissions/50552834（Solve）

// 入力の範囲内で要件
// (1) Fは写像f:N^2 -> R1に相当する型である。
// (2) DFxは写像dfx:R1& \times N^3 -> R1&に相当する型である。
// (3) DFyは写像dfy:R1& \times N^3 -> R1&に相当する型である。
// (4) いかなる(x,y,x') in N^3に対してもf(x',y) = dfx(f(x,y),x,y,x')である。
// (5) いかなる(x,y,y') in N^3に対してもf(x,y') = dfy(f(x,y),x,y,y')である。
// (6) Gは写像g:R1 \times N -> R2に相当する型である。
// を満たす場合にのみサポート。

// 零初期化O(1)
// オフラインクエリ初期化O(min(ΔX+Q,Q log Q))

// 全クエリ回答取得O((ΔX+Q)sqrt(ΔY))
// （ただしdfx(r,x,y,x')とdfy(r,x,y,y')の計算量をO(|x-x'|+sqrt(ΔY))とO(|y-y'|)と仮定する）

class Mo
{

private:
  int m_Q;
  // バケット数（yの動き幅/y_dif_sqrt+1）
  int m_Y_d;
  // バケット分割＆ソート済みのクエリ{x,y,q}を格納する。
  vector<vector<tuple<int,int,int>>> m_query;

public:
  inline Mo() = default;
  // y_dif_sqrt設定時はそれを、非設定時はyの動き幅の平方根をバケットサイズにする。
  template <typename QUERY> inline Mo( const QUERY& query , int y_dif_sqrt = 0 );

  // クエリを変更する。（追加ではない）
  template <typename QUERY> inline void Set( const QUERY& query , int y_dif_sqrt = 0 );
  // バケット分割＆ソート済みのクエリを返す。
  inline const vector<vector<tuple<int,int,int>>>& Get() const noexcept;

  // 莫のアルゴリズムで各クエリquery[i] = (x,y)に対するg(f(x,y),i)を計算。
  template <typename F , typename DFx , typename DFy , typename G> vector<decay_t<ret_t<G,ret_t<F,int,int>,int>>> Solve( F& f , DFx& dfx , DFy& dfy , G& g ) const;
  // 莫のアルゴリズムで各クエリquery[i] = (x,y)に対するf(x,y)を計算。
  template <typename F , typename DFx , typename DFy> inline vector<ret_t<F,int,int>> Solve( F& f , DFx& dfx , DFy& dfy ) const;
  // バケット変更時にもfでなくdfyが呼ばれることに注意。
  // バケット変更時にfを呼びたい場合はdfyの定義でyが小さくなる際にfを呼ぶようにすれば良い。

private:
  // std::sortでのソートを行う。
  template <typename QUERY> inline void IntroSort( const QUERY& query , const int& y_start , const int& y_dif_sqrt );
  template <typename QUERY> inline void BucketSort( const QUERY& query , const int& x_start , const int& x_dif , const int& y_start , const int& y_dif_sqrt );
  template <typename R , typename DFx , typename DFy , typename G> void Solve_Body( vector<R>& answer , R& temp , int& x , int& y , DFx& dfx , DFy& dfy , const int& d , const int& i_start , G& g ) const;
  
};

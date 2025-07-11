// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Mo/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/954977（Get）
// https://atcoder.jp/contests/abc174/submissions/67484031（Solve）

// 入力の範囲内で要件
// (1) Fは写像f:N^2 -> R1に相当する型である。
// (2) DFxpは写像dfxp:R1 \times N^3 -> R1に相当する型である。
// (3) DFxmは写像dfxm:R1 \times N^3 -> R1に相当する型である。
// (4) DFypは写像dfyp:R1 \times N^3 -> R1に相当する型である。
// (5) DFymは写像dfym:R1 \times N^3 -> R1に相当する型である。
// (6) いかなる(x,y,x') in N^3に対してもf(x',y) = (x<x'?dfxp:dfxm)(f(x,y),x,y,x')である。
// (7) いかなる(x,y,y') in N^3に対してもf(x,y') = (y<y'?dfyp:dfym)(f(x,y),x,y,y')である。
// (8) Gは写像g:R1 \times N -> R2に相当する型である。
// を満たす場合にのみサポート。
// DFxp,DFxm,DFyp,DFymは参照返しにするとint型で2.5倍ほど遅くなるのでムーブセマティクスにする。

// y側をバケット分割し、各バケットでxを単調にして処理する。

// 零初期化O(1)
// オフラインクエリ初期化O(min(ΔX+Q,Q log Q))

// 全クエリ回答取得O((ΔX+Q)sqrt(ΔY))
// （ただし(x<x'?dfxp:dfxm)(r,x,y,x')と(y<y'?dfyp:dfym)(r,x,y,y')の計算量を
//  O(|x-x'|+sqrt(ΔY))とO(|y-y'|)と仮定する）
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
  template <typename F , typename DFxp , typename DFxm , typename DFyp , typename DFym , typename G> vector<decay_t<ret_t<G,ret_t<F,int,int>,int>>> Solve( F& f , DFxp& dfxp , DFxm& dfxm , DFyp& dfyop , DFym& dfym , G& g , const bool& reverse = true ) const;
  // 莫のアルゴリズムで各クエリquery[i] = (x,y)に対するf(x,y)を計算。
  template <typename F , typename DFxp , typename DFxm , typename DFyp , typename DFym> inline vector<ret_t<F,int,int>> Solve( F& f , DFxp& dfxp , DFxm& dfxm , DFyp& dfyp , DFym& dfym , const bool& reverse = true ) const;
  // バケット変更時にはfでなくdfxmが呼ばれることに注意。
  // バケット変更時にfを呼びたい場合はdfxmの定義でfを呼ぶようにすれば良い。

private:
  // std::sortでのソートを行う。
  template <typename QUERY> inline void IntroSort( const QUERY& query , const int& y_start , const int& y_dif_sqrt );
  template <typename QUERY> inline void BucketSort( const QUERY& query , const int& x_start , const int& x_dif , const int& y_start , const int& y_dif_sqrt );
  template <typename R , typename DFxp , typename DFxm , typename DFyp , typename DFym , typename G> void Solve_Body( vector<R>& answer , R& temp , int& x , int& y , DFxp& dfxp , DFxm& dfxm , DFyp& dfyp , DFym& dfym , const int& d , const int& i_start , G& g , const bool& reversed ) const;
  
};

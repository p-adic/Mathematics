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
// (9) queryは組(x,y)の配列である。
// を満たす場合にのみサポート。
// DFxp,DFxm,DFyp,DFymは参照返しにするとint型で2.5倍ほど遅くなるのでムーブセマティクスにする。

// xの動く広さをX、yの動く広さをYと置く。
// y側をバケット分割し、各バケットでxを単調にして処理する。
// xを減らす差分計算が実装できない場合、dxxmをフラグのみ建てる関数にして
// fをフラグが立っている時にフラグを戻して端から計算し直す関数にすれば良い。

// 零初期化O(1)
// オフラインクエリ初期化O(min(X+Q,Q log Q))

// 全クエリ回答取得O((X+Q)sqrt(Y))
// （ただし(x<x'?dfxp:dfxm)(r,x,y,x')と(y<y'?dfyp:dfym)(r,x,y,y')の計算量を
//  O(|x-x'|+sqrt(Y))とO(|y-y'|)と仮定する）
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
  // バケット変更時にはfでなくreversed?dfxm:dfxpが呼ばれることに注意。
  // バケット変更時にfを呼びたい場合はreverseをfalseにしてdfxmの定義でfを呼ぶようにすれば良い。

private:
  // std::sortでのソートを行う。
  template <typename QUERY> inline void IntroSort( const QUERY& query , const int& y_start , const int& y_dif_sqrt );
  template <typename QUERY> inline void BucketSort( const QUERY& query , const int& x_start , const int& x_dif , const int& y_start , const int& y_dif_sqrt );
  template <typename R1 , typename R2 , typename DFxp , typename DFxm , typename DFyp , typename DFym , typename G> void Solve_Body( vector<R2>& answer , R1& temp , int& x , int& y , DFxp& dfxp , DFxm& dfxm , DFyp& dfyp , DFym& dfym , const int& d , const int& i_start , G& g , const bool& reversed ) const;
  
};

// 種類数計算時は
  // using Mo_t = int;
  // auto f = [&]( const int& l , const int& r ) -> Mo_t {
  //   CERR( "Reset: [" , l , "," , r , "]"  );
  //   Mo_t answer = 0;
  //   FOREQ( i , l , r ){
  //     found[C[i]]++ == 0 ? ++answer : answer;
  //   }
  //   return answer;
  // };
  // // l->l_next
  // auto dflp = [&]( Mo_t a , const int& l , const int& r , const int& l_next ) -> Mo_t {
  //   CERR( "[" , l , "," , r , "] - > [" , l_next , "," , r , "]"  );
  //   int i_max = min( r , l_next - 1 );
  //   FOREQ( i , l , i_max ){
  //     --found[C[i]] == 0 ? --a : a;
  //   }
  //   return forward<Mo_t>( a );
  // };
  // // l_next<-l (折り返し時のみ)
  // auto dflm = [&]( Mo_t a , const int& l , const int& r , const int& l_next ) -> Mo_t {
  //   CERR( "[" , l , "," , r , "] - > [" , l_next , "," , r , "]"  );
  //   FOREQINV( i , min( r , l - 1 ) , l_next ){
  //     found[C[i]]++ == 0 ? ++a : a;
  //   }
  //   return forward<Mo_t>( a );
  // };
  // // r->r_next
  // auto dfrp = [&]( Mo_t a , const int& l , const int& r , const int& r_next ) -> Mo_t {
  //   CERR( "[" , l , "," , r , "] - > [" , l , "," , r_next , "]"  );
  //   FOREQ( i , max( l , r + 1 ) , r_next ){
  //     found[C[i]]++ == 0 ? ++a : a;
  //   }
  //   return forward<Mo_t>( a );
  // };
  // // r_next<-r
  // auto dfrm = [&]( Mo_t a , const int& l , const int& r , const int& r_next ) -> Mo_t {
  //   CERR( "[" , l , "," , r , "] - > [" , l , "," , r_next , "]"  );
  //   FOREQINV( i , r , max( l , r_next + 1 ) ){
  //     --found[C[i]] == 0 ? --a : a;
  //   }
  //   return forward<Mo_t>( a );
  // };
  // Mo mo{ query };
  // bool reverse = true;
  // auto answer = mo.Solve( f , dflp , dflm , dfrp , dfrm , reverse );
  // FOR( q , 0 , Q ){
  //   COUT( answer[q] );
  // }
// とすれば良い。

// l,r以外に依存する項がある場合（l,rが更新に使われ別の区間で総和計算をする場合など）は引数gを用いる。
// fの返り値が区間情報以外不要であればMo_tをT2<int>にして[l,r]を返す。
// その場合、dfxpたちは[l,r]を変更してもしなくても良い。
// 区間情報すら不要な場合はMo_tをboolとして常にtrueを返す。

// reverse=falseとしている場合はl_next<-lの実装を手抜いてfを呼んでも良い。例えば
  // // l_next<-l (!reverseの場合に折り返し時のみ)
  // auto dflm = [&]( Mo_t a , const int& l , const int& r , const int& l_next ) -> Mo_t {
  //   CERR( "[" , l , "," , r , "] - > [" , l_next , "," , r , "]"  );
  //   return forward<Mo_t>( a = f( l_next , r ) );
  // };
// とすればfが初期化とl_next<-lの時のみ呼ばれる。

// r_next<-rの実装を手抜きたい時は各種ラムダ式のl,rを逆にして
  // // r_next<-r (!reverseの場合に折り返し時のみ)
  // auto dfrm = [&]( Mo_t a , const int& r , const int& l , const int& r_next ) -> Mo_t {
  //   CERR( "[" , l , "," , r , "] - > [" , l , "," , r_next , "]"  );
  //   return forward<Mo_t>( a = f( r_next , l ) );
  // };
// として
  // auto answer = mo.Solve( f , dfrp , dfrm , dflp , dflm , reverse );
// に変更とすれば良い。

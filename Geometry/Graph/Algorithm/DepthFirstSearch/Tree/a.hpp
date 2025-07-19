// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/957468（Depth,Heaviness,Ancestor,LCA）
// https://yukicoder.me/submissions/957397（RootingDP）
// https://yukicoder.me/submissions/957399（RerootingDP）
// https://yukicoder.me/submissions/957400（RerootingDP）

// TREEはGraph<Edge>と表せる、木T=(V_T,E_T)に相当する型。特にV_Tの型はintに限られる。
// ただしE_Tは辺V_T -> (V_T \times ...)^{< \omega}に相当する関数オブジェクト。

// 入力の範囲内で
// (1) Tが無向木であるか、rootを根とし葉に向かう有向木である。
// を満たす場合にのみサポート。

// 構築O(|V_T|)

// 根からの辺の本数（深さ）取得O(|V_T|)（二度目以降はO(1)）
// 葉からの辺の本数の最大／最小値（高さ）取得O(|V_T|)（二度目以降はO(1)）
// 部分木の辺の本数（重さ）取得O(|V_T|)（二度目以降はO(1)）

// 木動的計画法O(|V_T|)
// 全方位木動的計画法O(|V_T|)

// 以下、入力の範囲内で
// (2) 各ノードの葉からの辺の本数 < 2^digit
// を満たす場合にのみサポート。
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
// 先祖取得O(|V_T| digit)（二度目以降はO(digit)）
// 最近接共通先祖取得O(|V_T| digit)（二度目以降はO(digit)）
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

  int m_digit;
  vector<vector<int>> m_doubling;
  bool m_set_doubling;

public:
  inline DepthFirstSearchOnTree( TREE& T , const int& root = 0 , const int& digit = 0 );
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

  // 入力の範囲内で要件
  // (1) 各ノードの高さ < 2^digit
  // を満たす場合のみサポート。
  // n階の親Parent^n( i )を返す。
  int Ancestor( int i , int n );

  // 入力の範囲内で要件
  // (1) 各ノードの高さ < 2^digit
  // を満たす場合のみサポート。
  // iとjの最近接共通祖先を返す。
  inline int LCA( int i , int j );
  // LCAからi,j側に進める場合に進んだ先の頂点のラベルをi_prev,j_prevに格納する。
  int LCA( int i , int j , int& i_prev , int& j_prev );

  // Uは適当な型、Fは写像f:U^{< \omega} \times N -> Uに相当する型。
  // 型推論のためにfはデフォルト引数で呼び出し可能とする。
  // 入力の範囲内で要件
  // (2) 任意の非負整数n,iとTの要素のみからなる任意の長さnの任意の列(u1,...,un)と
  //     その並び換え(v1,...,vn)に対しf((u1,...,un),i)=f((v1,...,vn),i)である。
  // を満たす場合のみサポート。
  // dp[j] = f(jの子ノードkを渡るdp[k]の列,j)
  // を満たす配列dpの根での値dp[root]をO(|V_T|)で求める。
  template <typename F> ret_t<F> RootingDP( F& f );
  // - ノードiにU型の値A[i]が定まっておりその部分木和をdp[i]に格納する場合：
  //   auto f = [&]( const vector<U>& u , const int& i ){
  //     U answer = A[i];
  //     for( auto& x : u ){ answer += x; }
  //     return answer;
  //   };
  // - ノードiにU型の値A[i]が定まっており型Uの非可換モノイド構造Mが与えられノード番号の全順序ordが定義されておりiの子ノードをわたるノード番号jのord昇順のMに関するdp[j]の総乗をA[i]に右から掛けたものをdp[i]に格納する場合：
  //   auto f = [&]( vector<pair<U,int>>& u , const int& i ){
  //     U answer = A[i];
  //     sort( u.begin() , u.end() , [&]( const pair<U,int>& u0 , const pair<U,int>& u1 ){ return ord( get<1>( u0 ) , get<1>( u1 ) ); } );
  //     for( auto& [x,j] : u ){ answer = M.Product( move( answer ) , x ); }
  //     return pair{ move( answer ) , i };
  //   };
  
  // Uは適当な型、Fは写像f:U \times N ->Uに相当する型、
  // Gは写像g:U \times \{0,1\} \times N^2 -> Uに相当する型。
  // 入力の範囲内で要件
  // (1) MがUのモノイド構造である。（以下演算を*と置く）
  // を満たす場合のみサポート。
  // dp[i][j] =
  // f(iを根とみなした時のjの子ノードkをord(i,j)順でわたらせてg(dp[i][k],元の木構造でjはiの子孫,k,j)のMに関して右に掛けていく積,j)
  // を満たす二重配列dpの対角成分dp[i][i]をO(|V_T|)で求めてanswer[i]に格納する。
  // ただしord(i,j)はiを根とした時のjの子ノードkの順序づけで、
  // - 元の木構造でjの親となるものを最初に
  // - そうでないものはChildrenNumber()に関して昇順に
  // として定義する。
  template <typename MONOID , typename F , typename G> vector<inner_t<MONOID>> RerootingDP( MONOID M , F& f , G& g );
  // fはノードjごとのデータ（グラフ構造に依存しない）
  // gは有向辺is_child?(j,k):(k,j)ごとのデータ（グラフ構造、例えばkが葉か否かに依存できる）
  // に対応。
  // -「パスの数」を求める場合：
  //   AdditiveMonoid<int> M{};
  //   auto f = [&]( const int& u , const int& i ){ return u + 1; };
  //   auto g = [&]( cost int& u , const bool& is_child , const int& k , const int& j ){ return u; };
  // -「パスの長さの最大値」を求める場合：
  //   MaxSemilattive<int> M{ -1 };
  //   auto f = [&]( const int& u , const int& i ){ return u + 1; };
  //   auto g = [&]( cost int& u , const bool& is_child , const int& k , const int& j ){ return u; };
  // - ノードiにU型の値A[i]が定まっており型Uの可換モノイド構造Mが与えられiを根としてノードjの子ノードkをわたって(iを根としてkが葉?A[k]:dp[i][k])の総和をdp[i][j]に格納する場合：
  //   auto f = [&]( const U& u , const int& i ){ return u; };
  //   auto g = [&]( cost U& u , const bool& is_child , const int& k , const int& j ) { return dfst.IsLeaf( i , k ) ? A[k] : u; };
  // - ノードiにU型の値A[i]が定まっており型Uの可換モノイド構造Mが与えられiを根として(ノードjが葉?A[j]:jの子ノードkをわたるdp[i][k]の総和)をdp[i][j]に格納する場合は、dp[i][i]=(size=1?A[i]:上のケースのdp[i][i])で処理可能
  // - 並び換え不変な関数h:U^{< omega} -> Uが与えられておりh(iを根とした時のjの子ノードkをわたるdp][i][k]たち)をdp[i][j]に格納する場合：
  //   auto concate = [&]( vector<U> v0 ,  const vector<U>& v1 ) {
  //     RUN( v1 , u ){
  //       v0 <<= u;
  //     }
  //     return move( v0 );
  //   }
  //   vector<U> empty{}:
  //   AbstractMonoid M{ concat , empty };
  //   auto f = [&]( const vector<U>& v , const int& i ){ return vector<U>{ h( v ) }; };
  //   auto g = [&]( cost vector<U>& v , const bool& is_child , const int& k , const int& j ) -> const vector<U>& { return v; };

  inline tuple<int,int,int> Diameter();
  
private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetHeaviness();

  // LCA()を呼ぶ前にAncestor()経由で完全にダブリングを設定する。
  // 遅延評価してしまう
  // ../../../../Function/Iteration/Doubling/
  // のダブリングでは代用しない。
  void SetDoubling();

};

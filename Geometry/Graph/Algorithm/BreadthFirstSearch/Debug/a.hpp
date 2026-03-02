// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/Debug/a.hpp

#pragma once
// デバッグ出力とインスタンスIDを追加したもの。
// 各探索ステップの計算量がO(V)追加されることに注意。

template <typename T , typename GRAPH>
class VirtualBreadthFirstSearch
{

protected:
  GRAPH& m_G;
  // 未訪問点のm_prevに格納するための変数。m_nextが空の時のNext()の戻り値。
  T m_external;
  bool m_initialised;
  // 次の探索点とそのprevの組たちを格納。
  list<pair<T,T>> m_next;

  // 以下GRAPHがGraphでない場合は添字にEnumerationが絡むことに注意。
  // 到達済みか否か。（m_prevで代用するとinitsを誤判定することに注意）
  vector<bool> m_reached;
  // 到達済みかつ到達済みの点から辺を辿ってNext()で到達する場合、
  // 初めて到達する時に通る辺の始点を格納。
  // GRAPHがGraphでない場合は添字にEnumerationが絡むことに注意。
  vector<T> m_prev;

  string m_ID;

public:
  inline VirtualBreadthFirstSearch( GRAPH& G , const T& external );
  // 始点をinitに設定する。
  template <typename Arg> inline VirtualBreadthFirstSearch( GRAPH& G , const T& external , Arg&& init );

  // m_nextとm_reachedとm_prevを初期化する。
  inline void Initialise();
  // m_nextとm_reachedとm_prevを初期化した上でinitを最初の探索点に設定する。
  inline void Initialise( T init );
  template <template <typename...> typename VEC> inline void Initialise( VEC<T> inits );
  // m_nextを初期化した上でm_reachedとm_prevを非初期化せずinitを次の探索点に設定する。
  inline void Shift( T init );
  template <template <typename...> typename VEC> inline void Shift( VEC<T> inits );

  // Gのサイズを取得。
  inline const int& size() const noexcept;
  inline vector<bool>::reference reached( const T& t );
  inline const T& prev( const T& t );

  inline T Next();
  
  // GRAPHがMemorisationGraphでない無向グラフ（の有向化）である場合にのみサポート。
  // {未到達点の全体のなす部分グラフにおける連結成分の色分け,その逆像,色の種類数}を格納。
  tuple<vector<int>,vector<vector<T>>,int> GetConnectedComponent();

  // m_nextに格納されている未到達点から到達できる未到達点を探索順に格納する。
  vector<T> GetNodeEnumeration();
  
  // m_nextに格納されている未到達点から到達できる未到達点を帰りがけ順に格納する。
  // 行きがけ順の逆順ではないことに注意。
  vector<T> GetReversedNodeEnumeration();

private:
  virtual void Push( list<pair<T,T>>& next , const T& t , const T& p ) = 0;

};

template <typename T , typename GRAPH>
class BreadthFirstSearch :
  public VirtualBreadthFirstSearch<T,GRAPH>
{

public:
  template <typename...Args> inline BreadthFirstSearch( GRAPH& G , const T& external , Args&&... args );


  // m_nextに格納されている未到達点（初期化時点ではinit/inits）から到達できる未到達点の深さを
  // 格納した配列を返す。ただし到達できない未到達点や既到達点は深さの代わりに-1を格納する。
  template <typename U = T> auto GetDistance() -> enable_if_t<is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,Map<T,int>>;
  template <typename U = T> auto GetDistance() -> enable_if_t<!is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,vector<int>>;
  
private:
  inline void Push( list<pair<T,T>>& next , const T& t , const T& p );

};


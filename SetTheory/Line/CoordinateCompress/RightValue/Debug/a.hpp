// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/CoordinateCompress/RightValue/Debug/a.hpp

#pragma once
// デバッグ出力を追加しただけのもの。

// ハッシュの定義された型にのみ使用可能。
// Set回数をQ、Setされた項の種類数をNと置く。

// 右辺値登録O(log N)
// 右辺値圧縮結果取得O(N)
// 右辺値圧縮結果使用O(1)（expected）
// 合計O(Q log N)（expected）

// 上界の評価は右辺値圧縮の方が小さいが、NがQに近い時は左辺値圧縮の方が軽い。
template <typename INT = ll>
class CoordinateCompressR
{

private:
  unordered_set<INT> m_r;
  int m_num;

public:
  inline CoordinateCompressR();

  inline void Set( INT t );
  template <typename U , template <typename...> typename V > inline void Set( V<U> a );
  // 右辺値を圧縮し、{enum_im,enum_im_inv,len(enum_im)}={圧縮前の値をソートして重複をなくした配列,圧縮後の値の元の値,圧縮後の値の最大値+1}を返す。
  tuple<vector<INT>,unordered_map<INT,int>,int> Get();
  inline void clear();

};

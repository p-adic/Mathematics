// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/CoordinateCompress/LeftValue/Debug/a.hpp

#pragma once
// デバッグ出力を追加しただけのもの。

// intから型変換可能な全順序の定義された型にのみ使用可能。
// Set回数をQと置く。

// 左辺値登録O(1)
// 左辺値圧縮O(Q log Q)
// 合計O(Q log Q)

// 上界の評価は右辺値圧縮の方が小さいが、NがQに近い時は左辺値圧縮の方が軽い。
template <typename INT = ll>
class CoordinateCompressL
{

private:
  vector<INT*> m_l;
  int m_num;

public:
  inline CoordinateCompressL();

  inline void Set( INT& t );
  template <typename U , template <typename...> typename V > inline void Set( V<U>& a );
  // 左辺値を圧縮し、{sorted,len(sorted)}={圧縮前の値をソートした配列,圧縮後の値の最大値+1}を返す。
  pair<vector<INT>,int> Get();
  inline void clear();

};

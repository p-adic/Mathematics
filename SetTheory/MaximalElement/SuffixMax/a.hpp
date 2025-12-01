// c:/Users/user/Documents/Programming/Mathematics/SetTheory/MaximalElement/SuffixMax/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1137563 (FinalSegmentMax,FinalSegmentMaxSum)

// N \times Yの部分集合Sであって関数のグラフをなすものを
// 辞書式順序に関する極大元の情報で管理する。

// 構築O(1)

// 末尾挿入O(1)（均し）
// 全要素削除O(N)

// 終切片max取得O(log N)
// 終切片maxの終切片和取得O(log N)

template <typename INT , typename Y , typename RET = Y>
class DynamicSuffixMax
{

private:
  // 第1成分の下限より小さい値。
  INT m_i_llim;
  // 第1成分の現在の最大値。
  INT m_i_max;
  // 第2成分の上限より大きい値。
  Y m_y_ulim;
  // (m_i_llim,m_y_ulim)と極大要素全体の集合を辞書式順序で昇順に管理。
  vector<Pair<INT,Y>> m_me;
  // m_ps[i]に右からの累積maxのm_pe[i][O]までの左からの累積和
  // sum_{j in (m_i_lim,m_pe[i][O]]} max_{(k,y) in S land k in [j,m_i_max]} y
  // を格納する。
  vector<RET> m_ps;

public:
  inline DynamicSuffixMax( INT i_llim , Y y_ulim );

  void insert( const INT& i , const Y& y );
  inline void clear();

  // 第1成分がi以上である要素の第2成分の最大値を返す。
  inline Y FinalSegmentMax( const INT& i );
  // i以上であり第1成分の最大値以下である各正整数jに対するFinalSegmemtMax( j )の総和を返す。
  inline RET FinalSegmentMaxSum( const INT& i );

private:
  // 辞書式順序の極大元のうちm_me[l][O]<=i<=m_me[r][O]を満たす最大のlと最小のrの組を返す。
  inline T2<INT> GetInterval( const INT& i );

};



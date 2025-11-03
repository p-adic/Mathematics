// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/ChoiceRestoration/Costwise/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1131062 (コスト最小性を辞書順最小性に変更)

#include "../../../Algebra/Monoid/a.hpp"

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しM.One() <= value[i]である。
// (3) N未満の各iに対し0 <= cost[i]である。
// (4) 0 <= cost_sum_boundである。
// を満たす場合にのみサポート。

// - 構築O(N cost_sum_bound)
// - コストの総和cost_sum_bound以下における価値の総和の最大値とそれを実現するコストの最小値と
//   それを実現する辞書順最小のものを降順表示O(N+cost_sum_bound)

template <typename U , typename COMM_MONOID , typename INT>
class AbstractValueKnapsackChoiceRestoration
{

private:
  COMM_MONOID m_M;
  vector<INT> m_cost;
  INT m_cost_sum_bound;
  int m_N;
  // m_prev[i+1]に項目i選択時の直前の最適選択を格納。
  // 直前が存在しない場合は-1を格納。
  vector<vector<int>> m_prev;
  // m_curr[L]に[0,L)までの項目選択時の価値最大値と最後の最適選択を格納。
  // 存在しない場合は{m_M.One(),-1}を格納。
  vector<vector<pair<U,int>>> m_curr;

public:
  AbstractValueKnapsackChoiceRestoration( COMM_MONOID M , const vector<U>& value , vector<INT> cost , const INT& cost_sum_bound );

  // 要件
  // (6) 0 <= L <= N
  // (7) 0 <= cost_sum_max <= cost_sum_bound
  // を満たす場合のみサポート。
  // 項を[0,L)から選ぶ場合にコストの総和cost_sum_max以下における価値の総和の最大値と
  // それを実現するコストの最小値とそれを実現する選択のうち辞書順最小のものを降順表示O(L+cost_sum)
  tuple<U,INT,vector<int>> Get( const int& L , const INT& cost_sum_max );
  
};

template <typename INT1 , typename INT2>
class KnapsackChoiceRestoration :
  public AbstractValueKnapsackChoiceRestoration<INT1,AdditiveMonoid<INT1>,INT2>
{

public:
  inline KnapsackChoiceRestoration( const vector<INT1>& value , vector<INT2> cost , const INT2& cost_sum_bound );

};

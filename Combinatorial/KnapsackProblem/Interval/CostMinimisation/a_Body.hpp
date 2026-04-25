// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/CostMinimisation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../CostOne/Interval/a_Body.hpp"

template <typename U1 , typename GROUP1 , typename U2 , typename GROUP2>
vector<pair<U2,int>> AbstractCostMinimisationIntervalKnapsack( GROUP1 M1 , GROUP2 M2 , const vector<U1>& value , const U1& value_prod_ubound , const vector<U2>& cost , const U2& exceptional )
{

  const int N = value.size();
  const vector<int> r = AbstractCostOneIntervalKnapsack( move( M1 ) , value , value_prod_ubound );
  vector<U2> ccost( N + 1 , M2.One() );

  for( int i = 0 ; i < N ; i++ ){

    ccost[i+1] = M2.Product( ccost[i] , cost[i] );

  }

  vector<pair<U2,int>> answer( N , {exceptional,N} );

  for( int i = 0 ; i < N && r[i] < N ; i++ ){

    answer[i] = { M2.Product( M2.Inverse( ccost[i] ) , ccost[r[i]+1] ) , r[i] };

  }

  return answer;

}

template <typename INT1 , typename INT2> inline vector<pair<INT2,int>> CostMinimisationIntervalKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost ) { return AbstractCostMinimisationIntervalKnapsack( AdditiveGroup<INT1>{} , AdditiveGroup<INT2>{} , value , value_sum_bound , cost , -1 ); }

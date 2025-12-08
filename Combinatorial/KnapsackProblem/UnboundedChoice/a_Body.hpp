// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/a_Body.hpp

#pragma once
#include "a.hpp"

#include "NegativeValue/a_Body.hpp"
#include "../../../Utility/Vector/a_Body.hpp"
#include "../../../Utility/Tuple/Wrap/a_Body.hpp"

// O(N(sum_i value[i])(max_i cost[i]))
template <typename INT1 , typename INT2>
pair<INT1,INT2> UnboundedChoiceKnapsackFewValues( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound )
{

  using T = Pair<INT2,INT1>;
  vector<T> rate{};
  int N = value.size();
  assert( N == int( cost.size() ) );

  if( N == 0 ){

    return {0,0};

  }

  for( int i = 0 ; i < N ; i++ ){

    assert( cost[i] == 0 ? value[i] == 0 : 0 < cost[i] && 0 < value[i] );
    
    if( 0 < value[i] ){

      rate <<= {cost[i],value[i]};

    }

  }

  sort( rate.begin() , rate.end() , [&]( const T& r0 , const T& r1 ) { return r0[O] * r1[I] < r1[O] * r0[I]; } );
  N = rate.size();
  INT1 val_sum = 0;

  for( int i = 1 ; i < N ; i++ ){

    val_sum += rate[i][I] * min( rate[0][O] , cost_sum_bound / rate[i][O] );

  }

  vector<INT2> cost_min( val_sum + 1 , cost_sum_bound + 1 );
  cost_min[0] = 0;

  for( int i = 1 ; i < N ; i++ ){

    for( INT1 v = rate[i][I] ; v <= val_sum ; v++ ){

      SetMin( cost_min[v] , min( cost_min[v-rate[i][I]] + rate[i][O] , cost_sum_bound + 1 ) );

    }

  }

  pair<INT1,INT2> answer{};

  for( INT1 v = 0 ; v <= val_sum ; v++ ){

    if( cost_min[v] <= cost_sum_bound ){
      
      const INT2 c = ( cost_sum_bound - cost_min[v] ) / rate[0][O] , w_temp = cost_min[v] + c * rate[0][O];
      const INT1 v_temp = v + c * rate[0][I];
      SetMax( answer , pair{v_temp,w_temp} );

    }
    
  }

  return answer;

}

template <typename INT1 , typename INT2> inline pair<INT1,INT2> UnboundedChoiceKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return len( value ) + static_cast<double>( cost_sum_bound ) * cost_sum_bound < Sum<double>( value ) * Max( cost ) ? NegativeValueUnboundedChoiceKnapsack( value , INT1( -1 ) , cost , cost_sum_bound ) : UnboundedChoiceKnapsackFewValues( value , cost , cost_sum_bound ); }

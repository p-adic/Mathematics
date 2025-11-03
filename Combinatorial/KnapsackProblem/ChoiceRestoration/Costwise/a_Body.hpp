// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/ChoiceRestoration/Costwise/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Algebra/Monoid/a_Body.hpp"
#include "../ValueSumBound/a_Body.hpp"

template <typename U , typename COMM_MONOID , typename INT>
AbstractValueKnapsackChoiceRestoration<U,COMM_MONOID,INT>::AbstractValueKnapsackChoiceRestoration( COMM_MONOID M , const vector<U>& value , vector<INT> cost , const INT& cost_sum_bound )
  : m_M( move( M ) ) , m_cost(move( cost ) ) , m_cost_sum_bound( cost_sum_bound ) , m_N( value.size() ) , m_prev( m_N + 1 , vector( m_cost_sum_bound + 1 , -1 ) ) , m_curr( m_N + 1 , vector( m_cost_sum_bound + 1 , pair{m_M.One(),-1} ) )
{

  static_assert( is_same_v<inner_t<COMM_MONOID>,U> );
  assert( int( m_cost.size() ) == m_N );
  const U& one = m_M.One();
  
  if( m_N > 0 ){

    for( int i = 0 ; i < m_N ; i++ ){

      assert( !( value[i] < one || m_cost[i] < INT( 0 ) ) );
      m_curr[i+1] = m_curr[i];
      
      if( m_cost_sum_bound < m_cost[i] ){

        continue;

      }

      for( int cost_sum = m_cost[i] ; cost_sum <= m_cost_sum_bound ; cost_sum++ ){

        auto& [v,j] = m_curr[i][cost_sum - m_cost[i]];
        
        if( j != -1 || cost_sum == m_cost[i] ){

          m_prev[i+1][cost_sum] = j;
          auto& [opt,k] = m_curr[i+1][cost_sum];
          U temp = m_M.Product( v , value[i] );

          if( k == -1 || opt < temp ){

            opt = move( temp );
            k = i;

          }

        }

      }

    }
    
  }

}

template <typename INT1 , typename INT2> inline KnapsackChoiceRestoration<INT1,INT2>::KnapsackChoiceRestoration( const vector<INT1>& value , vector<INT2> cost , const INT2& cost_sum_bound ) : AbstractValueKnapsackChoiceRestoration<INT1,AdditiveMonoid<INT1>,INT2>( AdditiveMonoid<INT1>() , value , move( cost ) , cost_sum_bound ) {}

template <typename U , typename COMM_MONOID , typename INT>
tuple<U,INT,vector<int>> AbstractValueKnapsackChoiceRestoration<U,COMM_MONOID,INT>::Get( const int& L , const INT& cost_sum_max )
{

  assert( 0 <= L && L <= m_N && 0 <= cost_sum_max && cost_sum_max <= m_cost_sum_bound );
  U opt = m_M.One();
  INT w = 0;
  int last = -1;

  for( int cost_sum = 0 ; cost_sum <= cost_sum_max ; cost_sum++ ){

    auto& [temp,i] = m_curr[L][cost_sum];
    
    if( opt < temp ){

      opt = temp;
      w = cost_sum;
      last = i;
      
    }

  }

  vector<int> choice{};
  INT cost_sum = w;

  while( last != -1 ){

    choice.push_back( last );
    int i = m_prev[last+1][cost_sum];
    cost_sum -= m_cost[last];
    last = i;

  }

  assert( cost_sum == INT( 0 ) );
  return {move(opt),w,move(choice)};

}

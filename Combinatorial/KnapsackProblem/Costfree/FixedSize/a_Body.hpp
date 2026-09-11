// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/FixedSize/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Utility/BinarySearch/a_Body.hpp"
#include "../../../../Utility/Vector/a_Body.hpp"

template <typename U , typename COMM_MONOID>
U AbstractCostfreeFixedSizeKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const int& subset_size )
{

  const int N = value.size();
  assert( 0 <= subset_size && subset_size <= N );
  const U& one = M.One();
  U answer = exceptional;

  if( N == 1 ){

    if( !( value_sum_bound < value[0] ) ){
      
      answer = value[0];

    }

  } else if( N > 1 ){

    const int N_half_left = N >> 1;
    const int N_half_right = N - N_half_left;
    unordered_map<int,int> valuation{};

    for( int i = 0 ; i < N_half_right ; i++ ){

      valuation[1<<i] = i;

    }
    
    const int power_left = 1 << N_half_left;
    vector<U> value_sum_left( power_left , one );

    for( int s = 1 ; s < power_left ; s++ ){

      const int lsb = s & -s;
      value_sum_left[s] = M.Product( value_sum_left[s ^ lsb] , value[valuation[lsb]] );

    }

    const int power_right = 1 << N_half_right;
    vector<U> value_sum_right( power_right , one );
    vector<int> bit_count( power_right );
    vector value_sum_right_im( N_half_right + 1 , vector<U>{} );
    value_sum_right_im[0] <<= one;

    for( int s = 1 ; s < power_right ; s++ ){

      const int lsb = s & -s;
      value_sum_right_im[bit_count[s] = bit_count[s ^ lsb] + 1] <<= value_sum_right[s] = M.Product( value_sum_right[s ^ lsb] , value[N_half_left + valuation[lsb]] );

    }

    for( auto& v : value_sum_right_im ){

      Sort( v );

    }

    for( int s = 0 ; s < power_left ; s++ ){

      auto& value_sum_left_s = value_sum_left[s];
      int i = subset_size - bit_count[s];

      if( !( i > N_half_right || value_sum_bound < value_sum_left_s ) ){

        const int L = value_sum_right_im[i].size();
        MAX_LEQ( t , 0 , L - 1 , M.Product( value_sum_left_s , value_sum_right_im[i][t] ) , value_sum_bound );

        if( 0 <= t && t < L ){

          U temp = M.Product( value_sum_left_s , value_sum_right_im[i][t] );
          
          if( answer == exceptional || answer < temp ){

            answer = move( temp );

          }

        }

      }

    }
    
  }

  return answer;

}

template <typename INT> inline INT CostfreeFixedSizeKnapsack( const vector<INT>& value , const INT& value_sum_bound , const INT& exceptional , const int& subset_size ) { return AbstractCostfreeFixedSizeKnapsack( AdditiveMonoid<INT>() , value , value_sum_bound , exceptional , subset_size ); }

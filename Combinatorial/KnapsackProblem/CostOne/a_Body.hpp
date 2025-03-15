// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/CostOne/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Algebra/Monoid/Group/a_Body.hpp"

template <typename U , typename COMM_MONOID>
pair<U,int> AbstractValueCostOneKnapsack( COMM_MONOID M , const vector<U>& value , const vector<int>& cost_sum_bound )
{

  const int N = value.size();
  assert( N == int( cost_sum_bound.size() ) );
  const U& one = M.One();
  multiset<U> opt{};

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    auto& cost_sum_bound_i = cost_sum_bound[i];
    assert( 0 <= cost_sum_bound_i );

    if( one < value_i ){

      opt.insert( value_i );

      while( int( opt.size() ) > cost_sum_bound_i ){

        opt.erase( opt.begin() );

      }

    }

  }

  U sum = one;

  for( auto& v : opt ){

    sum = M.Product( move( sum ) , v );

  }

  return {sum,opt.size()};

}

template <typename INT> inline pair<INT,int> CostOneKnapsack( const vector<INT>& value , const vector<int>& cost_sum_bound ) { return AbstractValueCostOneKnapsack( AdditiveMonoid<INT>() , value , cost_sum_bound ); }

template <typename U , typename ABEL_GROUP>
vector<pair<U,int>> AbstractValueCostOneItemwiseKnapsack( ABEL_GROUP M , const vector<U>& value , const vector<int>& cost_sum_bound )
{

  const int N = value.size();
  assert( N == int( cost_sum_bound ) );
  const U& one = M.One();
  U sum = one;
  multiset<U> opt{};
  vector<pair<U,int>> answer( N );

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    auto& cost_sum_bound_i = cost_sum_bound[i];
    assert( 0 <= cost_sum_bound_i );

    if( one < value_i ){

      opt.insert( value_i );
      sum = M.Product( move( sum ) , value_i );

      while( int( opt.size() ) > cost_sum_bound_i ){

        auto itr = opt.begin();
        sum = M.Product( move( sum ) , M.Inverse( *itr ) );
        opt.erase( itr );

      }

    }

    answer[i] = {sum,opt.size()};    
    
  }

  return answer;

}

template <typename INT> inline vector<pair<INT,int>> CostOneItemwiseKnapsack( const vector<INT>& value , const vector<int>& cost_sum_bound ) { return AbstractValueCostOneItemwiseKnapsack( AdditiveGroup<INT>() , value , cost_sum_bound ); }

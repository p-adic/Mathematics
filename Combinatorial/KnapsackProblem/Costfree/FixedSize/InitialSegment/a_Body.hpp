// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/FixedSize/InitialSegment/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename COMM_GROUP>
vector<U> AbstractCostfreeFixedSizeInitialSegmentwiseKnapsack( COMM_GROUP G , const vector<U>& value , const int& subset_size )
{

  const int size = value.size();
  U temp = G.Zero();
  vector<U> answer( size , temp );

  if( 0 < subset_size && subset_size <= size ){

    multiset<U> subset{};

    for( int i = 0 ; i < subset_size ; i++ ){

      subset.insert( value[i] );
      temp = G.Sum( move( temp ) , value[i] );

    }
    
    answer[subset_size-1] = temp;

    for( int i = subset_size ; i < size ; i++ ){

      subset.insert( value[i] );
      auto itr = subset.begin();
      answer[i] = temp = G.Sum( move( temp ) , G.Sum( G.Inverse( *itr ) , value[i] ) );
      subset.erase( itr );

    }
    
  }

  return answer;
  
}

template <typename INT> inline vector<INT> CostfreeFixedSizeInitialSegmentwiseKnapsack( const vector<INT>& value , const int& subset_size ) { return AbstractCostfreeFixedSizeInitialSegmentwiseKnapsack( AdditiveGroup<INT>() , value , subset_size ); }

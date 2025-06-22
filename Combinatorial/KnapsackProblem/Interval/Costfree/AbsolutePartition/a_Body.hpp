// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/AbsolutePartition/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
vector<INT> MaximisationIntervalSumAbsoluteSum( const vector<INT>& value , const int& partition_size , const vector<INT>& acs )
{

  const int N = value.size();
  assert( int( acs.size() ) == N + 1 );
  vector<INT> answer = acs;

  if( partition_size <= N ){

    vector temp( N , vector<INT>( 2 , -1 ) );
    temp[partition_size-1] = { acs[partition_size-1] + value[partition_size-1] , acs[partition_size-1] - value[partition_size-1] };
    answer[partition_size] = max( temp[partition_size-1][0] , temp[partition_size-1][1] );
  
    for( int i = partition_size ; i < N ; i++ ){

      temp[i] = { max( temp[i-1][0] , acs[i] ) + value[i] , max( temp[i-1][1] , acs[i] ) - value[i] };
      answer[i+1] = max( temp[i][0] , temp[i][1] );

    }

  }

  return answer;

}

template <typename INT>
vector<INT> MaximisationIntervalSumAbsoluteSum( const vector<INT>& value , const int& partition_size )
{

  assert( partition_size >= 1 );
  const int N = value.size();

  vector<INT> answer( N + 1 );

  for( int i = 0 ; i < N ; i++ ){

    answer[i+1] = answer[i] + value[i];

  }

  for( int i = 0 ; i < N ; i++ ){

    answer[i+1] = abs( answer[i+1] );

  }
  
  for( int p = 2 ; p <= partition_size ; p++ ){

    answer = MaximisationIntervalSumAbsoluteSum( value , p , answer );

  }

  return answer;

}

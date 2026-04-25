// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/CostMinimisation/Disjoint/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../../../../Utility/Tuple/Wrap/a_Body.hpp"

template <typename U1 , typename GROUP1 , typename U2 , typename GROUP2>
pair<U2,vector<T2<int>>> AbstractCostMinimisationDisjointIntervalKnapsack( GROUP1 M1 , GROUP2 M2 , const vector<U1>& value , const U1& value_prod_ubound , const vector<U2>& cost , const int& K , const U2& exceptional )
{

  const int N = value.size();

  if( K == 0 ){

    return { M2.One() , {} };

  }
  
  auto cr = AbstractCostMinimisationIntervalKnapsack( move( M1 ) , M2 , value , value_prod_ubound , cost , exceptional );
  // opt[k][i]に1個目の区間の左端がi以上であるようなk+1個の区間を選択する場合の
  // 1個目の区間の左端lと最小のコスト総和cの組{l,c}を格納する。
  vector opt( K , vector<pair<U2,int>>( N , {exceptional,N} ) );

  for( int k = 0 ; k < K ; k++ ){

    for( int i = 0 ; i < N ; i++ ){

      auto& [c0,r] = cr[i];

      if( k == 0 ){

        opt[k][i] = {c0,r==N?N:i};

      } else if( r < N - 1 ){

        auto& [c1,l] = opt[k-1][r+1];

        if( l != N ){

          opt[k][i] = { M2.Product( c0 , c1 ) , i };

        }

      }
      
    }

    for( int i = N - 2 ; i >= 0 ; i-- ){

      if( opt[k][i].second == N || ( opt[k][i+1].second != N && opt[k][i+1] < opt[k][i] ) ){
          
        opt[k][i] = opt[k][i+1];

      }

    }

  }

  auto [c,l] = opt[K-1][0];

  if( l == N ){

    assert( c == exceptional );
    return { c , {} };

  }
  
  vector<T2<int>> lr( K );
  int r = 0;

  for( int k = 0 ; k < K ; k++ ){

    if( k > 0 ){
      
      l = opt[K-1-k][r+1].second;

    }

    assert( l < N );
    r = cr[l].second;
    assert( r < N );
    lr[k] = {l,r};

  }

  return { move( c ) , move( lr ) };
  
}

template <typename INT1 , typename INT2> inline pair<INT2,vector<T2<int>>> CostMinimisationDisjointIntervalKnapsack( const vector<INT1>& value , const INT1& value_sum_ubound , const vector<INT2>& cost , const int& K ) { return AbstractCostMinimisationDisjointIntervalKnapsack( AdditiveGroup<INT1>{} , AdditiveGroup<INT2>{} , value , value_sum_ubound , cost , K , -1 ); }

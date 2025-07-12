// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/MaximumFlow/ProjectSelectionProblem/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
// Get( e )Ç…ópÇ¢ÇÈÅB
#include "../../../../../Utility/Vector/a_Body.hpp"

template <typename U , typename ABEL_GROUP , typename V0 , typename V1 , typename V2 , typename V3>
U AbstractProjectSelectionProblem( ABEL_GROUP R , const U& infty , const V0& score , const V1& dependency_penalty , const V2& pair_accept_score , const V3& pair_reject_score )
{

  const U& zero = R.Zero();
  U answer = zero;
  const int N = score.size();
  vector<vector<tuple<int,U>>> e( N + 2 );

  for( int i = 0 ; i < N ; i++ ){

    if( score[i] < zero ){

      e[i].push_back( {N+1,R.Inverse(score[i])} );

    } else {
      
      e[N].push_back( {i,score[i]} );
      answer = R.Sum( move( answer ) , score[i] );

    }

  }
  
  vector d( N , vector<U>( N , zero ) );

  for( auto& [i,j,u] : dependency_penalty ){

    assert( !( u < zero || i == j ) );
    d[i][j] = R.Sum( move( d[i][j] ) , u );
    
  }
  
  vector a( N , vector<U>( N , zero ) );

  for( auto& [i,j,u] : pair_accept_score ){

    assert( !( u < zero || i == j ) );
    a[j][i] = a[i][j] = R.Sum( move( a[i][j] ) , u );
    
  }
  
  vector r( N , vector<U>( N , zero ) );

  for( auto& [i,j,u] : pair_reject_score ){

    assert( !( u < zero || i == j ) );
    r[j][i] = r[i][j] = R.Sum( move( r[i][j] ) , u );
    
  }

  for( int i = 0 ; i < N ; i++ ){

    for( int j = i + 1 ; j < N ; j++ ){

      if( d[i][j] != zero ){

        if( d[j][i] != zero ){

          const int& ij_l = d[i][j] < d[j][i] ? i : j;
          const int& ij_r = d[i][j] < d[j][i] ? j : i;
          U& dmin = d[ij_l][ij_r];
          const U& dmax = d[ij_r][ij_l];
          a[i][j] = R.Sum( move( a[i][j] ) , dmin );
          r[i][j] = R.Sum( move( r[i][j] ) , dmin );
          const bool same = dmin == dmax;
          dmin = R.Inverse( dmin );
          answer = R.Sum( move( answer ) , dmin );

          if( !same ){
            
            e[ij_r].push_back( {ij_l,R.Sum(move(dmin),dmax)} );

          }

        } else {

          e[i].push_back( {j,d[i][j]} );

        }

      } else if( d[j][i] != zero ){

        e[j].push_back( {i,d[j][i]} );

      }

      if( a[i][j] != zero ){

        const int k = e.size();
        e.push_back( {{i,infty},{j,infty}} );
        e[N].push_back( {k,a[i][j]} );
        answer = R.Sum( move( answer ) , a[i][j] );

      }

      if( r[i][j] != zero ){

        const int k = e.size();
        e.push_back( {{N+1,r[i][j]}} );
        e[i].push_back( {k,infty} );
        e[j].push_back( {k,infty} );
        answer = R.Sum( move( answer ) , r[i][j] );

      }

    }

  }

  Graph graph{ int( e.size() ) , Get( e ) };
  AbstractMaximumFlow mf( graph , move( R ) );
  auto [loss,flow] = mf.GetFlow( N , N + 1 );
  return R.Sum( move( answer ) , R.Inverse( loss ) );

}

template <typename U , typename V0 , typename V1 , typename V2 , typename V3> inline U ProjectSelectionProblem( const U& infty , const V0& score , const V1& dependency_penalty , const V2& pair_accept_score , const V3& pair_reject_score ) { return AbstractProjectSelectionProblem( AdditiveGroup<U>{} , infty , score , dependency_penalty , pair_accept_score , pair_reject_score ); }

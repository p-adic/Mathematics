// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/MaximumFlow/ProjectSelectionProblem/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
// Get( e )に用いる。
#include "../../../../../Utility/Vector/a_Body.hpp"

template <typename U , typename ABEL_GROUP , typename V0 , typename V1 , typename V2 , typename V3>
U AbstractProjectSelectionProblem( ABEL_GROUP R , const U& infty , const V0& score , const V1& dependency_penalty , const V2& set_accept_score , const V3& set_reject_score )
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

  for( int i = 0 ; i < N ; i++ ){

    for( int j = i + 1 ; j < N ; j++ ){

      if( d[i][j] != zero ){

        if( d[j][i] != zero ){

          const int& ij_l = d[i][j] < d[j][i] ? i : j;
          const int& ij_r = d[i][j] < d[j][i] ? j : i;
          U& dmin = d[ij_l][ij_r];
          const U& dmax = d[ij_r][ij_l];

          const int k = e.size();
          e.push_back( {{i,infty},{j,infty}} );
          e.push_back( {{N+1,dmin}} );
          e[N].push_back( {k,dmin} );
          e[i].push_back( {k+1,infty} );
          e[j].push_back( {k+1,infty} );
          answer = R.Sum( move( answer ) , dmin );

          if( dmin != dmax ){
            
            e[ij_r].push_back( {ij_l,R.Sum(R.Inverse(dmin),dmax)} );

          }

        } else {

          e[i].push_back( {j,d[i][j]} );

        }

      } else if( d[j][i] != zero ){

        e[j].push_back( {i,d[j][i]} );

      }

    }

  }

  vector<bool> found( N );

  for( auto& [v,u] : set_accept_score ){

    assert( !( u < zero || v.empty() ) );

    if( u != zero ){

      const int k = e.size();
      e.push_back( {{}} );

      for( auto& i : v ){

        assert( !found[i] );
        found[i] = true;

      }

      for( auto& i : v ){

        found[i] = false;
        e[k].push_back( {i,infty} );

      }
      
      e[N].push_back( {k,u} );
      answer = R.Sum( move( answer ) , u );

    }

  }
  
  for( auto& [v,u] : set_reject_score ){

    assert( !( u < zero || v.empty() ) );

    if( u != zero ){

      const int k = e.size();
      e.push_back( {{N+1,u}} );

      for( auto& i : v ){

        assert( !found[i] );
        found[i] = true;

      }

      for( auto& i : v ){

        found[i] = false;
        e[i].push_back( {k,infty} );

      }
      
      answer = R.Sum( move( answer ) , u );

    }

  }

  Graph graph{ int( e.size() ) , Get( e ) };
  AbstractMaximumFlow mf( graph , move( R ) );
  auto [loss,flow] = mf.GetFlow( N , N + 1 );
  return R.Sum( move( answer ) , R.Inverse( loss ) );

}

template <typename U , typename V0 , typename V1 , typename V2 , typename V3> inline U ProjectSelectionProblem( const U& infty , const V0& score , const V1& dependency_penalty , const V2& set_accept_score , const V3& set_reject_score ) { return AbstractProjectSelectionProblem( AdditiveGroup<U>{} , infty , score , dependency_penalty , set_accept_score , set_reject_score ); }

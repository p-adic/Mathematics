// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/MultipointEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
vector<set<pair<INT,int>>> Multipoint_L1_Distance( const vector<INT>& x0 , const INT& y0 , const vector<pair<INT,INT>>& v1 , const int& length )
{

  const int size0 = x0.size();
  const int size1 = v1.size();
  const int size = size0 + size1;
  vector<pair<INT,int>> x( size );

  for( int i = 0 ; i < size0 ; i++ ){

    x[i] = { x0[i] , i };
    
  }

  for( int i = 0 ; i < size1 ; i++ ){

    x[i + size0] = { v1[i].first , i + size0 };
    
  }

  sort( x.begin() , x.end() );
  vector<set<pair<INT,int>>> answer( size0 );
  set<pair<INT,int>> temp{};
  INT d_init = x.back().first;

  for( int n = 0 ; n < size ; n++ ){

    auto& [xn,i] = x[n];

    if( i < size0 ){

      const INT dx = xn - d_init;
      auto& answer_i = answer[i];

      for( auto& d : temp ){

	answer_i.insert( { d.first + dx , d.second } );

      }

    } else {

      temp.insert( { abs( v1[i - size0].second - y0 ) - ( xn - ( d_init = min( d_init , xn ) ) ) , i - size0 } );

      if( int( temp.size() ) > length ){

	temp.erase( --( temp.end() ) );

      }

    }

  }

  temp.clear();
  d_init = x.front().first;

  for( int n = size - 1 ; n >= 0 ; n-- ){

    auto& [xn,i] = x[n];

    if( i < size0 ){

      const INT dx = d_init - xn;
      auto& answer_i = answer[i];

      for( auto& d : temp ){

	answer_i.insert( { d.first + dx , d.second } );

	if( int( answer_i.size() ) > length ){

	  answer_i.erase( --( answer_i.end() ) );

	}

      }

    } else {

      temp.insert( { abs( v1[i - size0].second - y0 ) - ( ( d_init = max( d_init , xn ) ) - xn ) , i - size0 } );

      if( int( temp.size() ) > length ){

	temp.erase( --( temp.end() ) );

      }

    }

  }

  return answer;

}

template <typename INT> inline vector<set<pair<INT,int>>> Multipoint_L1_Distance( const INT& x0 , const vector<INT>& y0 , vector<pair<INT,INT>> v1 , const int& length ) { for( auto& [x,y] : v1 ){ swap( x , y ); } return Multipoint_L1_Distance( y0 , x0 , v1 , length ); }

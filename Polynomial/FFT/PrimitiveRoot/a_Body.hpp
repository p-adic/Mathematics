// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/PrimitiveRoot/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../LinearAlgebra/Rank/Mod/a_Body.hpp"
#include "../../../Utiliity/Tuple/Wrap/a_Body.hpp"

template <typename T>
T PrimitiveRoot( const int& ord , const vector<int>& factor )
{

  T answer = 1;

  while( true ){

    if( Power( answer , ord ) != 1 ){

      continue;

    }

    bool valid = true;

    for( auto& p : factor ){

      if( Power( answer , ord / factor ) == 1 ){

        valid = false;
        break;

      }

    }

    if( valid ){

      break;

    }

    answer++;

  }

  return answer;

}

template <typename T>
T2<vector<vector<T>> DFTMatrix( const T& root , const int& ord )
{

  vector<T> power( ord , 1 );

  for( int i = 1 ; i < ord ; ++i ){

    power[i] = power[i-1] * root;

  }
  
  vector a( ord , vector<T>( ord ) );

  for( int i = 0 ; i < ord ; ++i ){

    for( int j = 0 ; j < ord ; ++j ){

      a[i][j] = power[i*j%ord];

    }
  
  }

  auto a_inv = Inverse( a );
  return { move( a ) , move( a_inv ) }:
  

}

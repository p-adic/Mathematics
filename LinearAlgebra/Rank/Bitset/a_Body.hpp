// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a_Body.hpp

#pragma once
#include "a.hpp"

template <size_t bound_M>
size_t RowEchelonForm( vector<bitset<bound_M>>& A  , const size_t& M )
{

  assert( M <= bound_M );
  const size_t L = A.size();
  size_t i_min = 0;
  size_t i_curr;
  size_t j_curr = 0;

  while( i_min < L && j_curr < M ){

    i_curr = i_min;

    while( i_curr < L ? A[i_curr][j_curr] == 0 : false ){
      
      i_curr++;

    }

    if( i_curr < L ){

      swap( A[i_min] , A[i_curr] );
      const bitset<bound_M>& A_i_min = A[i_min++];

      while( ++i_curr < L ){

	bitset<bound_M>& A_i_curr = A[i_curr];
	
	if( A_i_curr[j_curr] == 1 ){

	  A_i_curr ^= A_i_min;

	}

      }

    }

    j_curr++;

  }

  return i_min;
  
}

template <size_t bound_M_N>
pair<size_t,vector<bool>> ExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , const size_t& M )
{

  const int L = A.size();
  constexpr int N = 1;
  vector<int> left( L , -1 );
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( size_t& j = left[i] );
  vector<bool> solution{};

  if( solvable[0] ){

    solution.resize( M );
    i = rank;
  
    while( --i >= 0 ){

      auto& A_i = A[i];
      const int& j = left[i];
      solution[j] = A_i[M];

    }

  }

  return { rank , move( solution ) };

}

template <size_t bound_N , size_t bound_M_N>
tuple<size_t,vector<bool>,vector<bitset<bound_N>>> MultiExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , const size_t& M , const size_t& N )
{

  assert( N <= bound_N );
  const size_t L = A.size();
  vector<size_t> left( L );
  DEFINITION_OF_EXTENDED_REDUCED_ROW_ECHELON_FORM_FOR_BITSET( size_t& j = left[i] );
  vector<bitset<bound_N>> solutions( M , bitset<bound_N>() );
  i = rank;
  
  while( --i < rank ){

    const bitset<bound_M_N>& A_i = A[i];
    const size_t& j = left[i];
    bitset<bound_N>& solutions_j = solutions[j];
      
    for( size_t k = 0 ; k < N ; k++ ){

      solutions_j[k] = A_i[M + k];

    }

  }

  return { rank , move( solvable ) , move( solutions ) };

}

template <size_t bound_M> inline size_t ReducedRowEchelonForm( vector<bitset<bound_M>>& A , const size_t& M ) { return get<0>( MultiExtendedReducedRowEchelonForm<0>( A , M , 0 ) ); }

template <size_t bound_M> inline size_t Rank( vector<bitset<bound_M>> A , const size_t& M ) { return ReducedRowEchelonForm( A , M ); }

template <size_t bound_L>
pair<bool,vector<bitset<bound_L>>> Inverse( const vector<bitset<bound_L>>& A )
{

  const size_t L = A.size();
  vector<bitset<bound_L + bound_L>> A_copy( L );

  for( size_t i = 0 ; i < L ; i++ ){

    const bitset<bound_L>& A_i = A[i];
    bitset<bound_L + bound_L>& A_copy_i = A_copy[i];

    for( size_t j = 0 ; j < L ; j++ ){

      A_copy_i[j] = A_i[j];

    }

    for( size_t j = 0 ; j < L ; j++ ){

      A_copy_i[L + j] = i == j ? 1 : 0;

    }
    
  }

  size_t rank = ExtendedReducedRowEchelonForm( A_copy , L , L ).first;
  vector<bitset<bound_L>> A_inv( rank == L ? L : 0 );

  for( size_t i = 0 ; i < L ; i++ ){

    bitset<bound_L>& A_inv_i = A_inv[i];
    const bitset<bound_L + bound_L>& A_copy_i = A_copy[i];

    for( size_t j = 0 ; j < L ; j++ ){

      A_inv_i[j] = A_copy_i[L+j];

    }
    
  }

  return { rank == L , move( A_inv ) };  

}

template <size_t bound_L , size_t bound_M>
pair<int,vector<bool>> LinearRelation( const vector<bitset<bound_M>>& A , const size_t& M )
{

  const size_t L = A.size();
  const size_t rank = ReducedRowEchelonForm( A , M );
  vector<bool> coeff{};

  if( rank < M ){
  
    coeff.resize( M );
    int j = 0;
  
    while( j < L && A[j][j] != 0 ){

      j++;

    }

    for( int i = 0 ; i < j ; i++ ){

      coeff[i] = A[i][j] == 1;

    }

    coeff[j] = true;

  }

  return { rank , move( coeff ) };

}

// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/ParallelBinarySearch/a_Macro.hpp

#pragma once

#ifndef CERR
  #ifdef DEBUG
    #define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
    #define COUT( ... ) VariadicCout( cout << "�o�́F " , __VA_ARGS__ ) << endl
    #define CERR_A( A , N ) OUTPUT_ARRAY( cerr , A , N ) << endl
    #define COUT_A( A , N ) cout << "�o�́F "; OUTPUT_ARRAY( cout , A , N ) << endl
    #define CERR_ITR( A ) OUTPUT_ITR( cerr , A ) << endl
    #define COUT_ITR( A ) cout << "�o�́F "; OUTPUT_ITR( cout , A ) << endl
  #else
    #define CERR( ... ) 
    #define COUT( ... ) VariadicCout( cout , __VA_ARGS__ ) << ENDL
    #define CERR_A( A , N ) 
    #define COUT_A( A , N ) OUTPUT_ARRAY( cout , A , N ) << ENDL
    #define CERR_ITR( A ) 
    #define COUT_ITR( A ) OUTPUT_ITR( cout , A ) << ENDL
  #endif
#endif

#define INITIALISE_FOR_PBUF					\
  CERR( "" );					\
  CERR( "����񕪒T�����F" );					\
  CERR( "l = (" , l , ")" );					\
  CERR( "r = (" , r , ")" );					\
  AbstractUnionFindForest uff{ G , AdditiveGroup<int>() };	\
  auto itr = begin;						\

#define GRAFT_FOR_PBUF( VAL )					\
  CERR( "���삷��ӂ̏d�݂̏�E =" , VAL );		\
								\
  while( itr != end && itr->first <= VAL ){			\
								\
    CERR( "���쒆�̕ӂ̏d�� =" , itr->first );			\
								\
    for( auto& [s,t] : itr->second ){				\
								\
      if( uff.RootOfNode( s ) != uff.RootOfNode( t ) ){		\
								\
	CERR( "�����F ( s , t ) = (" , s , "," , t , ")" );	\
								\
      }								\
								\
      uff.Graft( s , t );					\
								\
    }								\
								\
    itr++;							\
								\
  }								\
  
#define UPDATE_FOR_PBUF( VAL )						\
  auto& [s,t] = query[q];						\
  uff.RootOfNode( s ) == uff.RootOfNode( t ) ? r[q] = VAL : ++( l[q] = VAL ); \



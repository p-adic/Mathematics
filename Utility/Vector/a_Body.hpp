// c:/Users/user/Documents/Programming/Utility/Vector/a_Body.hpp

#pragma once
#include "a.hpp"

#if !defined( SAMPLE_CHECK ) && defined( DEBUG )
  #include "StdStream/Debug/a_Body.hpp"
#else
  #include "StdStream/a_Body.hpp"
#endif

DEFINITION_OF_ARITHMETICS_FOR_VECTOR( vector );
DEFINITION_OF_ARITHMETICS_FOR_VECTOR( list );
DEFINITION_OF_SHIFT_FOR_VECTOR( basic_string );

template <typename V> inline auto Get( V& a ) { return [&]( const int& i = 0 ) -> const decldecay_t( a[0] )& { return a[i]; }; }
template <typename T> inline vector<T> id( const int& size ) { vector<T> answer( size ); for( int i = 0 ; i < size ; i++ ){ answer[i] = i; } return answer; }

template <typename V> inline void Sort( V& a , const bool& reversed ) { using T = decldecay_t(a[0]); if( reversed ){ static auto comp = []( const T& t0 , const T& t1 ) { return t1 < t0; }; sort( a.begin() , a.end() , comp ); } else { sort( a.begin() , a.end() ); } }
template <typename V0 , typename V1> inline void Sort( V0& a , V1& b , const bool& reversed ) { const int size = a.size(); assert( size == int( b.size() ) ); vector<pair<decldecay_t(a[0]),decldecay_t(b[0])>> v( size ); for( int i = 0 ; i < size ; i++ ){ v[i] = { move( a[i] ) , move( b[i] ) }; } Sort( v , reversed ); for( int i = 0 ; i < size ; i++ ){ a[i] = move( v[i].first ); b[i] = move( v[i].second ); } }
template <typename V> inline pair<vector<int>,vector<int>> IndexSort( const V& a , const bool& reversed ) { const int size = a.size(); auto index = id<int>( size ) , ord = index; sort( index.begin() , index.end() , [&]( const int& i , const int& j ) { const pair ti{ a[i] , i } , tj{ a[j] , j }; return reversed ? tj < ti : ti < tj; } ); for( int i = 0 ; i < size ; i++ ){ ord[index[i]] = i; } return { move( index ) , move( ord ) }; }

template <typename V> inline int len( const V& a ) { return a.size(); }

template <typename V> inline void Reverse( V& a ) { const int size = len( a ) , half = size / 2; for( int i = 0 ; i < half ; i++ ){ swap( a[i] , a[size-1-i] ); } }
;
template <typename V> inline V Reversed( V a ) { Reverse( a ); return move( a ); }

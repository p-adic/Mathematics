// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Iteration/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename U , template <typename...> typename V , typename OPR> T LeftConnectiveProd( T t , const V<U>& f , OPR opr ) { for( auto& u : f ){ t = opr( move( t ) , u ); } return move( t ); }
template <typename T , typename U , template <typename...> typename V> inline T Sum( T t , const V<U>& f ) { return LeftConnectiveProd( move( t ) , f , []( T t0 , const U& u1 ){ return move( t0 += u1 ); } ); }
template <typename T , template <typename...> typename V> inline T Sum( const V<T>& f ) { return Sum( T{} , f ); }
template <typename T , typename U , template <typename...> typename V> inline T Prod( T t , const V<U>& f ) { return LeftConnectiveProd( move( t ) , f , []( T t0 , const U& u1 ){ return move( t0 *= u1 ); } ); }
template <typename T , template <typename...> typename V> inline T Prod( const V<T>& f ) { return Prod( T{ 1 } , f ); }
template <typename T , template <typename...> typename V> inline const T& Max( const V<T>& f ) { return *max_element( f.begin() , f.end() ); }
template <typename T , typename...Args> inline T Max( const T& t0 , const T& t1 , const Args&... args ) { return Max( vector<T>{ t0 , t1 , args... } ); }
template <typename T , template <typename...> typename V> inline const T& Min( const V<T>& f ) { return *min_element( f.begin() , f.end() ); }
template <typename T , typename...Args> inline T Min( const T& t0 , const T& t1 , const Args&... args ) { return Min( vector<T>{ t0 , t1 , args... } ); }

template <typename T , typename U> inline T SetMax( T& n , const U& m ) { return n < m ? n = m : n; }
template <typename T , typename U> inline T SetMin( T& n , const U& m ) { return n > m ? n = m : n; }

template <typename T , typename UINT>
T Power( const T& t , const UINT& exponent , T init )
{

  return exponent > 1 ? Power( t * t , exponent >> 1 , move( exponent & 1 ? init *= t : init ) ) : move( exponent > 0 ? init *= t : ( assert( exponent == 0 ) , init ) );

}

template <typename T> inline T PowerMemorisation( const T& t , const int& exponent ) { assert( exponent >= 0 ); static Map<T,vector<T>> memory{}; auto& answer = memory[t]; if( answer.empty() ){ answer.push_back( 1 ); } while( int( answer.size() ) <= exponent ){ answer.push_back( answer.back() * t ); } return answer[exponent]; }

template <typename INT> inline INT ArithmeticProgressionSum( const INT& l , const INT& r , const INT& d ) { return ( l + r ) * ( r - l + 1 ) / 2; }
template <typename INT> inline INT SpecialisedArithmeticProgressionSum( const INT& l , const INT& r , const INT& d ) { assert( l <= r ); const INT c = ( r - l ) / d; return ( c & 1 ) == 0 ? ( c + 1 ) * ( l + d * ( c >> 1 ) ) : ( ( c + 1 ) >> 1 ) * ( ( l << 1 ) + d * c ); }
SPECIALSATION_OF_ARITHMETIC_PROGRESSION_SUM( int );
SPECIALSATION_OF_ARITHMETIC_PROGRESSION_SUM( uint );
SPECIALSATION_OF_ARITHMETIC_PROGRESSION_SUM( ll );
SPECIALSATION_OF_ARITHMETIC_PROGRESSION_SUM( ull );
template <typename INT> inline INT ArithmeticProgressionSum( const INT& r ) { return ArithmeticProgressionSum( INT{} , r ); }

template <typename T , typename UINT> inline T GeometricProgressionSum( T rate , UINT exponent_max , const T& init ) { T rate_minus = rate - 1; return rate_minus == 0 ? init * ++exponent_max : ( Power( move( rate ) , move( ++exponent_max ) ) - 1 ) / move( rate_minus ) * init; }

template <typename T , typename UINT>
T GeometricProgressionLinearCombinationSum( vector<T> rate , vector<UINT> exponent_max , const vector<T>& init )
{

  const int size = init.size();
  assert( int( rate.size() ) == size && int( exponent_max.size() ) == size );
  T answer{};

  for( int i = 0 ; i < size ; i++ ){

    answer += GeometricProgressionSum( move( rate[i] ) , move( exponent_max[i] ) , init[i] );

  }

  return answer;

}

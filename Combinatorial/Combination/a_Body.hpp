// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Combination/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Utility/Set/Map/a_Body.hpp"
#include "../../Utility/Vector/a_Body.hpp"

template <typename RET , typename INT>
RET CombinationCumulativeProductRecursion( const INT& n , const INT& m , const bool& reset )
{

  static Map<INT,vector<RET>> memory{};
  auto& memory_n = memory[n];
  
  if( memory_n.empty() ){

    memory_n <<= 1;

  }

  INT M;

  while( ( M = memory_n.size() ) <= m ){

    memory_n <<= memory_n.back() * ( n - M + 1 ) / M;

  }

  if( reset ){

    RET answer = memory_n[m];
    memory.erase( n );
    return answer;

  }

  return memory_n[m];

}

template <typename RET , typename INT1 , typename INT2> inline RET CombinationCumulativeProduct( const INT1& n , INT2 m  , const bool& reset ){ const INT1 m_copy = move( m ); return m < 0 || n < m_copy ? CombinationCumulativeProductRecursion<RET>( n , INT1{ 0 } , reset ) - 1 : CombinationCumulativeProductRecursion<RET>( n , min( m_copy , n - m_copy ) , reset ); }


template <typename INT>
INT CombinationFactorialRecursion( const INT& n , const INT& m )
{

  static vector<INT> factorial{ 1 };
  INT N;

  while( ( N = factorial.size() ) <= n ){

    factorial <<= factorial.back() * N;

  }

  return factorial[n] / factorial[m] / factorial[n-m];

}

template <typename INT1 , typename INT2> inline INT1 CombinationFactorial( const INT1& n , INT2 m ){ assert( ( ( is_same_v<INT1,int> || is_same_v<INT1,uint> ) && n <= 12 ) || ( ( is_same_v<INT1,ll> || is_same_v<INT1,ull> ) && n <= 20 ) ); const INT1 m_copy = move( m ); return m < 0 || n < m_copy ? INT1( 0 ) : CombinationFactorialRecursion( n , m_copy ); }


template <typename RET>
RET CombinationPascal( const int& n , const int& m )
{

  if( n < 0 || m < 0 || n < m ){

    return 0;

  }
  
  static vector<vector<RET>> memory = {{1}};
  int N;

  while( ( N = memory.size() ) <= n ){

    memory <<= vector<RET>( N + 1 , 1 );

    for( int i = 1 ; i < N ; i++ ){

      memory[N][i] = memory[N-1][i-1] + memory[N-1][i];

    }

  }

  return memory[n][m];

}

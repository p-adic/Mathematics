// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Combination/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Arithmetic/Iteration/a_Body.hpp"
#include "../../Utility/Set/Map/a_Body.hpp"

template <typename INT>
INT CombinationCumulativeProductRecursion( const INT& n , const INT& m , const bool& reset )
{

  static Map<INT,vector<INT>> memory{};
  auto& memory_n = memory[n];
  
  if( memory_n.empty() ){

    memory_n.push_back( 1 );

  }

  INT size;

  while( ( size = memory_n.size() ) <= m ){

    memory_n.push_back( memory_n.back() * ( n - size + 1 ) / size );

  }

  if( reset ){

    INT answer = memory_n[m];
    memory.erase( n );
    return answer;

  }

  return memory_n[m];

}

template <typename INT1 , typename INT2> inline INT1 CombinationCumulativeProduct( const INT1& n , INT2 m  , const bool& reset ){ const INT1 m_copy = move( m ); return m < 0 || n < m_copy ? CombinationCumulativeProductRecursion( n , INT1{ 0 } , reset ) - 1 : CombinationCumulativeProductRecursion( n , min( m_copy , n - m_copy ) , reset ); }

template <typename MOD , typename INT , typename VEC> inline pair<MOD,vector<int>> CombinationCumulativeProductValuativeRecursion( const INT& n , const INT& m , const VEC& factor , const int& euler , const bool& reset )
{

  static const int L = factor.size();
  assert( L == int( factor.size() ) );
  static Map<INT,tuple<vector<MOD>,vector<vector<int>>>> memory{};

  if( n < m ){

    if( reset ){

      memory.erase( n );

    }

    return { MOD{ 0 } , vector<int>( L ) };

  }
  
  auto& [comb,exponent] = memory[n];
  
  if( comb.empty() ){

    comb.push_back( 1 );
    exponent.push_back( vector<int>( L ) );

  }

  INT size;

  while( ( size = comb.size() ) <= m ){

    MOD c = comb.back();
    vector<int> e = exponent.back();

    for( int num = 0 ; num < 2 ; num++ ){

      INT r = num == 0 ? n - size + 1 : size;

      for( int i = 0 ; i < L ; i++ ){

        auto& p = factor[i];

        while( r % p == 0 ){

          r /= p;
          num == 0 ? ++e[i] : --e[i];

        }

      }

      num == 0 ? c *= r : euler == -1 ? c /= r : c *= Power( MOD{ r } , euler - 1 );

    }

    comb.push_back( move( c ) );
    exponent.push_back( move( e ) );

  }
  
  if( reset ){

    pair<MOD,vector<int>> answer{ move( comb[m] ) , move( exponent[m] ) };
    memory.erase( n );
    return answer;

  }
  
  return { comb[m] , exponent[m] };

}

template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationCumulativeProductValuative( const INT1& n , INT2 m , const VEC& factor , const int& euler , const bool& reset ){ const INT1 m_copy = move( m ); return CombinationCumulativeProductValuativeRecursion<MOD>( n , m < 0 || n < m_copy ? n + 1 : min( m_copy , n - m_copy ) , factor , euler , reset ); }

template <typename INT>
INT CombinationFactorialRecursion( const INT& n , const INT& m )
{

  static vector<INT> factorial{ 1 };
  INT size;

  while( ( size = factorial.size() ) <= n ){

    factorial.push_back( factorial.back() * size );

  }

  return factorial[n] / factorial[m] / factorial[n-m];

}

template <typename INT1 , typename INT2> inline INT1 CombinationFactorial( const INT1& n , INT2 m ){ assert( ( ( is_same_v<INT1,int> || is_same_v<INT1,uint> ) && n <= 12 ) || ( ( is_same_v<INT1,ll> || is_same_v<INT1,ull> ) && n <= 20 ) ); const INT1 m_copy = move( m ); return m < 0 || n < m_copy ? INT1( 0 ) : CombinationFactorialRecursion( n , m_copy ); }

template <typename MOD , typename INT , typename VEC>
pair<MOD,vector<int>> CombinationFactorialValuativeRecursion( const INT& n , const INT& m , const VEC& factor , const int& euler )
{

  static const int L = factor.size();
  assert( L == int( factor.size() ) );

  if( n < m ){

    return { MOD{ 0 } , vector<int>( L ) };

  }
  
  static vector<MOD> factorial{ 1 };
  static vector<MOD> factorial_inv{ 1 };
  static vector exponent( 1 , vector<int>( L ) );
  INT size;

  while( ( size = factorial.size() ) <= n ){

    vector<int> e = exponent.back();

    for( int i = 0 ; i < L ; i++ ){

      auto& p = factor[i];

      while( size % p == 0 ){

        size /= p;
        e[i]++;

      }

    }

    factorial.push_back( factorial.back() * size );
    factorial_inv.push_back( euler == -1 ? factorial_inv.back() / size : factorial_inv.back() * Power( MOD{ size } , euler - 1 ) );
    exponent.push_back( move( e ) );

  }

  vector<int> e = exponent[n];

  for( int num = 0 ; num < 2 ; num++ ){

    auto& denom = exponent[num==0?m:n-m];

    for( int i = 0 ; i < L ; i++ ){

      e[i] -= denom[i];

    }

  }

  return { factorial[n] * factorial_inv[m] * factorial_inv[n-m] , move( e ) };

}

template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationFactorialValuative( const INT1& n , INT2 m , const VEC& factor , const int& euler ){ const INT1 m_copy = move( m ); return CombinationFactorialValuativeRecursion<MOD>( n , m < 0 || n < m_copy ? n + 1 : m_copy , factor , euler ); }

// valutaive‚ÍˆÈ‰º‚Æ•¹—p‚·‚éB
#include "../../Arithmetic/Iteration/Power/a_Body.hpp"
// PowerMemoriser( facto[i] , j )‚Åfactor[i]‚Ìjæ‚ðŽæ“¾B

#include "../../Arithmetic/Mod/Function/Euler/a_Body.hpp"
// auto [euler,fuctor,exponent] = EulerFunction( pe , n )

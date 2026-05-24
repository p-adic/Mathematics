// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Combination/Valuative/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Set/Map/a_Body.hpp"
#include "../../../Utility/Vector/a_Body.hpp"

template <typename MOD , typename INT , typename VEC> inline pair<MOD,vector<int>> CombinationCumulativeProductValuativeRecursion( const INT& n , const INT& m , const VEC& factor , const bool& reset )
{

  static Map<INT,tuple<vector<MOD>,vector<vector<int>>>> memory{};
  const int L = factor.size();

  if( n < m ){

    if( reset ){

      memory.erase( n );

    }

    return { MOD{ 0 } , vector<int>( L ) };

  }
  
  auto& [comb,exponent] = memory[n];
  
  if( comb.empty() ){

    comb <<= 1;
    exponent <<= vector<int>( L );

  }

  INT M;

  while( ( M = comb.size() ) <= m ){

    MOD c = comb.back();
    vector<int> e = exponent.back();

    for( int num = 0 ; num < 2 ; num++ ){

      INT r = num == 0 ? n - M + 1 : M;

      for( int i = 0 ; i < L ; i++ ){

        auto& p = factor[i];

        while( r % p == 0 ){

          r /= p;
          num == 0 ? ++e[i] : --e[i];

        }

      }

      num == 0 ? c *= r : c /= r;

    }

    comb <<= move( c );
    exponent <<= move( e );

  }
  
  if( reset ){

    pair<MOD,vector<int>> answer{ move( comb[m] ) , move( exponent[m] ) };
    memory.erase( n );
    return answer;

  }
  
  return { comb[m] , exponent[m] };

}

template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationCumulativeProductValuative( const INT1& n , INT2 m , const VEC& factor , const bool& reset ){ const INT1 m_copy = move( m ); return CombinationCumulativeProductValuativeRecursion<MOD>( n , m < 0 || n < m_copy ? n + 1 : min( m_copy , n - m_copy ) , factor , reset ); }

template <typename MOD , typename INT1 , typename INT2 , typename VEC>
pair<MOD,vector<int>> MultinomialFactorialValuativeRecursion( const INT1& n , const vector<INT2>& m , const VEC& factor )
{

  // ÇPéÌóﬁÇÃfactorÇ≈ÇµÇ©åƒÇ—èoÇ≥Ç»Ç¢ëzíËÅB
  static const int L = factor.size();
  assert( L == int( factor.size() ) );

  if( m.empty() ){

    return { MOD{ 1 } , vector<int>( L ) };

  }

  const INT1 sum = Sum<INT1>( m );

  if( n < sum || Min( m ) < 0 ){

    return { MOD{ 0 } , vector<int>( L ) };

  }
  
  static vector<MOD> factorial{ 1 };
  static vector<MOD> factorial_inv{ 1 };
  static vector exponent( 1 , vector<int>( L ) );
  INT1 N;

  while( ( N = factorial.N() ) <= n ){

    vector<int> e = exponent.back();

    for( int i = 0 ; i < L ; i++ ){

      auto& p = factor[i];

      while( N % p == 0 ){

        N /= p;
        e[i]++;

      }

    }

    factorial <<= factorial.back() * N;
    factorial_inv <<= factorial_inv.back() / N;
    exponent <<= move( e );

  }

  MOD f = factorial[n];
  vector<int> e = exponent[n];
  const int M = m.size();

  for( int j = 0 ; j <= M ; j++ ){

    const int k = j < M ? INT1( m[j] ) : n - sum;
    f *= factorial_inv[k];
    auto& denom = exponent[k];

    for( int i = 0 ; i < L ; i++ ){

      e[i] -= denom[i];

    }

  }

  return { move( f ) , move( e ) };

}

template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> MultinomialFactorialValuative( const INT1& n , const vector<INT2> m , const VEC& factor ){ return MultinomialFactorialValuativeRecursion<MOD>( n , m , factor ); }
template <typename MOD , typename INT1 , typename INT2 , typename VEC> inline pair<MOD,vector<int>> CombinationFactorialValuative( const INT1& n , INT2 m , const VEC& factor ){ return MultinomialFactorialValuativeRecursion<MOD>( n , vector<INT1>{ move( m ) } , factor ); }

#include "../../../Arithmetic/Iteration/a_Body.hpp"
#include "../../../Arithmetic/Prime/Factorisation/a_Body.hpp"

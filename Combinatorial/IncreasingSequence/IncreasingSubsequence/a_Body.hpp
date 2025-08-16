// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSequence/IncreasingSubsequence/a_Body.hpp

#pragma once
#include "a.hpp"

// Count(Non)StrictlyIncreasingSubsequenceに使う。
#include "../../SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp"
// modつきのCount(Non)StrictlyIncreasingSubsequenceに使う。
#include "../../Arithmetic/Mod/QuotientRing/a_Body.hpp"
// LongestIncreasingSubsequenceに使う。
#include "../../Uility/BinarySearch/a_Body.hpp"
// PointwiseLongestIncreasingSubsequenceに使う。
#include "../../SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp"

template <typename T>
ll CountStrictlyIncreasingSubsequence( const vector<T>& a )
{

  COUNT_INCREASING_SUBSEQUENCE( ll , n - 1 , answer , 1 );

}

template <typename T>
ll CountNonStrictlyIncreasingSubsequence( const vector<T>& a )
{

  COUNT_INCREASING_SUBSEQUENCE( ll , n , answer , 1 );

}

template <typename T>
ll CountStrictlyIncreasingSubsequence( const vector<T>& a , const ll& mod )
{

  COUNT_INCREASING_SUBSEQUENCE( QuotientRing<ll> , n - 1 , answer.Represent() < 0 ? answer.Represent() + mod : answer.Represent() , 1 , &mod );

}

template <typename T>
ll CountNonStrictlyIncreasingSubsequence( const vector<T>& a , const ll& mod )
{

  COUNT_INCREASING_SUBSEQUENCE( QuotientRing<ll> , n , answer.Represent() < 0 ? answer.Represent() + mod : answer.Represent() , 1 , &mod );

}

template <typename T , typename F>
int LongestIncreasingSubsequence( const vector<T>& a , const T& infty , F f )
{

  static_assert( is_invocable_r_v<T,F,const T&> );
  assert( infty <= f( infty ) );
  const int size = a.size();
  const int size_minus = size - 1;
  vector<T> t_min( size , infty );

  for( int i = 0 ; i < size ; i++ ){

    const T& a_i = a[i];
    assert( a_i <= f( a_i ) && a_i <= infty && a_i != infty );
    MIN_GEQ( n , 0 , size_minus , ( f( t_min[n] ) <= a_i ? 0 : 1 ) , 1 );

    if( a_i <= t_min[n] ){
      
      t_min[n] = a_i;

    }

  }

  for( int n = size_minus ; n >= 0 ; n-- ){

    if( t_min[n] != infty ){
      
      return n + 1;
    
    }

  }

  abort();
  return -1;
  
}

template <typename T>
vector<int> LongestStrictlyIncreasingSubsequence( const vector<T>& a )
{

  MAXIMISE_INCREASING_SUBSEQUENCE( -i );

}

template <typename T>
vector<int> LongestNonStrictlyIncreasingSubsequence( const vector<T>& a )
{

  MAXIMISE_INCREASING_SUBSEQUENCE( i );

}


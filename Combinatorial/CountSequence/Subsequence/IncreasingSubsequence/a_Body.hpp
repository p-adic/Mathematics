// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/CountSequence/Subsequence/IncreasingSubsequence/a_Body.hpp

#pragma once
#include "a.hpp"

// Count(Non)StrictlyIncreasingSubsequenceに使う。
#include "../../../SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp"
// modつきのCount(Non)StrictlyIncreasingSubsequenceに使う。
#include "../../../Arithmetic/Mod/QuotientRing/a_Body.hpp"

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


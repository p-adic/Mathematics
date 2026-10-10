// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SlidingMinimalisation/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1192788

#include "a_Macro.hpp"

DECLARATION_OF_SLIDING_MINIMALISATION( Min );
DECLARATION_OF_SLIDING_MINIMALISATION( Max );

// 型推論のためにfは第2引数にデフォルト引数が指定された関数オブジェクトとする。
// N = answer.size()と置く。

// 要件
// (1) 0 < interval_size
// を満たす場合にのみサポート。

// O(N)でf(gの区間[max(0,i-interval_size+1),i]における最大／最小値,i)を
// answer[i]に格納する。
// template <typename FUNC0 , typename FUNC1 , typename T> void SlidingMiniimalisation( FUNC0 f , FUNC1 g , vector<T>& answer , const int& interval_size );
// template <typename FUNC0 , typename FUNC1 , typename T> void SlidingMaximalisation( FUNC0 f , FUNC1 g , vector<T>& answer , const int& interval_size );

// fを関数に渡す（関数の返り値に手作業で適用しない）のは
// answerの値をgが参照する場合がありえるため。

// 例えばanswer[i]に
// - 配列aの区間[i-interval_size+1,i]での最小値を格納する場合は
//   int N = a.size();
//   vector<decltype( a[0] )> sm( N );
//   SlidingMinimalisation( [&]( const decltype( a[0] )& x , const int& i ) { return x; } , Get( a ) , sm , interval_size );
// - (i>0?answerの区間[i-interval_size,i-1]の最小値+a[i-1]:v0)を格納する場合は
//   int N = a.size();
//   vector<decltype( a[0] )> sm( N + 1 );
//   SlidingMinimalisation( [&]( const decltype( a[0] )& x , const int& i ) { return x + ( i < 1 ? 0 : a[i-1] ); } , [&]( const int& i ){ return i < 1 ? v0 : sm[i-1]; } , sm , interval_size );
// とすれば良い。

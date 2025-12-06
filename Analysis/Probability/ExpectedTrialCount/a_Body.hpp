// c:/Users/user/Documents/Programming/Mathematics/Analysis/Probability/ExpectedTrialCount/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename MODINT>
MODINT ExpectedCompleteCollectionTrialCount( const MODINT& n , const int& m , const int& l )
{

  assert( 0 <= l && l <= m );
  MODINT answer{};

  for( int i = 0 ; i < l ; i++ ){

    // 既にちょうどi種類を1回以上引いた後にi+1種類目を引くまでの試行回数の期待値を足す。
    answer += n / ( m - i );

  }

  return answer;

}

template <typename MODINT>
MODINT ExpectedDoubleCollectionTrialCount( const MODINT& n , const int& m , const int& l )
{

  assert( 0 <= l && l <= m );
  // dp[j]にちょうどi種類を2回以上引いてちょうどj種類をちょうど1回引いた後に
  // l種類を2回引くまでに掛かる試行回数の期待値をnext dpで格納する。
  vector<MODINT> dp( m - 1 + 1 );

  for( int i = l - 1 ; i >= 0 ; i-- ){

    vector<MODINT> ndp( m - i + 1 );
    const MODINT den = 1 / MODINT{ m - i };

    for( int j = m - i - 1 ; j >= 0 ; j-- ){

      // 残るm-i種類をもう1回引くまでにn/(m-i)回、
      // - 確率(m-i-j)/(m-i)で新たな種類となり更にndp[j+1]回。
      // - 確率j/(m-i)で1回だけ引いたものの2回目となり更にdp[j-1]回。
      ndp[j] = ( n + ( m - i - j ) * ndp[j+1] + ( j ? j * dp[j-1] : MODINT{} ) ) * den;

    }

    dp = move( ndp );

  }
  
  return dp[0];

}

// n種類から1種類ランダムに引いて戻す試行で、特定の2m種類からなるm組のうちl組を双方1回以上引く
// までに掛かる試行回数の期待値を返す。（O(ml)）
template <typename MODINT>
MODINT ExpectedCompletePairCollectionTrialCount( const MODINT& n , const int& m , const int& l )
{

  assert( 0 <= l && l <= m );
  // dp[j]にちょうどi組を双方1回以上引いてちょうどj組をちょうど片方1回以上引いた後に
  // l組を双方1回以上引くまでに掛かる試行回数の期待値をnext dpで格納する。
  vector<MODINT> dp( 2 * m - 2 * 1 + 1 );

  for( int i = l - 1 ; i >= 0 ; i-- ){

    vector<MODINT> ndp( 2 * m - 2 * i + 1 );

    for( int j = 2 * m - 2 * i - 1 ; j >= 0 ; j-- ){

      // 残る2m-2i-j種類をもう1回引くまでにn/(2m-2i-j)回、
      // - 確率(2m-2i-2j)/(2m-2i-j)で新たな組となり更にndp[j+1]回。
      // - 確率j/(2m-2i-2j)で片方のみ引いていた組のもう片方となり更にdp[j-1]回。
      ndp[j] = ( n + 2 * ( m - i - j ) * ndp[j+1] + ( j ? j * dp[j-1] : MODINT{} ) ) / ( 2 * m - 2 * i - j );

    }

    dp = move( ndp );

  }
  
  return dp[0];

}


template <typename MODINT , typename INT> inline MODINT ExpectedCompletionTrialCount( const MODINT& n , const int& m , INT c ) { assert( 0 <= m ); return ( 1 - Power( 1 - 1 / n , move( c ) ) ) * m; }

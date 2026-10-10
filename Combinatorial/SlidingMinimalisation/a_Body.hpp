// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SlidingMinimalisation/a_Body.hpp

#pragma once
#include "a.hpp"

DEFINITION_OF_SLIDING_MINIMALISATION( Min , > );
DEFINITION_OF_SLIDING_MINIMALISATION( Max , < );

template <typename FUNC0 , typename FUNC1 , typename T , typename COMP>
void SlidingMinimalisationBody( FUNC0 f , FUNC1 g , vector<T>& answer , const int& interval_size , COMP comp )
{

  assert( 0 < interval_size );
  const int N = answer.size();
  list<pair<decldecay_t(g(0)),int>> interval{};

  for( int i = 0 ; i < N ; i++ ){

    T t = g( i );

    while( !interval.empty() && comp( interval.back().first , t ) ){

      interval.pop_back();

    }

    interval.push_back( {move(t),i} );
    auto& [x,j] = interval.front();
    answer[i] = f( x , i );

    // #[j,i] = interval_size‚ÌŽžAŽŸ‚©‚çj‚ªŽg‚¦‚È‚­‚È‚é‚Ì‚Åj‚ðÁ‹Ž‚·‚éB
    if( j == i - interval_size + 1 ){

      interval.pop_front();

    }

  }

  return;

}



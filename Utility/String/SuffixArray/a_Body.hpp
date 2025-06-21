// c:/Users/user/Documents/Programming/Mathematics/Utility/String/SuffixArray/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename STR>
vector<int> ManberMyers( const STR& s )
{

  const int N = s.size();
  using CHAR = decldecay_t( s[0] );
  map<CHAR,vector<int>> bucket{};

  for( int i = 0 ; i < N ; i++ ){

    bucket[s[i]].push_back( i );

  }

  // orderは各suffixの順位を管理する配列、すなわちanswerの逆写像に対応する配列。
  vector<int> order( N );
  // orderの値の下界をorder_lbで管理する。
  int order_lb = 0;
  // orderの値の下界が等しく評価されているindex（answer中の区間）をintervalで管理する。
  vector<vector<int>> interval{};
  
  for( auto& [c,v] : bucket ){

    if( order_lb > 0 ){
      
      for( auto& i : v ){

        order[i] = order_lb;

      }

    }

    const int size = v.size();
    order_lb += size;

    if( size > 1 ){

      interval.push_back( move( v ) );

    }

  }

  vector<vector<int>> ninterval{};
  int L = 1;

  while( true ){

    while( !interval.empty() ){
      
      bucket.clear();

      for( auto& i : interval.back() ){

        const int j = i + L;
        bucket[j < N ? order[j] : -1].push_back( i );

      }

      interval.pop_back();
      int order_lb_diff = 0;

      for( auto& [c,v] : bucket ){

        if( order_lb_diff > 0 ){
          
          for( auto& i : v ){

            order[i] += order_lb_diff;

          }

        }

        const int size = v.size();
        order_lb_diff += size;

        if( size > 1 ){

          ninterval.push_back( move( v ) );

        }

      }

    }

    if( ninterval.empty() ){

      break;

    }
    
    swap( interval , ninterval );
    ninterval.clear();
    L <<= 1;

  }

  vector<int> answer( N );

  for( int i = 0 ; i < N ; i++ ){

    answer[order[i]] = i;

  }

  return answer;

}

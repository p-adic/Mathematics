// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/Weighted/Diameter/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename DFSWT>
tuple<int,int,decldecay_t(declval<MONOID>().Monoid())> WDiameter( DFSWT& dfswt )
{

  using U = decldecay_t(declval<MONOID>().Monoid());
  U& M = dfswt.Monoid();
  auto& V = dfswt.size();
  // dp[i]にiを根とする部分木でiを端点に持つパスのうち重みが上位２位までのものの
  // {もう１つの端点,重み}の組を管理する。
  vector<pair<pair<int,U>,pair<int,U>>> dp( V );
  int l0_opt = dfswt.Root() , l1_opt = l0_opt;
  U u_opt = M.One();

  for( int i = 0 ; i < V ; i++ ){

    auto& j = dfswt.NodeNumber( i , true );
    auto& [dpj0,dpj1] = dp[j];
    dpj0 = dpj1 = {j,M.One()};
    auto& [l0,u0] = dpj0;
    auto& [l1,u1] = dpj1;
    
    for( auto& k : dfswt.Children( j ) ){

      auto& [l,u] = get<1>( dp[k] );
      U temp = M.Product( dfswt.PrevWeight( k ) , u );

      if( u0 < temp ){

        if( u1 < temp ){

          dp[j] = { move( dpj1 ) , { l , move( temp ) } };

        } else {

          dp[j] = { { l , move( temp ) } , move( dpj1 ) };

        }

      }

    }

    U temp = M.Product( u0 , u1 );

    if( u_opt < temp ){

      u_opt = move( temp );
      l0_opt = l0;
      l1_opt = l1;

    }

  }

  return { l0_opt , l1_opt , move( u_opt ) };
  
}

// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/Recursion/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename EDGE , typename T , typename F0 , typename F1 , typename G0 , typename G1>
void RecursionOnDAG( EDGE& edge , const T& t_start , F0 f0 , F1 f1 , G0 g0 , G1 g1 )
{

  static_assert( is_invocable_r_v<vector<T>,EDGE,const T&> && is_invocable_v<F0,const T&> && is_invocable_v<F1,const T&,const T&> && is_invocable_v<G0,const T&,const T&> && is_invocable_v<G1,const T&> );
  f0( t_start );

  for( auto&& u : edge( t_start ) ){

    DERR( "RecursionOnDAG:" , t_start , "->" , u );
    f1( t_start , u );
    RecursionOnDAG( edge , u , move( f0 ) , f1 , g0 , g1 );
    DERR( "RecursionOnDAG:" , t_start , "<-" , u );
    g0( t_start , u );

  }

  g1( t_start );
  return;
  
}

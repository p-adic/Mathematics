// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/WeightSum/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../Algebra/Monoid/Group/TreeWeight/a_Body.hpp"
#include "../RootingDP/a_Body.hpp"

template <typename TREE , typename PREV_WEIGHT , typename INT>
Tuple<int,INT,INT> TreeWeightSum( const TREE& T , PREV_WEIGHT pw )
{

  TreeWeightGroup twg{ 0 , INT{ 1 } , INT{ 1 } };
  using U = twg::type;

  auto prod = [&]( U u0 , const U& u1 , const int& i , const int& j ){
    return twg.Product( move( u0 ) , twg.Extend( u1 , pw( j ) ) );
  };

  auto val = [&]( const int& i ){
    return twg.One();
  };

  return BinaryRootingDP( T , val , prod , 0 );

}

template <typename TREE , typename INT> inline Tuple<int,INT,INT> TreeWeightSum( const TREE& T ) { return TreeWeightSum( T , [&]( const int& j ){ return 1; } ); }

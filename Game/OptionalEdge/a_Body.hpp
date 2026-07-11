// c:/Users/user/Documents/Programming/Mathematics/Game/OptionalEdge/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../SetTheory/Mex/Debug/a_Body.hpp"
#include "../../Utility/Set/Map/a_Body.hpp"

template <typename OEdge , typename T>
const int& OptionalEdgeGrundyNumber( OEdge& oedge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<OEdge,const T&> );
  static Map<T,int> g{};

  if( reset ){

    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  auto&& next = oedge( t );
  bool first = true;
  Set<int> cap{};

  for( auto&& a : next ){

    Set<int> ncap{};

    for( auto&& u : a ){

      auto& val = OptionalEdgeGrundyNumber( oedge , u );
      
      if( first || In( val , cap ) ){

        ncap <<= val;

      }

    }

    cap = move( ncap );
    first = false;

  }

  MexSet S{ int( next.size() ) };

  for( auto& val : cap ){
    
    S.insert( val );
    
  }

  return g[t] = S.mex();

}




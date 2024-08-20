// c:/Users/user/Documents/Programming/Mathematics/Game/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../SetTheory/Mex/a_Body.hpp"
#include "../../../Utility/Set/Map/a_Body.hpp"

template <typename Edge , typename T>
const bool& IsWinningState( Edge& edge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<Edge,const T&> );
  static Map<T,bool> g{};
  static bool init = true;

  if( init ){

    cerr << "IsWinningState���f�o�b�O���[�h�Ŏ��s���܂��B" << endl;
    cerr << "�f�o�b�O�o�͈ȊO�ɕύX�_�͂���܂���B" << endl;
    init = false;

  }

  if( reset ){

    cerr << "IsWinningState�����������܂����B" << endl;
    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  bool b = false;

  for( auto&& u : edge( t ) ){

    b |= !IsWinningState( edge , u );
    
  }

  cerr << "IsWinningState: " << t << " -> " << b << endl;
  return ( g[t] = b );

}

template <typename AEdge , typename T>
const int& GrundyNumber( AEdge& aedge , const T& t , const bool& reset )
{

  static_assert( is_invocable_v<AEdge,const T&> );
  static Map<T,int> g{};
  static bool init = true;

  if( init ){

    cerr << "GrundyNumber���f�o�b�O���[�h�Ŏ��s���܂��B" << endl;
    cerr << "�f�o�b�O�o�͈ȊO�ɕύX�_�͂���܂���B" << endl;
    init = false;

  }

  if( reset ){

    cerr << "IsWinningState�����������܂����B" << endl;
    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  auto&& next = aedge( t );
  MexSet mex{ int( next.size() ) };

  for( auto&& a : next ){

    int temp = 0;

    for( auto&& u : a ){

      temp ^= GrundyNumber( aedge , u );

    }

    mex.insert( temp );
    
  }

  cerr << "GrundyNumber: " << t << " -> " << mex.Get() << endl;
  return g[t] = mex.Get();

}


template <typename Edge , typename T , typename INVARIANT>
const int& WinningConstantsOf( Edge& edge , const T& t , const INVARIANT& invariant , const bool& reset )
{


  static_assert( is_invocable_v<Edge,const T&> );
  static Map<T,int> g{};
  static bool init = true;

  if( init ){

    cerr << "WinningConstantsOf���f�o�b�O���[�h�Ŏ��s���܂��B" << endl;
    cerr << "�f�o�b�O�o�͈ȊO�ɕύX�_�͂���܂���B" << endl;
    init = false;

  }

  if( reset ){

    cerr << "WinningConstantsOf�����������܂����B" << endl;
    g.clear();

  }

  if( g.count( t ) == 1 ){

    return g[t];

  }

  auto&& e = edge( t );
  int c = e.empty() ? ( 1 << invariant( t ) ) : 0;

  for( auto&& u : e ){

    int temp = WinningConstantsOf( edge , u , invariant );

    for( int d = 0 ; d <= 1 ; d++ ){

      c |= ( ( temp >> ( 1 ^ d ) ) & 1 ) << d;

    }

  }

  cerr << "WinningConstantsOf: " << t << " -> " << c << endl;
  return g[t] = c;

}

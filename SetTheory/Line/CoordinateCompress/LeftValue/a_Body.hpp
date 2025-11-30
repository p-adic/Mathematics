// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/CoordinateCompress/LeftValue/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompressL<INT>::CoordinateCompressL() : m_l() {}

template <typename INT> inline void CoordinateCompressL<INT>::Set( INT& t ) { m_l.push_back( &t ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompressL<INT>::Set( V<U>& a ) { for( auto& t : a ){ Set( t ); } }

template <typename INT>
pair<vector<INT>,int> CoordinateCompressL<INT>::Get()
{

  pair<vector<INT>,int> answer{ {} , -1 };
  auto& [value,value_max] = answer;

  if( !m_l.empty() ){

    auto comp = []( INT* const& p0 , INT* const& p1 ) { return *p0 < *p1; };
    sort( m_l.begin() , m_l.end() , comp );
    INT temp = *( m_l[0] ) - 1;

    for( auto p : m_l ){

      *p = temp == *p ? value_max : ( value.push_back( temp = *p ) , ++value_max );

    }

  }

  value_max++;
  return answer;

}

template <typename INT> inline void CoordinateCompressL<INT>::clear() { m_l.clear(); }


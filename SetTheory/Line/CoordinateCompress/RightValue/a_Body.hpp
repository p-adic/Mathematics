// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/CoordinateCompress/RightValue/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompressR<INT>::CoordinateCompressR() : m_r() {}

template <typename INT> inline void CoordinateCompressR<INT>::Set( INT t ) { m_r.insert( move( t ) ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompressR<INT>::Set( V<U> a ) { for( auto& t : a ){ Set( move( t ) ); } }

template <typename INT>
tuple<vector<INT>,unordered_map<INT,int>,int> CoordinateCompressR<INT>::Get()
{

  tuple<vector<INT>,unordered_map<INT,int>,int> answer{};
  auto& [value,value_inv,value_max] = answer;
  value.resize( m_r.size() );
  
  for( auto t : m_r ){

    value[value_inv[t] = value_max++] = t;

  }

  return answer;

}

template <typename INT> inline void CoordinateCompressR<INT>::clear() { m_r.clear(); }


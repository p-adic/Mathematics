// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/CoordinateCompress/RightValue/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , bool ordered> inline CoordinateCompressR<INT,ordered>::CoordinateCompressR() : m_r() {}

template <typename INT , bool ordered> inline void CoordinateCompressR<INT,ordered>::Set( INT t ) { m_r.insert( move( t ) ); }
template <typename INT , bool ordered> template <typename U , template <typename...> typename V > inline void CoordinateCompressR<INT,ordered>::Set( V<U> a ) { for( auto& t : a ){ Set( move( t ) ); } }

template <typename INT , bool ordered>
tuple<vector<INT>,conditional_t<ordered,map<INT,int>,unordered_map<INT,int>>,int> CoordinateCompressR<INT,ordered>::Get()
{

  tuple<vector<INT>,conditional_t<ordered,map<INT,int>,unordered_map<INT,int>>,int> answer{};
  auto& [value,value_inv,value_max] = answer;
  value.resize( m_r.size() );
  
  for( auto t : m_r ){

    value[value_inv[t] = value_max++] = t;

  }

  return answer;

}

template <typename INT , bool ordered> inline void CoordinateCompressR<INT,ordered>::clear() { m_r.clear(); }


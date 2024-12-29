// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompress<INT>::CoordinateCompress() : m_r() , m_l() {}

template <typename INT> inline void CoordinateCompress<INT>::SetR( INT t ) { m_r.insert( move( t ) ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetR( V<U> a ) { for( auto& t : a ){ SetR( move( t ) ); } }

template <typename INT>
tuple<vector<INT>,unordered_map<INT,int>,int> CoordinateCompress<INT>::GetR()
{

  tuple<vector<INT>,unordered_map<INT,int>,int> answer{};
  auto& [value,value_inv,value_max] = answer;
  value.resize( m_r.size() );
  
  for( auto t : m_r ){

    value[value_inv[t] = value_max++] = t;

  }

  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearR() { m_r.clear(); }

template <typename INT> inline void CoordinateCompress<INT>::SetL( INT& t ) { m_l.push_back( &t ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetL( V<U>& a ) { for( auto& t : a ){ SetL( t ); } }

template <typename INT>
pair<vector<INT>,int> CoordinateCompress<INT>::GetL()
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

template <typename INT> inline void CoordinateCompress<INT>::clearL() { m_l.clear(); }


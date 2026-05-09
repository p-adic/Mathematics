// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Debug/a_Body.hpp"
#include "../../../../../../Utility/Set/Map/a_Body.hpp"

template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR> inline AbstractCompressedSortedSet<INT1,INT2,DATA_STR>::AbstractCompressedSortedSet( const vector<INT1>& query , const bool& output_mode ) : m_sorted_coord() , m_sorted_coord_inv()
{

  set<INT> S{};
  
  for( auto& i : query ){

    S.insert( i );

  }

  m_sorted_coord.reserve( S.size() );

  for( auto& i : S ){

    m_sorted_coord_inv[i] = m_sorted_coord.size();
    m_sorted_coord.push_back( i );

  }

  this->m_output_mode = output_mode;

  if( m_sorted_coord.empty() ){

    this->m_lbound = 0;
    this->m_ubound = -1;

  } else {

    this->m_lbound = m_sorted_coord.front();
    this->m_ubound = m_sorted_coord.back();

  }
  
  static int count = 0;
  this->m_name = "AbstractCompressedSortedSet" + to_string( count++ );
  this->m_ds.Initialise( int( S.size() ) , false );

  if( this->m_output_mode ){
    
    DERR( this->m_name , "をデバッグモードで実行します。" );

    static bool init = true;

    if( init ){

      init = true;
      DERR( "各処理の計算量がO(size)増えることに注意してください。" );

    }
    
    this->Display();
    DERR( "" );

  }
    
}

template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR> inline bool AbstractCompressedSortedSet<INT1,INT2,DATA_STR>::InRange( const INT1& i ) { return m_sorted_coord_inv.count( i ) > 0; }
template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR> inline const int& AbstractCompressedSortedSet<INT1,INT2,DATA_STR>::Normalise( const INT1& i ) { static const int exceptional = -1; return i < this->m_lbound || m_sorted_coord_inv.empty() ? exceptional : ( --m_sorted_coord_inv.upper_bound( i ) )->second; }
template <typename INT1 , typename INT2 , template <typename...> typename DATA_STR> inline const INT1& AbstractCompressedSortedSet<INT1,INT2,DATA_STR>::Denormalise( const int& d ) { return m_sorted_coord[d]; }

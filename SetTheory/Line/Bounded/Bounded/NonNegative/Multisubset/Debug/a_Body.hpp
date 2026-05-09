// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Multisubset/Debug/a_Body.hpp"

template <typename INT> inline NonNegativeLineMultiSubset<INT>::NonNegativeLineMultiSubset( const int& ubound , const bool& output_mode )
{

  assert( -1 <= ubound );
  this->m_output_mode = output_mode;
  this->m_lbound = 0;
  this->m_ubound = ubound;
  static int count = 0;
  this->m_name = "NonNegativeLineMultiSubset" + to_string( count++ );
  this->m_ds.Initialise( int( this->m_ubound + 1 ) , false );

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

template <typename INT> inline bool NonNegativeLineMultiSubset<INT>::InRange( const int& i ) { return this->m_lbound <= i && i <= this->m_ubound; }
template <typename INT> inline constexpr const int& NonNegativeLineMultiSubset<INT>::Normalise( const int& i ) { return i; }
template <typename INT> inline constexpr const int& NonNegativeLineMultiSubset<INT>::Denormalise( const int& d ) { return d; }

// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Debug/a_Body.hpp"

template <typename INT> inline NonNegativeLineSubset<INT>::NonNegativeLineSubset( const INT& ubound , const bool& output_mode ) : VirtualBoundedLineSubset<INT,const INT&,const INT&>()
{

  assert( -1 <= ubound );
  this->m_output_mode = output_mode;
  this->m_lbound = 0;
  this->m_ubound = ubound;
  static int count = 0;
  this->m_name = "NonNegativeLineSubset" + to_string( count++ );
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

template <typename INT> inline bool NonNegativeLineSubset<INT>::InRange( const INT& i ) { return this->m_lbound <= i && i <= this->m_ubound; }
template <typename INT> inline constexpr const INT& NonNegativeLineSubset<INT>::Normalise( const INT& i ) { return i; }
template <typename INT> inline constexpr const INT& NonNegativeLineSubset<INT>::Denormalise( const INT& d ) { return d; }

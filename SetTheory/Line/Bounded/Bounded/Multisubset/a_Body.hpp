// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::insert( const INT1& i , const INT2& c ) { assert( this->InRange( i ) && c >= 0 ); this->m_ds.Add( this->Normalise( i ) , c ); }

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::erase( const INT1& i , const INT2& c ) { assert( c >= 0 ); if( this->InRange( i ) ){ this->m_ds.Add( this->Normalise( i ) , -c ); } }

template <typename INT1 ,typename INT2 , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN,DATA_STR>::EraseAll( const INT1& i ) { if( this->InRange( i ) ){ this->m_ds.Set( this->Normalise( i ) , 0 ); } }

template <typename INT1 , typename INT2> inline BoundedLineMultiSubset<INT1,INT2>::BoundedLineMultiSubset( const INT1& lbound , const INT1& ubound ) : AbstractBoundedLineSubset<INT1,INT2,BIT>( lbound , ubound ) {}

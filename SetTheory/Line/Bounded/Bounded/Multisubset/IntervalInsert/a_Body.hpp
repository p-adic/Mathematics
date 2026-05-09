// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#ifdef DEBUG
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a_Body.hpp"
#else
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/a_Body.hpp"
#endif

template <typename INT1 , typename INT2 , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN>::IntervalInsert( const INT1& i_start , const INT1& i_final , const INT2& c ) { assert( this->InRange( i_start ) && this->InRange( i_final ) && c >= 0 ); this->m_ds.IntervalAdd( this->Normalise( i_start ) , this->Normalise( i_final ) , c ); }
template <typename INT1 ,typename INT2 , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,RET_NOR,RET_DEN>::IntervalErase( const INT1& i_start , const INT1& i_final , const INT2& c ) { assert( this->InRange( i_start ) && this->InRange( i_final ) && c >= 0 ); this->m_ds.IntervalAdd( this->Normalise( i_start ) , this->Normalise( i_final ) , -c ); }

template <typename INT1 , typename INT2> inline IntervalInsertBoundedLineMultiSubset<INT1,INT2>::IntervalInsertBoundedLineMultiSubset( const INT1& lbound , const INT1& ubound ) : AbstractBoundedLineSubset<INT1,INT2,IntervalAddBIT>( lbound , ubound ) , VirtualIntervalInsertBoundedLineMultiSubset<INT1,INT2,INT1,INT1>() {}

// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/Interval/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename ABEL_GROUP , typename R_SET , typename R , typename U> inline AbstractIntervalRSet<ABEL_GROUP,R_SET,R,U>::AbstractIntervalRSet( ABEL_GROUP L , R_SET M ) : R_SET( move( M ) ) , m_L( move( L ) ) { static_assert( is_same_v<R,inner_t<ABEL_GROUP>> && is_same_v<U,inner_t<R_SET>> ); }
template <typename R , typename U> IntervalModule<R,U>::IntervalModule() : AbstractIntervalRSet<AdditiveGroup<R>,Module<R,U>>( AdditiveGroup<R>() , Module<R,U>() ) {}

template <typename ABEL_GROUP , typename R_SET , typename R , typename U> inline U AbstractIntervalRSet<ABEL_GROUP,R_SET,R,U>::Action( const pair<R,R>& lr , U u ) { return R_SET::Action( m_L.Sum( lr.second , m_L.Inverse( lr.first ) ) , move( u ) ); }

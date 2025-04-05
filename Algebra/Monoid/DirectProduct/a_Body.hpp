// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/DirectProduct/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename MONOID0 , typename MONOID1 , typename TYPE> inline DirectProductMonoid<MONOID0,MONOID1,TYPE>::DirectProductMonoid( MONOID0 M0 , MONOID1 M1 ) : PointedSet<TYPE>( m_one ) , m_M0( move( M0 ) ) , m_M1( move( M1 ) ) , m_one( m_M0.One() , m_M1.One() ) { static_assert( is_same_v<TYPE,pair<typename MONOID0::type,typename MONOID1::type>> ); }

template <typename MONOID0 , typename MONOID1 , typename TYPE> inline TYPE DirectProductMonoid<MONOID0,MONOID1,TYPE>::Product( TYPE t0 , const TYPE& t1 ) { return { m_M0.Product( move( t0.first ) , t1.first ) , m_M1.Product( move( t0.second ) , t1.second ) }; }
template <typename MONOID0 , typename MONOID1 , typename TYPE> inline const TYPE& DirectProductMonoid<MONOID0,MONOID1,TYPE>::Point() { return m_one; }

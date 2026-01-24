// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/PlainCoordinate/PlainSort/Order/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline ArgumentSortOrder<INT>::ArgumentSortOrder( INT x , INT y ) : m_x( move( x ) ) , m_y( move( y ) ) {}
template <typename INT> template <typename PAIR> inline bool ArgumentSortOrder<INT>::operator()( const PAIR& v0 , const PAIR& v1 ) const { auto& [x0,y0] = v0; auto& [x1,y1] = v1; const ll S = Area<ll>( m_x , m_y , x0 , y0 , x1 , y1 ); return S > 0 || ( S == 0 && ( abs( x0 - m_x ) < abs( x1 - m_x ) || abs( y0 - m_y ) < abs( y1 - m_y ) ) ); }

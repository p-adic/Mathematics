// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/Ring/Algebra/SquareSum/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../../Utility/Tuple/Wrap/a_Body.hpp"

template <typename RING , typename U> inline SquareSumAlgebra<RING,U>::SquareSumAlgebra( RING R ) : m_R( move( R ) ) {}

template <typename RING , typename U> inline const T3<U>& SquareSumAlgebra<RING,U>::Zero() { static const T3<U> zero{ m_R.Zero() , m_R.Zero() , m_R.Zero() }; return zero; }
template <typename RING , typename U> inline const T3<U>& SquareSumAlgebra<RING,U>::One() { static const T3<U> one{ m_R.One() , m_R.Zero() , m_R.Zero() }; return one; }

template <typename RING , typename U> inline T3<U> SquareSumAlgebra<RING,U>::Sum( T3<U> v0 , const T3<U>& v1 ) { v0[II] = m_R.Sum( move( v0[II] ) , v1[II] ); v0[I] = m_R.Sum( move( v0[I] ) , v1[I] ); v0[O] = m_R.Sum( move( v0[O] ) , v1[O] ); return move( v0 ); }
template <typename RING , typename U> inline T3<U> SquareSumAlgebra<RING,U>::Product( T3<U> v0 , const T3<U>& v1 ) { v0[II] = m_R.Sum( m_R.Sum( m_R.Product( move( v0[II] ) , v1[O] ) , m_R.Product( v0[I] , v1[I] ) ) , m_R.Sum( m_R.Product( v1[I] , v0[I] ) , m_R.Product( v0[O] , v1[II] ) ) ); v0[I] = m_R.Sum( m_R.Product( move( v0[I] ) , v1[O] ) , m_R.Product( v0[O] , v1[I] ) ); v0[O] = m_R.Product( move( v0[O] ) , v1[O] ); return move( v0 ); }
template <typename RING , typename U> inline T3<U> SquareSumAlgebra<RING,U>::Action( const U& u , T3<U> v ) { v[II] = m_R.Product( u , v[II] ); v[I] = m_R.Product( u , v[I] ); v[O] = m_R.Product( u , v[O] ); return move( v ); }

#define DECLARATION_OF_ARITHMETIC_FOR_DISTRIBUTION( OPR ) inline Distribution<MODINT> operator OPR ( const Distribution<MODINT>& d ) const;

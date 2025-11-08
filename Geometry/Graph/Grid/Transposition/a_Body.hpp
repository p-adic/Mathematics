// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/Transposition/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T> inline TransposableGridRow<T>::TransposableGridRow( vector<vector<T>>& a , const int& i ) : m_p_a( &a ) , m_i( i ) , m_transposed( transposed ) { assert( 0 <= i && i <= H ); }
template <typename T> inline TransposableGridRow<T>::TransposableGridRow( const TransposableGridRow<T>& a ) : m_p_a( a.m_p_a ) , m_i( a.m_i ) , m_transposed( a.m_transposed ) { assert( m_transposed == transposed ); }
template <typename T> inline TransposableGridRow<T>::TransposableGridRow( TransposableGridRow<T>&& a ) : m_p_a( a.m_p_a ) , m_i( a.m_i ) , m_transposed( a.m_transposed ) { assert( m_transposed == transposed ); }
template <typename T> inline bool TransposableGridRow<T>::operator==( const TransposableGridRow<T>& v ) const { assert( m_p_a == v.m_p_a ); return m_transposed == v.m_transposed && m_i == v.m_i; }
template <typename T> inline bool TransposableGridRow<T>::operator!=( const TransposableGridRow<T>& v ) const { return !( *this == v ); }
template <typename T> inline T& TransposableGridRow<T>::operator[]( const int& j ) const { assert( m_transposed == transposed && m_i < H && 0 <= j && j < W ); return transposed ? ( *m_p_a )[j][m_i] : ( *m_p_a )[m_i][j]; }
template <typename T> inline TransposableGridRow<T>& TransposableGridRow<T>::operator*() { assert( m_i < H ); return *this; }
template <typename T> inline TransposableGridRow<T>& TransposableGridRow<T>::operator++() { assert( m_transposed == transposed && ++m_i <= H ); return *this; }
template <typename T> inline TransposableGridRow<T> TransposableGridRow<T>::operator++( int ) { TransposableGridRow<T> copy{ *this }; ++( *this ); return copy; }
template <typename T> inline TransposableGridRow<T>& TransposableGridRow<T>::operator--(){ assert( m_transposed == transposed && --m_i >= 0 ); return *this; }
template <typename T> inline TransposableGridRow<T> TransposableGridRow<T>::operator--( int ) { TransposableGridRow<T> copy{ *this }; --( *this ); return copy; }

template <typename T> inline TransposableGrid<T>::TransposableGrid() : m_a( transposed ? W : H , vector<T>( transposed ? H : W ) ) {}
template <typename T> inline TransposableGridRow<T> TransposableGrid<T>::operator[]( const int& i ) { return TransposableGridRow<T>{ m_a , i }; }
template <typename T> inline TransposableGridRow<T> TransposableGrid<T>::begin() { return ( *this )[0]; }
template <typename T> inline TransposableGridRow<T> TransposableGrid<T>::end() { return ( *this )[H]; }

inline void Transpose() { transposed ^= true; swap( H , W ); }
inline void ResolveTransposition() { if( transposed ){ Transpose(); } }

template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const TransposableGridRow<T>& v ) { for( int j = 0 ; j < W ; j++ ){ ( j == 0 ? os : os << " " ) << v[j]; } return os; }
template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , TransposableGrid<T>& a ) { for( int i = 0 ; i < H ; i++ ){ ( i == 0 ? os : os << "\n" ) << a[i]; } return os; }

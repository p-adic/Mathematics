// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedRational/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Utility/Set/a_Body.hpp"

#include "../Divisor/GCD/a_Body.hpp"
#include "../../Utility/Random/a_Body.hpp"

template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing>::ExtendedRational( T n , T d , const bool& reduced ) : m_n( move( n ) ) , m_d( move( d ) ) { assert( m_n != 0 || m_d != 0 ); if( reduced ){ assert( m_d > 0 ? ( m_n != 0 || m_d == 1 ) : ( m_n == ( m_n > 0 ? 1 : -1 ) && m_d == 0 ) ); } else { if( m_d < 0 ){ m_n *= -1; m_d *= -1; } if constexpr( reducing ){ Reduce(); } } }
template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing>::ExtendedRational( const ExtendedRational<T,reducing>& r ) : m_n( r.m_n ) , m_d( r.m_d ) {}
template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing>::ExtendedRational( ExtendedRational<T,reducing>&& r ) : m_n( move( r.m_n ) ) , m_d( move( r.m_d ) ) {}
template <typename T , bool reducing> template <typename U , bool red> inline constexpr ExtendedRational<T,reducing>::ExtendedRational( ExtendedRational<U,red> r ) : ExtendedRational( move( r.m_n ) , move( r.m_d ) ) {}

template <typename T , bool reducing> inline constexpr void ExtendedRational<T,reducing>::Reduce() { if( m_d == 0 ){ m_n = m_n > 0 ? 1 : -1; } else if( m_n == 0 ){ m_d = 1; } else if( m_d != 1 ){ const T gcd = GCD( m_n , m_d ); assert( gcd != 0 ); m_n /= gcd; m_d /= gcd; } }

template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing>& ExtendedRational<T,reducing>::operator=( ExtendedRational<T,reducing> r ) noexcept { m_n = move( r.m_n ); m_d = move( r.m_d ); return *this; }

template <typename T , bool reducing> inline constexpr T ExtendedRational<T,reducing>::DifferenceNumerator( const ExtendedRational<T,reducing>& r0 , const ExtendedRational<T,reducing>& r1 ) { if( r0.m_d == 0 ){ assert( r1.m_d != 0 || ( r0.m_n > 0 ) == ( r1.m_n > 0 ) ); return r0.m_n > 0 ? 1 : -1; } if( r1.m_d == 0 ){ return r1.m_n > 0 ? -1 : 1; } return r0.m_n * r1.m_d - r1.m_n * r0.m_d; }
template <typename T , bool reducing> inline constexpr bool ExtendedRational<T,reducing>::operator==( const ExtendedRational<T,reducing>& r ) const { return reducing ? m_n == r.m_n && m_d == r.m_d : DifferenceNumerator( *this , r ) == 0; }
template <typename T , bool reducing> inline constexpr bool ExtendedRational<T,reducing>::operator!=( const ExtendedRational<T,reducing>& r ) const { return !( *this == r ); }
template <typename T , bool reducing> inline constexpr bool ExtendedRational<T,reducing>::operator<=( const ExtendedRational<T,reducing>& r ) const { return *this == r || *this < r; }
template <typename T , bool reducing> inline constexpr bool ExtendedRational<T,reducing>::operator>=( const ExtendedRational<T,reducing>& r ) const { return r <= *this; }
template <typename T , bool reducing> inline constexpr bool ExtendedRational<T,reducing>::operator<( const ExtendedRational<T,reducing>& r ) const { return DifferenceNumerator( *this , r ) < 0; }
template <typename T , bool reducing> inline constexpr bool ExtendedRational<T,reducing>::operator>( const ExtendedRational<T,reducing>& r ) const { return r < *this; }

DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( + );
DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( - );
DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( * );
DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( / );
template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing> ExtendedRational<T,reducing>::operator+( const ExtendedRational<T,reducing>& r ) const { if( m_d == 0 ){ assert( r.m_d != 0 || ( m_n > 0 ) == ( r.m_n > 0 ) ); return *this; } if( r.m_d == 0 ){ return r; } const T gcd = GCD( m_d , r.m_d ) , d = gcd == 0 ? gcd : r.m_d / gcd; return gcd == 0 ? *this : ExtendedRational<T,reducing>{ m_n * d + r.m_n * ( m_d / gcd ) , m_d * d }; }
template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing> ExtendedRational<T,reducing>::operator-() const noexcept { return ExtendedRational<T,reducing>{ -m_n , m_d , true }; }
template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing> ExtendedRational<T,reducing>::operator-( const ExtendedRational<T,reducing>& r ) const { return *this + ( -r ); }
template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing> ExtendedRational<T,reducing>::operator*( const ExtendedRational<T,reducing>& r ) const { if( m_d == 0 ){ assert( r.m_n != 0 ); return *this; } if( r.m_d == 0 ){ assert( m_n != 0 ); return r; } const T gcd1 = GCD( m_n , r.m_d ) , gcd2 = GCD( m_d , r.m_n ); return ExtendedRational<T,reducing>{ ( m_n / gcd1 ) * ( r.m_n / gcd2 ) , ( m_d / gcd2 ) * ( r.m_d / gcd1 ) , reducing }; }
template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing> ExtendedRational<T,reducing>::Inverse() const noexcept { return ExtendedRational<T,reducing>{ m_n > 0 ? m_d : m_n < 0 ? -m_d : T{1} , m_n < 0 ? -m_n : m_n , reducing }; }
template <typename T , bool reducing> inline constexpr ExtendedRational<T,reducing> ExtendedRational<T,reducing>::operator/( const ExtendedRational<T,reducing>& r ) const { return *this * r.Inverse(); }

template <typename T , bool reducing> inline constexpr const T& ExtendedRational<T,reducing>::GetNumerator() const noexcept { return m_n; }
template <typename T , bool reducing> inline constexpr const T& ExtendedRational<T,reducing>::GetDenominator() const noexcept { return m_d; }

template <typename T , bool reducing> inline constexpr bool operator==( const T& n , const ExtendedRational<T,reducing>& r ) { return n * r.GetDenominator() == r.GetNumerator(); }
template <typename T , bool reducing> inline constexpr bool operator!=( const T& n , const ExtendedRational<T,reducing>& r ) { return !( n == r ); }
template <typename T , bool reducing> inline constexpr bool operator<=( const T& n , const ExtendedRational<T,reducing>& r ) { return n * r.GetDenominator() <= r.GetNumerator(); }
template <typename T , bool reducing> inline constexpr bool operator>=( const T& n , const ExtendedRational<T,reducing>& r ) { return r <= n; }
template <typename T , bool reducing> inline constexpr bool operator<( const T& n , const ExtendedRational<T,reducing>& r ) { return n * r.GetDenominator() < r.GetNumerator(); }
template <typename T , bool reducing> inline constexpr bool operator>( const T& n , const ExtendedRational<T,reducing>& r ) { return r < n; }

DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( + ) { const T& d = r.GetDenominator(); return ExtendedRational( t * d + r.GetNumerator() , d , true ); }
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( - ) { const T& d = r.GetDenominator(); return ExtendedRational( t * d - r.GetNumerator() , d , true ); }
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( * ) { return ExtendedRational<T,reducing>( t ) * r; }
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( / ) { return ExtendedRational<T,reducing>( t ) / r; }

template <typename T , bool reducing , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , ExtendedRational<T,reducing>& r ) { T temp; cin >> temp; r = temp; return cin; }
template <typename T , bool reducing , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const ExtendedRational<T,reducing>& r ) { return os << r.GetNumerator() << " " << r.GetDenominator(); }

template <typename T , bool reducing> inline size_t hash<ExtendedRational<T,reducing>>::operator()( const ExtendedRational<T,reducing>& r ) const { static const size_t seed = ( GetRand( 1e3 , 1e8 ) << 1 ) | 1; if constexpr( reducing ){ static const hash<T> h; return ( h( r.GetNumerator() ) * seed ) ^ h( r.GetDenominator() ); } static const hash<ExtendedRational<T,true>> h; return h( r ); }

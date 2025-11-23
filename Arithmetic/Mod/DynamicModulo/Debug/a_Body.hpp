// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Constant/a_Body.hpp"
#include "../../Function/Residue/a_Body.hpp"
#include "../../../Divisor/GCD/a_Body.hpp"

template <int NUM> inline DMods<NUM>::DMods() noexcept : m_non_negative( true ) , m_n() , m_d( 1 ) {}
template <int NUM> inline DMods<NUM>::DMods( const DMods<NUM>& n ) noexcept : m_non_negative( n.m_non_negative ) , m_n( n.m_n ) , m_d( n.m_d ) {}
template <int NUM> inline DMods<NUM>::DMods( DMods<NUM>&& n ) noexcept : m_non_negative( n.m_non_negative ) , m_n( move( n.m_n ) ) , m_d( move( n.m_d ) ) {}
template <int NUM> template <typename T , SFINAE_FOR_DMOD> inline DMods<NUM>::DMods( T n ) noexcept : m_non_negative( n >= 0 ) , m_n( uint( move( ( m_non_negative ? n : n *= -1 ) %= Constants::g_M ) ) ) , m_d( Constants::g_M > 1 ? 1 : 0 ) {}

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator=( DMods<NUM> n ) noexcept { m_non_negative = n.m_non_negative; m_n = move( n.m_n ); m_d = move( n.m_d ); return *this; }

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator+=( const DMods<NUM>& n ) noexcept { if( Constants::g_M > 1 ){ ull m_n0 = ull( m_n ) * n.m_d , m_n1 = n.m_n * ull( m_d ) , m_n_copy = m_non_negative == n.m_non_negative ? move( m_n0 += m_n1 ) : m_n0 == m_n1 ? ( m_non_negative = true , 0 ) : m_n0 > m_n1 ? move( m_n0 -= m_n1 ) : ( m_non_negative = !m_non_negative , move( m_n1 -= m_n0 ) ); ull m_d_copy = ull( m_d ) * n.m_d; ull gcd = GCD( m_n_copy , m_d_copy ); assert( gcd != 0 ); m_n = uint( move( ( m_n_copy /= gcd ) %= Constants::g_M ) ); m_d = uint( move( ( m_d_copy /= gcd ) %= Constants::g_M ) ); } return *this; }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator-=( const DMods<NUM>& n ) noexcept { if( Constants::g_M > 1 ){ ull m_n0 = ull( m_n ) * n.m_d , m_n1 = n.m_n * ull( m_d ) , m_n_copy = m_non_negative != n.m_non_negative ? move( m_n0 += m_n1 ) : m_n0 == m_n1 ? ( m_non_negative = true , 0 ) : m_n0 > m_n1 ? move( m_n0 -= m_n1 ) : ( m_non_negative = !m_non_negative , move( m_n1 -= m_n0 ) ); ull m_d_copy = ull( m_d ) * n.m_d; ull gcd = GCD( m_n_copy , m_d_copy ); assert( gcd != 0 ); m_n = uint( move( ( m_n_copy /= gcd ) %= Constants::g_M ) ); m_d = uint( move( ( m_d_copy /= gcd ) %= Constants::g_M ) ); } return *this; }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator*=( const DMods<NUM>& n ) noexcept { if( Constants::g_M > 1 ){ ull m_n_copy = ull( m_n ) * n.m_n , m_d_copy = ull( m_d ) * n.m_d; ull gcd = GCD( m_n_copy , m_d_copy ); assert( gcd != 0 ); m_n = uint( move( ( m_n_copy /= gcd ) %= Constants::g_M ) ); m_d = uint( move( ( m_d_copy /= gcd ) %= Constants::g_M ) ); m_non_negative = m_n == 0 || m_non_negative == n.m_non_negative; } return *this; }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator/=( DMods<NUM> n ) { return operator*=( n.Invert() ); }
template <int NUM> inline DMods<NUM>& DMods<NUM>::PositivePower( ll exponent ) noexcept { DMods<NUM> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <int NUM> inline DMods<NUM>& DMods<NUM>::NonNegativePower( ll exponent ) noexcept { return exponent == 0 ? ( m_n = 1 , *this ) : PositivePower( move( exponent ) ); }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator^=( ll exponent ) { if( exponent < 0 ){ Invert(); exponent *= -1; } return NonNegativePower( move( exponent ) ); }

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator<<=( ll n ) { return *this *= ( n < 0 && -n < int( Constants::g_memory_length ) ) ? TwoPowerInverse( - int( n ) ) : ( n >= 0 && n < int( Constants::g_memory_length ) ) ? TwoPower( int( n ) ) : DMods<NUM>( 2 ) ^= move( n ); }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator>>=( ll n ) { return *this <<= move( n *= -1 ); }

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator++() noexcept { return *this += 1; }
template <int NUM> inline DMods<NUM> DMods<NUM>::operator++( int ) noexcept { DMods<NUM> n{ *this }; operator++(); return n; }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator--() noexcept { return *this -= 1; }
template <int NUM> inline DMods<NUM> DMods<NUM>::operator--( int ) noexcept { DMods<NUM> n{ *this }; operator--(); return n; }

template <int NUM> inline bool DMods<NUM>::operator==( const DMods<NUM>& n ) const noexcept { const uint n0 = ull( m_n ) * n.m_d % Constants::g_M , n1 = n.m_n * ull( m_d ) % Constants::g_M; return ( m_non_negative || n0 == 0 ? n0 : Constants::g_M - n0 ) == ( n.m_non_negative || n1 == 0 ? n1 : Constants::g_M - n1 ); }
template <int NUM> inline bool DMods<NUM>::operator!=( const DMods<NUM>& n ) const noexcept { return !( *this == n ); }
template <int NUM> inline bool DMods<NUM>::operator<( const DMods<NUM>& n ) const noexcept { const uint n0 = ull( m_n ) * n.m_d % Constants::g_M , n1 = n.m_n * ull( m_d ) % Constants::g_M; return ( m_non_negative || n0 == 0 ? n0 : Constants::g_M - n0 ) < ( n.m_non_negative || n1 == 0 ? n1 : Constants::g_M - n1 ); }
template <int NUM> inline bool DMods<NUM>::operator<=( const DMods<NUM>& n ) const noexcept { return !( n < *this ); }
template <int NUM> inline bool DMods<NUM>::operator>( const DMods<NUM>& n ) const noexcept { return n < *this; }
template <int NUM> inline bool DMods<NUM>::operator>=( const DMods<NUM>& n ) const noexcept { return n <= *this; }

DEFINITION_OF_ARITHMETIC_FOR_DMOD( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_DMOD( - , noexcept , n.SignInvert() , + );
DEFINITION_OF_ARITHMETIC_FOR_DMOD( * , noexcept , n , * );
DEFINITION_OF_ARITHMETIC_FOR_DMOD( / , , n.Invert() , * );
template <int NUM> inline DMods<NUM> DMods<NUM>::operator^( ll exponent ) const { return move( DMods<NUM>( *this ) ^= move( exponent ) ); }
template <int NUM> inline DMods<NUM> DMods<NUM>::operator<<( ll n ) const { return move( DMods<NUM>( *this ) <<= move( n ) ); }
template <int NUM> inline DMods<NUM> DMods<NUM>::operator>>( ll n ) const { return move( DMods<NUM>( *this ) >>= move( n ) ); }

template <int NUM> inline DMods<NUM> DMods<NUM>::operator-() const noexcept { return move( DMods<NUM>( *this ).SignInvert() ); }
template <int NUM> inline DMods<NUM>& DMods<NUM>::SignInvert() noexcept { m_non_negative = m_n == 0 || !m_non_negative; return *this; }

template <int NUM> inline DMods<NUM>& DMods<NUM>::Invert() { assert( GCD( m_n , Constants::g_M ) == 1 ); std::swap( m_n , m_d ); return *this; }

template <int NUM> inline void DMods<NUM>::swap( DMods<NUM>& n ) noexcept { std::swap( m_non_negative , n.m_non_negative ); std::swap( m_n , n.m_n ); std::swap( m_d , n.m_d ); }

template <int NUM> inline const DMods<NUM>& DMods<NUM>::Inverse( const int& n ) { if( Constants::g_M == 1 ){ return zero(); } assert( Constants::g_M_is_prime && 0 < n && n < int( Constants::g_memory_length ) ); static vector<DMods<NUM>> memory = { zero() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( Derepresent( Constants::g_M - memory[Constants::g_M % length_curr].m_n * ull( Constants::g_M / length_curr ) % Constants::g_M ) ); length_curr++; } return memory[n]; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::TwoPower( const int& n ) { if( Constants::g_M == 1 ){ return zero(); } assert( 0 <= n && n < int( Constants::g_memory_length ) ); static vector<DMods<NUM>> memory = { one() }; static int length_curr = 1; while( length_curr <= n ){ memory.push_back( memory.back() + memory.back() ); length_curr++; } return memory[n]; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::TwoPowerInverse( const int& n ) { if( Constants::g_M == 1 ){ return zero(); } assert( 0 <= n && n < int( Constants::g_memory_length ) ); static vector<DMods<NUM>> memory = { one() }; static int length_curr = 1; while( length_curr <= n ){ memory.push_back( Derepresent( 1 ) / TwoPower( n ) ); length_curr++; } return memory[n]; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::Factorial( const ll& n ) { assert( n >= 0 ); if( ll( Constants::g_M ) <= n ){ return zero(); } static vector<DMods<NUM>> memory = { one() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] ); auto& temp = memory.back().m_n; temp = ull( temp ) * length_curr++ % Constants::g_M; } return memory[n]; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::FactorialInverse( const ll& n ) { assert( Constants::g_M_is_prime && 0 <= n && n < Constants::g_M ); static vector<DMods<NUM>> memory = { one() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] ); auto& temp = memory.back().m_d; temp = ull( temp ) * length_curr++ % Constants::g_M; } return memory[n]; }
template <int NUM> inline DMods<NUM> DMods<NUM>::Combination( const ll& n , const ll& i ) { return 0 <= i && i <= n ? Factorial( n ) * FactorialInverse( i ) * FactorialInverse( n - i ) : zero(); }

template <int NUM> inline const bool& DMods<NUM>::GetSign() const noexcept { return m_non_negative; }
template <int NUM> inline const uint& DMods<NUM>::GetNumerator() const noexcept { return m_n; }
template <int NUM> inline const uint& DMods<NUM>::GetDenominator() const noexcept { return m_d; }
template <int NUM> inline uint DMods<NUM>::Represent() const noexcept { return ull( m_non_negative ? m_n : Constants::g_M - m_n ) * ModularInverse( Constants::g_M , m_d ) % Constants::g_M; }
template <int NUM> inline DMods<NUM> DMods<NUM>::Derepresent( uint n ) noexcept { DMods<NUM> n_copy{}; n_copy.m_n = move( n ); return n_copy; }

template <int NUM> inline const DMods<NUM>& DMods<NUM>::zero() noexcept { static const DMods<NUM> z{}; return z; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::one() noexcept { static const DMods<NUM> o{ 1 }; return o; }

template <int NUM> inline const uint& DMods<NUM>::GetModulo() noexcept { return Constants::g_M; }
template <int NUM> inline void DMods<NUM>::SetModulo( const uint& M , const bool& M_is_prime ) noexcept { Constants::g_M = M; Constants::g_memory_length = M < Constants::g_memory_bound ? M : Constants::g_memory_bound;; Constants::g_M_minus = M - 1; Constants::g_M_is_prime = M_is_prime; }

template <int NUM> inline DMods<NUM> Inverse( const DMods<NUM>& n ) { return move( DMods<NUM>( n ).Invert() ); }

template <int NUM> inline DMods<NUM> Power( DMods<NUM> n , ll exponent ) { return move( n ^= move( exponent ) ); }

template <int NUM> inline void swap( DMods<NUM>& n0 , DMods<NUM>& n1 ) noexcept { n0.swap( n1 ); }

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , DMods<NUM>& n ) { ll m; is >> m; n = m; return is; }

template <int NUM , class Traits>
inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const DMods<NUM>& n )
{

  if( exec_mode == solve_mode || exec_mode == sample_analysis_mode  ){

    os << ( n.GetSign() ? "" : "-" ) << n.GetNumerator();
    return n.GetDenominator() == 1 ? n.GetSign() ? os : os << " Åﬂ " << n.Represent() : os << "/" << n.GetDenominator() << " Åﬂ " << n.Represent();

  }

  return os << n.Represent();
  
}

template <int NUM> inline string to_string( const DMods<NUM>& n ) noexcept { const uint& M = DMods<NUM>::GetModulo(); return ( n.GetSign() ? "" : "-" ) + to_string( n.GetNumerator() ) + ( n.GetNumerator() == 1 ? " + " + to_string( M ) + "Z" : "/" + to_string( n.GetDenominator() ) + " + " + to_string( M ) + "Z = " + to_string( n.Represent() ) + " + " + to_string( M ) + "Z" ); }

#include "../../Hash/a_Body.hpp"
template <int NUM> DEFINITION_OF_HASH_FOR_MOD( DMods<NUM> );

// îÒDebugéûÇ∆includeÇìùàÍÇ∑ÇÈÅB
#include "../../Function/Residue/Inverse/a_Body.hpp"

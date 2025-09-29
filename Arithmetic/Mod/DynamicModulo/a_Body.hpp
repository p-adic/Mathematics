// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"
#include "../Function/Residue/a_Body.hpp"

template <int NUM> inline DMods<NUM>::DMods() noexcept : m_n() {}
template <int NUM> inline DMods<NUM>::DMods( const DMods<NUM>& n ) noexcept : m_n( n.m_n ) {}
template <int NUM> inline DMods<NUM>::DMods( DMods<NUM>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <int NUM> template <typename T , SFINAE_FOR_DMOD> inline DMods<NUM>::DMods( T n ) noexcept : m_n( Residue( move( n ) , Constants::g_M ) ) {}

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator=( DMods<NUM> n ) noexcept { m_n = move( n.m_n ); return *this; }

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator+=( const DMods<NUM>& n ) noexcept { ( m_n += n.m_n ) < Constants::g_M ? m_n : m_n -= Constants::g_M; return *this; }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator-=( const DMods<NUM>& n ) noexcept { m_n < n.m_n ? ( m_n += Constants::g_M ) -= n.m_n : m_n -= n.m_n; return *this; }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator*=( const DMods<NUM>& n ) noexcept { m_n = Residue( move( ull( m_n ) * n.m_n ) , Constants::g_M ); return *this; }

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator/=( DMods<NUM> n ) { return operator*=( n.Invert() ); }
template <int NUM> inline DMods<NUM>& DMods<NUM>::PositivePower( ll exponent ) noexcept { DMods<NUM> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <int NUM> inline DMods<NUM>& DMods<NUM>::NonNegativePower( ll exponent ) noexcept { return exponent == 0 ? ( m_n = 1 , *this ) : PositivePower( move( exponent ) ); }

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator^=( ll exponent ) { if( exponent < 0 ){ m_n = ModularInverse( Constants::g_M , move( m_n ) ); exponent *= -1; } return NonNegativePower( move( exponent ) ); }

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator<<=( ll n ) { return *this *= ( n < 0 && -n < int( Constants::g_memory_length ) ) ? TwoPowerInverse( - int( n ) ) : ( n >= 0 && n < int( Constants::g_memory_length ) ) ? TwoPower( int( n ) ) : DMods<NUM>( 2 ) ^= move( n ); }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator>>=( ll n ) { return *this <<= move( n *= -1 ); }

template <int NUM> inline DMods<NUM>& DMods<NUM>::operator++() noexcept { m_n < Constants::g_M_minus ? ++m_n : m_n = 0; return *this; }
template <int NUM> inline DMods<NUM> DMods<NUM>::operator++( int ) noexcept { DMods<NUM> n{ *this }; operator++(); return n; }
template <int NUM> inline DMods<NUM>& DMods<NUM>::operator--() noexcept { m_n == 0 ? m_n = Constants::g_M_minus : --m_n; return *this; }
template <int NUM> inline DMods<NUM> DMods<NUM>::operator--( int ) noexcept { DMods<NUM> n{ *this }; operator--(); return n; }

DEFINITION_OF_COMPARISON_FOR_DMOD( == );
DEFINITION_OF_COMPARISON_FOR_DMOD( != );
DEFINITION_OF_COMPARISON_FOR_DMOD( > );
DEFINITION_OF_COMPARISON_FOR_DMOD( >= );
DEFINITION_OF_COMPARISON_FOR_DMOD( < );
DEFINITION_OF_COMPARISON_FOR_DMOD( <= );

DEFINITION_OF_ARITHMETIC_FOR_DMOD( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_DMOD( - , noexcept , n.SignInvert() , + );
DEFINITION_OF_ARITHMETIC_FOR_DMOD( * , noexcept , n , * );
DEFINITION_OF_ARITHMETIC_FOR_DMOD( / , , n.Invert() , * );
template <int NUM> inline DMods<NUM> DMods<NUM>::operator^( ll exponent ) const { return move( DMods<NUM>( *this ) ^= move( exponent ) ); }
template <int NUM> inline DMods<NUM> DMods<NUM>::operator<<( ll n ) const { return move( DMods<NUM>( *this ) <<= move( n ) ); }
template <int NUM> inline DMods<NUM> DMods<NUM>::operator>>( ll n ) const { return move( DMods<NUM>( *this ) >>= move( n ) ); }

template <int NUM> inline DMods<NUM> DMods<NUM>::operator-() const noexcept { return move( DMods<NUM>( *this ).SignInvert() ); }
template <int NUM> inline DMods<NUM>& DMods<NUM>::SignInvert() noexcept { m_n > 0 ? m_n = Constants::g_M - m_n : m_n; return *this; }

template <int NUM> inline DMods<NUM>& DMods<NUM>::Invert() { m_n = Constants::g_M_is_prime && m_n < Constants::g_memory_length ? Inverse( int( m_n ) ).m_n : ModularInverse( Constants::g_M , move( m_n ) ); return *this; }

template <int NUM> inline void DMods<NUM>::swap( DMods<NUM>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <int NUM> inline const DMods<NUM>& DMods<NUM>::Inverse( const int& n ) { if( Constants::g_M == 1 ){ return zero(); } assert( Constants::g_M_is_prime && 0 < n && n < int( Constants::g_memory_length ) ); static vector<DMods<NUM>> memory = { zero() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( Derepresent( Constants::g_M - memory[Constants::g_M % length_curr].m_n * ull( Constants::g_M / length_curr ) % Constants::g_M ) ); length_curr++; } return memory[n]; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::TwoPower( const int& n ) { if( Constants::g_M == 1 ){ return zero(); } assert( 0 <= n && n < int( Constants::g_memory_length ) ); static vector<DMods<NUM>> memory = { one() }; static int length_curr = 1; while( length_curr <= n ){ memory.push_back( memory.back() + memory.back() ); length_curr++; } return memory[n]; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::TwoPowerInverse( const int& n ) { if( Constants::g_M == 1 ){ return zero(); } assert( 0 <= n && n < int( Constants::g_memory_length ) ); static vector<DMods<NUM>> memory = { one() }; static int length_curr = 1; while( length_curr <= n ){ auto& m = memory.back().m_n; memory.push_back( Derepresent( ( ( m & 1 ) == 0 ? m : m + Constants::g_M ) >> 1 ) ); length_curr++; } return memory[n]; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::Factorial( const ll& n ) { assert( 0 <= n ); if( ll( Constants::g_M ) <= n ){ return zero(); } static vector<DMods<NUM>> memory = { one() , one() }; static int length_curr = 2; while( length_curr <= n && memory.back().m_n != 0 ){ memory.push_back( memory.back() * Derepresent( length_curr ) ); length_curr++; } return length_curr <= n ? memory.back() : memory[n]; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::FactorialInverse( const ll& n ) { assert( 0 <= n && n < Constants::g_M ); static vector<DMods<NUM>> memory = { one() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] * Inverse( length_curr ) ); length_curr++; } return memory[n]; }
template <int NUM> inline DMods<NUM> DMods<NUM>::Combination( const ll& n , const ll& i ) { return 0 <= i && i <= n ? Factorial( n ) * FactorialInverse( i ) * FactorialInverse( n - i ) : zero(); }

template <int NUM> inline const uint& DMods<NUM>::Represent() const noexcept { return m_n; }
template <int NUM> inline DMods<NUM> DMods<NUM>::Derepresent( uint n ) noexcept { DMods<NUM> n_copy{}; n_copy.m_n = move( n ); return n_copy; }

template <int NUM> inline const DMods<NUM>& DMods<NUM>::zero() noexcept { static const DMods<NUM> z{}; return z; }
template <int NUM> inline const DMods<NUM>& DMods<NUM>::one() noexcept { static const DMods<NUM> o{ 1 }; return o; }

template <int NUM> inline const uint& DMods<NUM>::GetModulo() noexcept { return Constants::g_M; }
template <int NUM> inline void DMods<NUM>::SetModulo( const uint& M , const bool& M_is_prime ) noexcept { Constants::g_M = M; Constants::g_memory_length = M < Constants::g_memory_bound ? M : Constants::g_memory_bound;; Constants::g_M_minus = M - 1; Constants::g_M_is_prime = M_is_prime; }

template <int NUM> inline DMods<NUM> Inverse( const DMods<NUM>& n ) { return move( DMods<NUM>( n ).Invert() ); }
template <int NUM> inline DMods<NUM> Power( DMods<NUM> n , ll exponent ) { return move( n ^= move( exponent ) ); }

template <int NUM> inline void swap( DMods<NUM>& n0 , DMods<NUM>& n1 ) noexcept { n0.swap( n1 ); }

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , DMods<NUM>& n ) { ll m; is >> m; n = m; return is; }
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const DMods<NUM>& n ) { return os << n.Represent(); }

#include "../Hash/a_Body.hpp"
template <int NUM> DEFINITION_OF_HASH_FOR_MOD( DMods<NUM> );

template <int NUM> inline string to_string( const DMods<NUM>& n ) noexcept { return to_string( n.Represent() ) + " + " + to_string( DMods<NUM>::GetModulo() ) + "Z"; }

// ïsóvÇæÇ™ÅADebugÇÃï˚Ç≈includeÇµÇƒÇ¢ÇÈÇÃÇ≈includeÇµñYÇÍÉ~ÉXñhé~ÇÃÇΩÇﬂÇ…includeÇ∑ÇÈÅB
#include "../../Divisor/GCD/a_Body.hpp"


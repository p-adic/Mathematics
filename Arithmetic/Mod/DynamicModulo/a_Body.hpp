// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"
#include "../Function/Residue/a_Body.hpp"

template <int NUM> inline DynamicMods<NUM>::DynamicMods() noexcept : m_n() {}
template <int NUM> inline DynamicMods<NUM>::DynamicMods( const DynamicMods<NUM>& n ) noexcept : m_n( n.m_n ) {}
template <int NUM> inline DynamicMods<NUM>::DynamicMods( DynamicMods<NUM>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <int NUM> template <typename T , SFINAE_FOR_DMOD> inline DynamicMods<NUM>::DynamicMods( T n ) noexcept : m_n( Residue( move( n ) , Constants::g_M ) ) {}

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator=( DynamicMods<NUM> n ) noexcept { m_n = move( n.m_n ); return *this; }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator+=( const DynamicMods<NUM>& n ) noexcept { ( m_n += n.m_n ) < Constants::g_M ? m_n : m_n -= Constants::g_M; return *this; }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator-=( const DynamicMods<NUM>& n ) noexcept { m_n < n.m_n ? ( m_n += Constants::g_M ) -= n.m_n : m_n -= n.m_n; return *this; }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator*=( const DynamicMods<NUM>& n ) noexcept { m_n = Residue( move( ull( m_n ) * n.m_n ) , Constants::g_M ); return *this; }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator/=( DynamicMods<NUM> n ) { return operator*=( n.Invert() ); }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::PositivePower( ll exponent ) noexcept { DynamicMods<NUM> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::NonNegativePower( ll exponent ) noexcept { return exponent == 0 ? ( m_n = 1 , *this ) : PositivePower( move( exponent ) ); }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator^=( ll exponent ) { bool neg = exponent < 0; assert( !( neg && m_n == 0 ) ); return NonNegativePower( move( neg ? ( exponent %= Constants::g_order ) == 0 ? exponent : exponent += Constants::g_order : exponent ) ); }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator<<=( ll n ) { return *this *= ( n < 0 && -n < int( Constants::g_memory_length ) ) ? TwoPowerInverse( - int( n ) ) : ( n >= 0 && n < int( Constants::g_memory_length ) ) ? TwoPower( int( n ) ) : DynamicMods<NUM>( 2 ) ^= move( n ); }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator>>=( ll n ) { return *this <<= move( n *= -1 ); }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator++() noexcept { m_n < Constants::g_M_minus ? ++m_n : m_n = 0; return *this; }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::operator++( int ) noexcept { DynamicMods<NUM> n{ *this }; operator++(); return n; }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator--() noexcept { m_n == 0 ? m_n = Constants::g_M_minus : --m_n; return *this; }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::operator--( int ) noexcept { DynamicMods<NUM> n{ *this }; operator--(); return n; }

DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( == );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( != );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( > );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( >= );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( < );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( <= );

DEFINITION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( - , noexcept , n.SignInvert() , + );
DEFINITION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( * , noexcept , n , * );
DEFINITION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( / , , n.Invert() , * );
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::operator^( ll exponent ) const { return move( DynamicMods<NUM>( *this ) ^= move( exponent ) ); }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::operator<<( ll n ) const { return move( DynamicMods<NUM>( *this ) <<= move( n ) ); }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::operator>>( ll n ) const { return move( DynamicMods<NUM>( *this ) >>= move( n ) ); }

template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::operator-() const noexcept { return move( DynamicMods<NUM>( *this ).SignInvert() ); }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::SignInvert() noexcept { m_n > 0 ? m_n = Constants::g_M - m_n : m_n; return *this; }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::Invert() { return m_n < ( Constants::g_M_is_prime ? 1e6 : 3e4 ) ? *this = Inverse( m_n ) : NonNegativePower( Constants::g_order_minus ); }

template <int NUM> inline void DynamicMods<NUM>::swap( DynamicMods<NUM>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::Inverse( const int& n ) { if( Constants::g_M == 1 ){ return zero(); } assert( 0 < n && n < int( Constants::g_memory_length ) ); static vector<DynamicMods<NUM>> memory = { zero() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( Constants::g_M_is_prime ? Derepresent( Constants::g_M - memory[Constants::g_M % length_curr].m_n * ull( Constants::g_M / length_curr ) % Constants::g_M ) : Derepresent( n ).NonNegativePower( Constants::g_order_minus ) ); length_curr++; } return memory[n]; }
template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::TwoPower( const int& n ) { if( Constants::g_M == 1 ){ return zero(); } assert( 0 <= n && n < int( Constants::g_memory_length ) ); static vector<DynamicMods<NUM>> memory = { one() }; static int length_curr = 1; while( length_curr <= n ){ memory.push_back( memory.back() + memory.back() ); length_curr++; } return memory[n]; }
template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::TwoPowerInverse( const int& n ) { if( Constants::g_M == 1 ){ return zero(); } assert( 0 <= n && n < int( Constants::g_memory_length ) ); static vector<DynamicMods<NUM>> memory = { one() }; static int length_curr = 1; while( length_curr <= n ){ auto& m = memory.back().m_n; memory.push_back( Derepresent( ( ( m & 1 ) == 0 ? m : m + Constants::g_M ) >> 1 ) ); length_curr++; } return memory[n]; }
template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::Factorial( const ll& n ) { assert( 0 <= n ); if( ll( Constants::g_M ) <= n ){ return zero(); } static vector<DynamicMods<NUM>> memory = { one() , one() }; static int length_curr = 2; while( length_curr <= n && memory.back().m_n != 0 ){ memory.push_back( memory.back() * Derepresent( length_curr ) ); length_curr++; } return length_curr <= n ? memory.back() : memory[n]; }
template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::FactorialInverse( const ll& n ) { assert( 0 <= n && n < Constants::g_M ); static vector<DynamicMods<NUM>> memory = { one() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] * Inverse( length_curr ) ); length_curr++; } return memory[n]; }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::Combination( const ll& n , const ll& i ) { return 0 <= i && i <= n ? Factorial( n ) * FactorialInverse( i ) * FactorialInverse( n - i ) : zero(); }

template <int NUM> inline const uint& DynamicMods<NUM>::Represent() const noexcept { return m_n; }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::Derepresent( uint n ) noexcept { DynamicMods<NUM> n_copy{}; n_copy.m_n = move( n ); return n_copy; }

template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::zero() noexcept { static const DynamicMods<NUM> z{}; return z; }
template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::one() noexcept { static const DynamicMods<NUM> o{ 1 }; return o; }

template <int NUM> inline const uint& DynamicMods<NUM>::GetModulo() noexcept { return Constants::g_M; }
template <int NUM> inline void DynamicMods<NUM>::SetModulo( const uint& M , const int& order_minus ) noexcept { Constants::g_M = M; Constants::g_memory_length = M < Constants::g_memory_bound ? M : Constants::g_memory_bound;; Constants::g_M_minus = M - 1; Constants::g_order = order_minus == -1 ? M - 1 : order_minus + 1; Constants::g_order_minus = Constants::g_order - 1; Constants::g_M_is_prime = order_minus == -1; }

template <int NUM> inline DynamicMods<NUM> Inverse( const DynamicMods<NUM>& n ) { return move( DynamicMods<NUM>( n ).Invert() ); }
template <int NUM> inline DynamicMods<NUM> Power( DynamicMods<NUM> n , ll exponent ) { return move( n ^= move( exponent ) ); }

template <int NUM> inline void swap( DynamicMods<NUM>& n0 , DynamicMods<NUM>& n1 ) noexcept { n0.swap( n1 ); }

template <int NUM> inline string to_string( const DynamicMods<NUM>& n ) noexcept { return to_string( n.Represent() ) + " + " + to_string( DynamicMods<NUM>::GetModulo() ) + "Z"; }

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , DynamicMods<NUM>& n ) { ll m; is >> m; n = m; return is; }
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const DynamicMods<NUM>& n ) { return os << n.Represent(); }

#include "../Hash/a_Body.hpp"
template <int NUM> DEFINITION_OF_HASH_FOR_MOD( DynamicMods<NUM> );

// ïsóvÇæÇ™ÅADebugÇÃï˚Ç≈includeÇµÇƒÇ¢ÇÈÇÃÇ≈includeÇµñYÇÍÉ~ÉXñhé~ÇÃÇΩÇﬂÇ…includeÇ∑ÇÈÅB
#include "../../Divisor/GCD/a_Body.hpp"

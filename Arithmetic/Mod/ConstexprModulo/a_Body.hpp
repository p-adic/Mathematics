// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"
#include "../Function/Residue/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod() noexcept : m_n() {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( Mod<M>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <INT_TYPE_FOR_MOD M> template <typename T , SFINAE_FOR_MOD> inline constexpr Mod<M>::Mod( T n ) noexcept : m_n( Residue<M>( move( n ) ) ) {}

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator=( Mod<M> n ) noexcept { m_n = move( n.m_n ); return *this; }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { ( m_n += n.m_n ) < M ? m_n : m_n -= M; return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { m_n < n.m_n ? ( m_n += M ) -= n.m_n : m_n -= n.m_n; return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept { m_n = move( ull( m_n ) * n.m_n ) % M; return *this; }
template <> inline constexpr Mod<998244353>& Mod<998244353>::operator*=( const Mod<998244353>& n ) noexcept { ull m_n_copy = m_n; m_n = move( ( m_n_copy *= n.m_n ) < 998244353 ? m_n_copy : Residue998244353( m_n_copy ) ); return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( Mod<M> n ) { return operator*=( n.Invert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::PositivePower( ll exponent ) noexcept { Mod<M> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::NonNegativePower( ll exponent ) noexcept { return exponent == 0 ? ( m_n = 1 , *this ) : PositivePower( move( exponent ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator^=( ll exponent ) { if( exponent < 0 ){ Invert(); exponent *= -1; } return NonNegativePower( move( exponent ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator<<=( ll n ) { return *this *= ( n < 0 && -n < int( Constants::g_memory_length ) ) ? TwoPowerInverse( - int( n ) ) : ( n >= 0 && n < int( Constants::g_memory_length ) ) ? TwoPower( int( n ) ) : Mod<M>( 2 ) ^= move( n ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator>>=( ll n ) { return *this <<= move( n *= -1 ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator++() noexcept { m_n < Constants::g_M_minus ? ++m_n : m_n = 0; return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator++( int ) noexcept { Mod<M> n{ *this }; operator++(); return n; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator--() noexcept { m_n == 0 ? m_n = Constants::g_M_minus : --m_n; return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator--( int ) noexcept { Mod<M> n{ *this }; operator--(); return n; }

DEFINITION_OF_COMPARISON_FOR_MOD( == );
DEFINITION_OF_COMPARISON_FOR_MOD( != );
DEFINITION_OF_COMPARISON_FOR_MOD( > );
DEFINITION_OF_COMPARISON_FOR_MOD( >= );
DEFINITION_OF_COMPARISON_FOR_MOD( < );
DEFINITION_OF_COMPARISON_FOR_MOD( <= );

DEFINITION_OF_ARITHMETIC_FOR_MOD( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_MOD( - , noexcept , n.SignInvert() , + );
DEFINITION_OF_ARITHMETIC_FOR_MOD( * , noexcept , n , * );
DEFINITION_OF_ARITHMETIC_FOR_MOD( / , , n.Invert() , * );
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator^( ll exponent ) const { return move( Mod<M>( *this ) ^= move( exponent ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator<<( ll n ) const { return move( Mod<M>( *this ) <<= move( n ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator>>( ll n ) const { return move( Mod<M>( *this ) >>= move( n ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator-() const noexcept { return move( Mod<M>( *this ).SignInvert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::SignInvert() noexcept { m_n > 0 ? m_n = M - m_n : m_n; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::Invert() { m_n = m_n < Constants::g_memory_length ? Inverse( int( m_n ) ).m_n : ModularInverse( M , move( m_n ) ); return *this; }

template <INT_TYPE_FOR_MOD M> inline constexpr void Mod<M>::swap( Mod<M>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Inverse( const int& n ) { assert( 0 < n && n < int( Constants::g_memory_length ) ); static vector<Mod<M>> memory = { zero() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( Derepresent( M - memory[M % length_curr].m_n * ull( M / length_curr ) % M ) ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::TwoPower( const int& n ) { assert( 0 <= n && n < int( Constants::g_memory_length ) ); static vector<Mod<M>> memory = { one() }; static int length_curr = 1; while( length_curr <= n ){ memory.push_back( memory.back() + memory.back() ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::TwoPowerInverse( const int& n ) { assert( 0 <= n && n < int( Constants::g_memory_length ) ); static vector<Mod<M>> memory = { one() }; static int length_curr = 1; while( length_curr <= n ){ auto& m = memory.back().m_n; memory.push_back( Derepresent( ( ( m & 1 ) == 0 ? m : m + M ) >> 1 ) ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Factorial( const ll& n ) { assert( n >= 0 ); if( ll( M ) <= n ){ return zero(); } static vector<Mod<M>> memory = { one() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] * length_curr ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::FactorialInverse( const ll& n ) { assert( 0 <= n && n < ll( M ) ); static vector<Mod<M>> memory = { one() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] * Inverse( length_curr ) ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::Combination( const ll& n , const ll& i ) { return 0 <= i && i <= n ? Factorial( n ) * FactorialInverse( i ) * FactorialInverse( n - i ) : zero(); }

template <INT_TYPE_FOR_MOD M> inline constexpr const INT_TYPE_FOR_MOD& Mod<M>::Represent() const noexcept { return m_n; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::Derepresent( INT_TYPE_FOR_MOD n ) noexcept { Mod<M> n_copy{}; n_copy.m_n = move( n ); return n_copy; }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::zero() noexcept { static constexpr const Mod<M> z{}; return z; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::one() noexcept { static constexpr const Mod<M> o{ 1 }; return o; }

template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD Mod<M>::GetModulo() noexcept { return M; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n ) { return move( Mod<M>( n ).Invert() ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Power( Mod<M> n , ll exponent ) { return move( n ^= move( exponent ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept { return to_string( n.Represent() ) + " + " + to_string( M ) + "Z"; }

template <INT_TYPE_FOR_MOD M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Mod<M>& n ) { ll m; is >> m; n = m; return is; }
template <INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n ) { return os << n.Represent(); }

#include "../Hash/a_Body.hpp"
template <INT_TYPE_FOR_MOD M> DEFINITION_OF_HASH_FOR_MOD( Mod<M> );

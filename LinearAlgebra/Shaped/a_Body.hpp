// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Shaped/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"

#include "../../Arithmetic/Iteration/a_Body.hpp"
#include "../../Utility/Vector/a_Body.hpp"

template <typename T , int NUM> inline ShapedMatrix<T,NUM>::ShapedMatrix() noexcept : m_M( Constants::g_Y ) { for( int y = 0 ; y < Constants::g_Y ; y++ ){ m_M[y].resize( Constants::g_d[y] , Constants::g_zero ); } }
template <typename T , int NUM> inline ShapedMatrix<T,NUM>::ShapedMatrix( const T& t ) noexcept : ShapedMatrix() { for( int y = 0 ; y < Constants::g_Y ; y++ ){ operator()( y , y ) = t; } }
template <typename T , int NUM> inline ShapedMatrix<T,NUM>::ShapedMatrix( const ShapedMatrix<T,NUM>& mat ) noexcept : m_M( mat.m_M ) {}
template <typename T , int NUM> inline ShapedMatrix<T,NUM>::ShapedMatrix( ShapedMatrix<T,NUM>&& mat ) noexcept : m_M( move( mat.m_M ) ) {}

template <typename T , int NUM>
void ShapedMatrix<T,NUM>::SetShape( vector<int> l , vector<int> r ) noexcept
{

  assert( ( Constants::g_Y =  l.size() ) == int( r.size() ) );
  Constants::g_l = move( l );
  Constants::g_r = move( r );
  Constants::g_d.clear();
  Constants::g_mult.clear();
  
  for( int y = 0 ; y < Constants::g_Y ; y++ ){

    assert( Constants::g_l[y] <= Constants::g_r[y] + 1 );
    const int x0 = Constants::g_l[y] , x1 = Constants::g_r[y] , X = x1 - x0 + 1;
    Constants::g_d <<= X;

    for( int x = x0 ; x <= x1 ; x++ ){

      for( int z = x0 ; z <= x1 ; z++ ){

        if( Constants::g_l[x] <=  z && z <= Constants::g_r[x] ){

          Constants::g_mult <<= {y,x,z};

        }

      }

    }
    
  }

  return;

}

template <typename T , int NUM> inline void ShapedMatrix<T,NUM>::SetZero( T zero ) noexcept { Constants::g_zero = move( zero ); }
template <typename T , int NUM> inline int ShapedMatrix<T,NUM>::size() noexcept { return Constants::g_mult.size(); }

template <typename T , int NUM> inline ShapedMatrix<T,NUM>& ShapedMatrix<T,NUM>::operator+=( const ShapedMatrix<T,NUM>& mat ) { for( int y = 0 ; y < Constants::g_Y ; y++ ){ const int X = Constants::g_d[y]; for( int x = 0 ; x < X ; x++ ){ m_M[y][x] += mat.m_M[y][x]; } } return *this; }

template <typename T , int NUM> inline ShapedMatrix<T,NUM>& ShapedMatrix<T,NUM>::operator-=( const ShapedMatrix<T,NUM>& mat ) { for( int y = 0 ; y < Constants::g_Y ; y++ ){ const int X = Constants::g_d[y]; for( int x = 0 ; x < X ; x++ ){ m_M[y][x] -= mat.m_M[y][x]; } } return *this; }

template <typename T , int NUM> inline ShapedMatrix<T,NUM>& ShapedMatrix<T,NUM>::operator*=( const T& scalar ) noexcept { for( int y = 0 ; y < Constants::g_Y ; y++ ){ const int X = Constants::g_d[y]; for( int x = 0 ; x < X ; x++ ){ m_M[y][x] *= scalar; } } return *this; }

template <typename T , int NUM> inline ShapedMatrix<T,NUM>& ShapedMatrix<T,NUM>::operator*=( const ShapedMatrix<T,NUM>& mat ) { return operator=( move( *this * mat ) ); }

template <typename T , int NUM> inline ShapedMatrix<T,NUM>& ShapedMatrix<T,NUM>::operator/=( const T& scalar ) { return operator*=( T( 1 ) / scalar ); }

template <typename T , int NUM> inline ShapedMatrix<T,NUM>& ShapedMatrix<T,NUM>::operator%=( const T& scalar ) { for( int y = 0 ; y < Constants::g_Y ; y++ ){ const int X = Constants::g_d[y]; for( int x = 0 ; x < X ; x++ ){ m_M[y][x] %= scalar; } } return *this; }

template <typename T , int NUM> template <typename INT> inline ShapedMatrix<T,NUM>& ShapedMatrix<T,NUM>::operator^=( INT exponent ) { return *this = Power( move( *this ) , move( exponent ) , ShapedMatrix<T,NUM>( 1 ) ); }

template <typename T , int NUM> inline ShapedMatrix<T,NUM> ShapedMatrix<T,NUM>::operator+( const ShapedMatrix<T,NUM>& mat ) const { return move( ShapedMatrix<T,NUM>( *this ) += mat ); }
template <typename T , int NUM> inline ShapedMatrix<T,NUM> ShapedMatrix<T,NUM>::operator-( const ShapedMatrix<T,NUM>& mat ) const { return move( ShapedMatrix<T,NUM>( *this ) -= mat ); }
template <typename T , int NUM> inline ShapedMatrix<T,NUM> ShapedMatrix<T,NUM>::operator*( const T& scalar ) const noexcept { return move( ShapedMatrix<T,NUM>( *this ) *= scalar ); }

template <typename T , int NUM>
ShapedMatrix<T,NUM> ShapedMatrix<T,NUM>::operator*( const ShapedMatrix<T,NUM>& mat ) const
{

  ShapedMatrix<T,NUM> answer{};

  for( auto& [y,x,z] : Constants::g_mult ){

    answer.m_M[y][z-Constants::g_l[y]] += m_M[y][x-Constants::g_l[y]] * mat.m_M[x][z-Constants::g_l[x]];

  }
  // for( int y = 0 ; y < Constants::g_Y ; y++ ){

  //   const int x0 = Constants::g_l[y] , X = Constants::g_d[y];

  //   for( int x = x0 ; x <= Constants::g_r[y] ; x++ ){

  //     for( int z = 0 ; z < X ; z++ ){

  //       answer.m_M[y][z] += m_M[y][x - x0] * mat( x , z + x0 );

  //     }

  //   }

  // }

  return answer;

}

template <typename T , int NUM> inline ShapedMatrix<T,NUM> ShapedMatrix<T,NUM>::operator/( const T& scalar ) const { return move( ShapedMatrix<T,NUM>( *this ) /= scalar ); }
template <typename T , int NUM> inline ShapedMatrix<T,NUM> ShapedMatrix<T,NUM>::operator%( const T& scalar ) const { return move( ShapedMatrix<T,NUM>( *this ) %= scalar ); }
template <typename T , int NUM> template <typename INT> inline ShapedMatrix<T,NUM> ShapedMatrix<T,NUM>::operator^( INT exponent ) const { return move( ShapedMatrix<T,NUM>( *this ) %= move( exponent ) ); }

template <typename T , int NUM> inline const T& ShapedMatrix<T,NUM>::operator()( const int& y , const int& x ) const { assert( 0 <= y && y < Constants::g_Y && 0 <= x ); return Constants::g_l[y] <= x && x <= Constants::g_r[y] ? m_M[y][x - Constants::g_l[y]] : Constants::g_zero; }
template <typename T , int NUM> inline T& ShapedMatrix<T,NUM>::operator()( const int& y , const int& x ) { assert( 0 <= y && y < Constants::g_Y && Constants::g_l[y] <= x && x <= Constants::g_r[y] ); return m_M[y][x - Constants::g_l[y]]; }


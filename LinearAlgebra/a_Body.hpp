// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline Matrix<T>::Matrix( const int& Y , const int& X ) noexcept : m_Y( Y ) , m_X( X ) , m_M( Y , vector<T>( X ) ) {}
template <typename T> inline Vector<T>::Vector( const int& Y ) noexcept : Matrix<T>( Y , 1 ) {}
template <typename T> inline Matrix<T>::Matrix( const int& Y , const int& X , const T& t ) noexcept : Matrix( Y , X ) { const int minXY = min( X , Y ); for( int y = 0 ; y < minXY ; y++ ){ m_M[y][y] = t; }; }

template <typename T> template <typename Arg0 , typename Arg1 , typename... Args> inline Matrix<T>::Matrix( const int& Y , const int& X , Arg0&& t0 , Arg1&& t1 ,  Args&&... args ) noexcept : Matrix( Y , X ) { vector<T> temp = { T( forward<Arg0>( t0 ) ) , T( forward<Arg1>( t1 ) ) , T( forward<Args>( args ) )... }; assert( int( temp.size() ) == X * Y ); int i = 0; for( int y = 0 ; y < Y ; y++ ){ for( int x = 0 ; x < X ; x++ ){ m_M[y][x] = move( temp[i++] ); } } }
template <typename T> template <typename Arg0 , typename Arg1 , typename... Args> inline Vector<T>::Vector( Arg0&& t0 , Arg1&& t1 ,  Args&&... args ) noexcept : Matrix<T>( 2 + sizeof...( args ) , 1 , forward<Arg0>( t0 ) , forward<Arg1>( t1 ) , forward<Args>( args )... ) {}

template <typename T> inline Matrix<T>::Matrix( const Matrix<T>& mat ) noexcept : m_Y() , m_X() , m_M() { *this = mat.m_M; }
template <typename T> inline Vector<T>::Vector( const Matrix<T>& vec ) noexcept : Matrix<T>( vec ) {}
template <typename T> inline Matrix<T>::Matrix( Matrix<T>&& mat ) noexcept : m_Y() , m_X() , m_M() { *this = move( mat.m_M ); }
template <typename T> inline Vector<T>::Vector( Matrix<T>&& vec ) noexcept : Matrix<T>( move( vec ) ) {}

template <typename T> inline Matrix<T>::Matrix( const vector<vector<T>>& mat ) noexcept : m_Y() , m_X() , m_M() { *this = mat; }
template <typename T> inline Vector<T>::Vector( const vector<T>& vec ) noexcept : Matrix<T>() { *this = vec; }
template <typename T> inline Matrix<T>::Matrix( vector<vector<T>>&& mat ) noexcept : m_Y() , m_X() , m_M() { *this = move( mat ); }
template <typename T> inline Vector<T>::Vector( vector<T>&& vec ) noexcept : Matrix<T>() { *this = move( vec ); }

template <typename T> inline Matrix<T>& Matrix<T>::operator=( const Matrix<T>& mat ) noexcept { return *this = mat.m_M; }
template <typename T> inline Vector<T>& Vector<T>::operator=( const Matrix<T>& vec ) noexcept { assert( vec.m_X == 1 ); Matrix<T>& mat = *this; mat = vec; return *this; }
template <typename T> inline Matrix<T>& Matrix<T>::operator=( Matrix<T>&& mat ) noexcept { return *this = move( mat.m_M ); }
template <typename T> inline Vector<T>& Vector<T>::operator=( Matrix<T>&& vec ) noexcept { assert( vec.m_X == 1 ); Matrix<T>& mat = *this; mat = forward<Matrix<T>>( vec ); return *this; }
template <typename T> inline Matrix<T>& Matrix<T>::operator=( vector<vector<T>> mat ) { m_M = move( mat ); m_X = ( m_Y = m_M.size() ) > 0 ? int( m_M[0].size() ) : 0; for( int y = 1 ; y < m_Y ; y++ ){ assert( int( m_M[y].size() ) == m_X ); } return *this; }
template <typename T> inline Vector<T>& Vector<T>::operator=( const vector<T>& vec ) { this->m_M.resize( this->m_Y = vec.size() , vector<T>( this->m_X = 1 ) ); for( int y = 0 ; y < this->m_Y ; y++ ){ this->m_M[y][0] = vec[y]; } return *this; }

template <typename T> inline Matrix<T>& Matrix<T>::operator+=( const Matrix<T>& mat ) { assert( m_X == mat.m_X && m_Y == mat.m_Y ); for( int y = 0 ; y < m_Y ; y++ ){ auto& m_M_y = m_M[y]; auto& mat_y = mat.m_M[y]; for( int x = 0 ; x < m_X ; x++ ){ m_M_y[x] += mat_y[x]; } } return *this; }

template <typename T> inline Matrix<T>& Matrix<T>::operator-=( const Matrix<T>& mat ) { assert( m_X == mat.m_X && m_Y == mat.m_Y ); for( int y = 0 ; y < m_Y ; y++ ){ auto& m_M_y = m_M[y]; auto& mat_y = mat.m_M[y]; for( int x = 0 ; x < m_X ; x++ ){ m_M_y[x] -= mat_y[x]; } } return *this; }

template <typename T> inline Matrix<T>& Matrix<T>::operator*=( const T& scalar ) noexcept { for( int y = 0 ; y < m_Y ; y++ ){ auto& m_M_y = m_M[y]; for( int x = 0 ; x < m_X ; x++ ){ m_M_y[x] *= scalar; } } return *this; }

template <typename T> inline Matrix<T>& Matrix<T>::operator*=( const Matrix<T>& mat ) { return operator=( move( *this * mat ) ); }

template <typename T> inline Matrix<T>& Matrix<T>::operator/=( const T& scalar ) { return operator*=( T( 1 ) / scalar ); }

template <typename T> inline Matrix<T>& Matrix<T>::operator%=( const T& scalar ) { for( int y = 0 ; y < m_Y ; y++ ){ auto& m_M_y = m_M[y]; for( int x = 0 ; x < m_X ; x++ ){ m_M_y[x] %= scalar; } } return *this; }

template <typename T> template <typename INT> inline Matrix<T>& Matrix<T>::operator^=( INT exponent ) { assert( m_X == m_Y && exponent >= 0 ); Matrix<T> power{ m_X , m_Y , 1 }; while( exponent > 0 ){ ( exponent& 1 ) == 1 ? power *= *this : power; *this *= *this; exponent >>= 1; } return *this = move( power ); }

template <typename T> inline bool Matrix<T>::operator==( const Matrix<T>& mat ) const noexcept { if( m_X != mat.m_X || m_Y != mat.m_Y ){ return false; } for( int y = 0 ; y < m_Y ; y++ ){ auto& m_M_y = m_M[y]; auto& mat_y = mat[y]; for( int x = 0 ; x < m_X ; x++ ){ if( m_M_y[x] != mat_y[x] ){ return false; } } } return true; }
template <typename T> inline bool Matrix<T>::operator!=( const Matrix<T>& mat ) const noexcept { return !( *this == mat ); }

template <typename T> inline Matrix<T> Matrix<T>::operator+( const Matrix<T>& mat ) const { return move( Matrix<T>( *this ) += mat ); }
template <typename T> inline Matrix<T> Matrix<T>::operator-( const Matrix<T>& mat ) const { return move( Matrix<T>( *this ) -= mat ); }
template <typename T> inline Matrix<T> Matrix<T>::operator*( const T& scalar ) const noexcept { return move( Matrix<T>( *this ) *= scalar ); }
template <typename T> inline Matrix<T> Matrix<T>::operator*( const Matrix<T>& mat ) const { assert( m_X == mat.m_Y ); Matrix<T> prod{ m_Y , mat.m_X }; for( int y = 0 ; y < m_Y ; y++ ){ auto& m_M_y = m_M[y]; auto& prod_y = prod.m_M[y]; for( int x = 0 ; x < m_X ; x++ ){ auto& m_M_yx = m_M_y[x]; auto& mat_x = mat.m_M[x]; for( int z = 0 ; z < mat.m_X ; z++ ){ prod_y[z] += m_M_yx * mat_x[z]; } } } return prod; }
template <typename T> inline Matrix<T> Matrix<T>::operator/( const T& scalar ) const { return move( Matrix<T>( *this ) /= scalar ); }
template <typename T> inline Matrix<T> Matrix<T>::operator%( const T& scalar ) const { return move( Matrix<T>( *this ) %= scalar ); }
template <typename T> template <typename INT> inline Matrix<T> Matrix<T>::operator^( INT exponent ) const { return move( Matrix<T>( *this ) %= move( exponent ) ); }

template <typename T> inline Matrix<T> Matrix<T>::Transpose() const noexcept { Matrix<T> M_t{ m_Y , m_X }; for( int x = 0 ; x < m_X ; x++ ){ auto& M_t_x = M_t.m_M[x]; for( int y = 0 ; y < m_Y ; y++ ){ M_t_x[y] = m_M[y][x]; } } return M_t; }

template <typename T> inline T Matrix<T>::Trace() const noexcept { constexpr const int minXY = min( m_X , m_Y ); T answer{}; for( int y = 0 ; y < minXY ; y++ ){ answer += m_M[y][y]; } return answer; }

template <typename T> inline const int& Matrix<T>::GetCodomainDimension() const noexcept { return m_Y; }
template <typename T> inline const int& Matrix<T>::GetDomainDimension() const noexcept { return m_X; }
template <typename T> inline const vector<vector<T>>& Matrix<T>::GetEntry() const noexcept { return m_M; }

template <typename T> inline const vector<T>& Matrix<T>::operator[]( const int& y ) const { assert( 0 <= y && y < m_Y ); return m_M[y]; }
template <typename T> inline const T& Vector<T>::operator[]( const int& y ) const { assert( 0 <= y && y < this->m_Y ); return this->m_M[y][0]; }
template <typename T> inline vector<T>& Matrix<T>::operator[]( const int& y ) { assert( 0 <= y && y < m_Y ); return m_M[y]; }
template <typename T> inline T& Vector<T>::operator[]( const int& y ) { assert( 0 <= y && y < this->m_Y ); return this->m_M[y][0]; }

template <typename T> inline Matrix<T> operator*( const T& scalar , const Matrix<T>& mat ) noexcept { return mat * scalar; }

template <typename T , typename INT> inline Matrix<T> Power( Matrix<T> mat , INT exponent ) { return move( mat ^= move( exponent ) ); }

template <typename T , typename INT> inline Matrix<T> Act( Matrix<T> mat , INT exponent , Matrix<T> v ) { assert( exponent >= 0 ); while( exponent > 0 ){ ( exponent & 1 ) == 0 ? v : v = mat * v; mat *= mat; exponent >>= 1; } return move( v ); }
template <typename T , typename INT> inline Matrix<T> Act( Matrix<T> mat , INT exponent , const vector<T>& v ) { return Act( move( mat ) , move( exponent ) , Vector<T>( v ) ); }

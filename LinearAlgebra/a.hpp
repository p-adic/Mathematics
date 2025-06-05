// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/990692 (^=)
// https://yukicoder.me/submissions/1009307 (Act)

template <typename T>
class Matrix
{

protected:
  int m_Y;
  int m_X;
  vector<vector<T>> m_M;

public:
  inline Matrix( const int& Y = 0 , const int& X = 0 ) noexcept;
  // スカラー行列
  inline Matrix( const int& Y , const int& X , const T& t ) noexcept;
  template <typename Arg0 , typename Arg1 , typename... Args> inline Matrix( const int& Y , const int& X , Arg0&& t0 , Arg1&& t1 ,  Args&&... args ) noexcept;

  inline Matrix( const Matrix<T>& mat ) noexcept;
  inline Matrix( Matrix<T>&& mat ) noexcept;

  // {{...},{...},...,{...}}で渡すとambiguousになりうるので、
  // vector<vector<T>>を明示するか{Y,X,...}で渡す。
  inline Matrix( const vector<vector<T>>& mat ) noexcept;
  inline Matrix( vector<vector<T>>&& mat ) noexcept;

  inline Matrix<T>& operator=( const Matrix<T>& mat ) noexcept;
  inline Matrix<T>& operator=( Matrix<T>&& mat ) noexcept;
  inline Matrix<T>& operator=( vector<vector<T>> mat );
  
  inline Matrix<T>& operator+=( const Matrix<T>& mat );
  inline Matrix<T>& operator-=( const Matrix<T>& mat );
  inline Matrix<T>& operator*=( const T& scalar ) noexcept;
  inline Matrix<T>& operator*=( const Matrix<T>& mat );
  inline Matrix<T>& operator/=( const T& scalar );
  inline Matrix<T>& operator%=( const T& scalar );
  template <typename INT> inline Matrix<T>& operator^=( INT exponent );

  inline bool operator==( const Matrix<T>& mat ) const noexcept;
  inline bool operator!=( const Matrix<T>& mat ) const noexcept;

  inline Matrix<T> operator+( const Matrix<T>& mat ) const;
  inline Matrix<T> operator-( const Matrix<T>& mat ) const;
  inline Matrix<T> operator*( const T& scalar ) const noexcept;
  inline Matrix<T> operator*( const Matrix<T>& mat ) const;
  inline Matrix<T> operator/( const T& scalar ) const;
  inline Matrix<T> operator%( const T& scalar ) const;
  template <typename INT> inline Matrix<T> operator^( INT exponent ) const;

  inline Matrix<T> Transpose() const noexcept;
  inline T Trace() const noexcept;
  
  inline const int& GetCodomainDimension() const noexcept;
  inline const int& GetDomainDimension() const noexcept;
  inline const vector<vector<T>>& GetEntry() const noexcept;
  inline vector<vector<T>>& RefEntry() noexcept;
  inline const vector<T>& operator[]( const int& y ) const;
  inline vector<T>& operator[]( const int& y );

};

template <typename T>
class Vector :
  public Matrix<T>
{

public:
  inline Vector( const int& Y = 0 ) noexcept;
  template <typename Arg0 , typename Arg1 , typename... Args> inline Vector( Arg0&& t0 , Arg1&& t1 ,  Args&&... args ) noexcept;

  inline Vector( const Matrix<T>& vec ) noexcept;
  inline Vector( Matrix<T>&& vec ) noexcept;

  // {{...}}で渡すとambiguousになりうるので、vector<T>を明示するか
  // {...}で渡す。
  inline Vector( const vector<T>& vec ) noexcept;
  inline Vector( vector<T>&& vec ) noexcept;

  inline Vector<T>& operator=( const Matrix<T>& vec ) noexcept;
  inline Vector<T>& operator=( Matrix<T>&& vec ) noexcept;
  inline Vector<T>& operator=( const vector<T>& vec );
  
  inline const T& operator[]( const int& y ) const;
  inline T& operator[]( const int& y );

};

template <typename T> inline Matrix<T> operator*( const T& scalar , const Matrix<T>& mat ) noexcept;
template <typename T , typename INT> inline Matrix<T> Power( Matrix<T> mat , INT exponent );
template <typename T , typename INT> inline Matrix<T> Act( Matrix<T> mat , INT exponent , Matrix<T> v );
template <typename T , typename INT> inline Matrix<T> Act( Matrix<T> mat , INT exponent , const vector<T>& v );


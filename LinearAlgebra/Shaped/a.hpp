// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Shaped/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1194127

#include "Constant/a.hpp"

// 上三角行列や下三角行列など、行列環の部分半環を高速化する。

template <typename T , int NUM = 0>
class ShapedMatrix
{

private:
  vector<vector<T>> m_M;

public:
  inline ShapedMatrix() noexcept;
  // スカラー行列
  inline ShapedMatrix( const T& t ) noexcept;
  inline ShapedMatrix( const ShapedMatrix<T,NUM>& mat ) noexcept;
  inline ShapedMatrix( ShapedMatrix<T,NUM>&& mat ) noexcept;

  static void SetShape( vector<int> l , vector<int> r ) noexcept;
  static inline void SetZero( T zero ) noexcept;
  static inline int size() noexcept;
  
  inline ShapedMatrix<T,NUM>& operator=( const ShapedMatrix<T,NUM>& mat ) noexcept = default;
  inline ShapedMatrix<T,NUM>& operator=( ShapedMatrix<T,NUM>&& mat ) noexcept = default;
  
  inline ShapedMatrix<T,NUM>& operator+=( const ShapedMatrix<T,NUM>& mat );
  inline ShapedMatrix<T,NUM>& operator-=( const ShapedMatrix<T,NUM>& mat );
  inline ShapedMatrix<T,NUM>& operator*=( const T& scalar ) noexcept;
  inline ShapedMatrix<T,NUM>& operator*=( const ShapedMatrix<T,NUM>& mat );
  inline ShapedMatrix<T,NUM>& operator/=( const T& scalar );
  inline ShapedMatrix<T,NUM>& operator%=( const T& scalar );
  template <typename INT> inline ShapedMatrix<T,NUM>& operator^=( INT exponent );

  inline ShapedMatrix<T,NUM> operator+( const ShapedMatrix<T,NUM>& mat ) const;
  inline ShapedMatrix<T,NUM> operator-( const ShapedMatrix<T,NUM>& mat ) const;
  inline ShapedMatrix<T,NUM> operator*( const T& scalar ) const noexcept;
  ShapedMatrix<T,NUM> operator*( const ShapedMatrix<T,NUM>& mat ) const;
  inline ShapedMatrix<T,NUM> operator/( const T& scalar ) const;
  inline ShapedMatrix<T,NUM> operator%( const T& scalar ) const;
  template <typename INT> inline ShapedMatrix<T,NUM> operator^( INT exponent ) const;

  inline const T& operator()( const int& y , const int& x ) const;
  inline T& operator()( const int& y , const int& x );

  using Constants = ConstantsForShapedMatrix<T,NUM>;

};

// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Multivariablea.hpp

#pragma once
#include "../../SetTheory/DirectProduct/AffineSpace/a.hpp"
#include <vector>

#include "a_Alias.hpp"

template <typename T , int D> class MultivariablePolynomial;

template <typename T>
class MultivariablePolynomial<T,0>
{
  
private:
  T m_t;
  
public:
  using index = MultivariablePolynomialIndex<0>;

  inline MultivariablePolynomial();
  inline MultivariablePolynomial( const T& c );
  inline MultivariablePolynomial( const MultivariablePolynomial<T,0>& t );
  inline MultivariablePolynomial( const index& I );
  inline MultivariablePolynomial( const index& I , const T& t );

  MultivariablePolynomial<T,0>& operator=( const T& t );
  MultivariablePolynomial<T,0>& operator=( const MultivariablePolynomial<T,0>& t );
  
  template <int E> inline const T& operator()( const MultivariablePolynomialIndex<E>& I ) const;
  template <int E> inline T& operator()( const MultivariablePolynomialIndex<E>& I );
  inline const T& operator[]( const int& i ) const;
  // i == 0の場合しかサポートしない
  inline T& operator[]( const int& i );

  inline MultivariablePolynomial<T,0>& operator+=( const T& t );
  inline MultivariablePolynomial<T,0>& operator+=( const MultivariablePolynomial<T,0>& t );
  inline MultivariablePolynomial<T,0>& operator-=( const T& t );
  inline MultivariablePolynomial<T,0>& operator-=( const MultivariablePolynomial<T,0>& t );
  inline MultivariablePolynomial<T,0>& operator*=( const T& t );
  inline MultivariablePolynomial<T,0>& operator*=( const MultivariablePolynomial<T,0>& t );
  inline MultivariablePolynomial<T,0>& operator/=( const T& t );
  inline MultivariablePolynomial<T,0>& operator/=( const MultivariablePolynomial<T,0>& t );
  inline MultivariablePolynomial<T,0>& operator%=( const T& t );
  inline MultivariablePolynomial<T,0>& operator%=( const MultivariablePolynomial<T,0>& t );
  
  inline const int& size() const noexcept;
  
  inline void RemoveRedundantZero() const noexcept;
  inline void RecursivelyRemoveRedundantZero() const noexcept;

  inline string Display() const noexcept;

  static inline const MultivariablePolynomial<T,0>& zero();
  static inline const T& const_zero();
  static inline const T& const_one();
  
};

template <typename T , int D>
class MultivariablePolynomial
{

private:
  vector<MultivariablePolynomial<T,D-1> > m_f;
  // m_fのsize
  int m_size;
  bool m_no_redundant_zero;
    
public:
  using index = MultivariablePolynomialIndex<D>;

  inline MultivariablePolynomial();
  inline MultivariablePolynomial( const T& t );
  // E <= Dの場合のみサポート
  template <int E> inline MultivariablePolynomial( const MultivariablePolynomial<T,E>& f );
  inline MultivariablePolynomial( const MultivariablePolynomial<T,D>& f );
  inline MultivariablePolynomial( const index& I , const T& t = MultivariablePolynomial<T,0>::const_one() );

  MultivariablePolynomial<T,D>& operator=( const T& t );
    // E <= Dの場合のみサポート
  template <int E> MultivariablePolynomial<T,D>& operator=( const MultivariablePolynomial<T,E>& f );
  MultivariablePolynomial<T,D>& operator=( const MultivariablePolynomial<T,D>& f );

  template <int E> const T& operator()( const MultivariablePolynomialIndex<E>& I ) const;
  template <int E> T& operator()( const MultivariablePolynomialIndex<E>& I );
  inline const MultivariablePolynomial<T,D-1>& operator[]( const int& i ) const;
  inline MultivariablePolynomial<T,D-1>& operator[]( const int& i );

  // E <= Dの場合のみサポート
  inline MultivariablePolynomial<T,D>& operator+=( const T& t );
  template <int E> inline MultivariablePolynomial<T,D>& operator+=( const MultivariablePolynomial<T,E>& f );
  MultivariablePolynomial<T,D>& operator+=( const MultivariablePolynomial<T,D>& f );
  inline MultivariablePolynomial<T,D>& operator-=( const T& t );
  template <int E> inline MultivariablePolynomial<T,D>& operator-=( const MultivariablePolynomial<T,E>& f );
  MultivariablePolynomial<T,D>& operator-=( const MultivariablePolynomial<T,D>& f );
  MultivariablePolynomial<T,D>& operator*=( const T& t );
  template <int E> inline MultivariablePolynomial<T,D>& operator*=( const MultivariablePolynomial<T,E>& f );
  MultivariablePolynomial<T,D>& operator*=( const MultivariablePolynomial<T,D>& f );
  MultivariablePolynomial<T,D>& operator/=( const T& t );
  MultivariablePolynomial<T,D>& operator%=( const T& t );

  inline const int& size() const noexcept;
    
  void RemoveRedundantZero();
  void RecursivelyRemoveRedundantZero();

  string Display() const noexcept;

  static inline const MultivariablePolynomial<T,D>& zero();

};

template <typename T> inline bool operator==( const MultivariablePolynomial<T,0>& f0 , const T& t1 );
template <typename T> inline bool operator==( const MultivariablePolynomial<T,0>& f0 , const MultivariablePolynomial<T,0>& f1 );
template <typename T , int D>
bool operator==( const MultivariablePolynomial<T,D>& f0 , const T& t1 );
// E <= Dの場合のみサポート
template <typename T , int D , int E>
bool operator==( const MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,E>& f1 );
template <typename T , int D>
bool operator==( const MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,D>& f1 );
template <typename T , int D , typename P> inline bool operator!=( const MultivariablePolynomial<T,D>& f0 , const P& f1 );


template <typename T , int D , typename P> inline MultivariablePolynomial<T,D> operator+( const MultivariablePolynomial<T,D>& f0 , const P& f1 );
template <typename T , int D , typename P> inline MultivariablePolynomial<T,D> operator-( const MultivariablePolynomial<T,D>& f0 , const P& f1 );
template <typename T , int D , typename P> inline MultivariablePolynomial<T,D> operator*( const MultivariablePolynomial<T,D>& f0 , const P& f1 );
template <typename T , int D> inline MultivariablePolynomial<T,D> operator/( const MultivariablePolynomial<T,D>& f0 , const T& t1 );
template <typename T , int D> inline MultivariablePolynomial<T,D> operator%( const MultivariablePolynomial<T,D>& f0 , const T& t1 );

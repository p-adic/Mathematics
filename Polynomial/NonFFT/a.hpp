// c:/Users/user/Documents/Programming/Mathematics/Polynomial/NonFFT/a.hpp

#pragma once
#include "../a_Macro.hpp"

// FFT要素を削除した版。

template <typename T> class FormalPowerSeries;

template <typename T>
class Polynomial
{

  friend class FormalPowerSeries<T>;

protected:
  vector<T> m_f;
  // m_fのsize
  int m_size;
  
public:
  inline Polynomial();
  inline Polynomial( const Polynomial<T>& f );
  inline Polynomial( Polynomial<T>&& f );
  inline Polynomial( vector<T> f );
  inline Polynomial( T t );
  inline Polynomial( const int& i , T t );

  inline Polynomial<T>& operator=( T n );
  inline Polynomial<T>& operator=( Polynomial<T> f );
  inline Polynomial<T>& operator=( vector<T> f );

  // 係数を参照。capacity変更時に不正な参照となるのでこの返り値を参照型の引数に渡す時は注意。
  inline const T& operator[]( const int& i ) const;
  inline T& operator[]( const int& i );

  // 代入
  T operator()( const T& t ) const;

  Polynomial<T>& operator+=( const Polynomial<T>& f );
  Polynomial<T>& operator-=( const Polynomial<T>& f );
  Polynomial<T>& operator*=( Polynomial<T> f );
  // fがReduceされている場合にのみサポート。
  inline Polynomial<T>& operator/=( const Polynomial<T>& f );
  Polynomial<T>& operator/=( const T& t );
  // fがReduceされている場合にのみサポート。
  Polynomial<T>& operator%=( const Polynomial<T>& f );
  Polynomial<T>& operator%=( const T& t );

  bool operator==( const Polynomial<T>& f ) const;
  bool operator==( const T& t ) const;
  template <typename P> inline bool operator!=( const P& f ) const;

  DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( + );
  inline Polynomial<T> operator-() const;
  DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( - );
  DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( * );
  // fがReduceされている場合にのみサポート。
  inline Polynomial<T> operator/( const Polynomial<T>& f ) const;
  inline Polynomial<T> operator/( const T& t ) const;
  // fがReduceされている場合にのみサポート。
  inline Polynomial<T> operator%( const Polynomial<T>& f ) const;
  inline Polynomial<T> operator%( const T& t ) const;

  inline const vector<T>& GetCoefficient() const noexcept;
  inline const int& size() const noexcept;
  inline void resize( const int& deg_plus ) noexcept;
  int Valuation() const noexcept;

  inline void swap( Polynomial<T>& f );
  inline void swap( vector<T>& f );
  
  void Reduce();
  // N_trunc-1次までで打ち切って係数を反転する。
  void Transpose( const int& N_trunc );

  static Polynomial<T> NaiveConvolution( Polynomial<T> f0 , const int& valuation0 , const Polynomial<T>& f1 , const int& valuation1 , const int& N_trunc );
  // f1が0でなくReduceされている場合にのみサポート。
  static Polynomial<T> NaiveQuotient( Polynomial<T> f0 , const Polynomial<T>& f1 );
  static Polynomial<T> NaiveResidue( Polynomial<T> f0 , const Polynomial<T>& f1 );

  static inline const Polynomial<T>& zero();
  static inline const Polynomial<T>& one();
  static inline const Polynomial<T>& x();
  static inline const T& c_zero();
  static inline const T& c_one();
  static inline const T& c_minus_one();

private:
  inline Polynomial<T>& SignInvert();

};

template <typename T> inline Polynomial<T> Differential( const Polynomial<T>& f );
template <typename T> Polynomial<T> Differential( const int& n , const Polynomial<T>& f );

template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Polynomial<T>& f );

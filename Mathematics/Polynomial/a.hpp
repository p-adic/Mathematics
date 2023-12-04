// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a.hpp

// ���ɂ悭�o�O��̂ŁA�X�V������K��verify���邱�ƁI
// verify:
// https://yukicoder.me/submissions/892588
// https://yukicoder.me/submissions/919378
// https://judge.yosupo.jp/submission/175535

#pragma once
#include <vector>

#include "a_Macro.hpp"

template <typename T> class TruncatedPolynomial;

template <typename T> TruncatedPolynomial<T> Differential( const uint& n , const TruncatedPolynomial<T>& f );
template <typename T> TruncatedPolynomial<T> TruncatedDifferential( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );
template <typename T> TruncatedPolynomial<T> TruncatedIntegral( const TruncatedPolynomial<T>& f , const uint& N_output_start );

template <typename T>
class Polynomial
{

  friend class TruncatedPolynomial<T>;
  friend TruncatedPolynomial<T> Differential<T>( const uint& n , const TruncatedPolynomial<T>& f );
  friend TruncatedPolynomial<T> TruncatedDifferential<T>( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );
  friend TruncatedPolynomial<T> TruncatedIntegral<T>( const TruncatedPolynomial<T>& f , const uint& N_output_start );

protected:
  vector<T> m_f;
  // m_f��size
  uint m_size;
  
public:
  inline Polynomial();
  inline Polynomial( const T& t );
  inline Polynomial( T&& t );
  template <SFINAE_FOR_POLYNOMIAL( = nullptr )> inline Polynomial( const Arg& n );
  inline Polynomial( const Polynomial<T>& f );
  inline Polynomial( Polynomial<T>&& f );
  inline Polynomial( const uint& i , const T& t );
  inline Polynomial( const uint& i , T&& t );
  template <SFINAE_FOR_POLYNOMIAL( = nullptr )> inline Polynomial( const uint& i , const Arg& n );
  inline Polynomial( const vector<T>& f );
  inline Polynomial( vector<T>&& f );

  inline Polynomial<T>& operator=( const T& t );
  inline Polynomial<T>& operator=( T&& t );
  template <SFINAE_FOR_POLYNOMIAL( = nullptr )> inline Polynomial<T>& operator=( const Arg& n );
  inline Polynomial<T>& operator=( const Polynomial<T>& f );
  inline Polynomial<T>& operator=( Polynomial<T>&& f );
  inline Polynomial<T>& operator=( const vector<T>& f );
  inline Polynomial<T>& operator=( vector<T>&& f );

  // �W�����Q�ƁBcapacity�ύX���ɕs���ȎQ�ƂƂȂ�̂ł��̕Ԃ�l���Q�ƌ^�̈����ɓn�����͒��ӁB
  inline const T& operator[]( const uint& i ) const;
  inline T& operator[]( const uint& i );

  // ���
  inline T operator()( const T& t ) const;

  Polynomial<T>& operator+=( const Polynomial<T>& f );
  Polynomial<T>& operator-=( const Polynomial<T>& f );
  Polynomial<T>& operator*=( const Polynomial<T>& f );
  Polynomial<T>& operator*=( Polynomial<T>&& f );
  Polynomial<T>& operator/=( const T& t );
  inline Polynomial<T>& operator/=( const Polynomial<T>& f );
  Polynomial<T>& operator%=( const T& t );
  Polynomial<T>& operator%=( const Polynomial<T>& f );

  inline Polynomial<T> operator-() const;

  // X��X+t��shift
  // T�ɂ�����m_size�����̐��������t�ł��鎞�̂݃T�|�[�g
  Polynomial<T>& operator<<=( const T& t );

  inline const vector<T>& GetCoefficient() const noexcept;
  inline const uint& size() const noexcept;

  inline void swap( Polynomial<T>& f );
  inline void swap( vector<T>& f );
  
  void RemoveRedundantZero();

  inline string Display() const noexcept;

  static Polynomial<T> Quotient( const Polynomial<T>& f0 , const Polynomial<T>& f1 );
  static Polynomial<T> Transpose( const Polynomial<T>& f , const uint& f_transpose_size );

  static inline const Polynomial<T>& zero();
  static inline const T& const_zero();
  static inline const T& const_one();
  static inline const T& const_minus_one();

};

template <typename T>
bool operator==( const Polynomial<T>& f0 , const T& t1 );
template <typename T>
bool operator==( const Polynomial<T>& f0 , const Polynomial<T>& f1 );
template <typename T , typename P> inline bool operator!=( const Polynomial<T>& f0 , const P& f1 );

template <typename T , typename P> inline Polynomial<T> operator+( const Polynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline Polynomial<T> operator-( const Polynomial<T>& f );
template <typename T , typename P> inline Polynomial<T> operator-( const Polynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline Polynomial<T> operator*( const Polynomial<T>& f0 , const P& f1 );
template <typename T> inline Polynomial<T> operator/( const Polynomial<T>& f0 , const T& t1 );
template <typename T> inline Polynomial<T> operator/( const Polynomial<T>& f0 , const Polynomial<T>& f1 );
template <typename T , typename P> inline Polynomial<T> operator%( const Polynomial<T>& f0 , const P& f1 );
template <typename T> inline Polynomial<T> operator<<( const Polynomial<T>& f , const T& t );

// �������Ȃǂ̗�̑���𕪊������Ōv�Z���A���̌��ʂ��1�����Ɋi�[���ĎQ�ƕԂ�����B
// V<T>��erase�����K�v������B
template <typename T , template <typename...> typename V>
T& Prod( V<T>& f );

template <typename T> inline Polynomial<T> Differential( const Polynomial<T>& f );

template <typename T> Polynomial<T> Differential( const uint& n , const Polynomial<T>& f );

// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a.hpp

#pragma once
#include <vector>

#include "a_Macro.hpp"

template <typename T> class TruncatedPolynomial;

template <typename T>
class Polynomial
{

  friend class TruncatedPolynomial<T>;

protected:
  vector<T> m_f;
  // m_f��size
  uint m_size;
  
public:
  inline Polynomial();
  inline Polynomial( const T& t );
  inline Polynomial( const Polynomial<T>& f );
  inline Polynomial( Polynomial<T>&& f );
  inline Polynomial( const uint& i , const T& t );
  inline Polynomial( vector<T>&& f );

  Polynomial<T>& operator=( const T& t );
  Polynomial<T>& operator=( const Polynomial<T>& f );
  Polynomial<T>& operator=( Polynomial<T>&& f );

  // �W��
  inline const T& operator[]( const uint& i ) const;
  inline T& operator[]( const uint& i );

  // ���
  inline T operator()( const T& t ) const;

  inline Polynomial<T>& operator+=( const T& t );
  Polynomial<T>& operator+=( const Polynomial<T>& f );
  inline Polynomial<T>& operator-=( const T& t );
  Polynomial<T>& operator-=( const Polynomial<T>& f );
  Polynomial<T>& operator*=( const T& t );
  Polynomial<T>& operator*=( const Polynomial<T>& f );
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
  static Polynomial<T> TransposeQuotient( const Polynomial<T>& f0 , const uint& f0_transpose_size , const Polynomial<T>& f1_transpose_inverse , const uint& f1_size );
  static Polynomial<T> Transpose( const Polynomial<T>& f , const uint& f_transpose_size );

  static inline const Polynomial<T>& zero();
  static inline const T& const_zero();
  static inline const T& const_one();
  static inline const T& const_minus_one();
  static inline const T& factorial( const uint& i );
  static inline const T& factorial_inverse( const uint& i );

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
template <typename T , template <typename> typename V>
T& Prod( V<T>& f )

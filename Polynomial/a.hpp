// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a.hpp

#pragma once
#include "a_Macro.hpp"

// include�W�J��:
// Poynomial/a.hpp
// FPS/a.hpp
// FFT/a.hpp
// FFT/a_Body.hpp
// FPS/a_Body.hpp
// Poynomial/a_Body.hpp

// veriy:
// https://atcoder.jp/contests/practice2/submissions/64376018 (��ݍ���)
// https://judge.yosupo.jp/submission/276534 (��ݍ���)
// https://judge.yosupo.jp/submission/276660 (��])
// https://judge.yosupo.jp/submission/276549 (���s�ړ�)
// https://yukicoder.me/submissions/1062292 (�{�X�^���X)
// https://yukicoder.me/submissions/1062302 (mod�t��,����{�X�^���X)
// https://yukicoder.me/submissions/937654 (���_�]��)

template <typename T> class Polynomial;
template <typename T> class FormalPowerSeries;
template <typename T> Polynomial<T> FFTConvolution( Polynomial<T> f0 , Polynomial<T> f1 , const int& N_trunc );
template <typename T> Polynomial<T> FFTQuotient( Polynomial<T> f0 , Polynomial<T> f1 );
template <typename T> Polynomial<T> FFTResidue( Polynomial<T> f0 , const Polynomial<T>& f1 );

template <typename T>
class Polynomial
{

  friend class FormalPowerSeries<T>;
  friend Polynomial<T> FFTConvolution<T>( Polynomial<T> f0 , Polynomial<T> f1 , const int& N_trunc );
  friend Polynomial<T> FFTQuotient<T>( Polynomial<T> f0 , Polynomial<T> f1 );
  friend Polynomial<T> FFTResidue<T>( Polynomial<T> f0 , const Polynomial<T>& f1 );

protected:
  vector<T> m_f;
  // m_f��size
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

  // �W�����Q�ƁBcapacity�ύX���ɕs���ȎQ�ƂƂȂ�̂ł��̕Ԃ�l���Q�ƌ^�̈����ɓn�����͒��ӁB
  inline const T& operator[]( const int& i ) const;
  inline T& operator[]( const int& i );

  // ���
  T operator()( const T& t ) const;

  Polynomial<T>& operator+=( const Polynomial<T>& f );
  Polynomial<T>& operator-=( const Polynomial<T>& f );
  Polynomial<T>& operator*=( Polynomial<T> f );
  // f��Reduce����Ă���ꍇ�ɂ̂݃T�|�[�g�B
  inline Polynomial<T>& operator/=( const Polynomial<T>& f );
  Polynomial<T>& operator/=( const T& t );
  // f��Reduce����Ă���ꍇ�ɂ̂݃T�|�[�g�B
  Polynomial<T>& operator%=( const Polynomial<T>& f );
  Polynomial<T>& operator%=( const T& t );

  bool operator==( const Polynomial<T>& f ) const;
  bool operator==( const T& t ) const;
  template <typename P> inline bool operator!=( const P& f ) const;

  DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( + );
  inline Polynomial<T> operator-() const;
  DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( - );
  DECLARATION_OF_ARITHMETIC_FOR_POLYNOMIAL( * );
  // f��Reduce����Ă���ꍇ�ɂ̂݃T�|�[�g�B
  inline Polynomial<T> operator/( const Polynomial<T>& f ) const;
  inline Polynomial<T> operator/( const T& t ) const;
  // f��Reduce����Ă���ꍇ�ɂ̂݃T�|�[�g�B
  inline Polynomial<T> operator%( const Polynomial<T>& f ) const;
  inline Polynomial<T> operator%( const T& t ) const;

  inline const vector<T>& GetCoefficient() const noexcept;
  inline const int& size() const noexcept;
  inline void resize( const int& deg_plus ) noexcept;
  int Valuation() const noexcept;

  inline void swap( Polynomial<T>& f );
  inline void swap( vector<T>& f );
  
  void Reduce();
  // N_trunc-1���܂łőł��؂��ČW���𔽓]����B
  void Transpose( const int& N_trunc );

  static Polynomial<T> NaiveConvolution( Polynomial<T> f0 , const int& valuation0 , const Polynomial<T>& f1 , const int& valuation1 , const int& N_trunc );
  // f1��0�łȂ�Reduce����Ă���ꍇ�ɂ̂݃T�|�[�g�B
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

template <typename T> Polynomial<T> Differential( const int& n , const Polynomial<T>& f );

// Power��Sum/a_Body.hpp�Œ�`�B

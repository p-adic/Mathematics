// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a.hpp

#pragma once
#include "../a.hpp"

template <typename T>
class TruncatedPolynomial :
  public Polynomial<T>
{

private:
  // m_N == 0�ł��������A���̏ꍇ��m_size == 1�̎���m_size <= m_N�����藧���Ȃ��Ȃ邱�Ƃɒ���
  uint m_N;
  
public:
  inline TruncatedPolynomial( const uint& N = 0 );
  inline TruncatedPolynomial( const TruncatedPolynomial<T>& f );
  inline TruncatedPolynomial( const uint& N , const T& t );
  TruncatedPolynomial( const uint& N , const Polynomial<T>& f );
  inline TruncatedPolynomial( const uint& N , const uint& i , const T& t );

  // m_N���������邱�Ƃɒ���
  inline TruncatedPolynomial<T>& operator=( const TruncatedPolynomial<T>& f );
  inline TruncatedPolynomial<T>& operator=( const T& t );
  inline TruncatedPolynomial<T>& operator=( const Polynomial<T>& f );

  // m_N�͕ω����Ȃ����Ƃɒ���
  inline TruncatedPolynomial<T>& operator+=( const T& t );
  TruncatedPolynomial<T>& operator+=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator-=( const T& t );
  TruncatedPolynomial<T>& operator-=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator*=( const T& t );
  TruncatedPolynomial<T>& operator*=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator/=( const T& t );
  inline TruncatedPolynomial<T>& operator%=( const T& t );

  inline void SetTruncation( const uint& N ) noexcept;
  inline const uint& GetTruncation() const noexcept;

private:
  inline void Truncate();

};

// T���W��0�܂���f.m_N�ȏ�̑̂ł���f[0] == 0�̏ꍇ�̂݃T�|�[�g
template <typename T>
TruncatedPolynomial<T> Exp( const TruncatedPolynomial<T>& f );

// T���W��0�܂���f.m_N�ȏ�̑̂ł���f[0] == 1�̏ꍇ�̂݃T�|�[�g
template <typename T> inline TruncatedPolynomial<T> Log( const TruncatedPolynomial<T>& f );
// T���W��0�܂���f.m_N�ȏ�̑̂ł���f[0] == 0�̏ꍇ�̂݃T�|�[�g
template <typename T>
TruncatedPolynomial<T> ShiftedLog( const TruncatedPolynomial<T>& f );

// T���W��0�܂���f.m_N�ȏ�̑̂ł���f[0] == 1�̏ꍇ�̂݃T�|�[�g
template <typename T>
TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const T& t );


// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a.hpp

#pragma once

template <typename INT>
class QuotientRing
{

protected:
  INT m_n;
  const INT* m_p_M;

public:
  inline QuotientRing() noexcept;
  inline QuotientRing( const INT& n , const INT* const& p_M = nullptr ) noexcept;
  inline QuotientRing( const QuotientRing<INT>& n ) noexcept;

  inline QuotientRing<INT>& operator+=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator+=( const INT& n ) noexcept;
  // operator<����`����Ă��Ă����̐��͐��ɒ�������]����邱�Ƃɒ��ӁB
  inline QuotientRing<INT>& operator-=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator-=( const INT& n ) noexcept;
  inline QuotientRing<INT>& operator*=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator*=( const INT& n ) noexcept;
  // *m_p_M���f���ł���n�̋t�������݂���ꍇ�̂݃T�|�[�g�B
  inline QuotientRing<INT>& operator/=( const QuotientRing<INT>& n );
  inline QuotientRing<INT>& operator/=( const INT& n );

  // m_n�̐�����m_p_M�̈�v���݂̓����B
  inline bool operator==( const QuotientRing<INT>& n ) const noexcept;
  inline bool operator!=( const QuotientRing<INT>& n ) const noexcept;

  template <typename T> inline QuotientRing<INT> operator+( const T& n1 ) const noexcept;
  inline QuotientRing<INT> operator-() const noexcept;
  template <typename T> inline QuotientRing<INT> operator-( const T& n1 ) const noexcept;
  template <typename T> inline QuotientRing<INT> operator*( const T& n1 ) const noexcept;
  // *m_p_M���f���ł���n1�̋t�������݂���ꍇ�̂݃T�|�[�g�B
  template <typename T> inline QuotientRing<INT> operator/( const T& n1 ) const;

  inline const INT& Represent() const noexcept;
  inline const INT& GetModulo() const noexcept;
  inline void SetModulo( const INT* const& p_M = nullptr ) noexcept;

  template <typename T> static QuotientRing<INT> Power( const QuotientRing<INT>& n , T exponent );
  // *m_p_M���f���ł���n�̋t�������݂���ꍇ�̂݃T�|�[�g�B
  static QuotientRing<INT> Inverse( const QuotientRing<INT>& n );
  
};

template <typename INT , typename T> inline QuotientRing<INT> Power( const QuotientRing<INT>& n , T exponent );
// *(n.m_p_M)���f���ł���n�̋t�������݂���ꍇ�̂݃T�|�[�g�B
template <typename INT> inline QuotientRing<INT> Inverse( const QuotientRing<INT>& n );

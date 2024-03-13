// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/939377

// �C���X�^���X���ƂɈقȂ�@���߂����ꍇ��
// MultiBase/a.hpp
// �̃N���X��p����B
template <typename INT>
class QuotientRing
{

protected:
  INT m_n;
  static const INT* g_p_M;

public:
  inline QuotientRing() noexcept;
  inline QuotientRing( const INT& n ) noexcept;
  inline QuotientRing( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing( QuotientRing<INT>&& n ) noexcept;

  inline QuotientRing<INT>& operator=( QuotientRing<INT> n ) noexcept;
  inline QuotientRing<INT>& operator+=( const QuotientRing<INT>& n ) noexcept;
  // operator<����`����Ă��Ă����̐��͐��ɒ�������]����邱�Ƃɒ��ӁB
  inline QuotientRing<INT>& operator-=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator*=( const QuotientRing<INT>& n ) noexcept;
  // *g_p_M���f���ł���n�̋t�������݂���ꍇ�̂݃T�|�[�g�B
  inline QuotientRing<INT>& operator/=( QuotientRing<INT> n );

  // m_n�̐������݂̓����B
  inline bool operator==( const QuotientRing<INT>& n ) const noexcept;
  // m_n�̐������݂̓����B
  inline bool operator!=( const QuotientRing<INT>& n ) const noexcept;

  inline QuotientRing<INT> operator+( QuotientRing<INT> n1 ) const noexcept;
  inline QuotientRing<INT> operator-() const noexcept;
  inline QuotientRing<INT> operator-( QuotientRing<INT> n1 ) const noexcept;
  inline QuotientRing<INT> operator*( QuotientRing<INT> n1 ) const noexcept;
  // *g_p_M���f���ł���n1�̋t�������݂���ꍇ�̂݃T�|�[�g�B
  inline QuotientRing<INT> operator/( const QuotientRing<INT>& n1 ) const;
  template <typename T> QuotientRing<INT> operator^( T exponent );

  inline const INT& Represent() const noexcept;
  static inline const INT& GetModulo() noexcept;
  static inline void SetModulo( const INT* const& p_M ) noexcept;

  // *g_p_M���f���ł���n�̋t�������݂���ꍇ�̂݃T�|�[�g�B
  static QuotientRing<INT> Inverse( const QuotientRing<INT>& n );
  
};

template <typename INT , typename T> inline QuotientRing<INT> Power( const QuotientRing<INT>& n , T exponent );
// *g_p_M���f���ł���n�̋t�������݂���ꍇ�̂݃T�|�[�g�B
template <typename INT> inline QuotientRing<INT> Inverse( const QuotientRing<INT>& n );

template <typename INT , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , QuotientRing<INT>& n );
template <typename INT , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const QuotientRing<INT>& n );

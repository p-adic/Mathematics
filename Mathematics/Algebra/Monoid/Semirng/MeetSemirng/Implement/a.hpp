// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/MeetSemirng/Implement/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/964836

template <typename U> class Trop;

template <typename U>
class ZeroForTrop
{

  friend class Trop<U>;
  
private:
  ZeroForTrop() = delete;
  static U g_zero;

};

// ���͈͓͂̔��ŗv��
// (1) U��operator+=�Ɋւ��đS�������Q�ł���B
// (2) g_zero���ŏ����ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// U��operator+=��operaror<�Ɋւ����P�ʓIMax�g���s�J�����ɑ�������^�𓾂�B
// �s����g���ꍇ�Ȃ�AbsractTropicalSemrng�ł�筂���������Ȃ��ꍇ�ɗp����B
template <typename U = ll>
class Trop
{

private:
  U m_n;

public:
  inline Trop( const U& n = ZeroForTrop<U>::g_zero );

  inline Trop<U>& operator+=( const Trop<U>& n );
  inline Trop<U>& operator*=( const Trop<U>& n );
  inline Trop<U> operator+( const Trop<U>& n ) const;
  inline Trop<U> operator*( const Trop<U>& n ) const;

  inline void Set( const U& n ) noexcept;
  inline const U& Get() const noexcept;

  static inline void SetZero( const U& zero ) noexcept;;
  
};

template <class Traits , typename U> inline basic_istream<char,Traits>& operator>>( basic_ostream<char,Traits>& is , const Trop<U>& n ) noexcept;
template <class Traits , typename U> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Trop<U>& n ) noexcept;

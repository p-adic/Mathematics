// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticExtension/a.hpp

#pragma once

template <typename INT>
class QuadraticExtension
{

private:
  INT m_a;
  INT m_b;
  const INT* m_p_D;

public:
  inline QuadraticExtension( const INT& a = 0 , const INT& b = 0 , const INT* const & p_D = nullptr ) noexcept;
  inline QuadraticExtension( const QuadraticExtension& n ) noexcept;

  inline const INT& GetA() const noexcept;
  inline const INT& GetB() const noexcept;
  inline const INT& GetD() const noexcept;

  inline QuadraticExtension& operator+=( const QuadraticExtension& n ) noexcept;
  inline QuadraticExtension& operator-=( const QuadraticExtension& n ) noexcept;

  // 3���̏�@������̂ŃI�[�o�[�t���[�ɒ���
  // 10^6���傫��mod�Ōv�Z���鎞��INT��Mod<M>�Ȃǂ������邩��@�̒�`���C������
  inline QuadraticExtension& operator*=( const QuadraticExtension& n ) noexcept;
  template <typename T> inline QuadraticExtension& operator/=( const T& a ) noexcept;
  template <typename T> inline QuadraticExtension& operator%=( const T& a ) noexcept;

  // m_p_D�̈�v���݂̓���
  static inline bool Equal( const QuadraticExtension& n0 , const QuadraticExtension& n1 ) noexcept;
  
};

inline bool operator==( const QuadraticExtension& n0 , const QuadraticExtension& n1 ) noexcept;
inline bool operator!=( const QuadraticExtension& n0 , const QuadraticExtension& n1 ) noexcept;

inline QuadraticExtension operator+( const QuadraticExtension& n0 , const QuadraticExtension& n1 ) noexcept;
inline QuadraticExtension operator-( const QuadraticExtension& n0 , const QuadraticExtension& n1 ) noexcept;
inline QuadraticExtension operator*( const QuadraticExtension& n0 , const QuadraticExtension& n1 ) noexcept;
template <typename T> inline QuadraticExtension operator/( const QuadraticExtension& n , const T& a ) noexcept;
template <typename T> inline QuadraticExtension operator%( const QuadraticExtension& n , const T& a ) noexcept;

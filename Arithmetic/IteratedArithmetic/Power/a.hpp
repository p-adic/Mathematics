// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/IteratedArithmetic/Power/a.hpp

#pragma once

// base��㰏������������B
template <typename INT>
class PowerMemoriser
{

private:
  INT m_base;
  vector<INT> m_val;

public:
  inline PowerMemoriser( const INT& base = 0 );
  inline INT operator[]( const int& exponent ) noexcept;

};

// ���������Ȃ��J��Ԃ����@��
// ../IteratedArithmetic/
// �Ɏ����B

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/\a.hpp

#pragma once

// base��㰏������������B
template <typename INT>
class PowerMemoriser
{

private:
  vector<INT> m_base;
  vector<vector<INT>> m_val;

public:
  template <typename VEC> inline PowerMemoriser( const VEC& base );
  inline INT Get( const int& i , const int& j ) noexcept;

};

// ���������Ȃ��J��Ԃ����@��
// ../IteratedArithmetic/
// �Ɏ����B

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/Inverse/a.hpp

#pragma once

// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144

// N�ȏ�ł���ŏ���2㰂��R���p�C�����v�Z����B
template <int N>
class PowerInverse_constexpr
{
public:
  int m_val;
  inline constexpr PowerInverse_constexpr();
};

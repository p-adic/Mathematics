// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/PowerPower/a.hpp

#pragma once

template <typename T , int exponent_lim>
class PowerPower_constexpr
{
private:
// t^{2^i}��m_val[i]�Ɋi�[�B
  T m_val[exponent_lim];

public:
  inline constexpr PowerPower_constexpr( const T& t );

  inline constexpr const T& operator[]( const int& i ) const;
  inline constexpr const T ( &Get() const )[exponent_lim];
  
};

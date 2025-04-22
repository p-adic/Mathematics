// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Iteration/Constexpr/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942426

template <typename T , int exponent_lim>
class Power_constexpr
{
private:
  T m_val[exponent_lim];

public:
  inline constexpr Power_constexpr( const T& t , const T& init = T( 1 ) );

  inline constexpr const T& operator[]( const int& i ) const;
  inline constexpr const T ( &Get() const )[exponent_lim];
  
};

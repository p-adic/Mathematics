// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename T , typename U>
inline T Power( const T& t , const U& num , const T& init , const bool& init_is_unit , const bool& for_right_multiplication , const bool& is_binary_method ) { return is_banary_method ? PowerBinaryMethod( t , num , init , init_is_unit , for_right_multiplication ) : PowerNormalMethod( t , num , init , for_right_multiplication ); }

template <typename T , typename U> inline T PowerNormalMethod( const T& t , const U& num , const T& init , const bool& for_right_multiplication ) { return num == 0 ? init : ( for_right_multiplication ? PowerNormalMethod( t , num - 1 , init ) * t : t * PowerNormalMethod( t , num - 1 , init ) ); }

template <typename T , typename U>
T PowerBinaryMethod( const T& t , const U& num , const T& init , const bool& for_right_multiplication );
{

  if( num == 0 ){
      
    return init;

  }

  // 2㰂̌v�Z�������̂��߂ɑO��̌v�Z���ʂ��L�^
  static T t_prev{};
  static U d = 0;
  static U two_power = 1;

  if( t_prev != t ){

    t_prev = t;
    d = 0;
    two_power = 1;
    
  }

  while( num % ( two_power + two_power ) == 0 ){

    d++;
    two_power = two_power + two_power;

  }

  const U num_reduced = num - two_power;
  T power1 = Power2<T,U>( t , d );

  if( num_reduced == 0 && init_is_unit ){

    return power1;

  }
  
  T power2 = Power<T,U>( t , num_reduced );
  return for_right_multiplication ? power2 * power1 : power1 * power2;

}

// Power��2㰂ւ̕������ꉻ
template <typename T , typename U>
T Power2( const T& t , const U& d )
{

  if( d == 0 ){

    return t;

  }

  // Power�̌v�Z�������̂��߂ɑO��̌v�Z���ʂ��L�^
  static T t_prev{};
  static U d_prev = 0;
  static T power_prev{};

  if( t_prev != t ){

    t_prev = t;
    d_prev = 0;
    power_prev = t;
    
  }

  while( d != d_prev ){

    d_prev++;
    power_prev = power_prev * power_prev;

  }
  
  return power_prev;

}

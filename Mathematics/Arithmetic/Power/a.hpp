// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a.hpp

#pragma once

// init * ( t ^ num )
template <typename T , typename UINT>
T Power( const T& t , const UINT& num , const T& init = 1 , const bool& init_is_unit = true , const bool& for_right_multiplication = true , const bool& is_binary_method = false );

template <typename T , typename UINT> inline T PowerNormalMethod( const T& t , const UINT& num , const T& init = 1 , const bool& for_right_multiplication = true );
template <typename T , typename UINT>
T PowerBinaryMethod( const T& t , const UINT& num , const T& init = 1 , const bool& init_is_unit = true , const bool& for_right_multiplication = true );

// Power��2㰂ւ̕������ꉻ
template <typename T , typename UINT>
T Power2( const T& t , const UINT& d );



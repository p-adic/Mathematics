// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Padic/a_Body.hpp"

// PowerBinaryMetod�̌Ăяo���͕������ꉻ�ł͂Ȃ��I�[�o�[���[�h�ŏ����ł���悤�ɂ��邽�߂�PowerBinaryMethod<T,UINT>�Ƃ͂��Ȃ��B
template <typename T , typename UINT>
inline T Power( const T& t , const UINT& num , const T& init , const bool& for_right_multiplication , const string& method ) { return method == "binary" ? PowerBinaryMethod( t , num , init , for_right_multiplication ) : PowerNormalMethod( t , num , init , for_right_multiplication ); }

template <typename T , typename UINT> inline T PowerNormalMethod( const T& t , const UINT& num , const T& init , const bool& for_right_multiplication ) { return num == 0 ? init : ( for_right_multiplication ? PowerNormalMethod( t , num - 1 , init ) * t : t * PowerNormalMethod( t , num - 1 , init ) ); }

template <typename T , typename UINT>
T PowerBinaryMethod( const T& t , const UINT& num , const T& init , const bool& for_right_multiplication )
{

  const VLArray<UINT>& num_binary = AdicInt<2>::Expand( num );
  T answer = init;
  T power = t;

  for( auto itr = num_binary.begin() , end = num_binary.end() ; itr != end ; itr++ ){

    if( *itr == 1 ){

      answer = for_right_multiplication ? answer * power : power * answer;

    }

    // �������ꉻ�ł͂Ȃ��I�[�o�[���[�h�ŏ����ł���悤�ɂ��邽�߂�Square<T>�Ƃ��Ȃ��B
    power = Square( power );

  }

  return answer;

}

template <typename T> inline T Square( const T& t ) { return t * t; }

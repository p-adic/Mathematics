// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a.hpp

#pragma once

// init * ( t ^ num )
template <typename T , typename UINT>
T Power( const T& t , const UINT& num , const T& init = 1 , const bool& for_right_multiplication = true , const string& method = "normal" );

template <typename T , typename UINT> inline T PowerNormalMethod( const T& t , const UINT& num , const T& init = 1 , const bool& for_right_multiplication = true );
template <typename T , typename UINT>
T PowerBinaryMethod( const T& t , const UINT& num , const T& init = 1 , const bool& for_right_multiplication = true );

// �P�Ȃ�Q�悾���AT����ł̓I�[�o�[���[�h���Ă�荂���Ȃ��̂ɒu��������
template <typename T> inline T Square( const T& t );

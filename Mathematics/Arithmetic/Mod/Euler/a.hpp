// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Euler/a.hpp

#pragma once

template <typename INT> inline INT EulerFunction( const INT& n );

// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[����B
template <typename INT>
INT EulerFunction( const INT& n , vector<INT>& P , vector<INT>& exponent );

template <typename INT> inline INT CarmichaelFunction( const INT& n );

// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[���A�f�����̎w�����P_power�Ɋi�[����B
template <typename INT>
INT CarmichaelFunction( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );

void CarmichaelTransformation( vector<uint>& exponent );

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Factorisation/a.hpp

#pragma once

// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[����B
template <typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( INT1 n , vector<INT2>& P , vector<INT3>& exponent );
// sqrt( n )�ȉ��̍ő�̑f�� < val_limit �̎��̂݃T�|�[�g�B
template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT1 n , vector<INT2>& P , vector<INT3>& exponent );

// �񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[���A�f�����̎w�����P_power�Ɋi�[����B
template <typename INT1 , typename INT2 , typename INT3 , typename INT4> void SetPrimeFactorisation( INT1 n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power );
// sqrt( n )�ȉ��̍ő�̑f�� < val_limit �̎��̂݃T�|�[�g�B
template <typename INT , INT val_limit , int length_max , typename INT1 , typename INT2 , typename INT3 , typename INT4> void SetPrimeFactorisation( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT1 n , vector<INT2>& P , vector<INT3>& exponent , vector<INT4>& P_power );

// �f���������XN���������Ȃ��񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[����B
template <typename INT1 , typename INT2 , typename INT3 , int N> void SetPrimeFactorisationBounded( INT1 n , INT2 ( &P )[N] , INT3 ( &exponent )[N] );
// �f���������XN���������Ȃ��񕉐���n�̑f������P�Ɋi�[���A�f�����̎w����exponent�Ɋi�[���A�f�����̎w�����P_power�Ɋi�[����B
template <typename INT1 , typename INT2 , typename INT3 , typename INT4 , int N> void SetPrimeFactorisationBounded( INT1 n , INT2 ( &P )[N] , INT3 ( &exponent )[N] , INT4 ( &P_power )[N] );


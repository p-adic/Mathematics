// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/a.hpp

#pragma once
#include "../../../Prime/Constexpr/a.hpp"

// �񕉐���n��{�I�C���[�֐��̒l,�f����,�f�����̎w��}��Ԃ��B�iO(��n)�j
template <typename INT> inline tuple<INT,vector<INT>,vector<int>> EulerFunction( const INT& n );
// n < val_limit��2�� �̎��̂݃T�|�[�g�B�iO(��(��n)+log n)�j
template <typename INT1 , INT1 val_limit , int length_max , typename INT2> inline tuple<INT2,vector<INT1>,vector<int>> EulerFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const INT2& n ;

// n_max <= val_limit��2�� �̎��̂݃T�|�[�g�B�iO(��(��n_max) + n_max log n_max)�j
template <typename INT1 , INT1 val_limit , int length_max , int size , typename INT2> vector<INT2> TotalEulerFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const INT2& n_max )

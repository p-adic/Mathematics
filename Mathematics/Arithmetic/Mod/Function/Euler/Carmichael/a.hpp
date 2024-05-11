// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/Carmichael/a.hpp

#pragma once
#include "../../../../Prime/Constexpr/a.hpp"

// �񕉐���n��{�J�[�}�C�P���֐��̒l,�f����,�f�����̎w��,�f�����̎w����}��Ԃ��B
template <typename INT> inline tuple<INT,vector<INT>,vector<int>,vector<INT>> CarmichaelFunction( const INT& n );
// n < val_limit��2�� �̎��̂݃T�|�[�g�B
template <typename INT1 , INT1 val_limit , int length_max> inline tuple<INT2,vector<INT1>,vector<int>,vector<INT1>> CarmichaelFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const INT2& n );

// �f���������̎w����E�ł���񕉐����ɑ΂��A����Carmichael�֐��̒l�̑f���������̎w����Ԃ��B
template <typename INT> inline vector<INT> CarmichaelTransformation( const vector<INT>& E );
// E.size() <= length_max�ł���ꍇ�ɂ̂݃T�|�[�g�B
template <typename INT1 , INT1 val_limit , int length_max , typename INT2> inline vector<INT2> CarmichaelFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const vector<INT2>& E );

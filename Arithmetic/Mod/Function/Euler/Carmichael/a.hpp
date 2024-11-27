// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/Carmichael/a.hpp

#pragma once
#include "../../../../Prime/Enumeration/a.hpp"

// �񕉐���n��{�J�[�}�C�P���֐��̒l,�f����,�f�����̎w��,�f�����̎w����}��Ԃ��B
// O(��n)
template <typename INT> inline tuple<INT,vector<INT>,vector<int>,vector<INT>> CarmichaelFunction( const INT& n );
// PE��PrimeEnumeration/LeastDivisor�ȂǂŁA
// pe��sqrt( n )�ȉ��̑f��/n�ȉ��̐������̖񐔂��Ǘ����鎞�̂݃T�|�[�g�B
// O(��n/log n)/O((log n)^2)
template <typename PE , typename INT> inline tuple<INT,vector<int>,vector<int>,vector<int>> CarmichaelFunction( const PE& pe , const INT& n );

// �f���������̎w����E�ł���񕉐����ɑ΂��A����Carmichael�֐��̒l�̑f���������̎w����Ԃ��B
template <typename INT> inline vector<INT> CarmichaelTransformation( const vector<INT>& E );
// PE��PrimeEnumeration�ȂǂŁAE.size() <= pe.length()�̎��̂݃T�|�[�g�B
template <typename PE , typename INT> inline vector<INT> CarmichaelTransformation( const PE& pe , const vector<INT>& E );

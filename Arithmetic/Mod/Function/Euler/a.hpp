// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/a.hpp

#pragma once
#include "../../../Prime/Enumeration/a.hpp"

// �񕉐���n��{�I�C���[�֐��̒l,�f����,�f�����̎w��}��Ԃ��B
// O(��n)
template <typename INT> inline tuple<INT,vector<INT>,vector<int>> EulerFunction( const INT& n );
// PE��PrimeEnumeration/LeastDivisor�ȂǂŁA
// pe��sqrt( n )�ȉ��̑f��/n�ȉ��̐������̖񐔂��Ǘ����鎞�̂݃T�|�[�g�B
// O(��n/log n)/O(log n)
template <typename PE , typename INT> inline tuple<INT,vector<int>,vector<int>> EulerFunction( const PE& pe , const INT& n );

// PE��PrimeEnumeration�ȂǂŁApe��sqrt( n_max )�ȉ��̑f�����Ǘ����鎞�̂݃T�|�[�g�B
// O(n_max log n_max)
template <typename PE , typename INT> vector<INT> TotalEulerFunction( const PE& pe , const INT& n_max );
// LD���g���Ė���EulerFunction���v�Z����ꍇ�ƌv�Z�ʂ͓����B

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Factorisation/a.hpp

#pragma once
#include "../Enumeration/SFINAE/a.hpp"

// �񕉐���n��{�f����,�f�����̎w��}��Ԃ��B
// O(��n)
template <typename INT> pair<vector<INT>,vector<int>> PrimeFactorisation( INT n );
// O(��(��n))�A����O(��n/log n)
// PE��PrimeEnumeration�ȂǂŁAsqrt( n )�ȉ��̍ő�̑f����pe�ŊǗ�����Ă��鎞�̂݃T�|�[�g�B
template <typename PE , typename INT> auto PrimeFactorisation( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,pair<vector<INT>,vector<int>>>;
// O(n�̑f�����̎w���̑��a)�A����O(log n)
// LD��LeastDivisor�ȂǂŁAn�ȉ��̐����̍ŏ��̑f������ld�ŊǗ�����Ă��鎞�̂݃T�|�[�g�B
template <typename LD> auto PrimeFactorisation( const LD& ld , int n ) -> enable_if_t<!IsPE<LD>,pair<vector<int>,vector<int>>>;

// �񕉐���n��{�f����,�f�����̎w��,�f�����̎w����}�Ԃ��B
// O(��n)
template <typename INT> tuple<vector<INT>,vector<int>,vector<INT>> PrimePowerFactorisation( INT n );
// O(��(��n))�A����O(��n/log n)
// PE��PrimeEnumeration�ȂǂŁAsqrt( n )�ȉ��̍ő�̑f����pe�ŊǗ�����Ă��鎞�̂݃T�|�[�g�B
template <typename PE , typename INT> auto PrimePowerFactorisation( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,tuple<vector<INT>,vector<int>,vector<INT>>>;
// O(n�̑f�����̎w���̑��a)�A����O(log n)
// LD��LeastDivisor�ȂǂŁAn�ȉ��̐����̍ŏ��̑f������ld�ŊǗ�����Ă��鎞�̂݃T�|�[�g�B
template <typename LD> auto PrimePowerFactorisation( const LD& ld , int n ) -> enable_if_t<!IsPE<LD>,tuple<vector<int>,vector<int>,vector<int>>>;

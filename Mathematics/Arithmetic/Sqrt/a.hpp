// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sqrt/a.hpp

#pragma once
#include "a.hpp"

// ��n�𒴂��Ȃ��ő�̐�����O(log n)�Ōv�Z����B
template <typename INT> INT RoundDownSqrt( const INT& n );
// INT = long long�̏ꍇ��INT(std::sqrt(n))�Ɍ덷���o��P�[�X�F
// (n,RondDownSqrt(n)^2,INT(std::sqrt(n),RondDownSqrt(n),) =
// 57337544294423649 57337544294423649 239452592 239452593
// 229350177177694596 229350177177694596 478905185 478905186
// 3667470396035093041 3667470396035093041 1915064070 1915064071
// 3667470396035093... 3667470396035093041 1915064070 1915064071
// 3667470396035093247 3667470396035093041 1915064070 1915064071

// ��n���ȏ�̍ŏ��̐�����O(log n)�Ōv�Z����B
template <typename INT> INT RoundUpSqrt( const INT& n );

// �f���@�̕�������
// ../Mod/Function/QuadraticResidu/TonelliShanks/
// �Ɏ����B

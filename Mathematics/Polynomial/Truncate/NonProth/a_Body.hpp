// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Truncate/NonProth/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"


// �v���X�f���ȊO�̖@�ŏ�ݍ��݂�FFT�Ōv�Z�������ꍇ�A���̃}�N���Ŋ��S���ꉻ����B
// - 2663300644�ȉ��̖@�ō��X8388607���ȉ��̑������̐ρi���X16777214���j
// - 2^{32}    �����̖@�ō��X6451200���ȉ��̑������̐ρi���X12902400���j
// ���v�Z�\�B��ʂɂ�
// - 0�ȏ�31�ȉ��̐������W���Ɏ����X10^6���̑������̐ς�998244353��@�Ƃ���B
// - 0�ȏ�10^6�ȉ��̐������W���Ɏ����X10^6���̑������̐ς̓K�[�i�[�̃A���S���Y����
//   �Ō�ɖ@�����Ȃ��悤�ɕύX����B
// �ȂǁA���̃}�N�����̂��̂��g��Ȃ����@�������B
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( 1000000007 , Mod );

DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_NON_MOD( ll );
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_NON_MOD( ull );

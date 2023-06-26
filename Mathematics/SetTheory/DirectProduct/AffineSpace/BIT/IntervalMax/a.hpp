// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a.hpp

#pragma once
#include "a_Macro.hpp"

// �ő�i�ŏ��j���ɂ�鏉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(1)
// ���max�imin�j�擾O(log_2 N)

// ��_�X�VO((log_2 N)^2)
// max�imin�j�ɂ���_�X�VO(log_2 N)
// max�imin�j�ɂ���ԍX�VO(i_final-i_start+log_2 N)

// t�ȏ�i�ȉ��j�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 N)

// ���̂����̋��min�擾�ƈ�_�X�V��
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// �̎�@�����ƂɎ���
DECRALATION_OF_INTERVAL_MAX_BIT( Max );
DECRALATION_OF_INTERVAL_MAX_BIT( Min );

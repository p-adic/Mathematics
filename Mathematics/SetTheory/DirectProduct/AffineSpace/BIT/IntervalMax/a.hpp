// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/947876�i��_���Z�^���max�擾�j

// �ő�i�ŏ��j���ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_�擾O(1)
// LSB�ؕЎ擾O(1)�ileft:max(a[j-(j&-j)],...,a[j-1])�Aright:max(a[j-1],...,a[j+(j&-j)-1])�j
// ���max�imin�j�擾O(log_2 size)

// ��_�X�VO((log_2 size)^2)
// max�imin�j�ɂ���_�X�VO(log_2 size)
// max�imin�j�ɂ���ԍX�VO(i_final-i_start+log_2 size)
// max�imin�j�ɂ��S�̍X�VO(size)

// n�ȏ�i�ȉ��j�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
// �i���݂��Ȃ��ꍇ��size�ȏ�̍ŏ���2㰁~2-1��Ԃ��̂ŁAsize�ȏ�ł��邱�ƂŔ���\�j

// ���̂����̋��min�擾�ƈ�_�X�V��
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// �̎�@�����ƂɎ���
DECLARATION_OF_INTERVAL_MAX_BIT( Max );
DECLARATION_OF_INTERVAL_MAX_BIT( Min );

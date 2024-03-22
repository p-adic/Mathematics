// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/GridStampCoveringExpectation/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/963393�iH,W<998244353,X,Y<=1e3,N<=1e9�j
// https://yukicoder.me/submissions/963394�iH,W,X,Y<2e5,N=2�j

// H�~W�̔��F�O���b�h��X�~Y�̗̈����l�����_����N��I�э��F�ɓh��ׂ����̍��F�}�X�̌��̊��Ғl��
// https://yukicoder.me/problems/no/2457/editorial
// �����Ƃ�O(min(XY,N^2)log_2 N)�Ōv�Z�B
template <typename T> inline T GridStampCoveringExpectation( const int& H ,  const int& W ,  const int& X ,  const int& Y , const ull& N );

// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/964722
// https://yukicoder.me/submissions/964718
// https://yukicoder.me/submissions/964721

// �Ⴆ�Β���N�̔񕉐����l�z��A�ŋɑ�Ȑ��l��ԂƂ����ł̑��a���擾�������ꍇ
// auto update_L = [&]( int& i_L , auto& i_info ){ i_info -= A[i_L++]; };
// auto update_R = [&]( int& i_R , auto& i_info ){ if( ++i_R < N ){ i_info += A[i_R]; } };
// TPA( interval , i , 0 , i_R < N , update_L( i_L , i_info ) , update_R( i_R , i_info ) , A[i_L] > 0 && A[i_R] > 0 , ll( A[0] ) );
// �Ƃ����tuple<int,int,ll>�l�z��interval��{���[,�E�[,���a}�̗񂪊i�[�����B

// i_info��interval�ɃR�s�[�����̂ŁAset��vector�Ȃǂ̃R�s�[�̃R�X�g���傫���f�[�^��
// �p����on,off���肷�鎞��TPA���O�ɐ錾���Ďg���B

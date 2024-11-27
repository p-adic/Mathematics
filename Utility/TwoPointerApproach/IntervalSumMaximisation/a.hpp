// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/IntervalSumMaximisation/a.hpp

#pragma once
#include "a_Macro.hpp"

// FUNC�͎ʑ�funct:Z->Z�ɑ�������^�B
// answer[i]��[i_start,i_final]�̒���length_min+i�̘A��������ɂ�����func�̒l�̑��a��
// lim�����̍ő�l����ёΉ������Ԃ̍��[���i�[����B
// - ������������0�̏ꍇ�͍��[��i_start�Ƃ���B
// - ������lim�����̑��a���������񂪑��݂��Ȃ��ꍇ��{exceptional,i_start-1}���i�[����B
// �iO((i_final-i_start+2-length_min)(length_max - length_min+1))�j

// template <typename INT1 , typename INT2 , typename FUNC> vector<pair<INT1,INT2>> IntervalSumMaximisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min = 0 , INT2 length_max = -1 );
DECLARAIION_OF_INTERVAL_SUM_MAX( Max );

// template <typename INT1 , typename INT2 , typename FUNC> vector<pair<INT1,INT2>> IntervalSumMinimisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min = 0 , INT2 length_max = -1 );
DECLARAIION_OF_INTERVAL_SUM_MAX( Min );

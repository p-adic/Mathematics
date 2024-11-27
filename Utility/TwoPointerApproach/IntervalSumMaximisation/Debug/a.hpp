// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/IntervalSumMaximisation/Debug/a.hpp

#pragma once

// �f�o�b�O�p�Ƀ}�N����W�J���ăf�o�b�O�o�͂�ǉ��������́B

template <typename INT1 , typename INT2 , typename FUNC> vector<pair<INT1,INT2>> IntervalSumMaximisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min = 0 , INT2 length_max = -1 );
template <typename INT1 , typename INT2 , typename FUNC> vector<pair<INT1,INT2>> IntervalSumMinimisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min = 0 , INT2 length_max = -1 );

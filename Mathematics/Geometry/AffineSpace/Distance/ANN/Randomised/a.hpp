// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/Randomised/a.hpp

#pragma once
#include "a_Macro.hpp"

// TwoDimensionalAllNearestNeighbourRandomisedDouble�̏d�݂𐮐��͈̔͂ɂ����߂�
// �������]���ł���悤�ɂ��čŋߓ_��S�đI�ׂ�悤�ɂ������́B
// �}���肪�Ȃ��Ȃ邽�ߏ����x���Ȃ�B

// D2��2������ԏ�̏d��d2�ɑ�������^�B

// S�̊e�_s��T�ɂ�����ŋߓ_���q���[���X�e�B�b�N�Ɍv�Z����B
template <typename Dist2 , typename INT> vector<vector<int>> TwoDimensionalAllNearestNeighbourRandomised( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const int& success_count_bound );
template <typename Dist2 , typename INT> vector<vector<int>> TwoDimensionalAllNearestNeighbourRandomised( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const double& time );
// bucket_size��success_count_bound���������}����ꍇ�i�X���Ƀo�C�A�X�����Ȃ��ꍇ�j
// ��T.size()���x�A�傫�߂ɂ���Ȃ�log T.size()���x�B

// ��T.size()���x��log T.size()���x�łQ��v�Z����ΌX���Ƀo�C�A�X������P�[�X�������Ή��\�B

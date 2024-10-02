// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/Randomised/Double/a.hpp

#pragma once
#include "a_Macro.hpp"

// https://ebadian.org/publications/ann.pdf �����ƂɎ����B
// �������X���Ƀo�C�A�X������P�[�X�Ŏ}���肪�ア�̂�bucket_size���w�肷��B

// D��2������ԏ�̏d��d�ł����Ďˉe���k���ʑ��ƂȂ���́i���[�N���b�h�����Ȃǁj�ɑ�������^�B

// S�̊e�_s��T�ɂ�����ŋߓ_�����X�P�q���[���X�e�B�b�N�Ɍv�Z����B
template <typename Dist , typename INT> vector<int> TwoDimensionalAllNearestNeighbourRandomised( const Dist& d , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const int& success_count_bound );
template <typename Dist , typename INT> vector<int> TwoDimensionalAllNearestNeighbourRandomised( const Dist& d , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const double& time );

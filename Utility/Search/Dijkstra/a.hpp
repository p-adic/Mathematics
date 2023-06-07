// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

// ���͈͓͂̔��ŗv��
// (1) d�̒l��0�ȏ�܂���infty�ł���B
// (2) infty��0�ȏ�̐�size_max�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B�i-1�Ȃǂ͕s�K�j
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B
template <int size_max>
int Dijkstra( const map<int,int> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const int& infty );
template <int size_max>
int Dijkstra( const map<int,int> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const int& infty , list<int>& path );

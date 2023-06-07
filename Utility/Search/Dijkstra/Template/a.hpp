// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/Template/a.hpp

#pragma once
#include "../a_Macro.hpp"

// ���͈͓͂̔��ŗv��
// (1) d�̒l��e_T()�ȏ�܂���infty�ł���B
// (2) infty��e_T()�ȏ�̍�size_max�ȉ��̘a�ŕ\���邢���Ȃ鍀�����傫���B
// (3) (T,m_T:T^2->T,e_T:1->T)��bool operator<(const T&,const T&)�Ɋւ��ď������m�C�h�ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const map<int,T> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const T& infty );
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const map<int,T> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const T& infty , list<int>& path );

// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/FloydWarshall/a.hpp

#pragma once

// ���͈͓͂̔��ŗv��
// (1) (T,m_T:T^2->T,e_T:1->T)��bool operator<(const T&,const T&)�Ɋւ��ď������m�C�h�ł���B
// (2) d�̒l��e_T()�ȏ�܂���infty�ł���B
// (3) infty��e_T()�ȏ�̍�size_max�ȉ��̘a�ŕ\���Ȃ��B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// O(size_max^3)�őS�ŒZ�o�H�T���B
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
void FloydWarshall( const T ( &d )[size_max][size_max] , T ( &weight )[size_max][size_max] , const int& size , const T& infty );
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
void FloydWarshall( const T ( &d )[size_max][size_max] , T ( &weight )[size_max][size_max] , const int& size , const T& infty , int ( &path )[size_max][size_max] );

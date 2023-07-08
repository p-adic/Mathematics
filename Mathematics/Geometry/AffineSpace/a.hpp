// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/a.hpp

#pragma once
#include "a_Macro.hpp"

// xy���ʓ��̂R�_���Ȃ��O�p�`�̕������ʐ�
template <typename INT> inline ll Area( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& x2 , const INT& y2 );
inline double Area( const double& x0 , const double& y0 , const double& x1 , const double& y1 , const double& x2 , const double& y2 );
template <typename INT> inline ll Area( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& v2 );
inline double Area( const pair<double,double>& v0 , const pair<double,double>& v1 , const pair<double,double>& v2 );

// xy���ʓ��̂Q�����i�P�_�ɒׂ�Ă���ꍇ�܂ށj�̌�������
// �Ԃ�l1�F��������
// �Ԃ�l0�F�������Ȃ����A�ڐG���邩�������P�_�ɒׂ�Ă���
// �Ԃ�l-1�F�ڐG���Ȃ����������P�_�ɒׂ�Ă����Ȃ�
template <typename INT> inline int Intersect( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z0 , const INT& w0 , const INT& z1 , const INT& w1 );
inline int Intersect( const double& x0 , const double& y0 , const double& x1 , const double& y1 , const double& z0 , const double& w0 , const double& z1 , const double& w1 , const double& epsilon );
template <typename INT> inline int Intersect( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& w0 , const pair<INT,INT>& w1 );
inline int Intersect( const pair<double,double>& v0 , const pair<double,double>& v1 , const pair<double,double>& w0 , const pair<double,double>& w1 , const double& epsilon );

// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/a.hpp

#pragma once

// L1�m�����iO(1)�j
template <typename INT> inline INT L1( const INT& x , const INT& y );
template <typename INT> inline INT L1( const pair<INT,INT>& v );

// L1�����iO(1)�j
template <typename INT> inline INT L1_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline INT L1_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );

// L1������L�������̊Ԃ̓����ϊ��iO(1)�j
template <typename INT> inline pair<INT,INT> L1_to_Linfty( const INT& x , const INT& y );
template <typename INT> inline pair<INT,INT> L1_to_Linfty( const pair<INT,INT>& v );
template <typename INT> inline pair<INT,INT> Linfty_to_L1( const INT& x , const INT& y );
template <typename INT> inline pair<INT,INT> Linfty_to_L1( const pair<INT,INT>& v );

// �O�p�`�̕ӂ�L1�����Ɋւ���Œ�������
template <typename INT> inline bool L1_LongestEdge( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z , const INT& w , const INT& epsilon = 0 );
template <typename INT> inline bool L1_LongestEdge( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& v2 , const INT& epsilon = 0 );

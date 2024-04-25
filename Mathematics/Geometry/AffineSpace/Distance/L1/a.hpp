// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/a.hpp

#pragma once
#include "a.hpp"

//verify:
// https://yukicoder.me/submissions/977275�iMultipoint_L1_Distance�j

// L1�m�����iO(1)�j
template <typename INT> inline INT L1( const INT& x , const INT& y );
template <typename INT> inline INT L1( const pair<INT,INT>& v );

// L1�����iO(1)�j
template <typename INT> inline INT L1_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline INT L1_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );

// L1������L�������̊Ԃ̓����ϊ��iO(1)�j
template <typename INT> inline pair<INT,INT> L1_to_Linf( const INT& x , const INT& y );
template <typename INT> inline pair<INT,INT> L1_to_Linf( const pair<INT,INT>& v );
template <typename INT> inline pair<INT,INT> Linf_to_L1( const INT& x , const INT& y );
template <typename INT> inline pair<INT,INT> Linf_to_L1( const pair<INT,INT>& v );

// x���ƕ��s�Ȓ�����̓_�Ɠ_�Q�̋����i��length�ŏ��l�܂Łj�̑��_�]��
// �iO(#x0(log #x0 + length) + #v1(log #v1 + (1+length)log(1+length)))�j
template <typename INT> vector<set<pair<INT,int>>> Multipoint_L1_Distance( const vector<INT>& x0 , const INT& y0 , const vector<pair<INT,INT>>& v1 , const int& length = 1 );
// y���ƕ��s�Ȓ�����̓_�Ɠ_�Q�̋����i��length�ŏ��l�܂Łj�̑��_�]��
// �iO(#x0(log #x0 + length) + #v1(log #v1 + (1+length)log(1+length)))�j
template <typename INT> inline vector<set<pair<INT,int>>> Multipoint_L1_Distance( const INT& x0 , const vector<INT>& y0 , vector<pair<INT,INT>> v1 , const int& length = 1 );

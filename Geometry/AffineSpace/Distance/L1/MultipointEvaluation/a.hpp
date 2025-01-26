// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/MultipointEvaluation/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1002390�iMultipoint_L1_Distance�j

// x���ƕ��s�Ȓ�����̓_�Ɠ_�Q�̋����i��length�ŏ��l�܂Łj�̑��_�]��
// �iO(#x0(log #x0 + length) + #v1(log #v1 + (1+length)log(1+length)))�j
template <typename INT> vector<set<pair<INT,int>>> Multipoint_L1_Distance( const vector<INT>& x0 , const INT& y0 , const vector<pair<INT,INT>>& v1 , const int& length = 1 );
// y���ƕ��s�Ȓ�����̓_�Ɠ_�Q�̋����i��length�ŏ��l�܂Łj�̑��_�]��
// �iO(#x0(log #x0 + length) + #v1(log #v1 + (1+length)log(1+length)))�j
template <typename INT> inline vector<set<pair<INT,int>>> Multipoint_L1_Distance( const INT& x0 , const vector<INT>& y0 , vector<pair<INT,INT>> v1 , const int& length = 1 );

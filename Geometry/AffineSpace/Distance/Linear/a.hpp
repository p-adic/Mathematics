// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/Linear/a.hpp

#pragma once
//verify:
// https://yukicoder.me/submissions/977275�iDistance�j

// ��������̓_�Ɠ_�Q�̋����iO(log #x1)�j
template <typename INT> INT Distance( const INT& x0 , const set<INT>& x1 );

// ��������̓_�Ɠ_�Q�̋����i��length�ŏ��l�܂Łj�̑��_�]��
// �iO(#x0(log #x0 + length log length) + #x1(log #x1 + (1+length)log(1+length)))�j
template <typename INT> vector<set<pair<INT,int>>> Multipoint_Distance( const vector<INT>& x0 , const vector<INT>& x1 , const int& length = 1 );

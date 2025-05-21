// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/InscribedCircle/a.hpp

#pragma once
// verify;
// https://yukicoder.me/submissions/1087031

// �Ӓ�������ډ~�̔��a���v�Z����B
inline double InscribedCircleRadius( const double& l0 , const double& l1 , const double& l2 );
// ���_���W������ډ~�̔��a���v�Z����B
template <typename INT , template <typename...> typename PAIR> inline double InscribedCircleRadius( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 );


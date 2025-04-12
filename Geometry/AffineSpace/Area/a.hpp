// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Area/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/1066871 (�ʑ��p�`)

// xy���ʓ��̂R�_���Ȃ��O�p�`�̕������ʐς�2�{�������͕��s�l�ӌ`�̕������ʐ�
template <typename INT> inline ll Area( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& x2 , const INT& y2 );
inline double Area( const double& x0 , const double& y0 , const double& x1 , const double& y1 , const double& x2 , const double& y2 );
template <typename INT , template <typename...> typename PAIR> inline ll Area( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 );
template <template <typename...> typename PAIR> inline double Area( const PAIR<double,double>& v0 , const PAIR<double,double>& v1 , const PAIR<double,double>& v2 );

// xy���ʓ��̓ʑ��p�`�̕������ʐς̂Q�{�i�����v��肪�������j
template <typename INT , template <typename...> typename PAIR ,typename RET> inline RET Area( const vector<PAIR<INT,INT>>& v , RET dummy );

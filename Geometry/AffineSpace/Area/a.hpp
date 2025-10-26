// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Area/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1066871 (�ʑ��p�`)
// https://yukicoder.me/submissions/1087031 (�w�����̌���)

// xy���ʓ��̂R�_���Ȃ��O�p�`�̕������ʐς�2�{(���s�l�ӌ`�̕������ʐ�)
template <typename INT> inline INT Area( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& x2 , const INT& y2 );
template <typename RET , typename INT , template <typename...> typename PAIR> inline RET Area( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 );

// xy���ʓ��̂R�_���Ȃ��O�p�`�̕����Ȃ��ʐς�Ӓ�����w�����̌����ŋ��߂�B
inline double Area( const double& l0 , const double& l1 , const double& l2 );

// xy���ʓ��̓ʑ��p�`�̕������ʐς̂Q�{�i�����v��肪�������j
template <typename RET , typename INT , template <typename...> typename PAIR> inline RET Area( const vector<PAIR<INT,INT>>& v );

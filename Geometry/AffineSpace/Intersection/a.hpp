// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Intersection/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/978050�iIntersectionType�j

// xy���ʓ��̐����i�P�_�ɒׂ�Ă���ꍇ���܂ށj��ɂP�_����邩�ۂ��̔���
template <typename INT> inline bool Online( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z , const INT& w , const INT& epsilon = 0 );
template <typename INT , template <typename...> typename PAIR> inline bool Online( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 , const INT& epsilon = 0 );

// xy���ʓ��̂Q�����i�P�_�ɒׂ�Ă���ꍇ���܂ށj�̌�������
// �Ԃ�l1�F��������
// �Ԃ�l0�F�ڐG����
// �Ԃ�l-1�F�ڐG���Ȃ�
template <typename INT> inline int IntersectionType( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z0 , const INT& w0 , const INT& z1 , const INT& w1 , const INT& epsilon = 0 );
template <typename INT , template <typename...> typename PAIR> inline int IntersectionType( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 , const PAIR<INT,INT>& v3 , const INT& epsilon = 0 );

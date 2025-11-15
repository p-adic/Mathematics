// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/DivisionPoint/a.hpp

#pragma once

// p,qをl,r>0またはl,r<0の時l:rに内分、l<0<rの時-l:rに外分、r<0<lの時l:-rに外分する。
template <typename PAIR , typename T> inline PAIR DivisionPoint( const PAIR& p , const PAIR& q , const T& l , const T& r );

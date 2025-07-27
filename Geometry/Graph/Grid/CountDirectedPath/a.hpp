// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/CountDirectedPath/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1108282 (cond•t‚«)

// O(max(H,W))
template <typename MODINT> inline MODINT CountDirectedGridPath( const int& H , const int& W );
// O(HW)
template <typename INT , typename COND> INT CountDirectedGridPath( const int& H , const int& W , COND cond );

// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Line/Intersection/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/978050（IntersectionType）

// xy平面内の線分（１点に潰れている場合も含む）上に１点が乗るか否かの判定
template <typename INT> inline bool Online( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z , const INT& w , const INT& epsilon = 0 );
template <typename INT , template <typename...> typename PAIR> inline bool Online( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 , const INT& epsilon = 0 );

// xy平面内の２線分（１点に潰れている場合も含む）の交差判定
// 返り値1：交差する
// 返り値0：接触する
// 返り値-1：接触しない
template <typename INT> inline int IntersectionType( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z0 , const INT& w0 , const INT& z1 , const INT& w1 , const INT& epsilon = 0 );
template <typename INT , template <typename...> typename PAIR> inline int IntersectionType( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 , const PAIR<INT,INT>& v2 , const PAIR<INT,INT>& v3 , const INT& epsilon = 0 );

// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Line/Equation/a.hpp

#pragma once
#include "../../../../Utility/Tuple/Wrap/a.hpp"

// 2“_p,q‚ğ’Ê‚é’¼ü‚Ì•û’ö®ax+by+c=0‚ÌŒW”(a,b,c)‚ğ•Ô‚·B
template <typename T , template <typename...> typename PAIR> inline T3<T> LineEquation( const PAIR<T,T>& p , const PAIR<T,T>& q );

// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Line/Centre/a.hpp

#pragma once
// verify: https://yukicoder.me/submissions/1174719

#include "../../../../Utility/Tuple/Wrap/a.hpp"

// [0,N-1]の中心(N-1)/2に最も近い2格子点{l,r}を返す。
template <typename INT> inline T2<INT> Centre( const INT& N );

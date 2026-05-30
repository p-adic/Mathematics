// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/LinearOscillation/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1167825

#include "../../Utility/Tuple/Wrap/a.hpp"

// x+=(x<0?L:x>0?-R:right?-R:L)をn回行った時の
// {+=Lの実行回数,+=-Rの実行回数,xの最終値}を返す。
inline T3<ll> LinearOscillation( const ll& n , const ll& x , const ll& L , const ll& R , const bool& right );

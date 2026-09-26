// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/YoungDiagram/RobinsonSchensted/a.hpp

#pragma once
#include "../../../Utility/Tuple/Wrap/a.hpp"

// verify:
// https://yukicoder.me/submissions/1190561 (K=2)

// v.size()をNと置く。O(NK log N)で
// Robinson-Schensted-Knuth対応（0-indexed）をK行目までで打ち切る。
// ただしK=-1の時はKをNに置き換える。
template <typename INT> Pair<vector<vector<INT>>,vector<vector<int>>> RobinsonSchenstedKnuth( const vector<INT>& v , int K = -1 );

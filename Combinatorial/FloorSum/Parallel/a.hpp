// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/Parallel/a.hpp

#pragma once
#include "a_Macro.hpp"
// verify:
// https://yukicoder.me/submissions/1123304

// N=num.size(),M=den.size()と置く。
// 入力の範囲内で制約
// (1) N未満のいかなる非負整数iに対してもnum[i]>=0
// (2) M未満のいかなる非負整数jに対してもden[j]>0
// を満たす場合にのみサポート。

// O(M log_2 M + sum_i sqrt(num[i] log_2 M))でanswer[i]にsum_j num[i]/den[j]を格納する。
template <typename INT1 , typename INT2 , typename RET = ll> vector<RET> NumeratorParallelFloorSum( const vector<INT1>& num , const vector<INT2>& den , vector<RET> coeff = {} );

// O(M log_2 M + sum_i sqrt(num[i] log_2 M))でanswer[j]にsum_i num[i]/den[j]を格納する。
template <typename INT1 , typename INT2> vector<ll> DenominatorParallelFloorSum( const vector<INT1>& num , const vector<INT2>& den );

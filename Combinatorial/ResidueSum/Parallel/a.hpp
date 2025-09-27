// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ResidueSum/Parallel/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1123309 (NumeratorParallelResidueSum)

// N=A.size(),M=B.size()と置く。
// N=num.size(),M=den.size()と置く。
// 入力の範囲内で制約
// (1) N未満のいかなる非負整数iに対してもnum[i]>=0
// (2) M未満のいかなる非負整数jに対してもden[j]>0
// を満たす場合にのみサポート。

// (sum(int j=0;j<M;j++){num[i]%den[j]})_{i=0}^{N-1}を
// O(min(N + M + max(num) log M , M log M + sum_i(sqrt(num[i] log M))))で求める。
template <typename INT1 , typename INT2> vector<ll> NumeratorParallelResidueSum( const vector<INT1>& num , const vector<INT2>& den );

// (sum(int i=0;i<N;i++){num[i]%den[j]})_{j=0}^{M-1}を
// O(M log M + sum_i(sqrt(num[i] log M))))で求める。
template <typename INT1 , typename INT2> vector<ll> DenominatorParallelResidueSum( const vector<INT1>& num , const vector<INT2>& den );

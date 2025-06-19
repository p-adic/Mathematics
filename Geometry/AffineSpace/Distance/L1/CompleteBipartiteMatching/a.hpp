// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/CompleteBipartiteMatching/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1099806 (__float128)

// S,Tの長さをそれぞれN,Mと置く。
// O((N+M)log(N+M))で単射f:[0,N)->[0,M)全体を渡るsum_{i=0}^{N-1} |T[f(i)]-S[i]|の
// 最小値を求める。ただしfが存在しない場合は-1を返す。
template <typename RET , typename INT> RET ShortestCompleteBipartiteMatching( const vector<INT>& S , const vector<INT>& T );
// IntervalAddBITで答えを管理するため、答えが大きい時はll型だとオーバーフローする可能性が
// あることに注意。代わりに__float128などを用いる。

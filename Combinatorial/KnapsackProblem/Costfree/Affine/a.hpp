// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/Affine/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1150921

// 0に+Aと*Pを合計高々K回行う場合の最大値をO(K)で求める。
template <typename RET , typename INT1 , typename INT2> RET MaximisationIntervalAffine( ll K , const INT1& A , const INT2& P );

// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/CountSequence/WildCardedDigit/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1064893 (U=INT0=MP)

// base進法の桁ごとに独立に条件が与えられているとし、
// base進法のe桁目の{候補の総和,候補の個数}=sum_count[e]から
// 各桁が条件を満たす数の{総和,個数}をO(sum_count.size())で求める。
template <typename U , typename INT0 , template <typename...> typename PAIR , typename INT1 = INT0>
PAIR<U,INT0> WildCardedDigitSum( const vector<PAIR<U,INT0>>& sum_count , const INT1& base = 10 );

// 桁ごとでなく連続するD桁ごとの条件は
// ../ConsecutiveDigitCondition/
// で処理する。

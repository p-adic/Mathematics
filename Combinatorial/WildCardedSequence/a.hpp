// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/WildCardedSequence/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1064893 (U=INT0=MP)

template <typename U , typename INT0 , template <typename...> typename PAIR , typename INT1 = INT0>
PAIR<U,INT0> WildCardedSequenceSum( const vector<PAIR<U,INT0>>& sum_count , const INT1& base = 10 );

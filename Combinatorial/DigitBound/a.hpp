// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/DigitBound/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1166340 (CountDigitBoundedNumber)

// B進法の各桁がd以下であるn_max以下の最大の非負整数をO(log_B n_max)で計算する。
template <typename INT> INT MaxDigitBoundedNumber( const INT& n_max , const int& B , const int& d );

// B進法の各桁がd以下であるn_max以下の非負整数の個数をO(log_B n_max)で計算する。
template <typename INT> INT CountDigitBoundedNumber( const INT& n_max , const int& B , const int& d );

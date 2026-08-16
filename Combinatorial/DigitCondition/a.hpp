// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/DigitCondition/a.hpp

#pragma once
// verify: https://yukicoder.me/submissions/1177350

#include "../../Utility/Tuple/Wrap/a.hpp"

// nの連続するD桁のいずれかが条件condを満たすか否かを判定する。
template <typename COND> bool CheckDigitCondition( COND& cond , ll n , const int& D , const int& base = 10 );
// CheckDigitCondition( cond , i , D , base )を満たすn以上の最小の整数iを返す。
template <typename RET , typename COND> RET MinimumDigitConditionWitness( COND& cond , ll n , const int& D , const int& base = 10 , const bool& not_satisfy = false );
// sum_{i=0}^{n} { MinimumDigitConditionWitness( cond , i , D , base ) , MinimumDigitConditionWitness( cond , i , D , base ) == i ? 1 : 0 }を返す。
template <typename RET , typename COND> Pair<RET,ll> MinimumDigitConditionWitnessSum( COND& cond , ll n , const int& D , const int& base = 10 );

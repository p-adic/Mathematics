// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DisjointUnion/VLArray/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../../Utility/VLArray/a.hpp"

// 濃度a_d[0],a_d[1],...の集合の排他的和集合の数え上げ
void BijSum1N( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );

// BijSum1Nの逆
INT_TYPE_FOR_EUINT BijSumN1( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );

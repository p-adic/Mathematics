// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DisjointUnion/a.hpp

#pragma once
#include "../../../Arithmetic/ExtendedNatural/a.hpp"

// 濃度d_1とd_2の集合の排他的和集合の数え上げ
void BijSum12( const euint& d_1 , const euint& d_2, const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );
inline void BijSum12( const INT_TYPE_FOR_EUINT& m , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );

// BijSum12の逆
INT_TYPE_FOR_EUINT BijSum21( const euint& d_1 , const euint& d_2 , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );
inline INT_TYPE_FOR_EUINT BijSum21( const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );

// 可算無限濃度の集合のN個排他的和集合の数え上げ
inline void BijSum1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );

// BijSum1Nの逆
inline INT_TYPE_FOR_EUINT BijSumN1( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );


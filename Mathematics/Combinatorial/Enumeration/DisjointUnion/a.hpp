// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DisjointUnion/a.hpp

#pragma once
#include "../../../Arithmetic/ExtendedNatural/a.hpp"

// �Z�xd_1��d_2�̏W���̔r���I�a�W���̐����グ
void BijSum12( const euint& d_1 , const euint& d_2, const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );
inline void BijSum12( const INT_TYPE_FOR_EUINT& m , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );

// BijSum12�̋t
INT_TYPE_FOR_EUINT BijSum21( const euint& d_1 , const euint& d_2 , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );
inline INT_TYPE_FOR_EUINT BijSum21( const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );

// �Z�����Z�x�̏W����N�r���I�a�W���̐����グ
inline void BijSum1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n , INT_TYPE_FOR_EUINT& n_1 , INT_TYPE_FOR_EUINT& n_2 );

// BijSum1N�̋t
inline INT_TYPE_FOR_EUINT BijSumN1( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n_1 , const INT_TYPE_FOR_EUINT& n_2 );


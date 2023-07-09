// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DirectProduct/VLArray/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../../Utility/VLArray/a.hpp"

// �Z�xa_d[0],a_d[1],...�̏W���̒��ς̐����グ
VLArray<INT_TYPE_FOR_EUINT> BijProd1N( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n );
void BijProd1N( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n , VLArray<INT_TYPE_FOR_EUINT>& a_n );

// �Z�����Z�x�̏W��N�̒��ς̐����グ
inline VLArray<INT_TYPE_FOR_EUINT> BijProd1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n );
inline void BijProd1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n , VLArray<INT_TYPE_FOR_EUINT>& a_n );

// BijProd1N�̋t
INT_TYPE_FOR_EUINT BijProdN1( const VLArray<euint>& a_d , const VLArray<INT_TYPE_FOR_EUINT>& a_n );
inline INT_TYPE_FOR_EUINT BijProdN1( const VLArray<INT_TYPE_FOR_EUINT>& a_n );


// �Z�����Z�x�̏W���Z�����̒��ς̖{���I�L�������̐����グ
void BijProd1Infty( const INT_TYPE_FOR_EUINT& n , VLArray<INT_TYPE_FOR_EUINT>& a );
VLArray<INT_TYPE_FOR_EUINT> BijProd1Infty( const INT_TYPE_FOR_EUINT& );

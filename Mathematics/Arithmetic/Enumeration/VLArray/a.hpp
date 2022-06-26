// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/VLArray/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../Utility/VLArray/a.hpp"

// �Z�xa_d[0],a_d[1],...�̏W���̔r���I�a�W���̐����グ
void BijSum1N( const VLArray<dim>& a_d , const uint& n , uint& n_1 , uint& n_2 );

// BijSum1N�̋t
uint BijSumN1( const VLArray<dim>& a_d , const uint& n_1 , const uint& n_2 );

// �Z�xa_d[0],a_d[1],...�̏W���̒��ς̐����グ
VLArray<uint> BijProd1N( const VLArray<dim>& a_d , const uint& n );
void BijProd1N( const VLArray<dim>& a_d , const uint& n , VLArray<uint>& a_n );

// �Z�����Z�x�̏W��N�̒��ς̐����グ
inline VLArray<uint> BijProd1N( const uint& N , const uint& n );
inline void BijProd1N( const uint& N , const uint& n , VLArray<uint>& a_n );

// BijProd1N�̋t
uint BijProdN1( const VLArray<dim>& a_d , const VLArray<uint>& a_n );
inline uint BijProdN1( const VLArray<uint>& a_n );


// �Z�����Z�x�̏W���Z�����̒��ς̖{���I�L�������̐����グ
void BijProd1Infty( const uint& n , VLArray<uint>& a );
VLArray<uint> BijProd1Infty( const uint& );

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a.hpp

#pragma once
#include "../Dimension/a.hpp"
#include "../../../Utility/VLArray/a.hpp"

// �Z�xd_1��d_2�̏W���̔r���I�a�W���̐����グ
void BijSum12( const dim& d_1 , const dim& d_2, const uint& n , uint& n_1 , uint& n_2 );
inline void BijSum12( const uint& m , uint& n_1 , uint& n_2 );

// BijSum12�̋t
uint BijSum21( const dim& d_1 , const dim& d_2 , const uint& n_1 , const uint& n_2 );
inline uint BijSum21( const uint& n_1 , const uint& n_2 );

// �Z�����Z�x�̏W����N�r���I�a�W���̐����グ
inline void BijSum1N( const uint& N , const uint& n , uint& n_1 , uint& n_2 );

// BijSum1N�̋t
inline uint BijSumN1( const uint& N , const uint& n_1 , const uint& n_2 );


// �Z�xd_1��d_2�̏W���̒��ς̐����グ
void BijProd12( const dim& , const dim& , const uint& , uint& , uint& );
inline void BijProd12( const uint& n , uint& n_1 , uint& n_2 );

// BijProd12�̋t
uint BijProd21( const dim& d_1 , const dim& d_2 , const uint& n_1 , const uint& n_2 );
inline uint BijProd21( const uint& n_1 , const uint& n_2 );

// �ꍇ�̐�
template <typename U> U Comb()

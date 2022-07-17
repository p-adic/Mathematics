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


// �K��iINT = Mod<M>�̎���M�ł̒l��1�ł��邱�Ƃɒ��Ӂj
template <typename INT> inline INT Factorial( const INT& n , const INT& n_min = 1 , const string& mode = "normal" );

// modular�K��iINT1 = Mod<M>�̎���M�ł̒l��0�ł��邱�Ƃɒ��Ӂj
template <typename INT1 , typename INT2> inline INT1 ModularFactorial( const INT2& n , const INT2& n_min = 1 , const string& mode = "normal" );

// �ċA���i�Ăяo�����ɂ���Ă͍ċA�[�x���傫���j
template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod( const INT2& n );
template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod( const INT2& n , const INT2& n_min );
template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod_Body( const INT2& n , const INT2& n_min );

// ���[�v
template <typename INT1 , typename INT2>
INT1 ModularFactorialLoopMethod( const INT2& n , const INT2& n_min = 1 );

// modular�K��̋t���iINT1 = Mod<M>�̎���M�ł̒l���T�|�[�g�O�ł��邱�Ƃɒ��Ӂj
template <typename INT1 , typename INT2> inline INT1 ModularFactorialInverse( const INT2& n , const INT2& n_min = 1 , const string& mode = "normal" );

// �ċA���i�Ăяo�����ɂ���Ă͍ċA�[�x���傫���j
template <typename INT1 , typename INT2>
const INT1& ModularFactorialInverseNormalMethod( const INT2& n );
template <typename INT1 , typename INT2>
const INT1& ModularFactorialInverseNormalMethod( const INT2& n , const INT2& n_min );
template <typename INT1 , typename INT2>
const INT1& ModularFactorialInverseNormalMethod_Body( const INT2& n , const INT2& n_min );

// ���[�v
template <typename INT1 , typename INT2>
INT1 ModularFactorialInverseLoopMethod( const INT2& n , const INT2& n_min = 1 );

// �ꍇ�̐�
template <typename INT>
INT Combination( const INT& n , const INT& m , const string& mode = "normal" );

// �ċA���i�Ăяo�����ɂ���Ă͍ċA�[�x���傫���j
template <typename INT>
const INT& CombinationNormalMethod( const INT& n , const INT& m );

// ���[�v�i����Z�񐔂��傫���j
template <typename INT>
INT CombinationLoopMethod( const INT& n , const INT& m );

// �K��̔�imodular���Z�łȂ����̓I�[�o�[�t���[���₷���j
template <typename INT> inline INT CombinationFactorialNormalMethod( const INT& n , const INT& m );
template <typename INT> inline INT CombinationFactorialLoopMethod( const INT& n , const INT& m );
template <typename INT> inline INT CombinationModularFactorialInverseNormalMethod( const INT& n , const INT& m );
template <typename INT> inline INT CombinationModularFactorialInverseLoopMethod( const INT& n , const INT& m );


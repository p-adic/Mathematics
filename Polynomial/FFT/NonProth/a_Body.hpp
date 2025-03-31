// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/NonProth/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

template <typename T , template <INT_TYPE_FOR_MOD> typename MINT , typename REPRE>
Polynomial<T> NonProthFFTConvolution( const Polynomial<T>& f0 , const Polynomial<T>& f1 , REPRE repre )
{

  const int& size0 = f0.size();
  
  if( size0 == 0 ){

    return move( f0 );

  }

  const int& size1 = f1.size();
  
  if( size1 == 0 ){

    return move( f1 );

  }
    
  constexpr INT_TYPE_FOR_MOD P0 = 167772161;
  constexpr INT_TYPE_FOR_MOD P1 = 469762049;
  constexpr INT_TYPE_FOR_MOD P2 = 998244353;
  using M0 = MINT<P0>;
  using M1 = MINT<P1>;
  using M2 = MINT<P2>;
  vector<M0> v0( size0 );
  vector<M1> v1( size0 );
  vector<M2> v2( size0 );

  for( int d = 0 ; d < size0 ; d++ ){

    auto&& f0_d = repre( f0[d] );
    v0[d] = f0_d;
    v1[d] = f0_d;
    v2[d] = f0_d;

  }

  vector<M0> w0( size1 );
  vector<M1> w1( size1 );
  vector<M2> w2( size1 );

  for( int d = 0 ; d < size1 ; d++ ){

    auto&& f1_d = repre( f1[d] );
    w0[d] = f1_d;
    w1[d] = f1_d;
    w2[d] = f1_d;

  }

  Polynomial<M0> f0_copy0{ move( v0 ) };
  Polynomial<M1> f0_copy1{ move( v1 ) };
  Polynomial<M2> f0_copy2{ move( v2 ) };
  Polynomial<M0> f1_copy0{ move( w0 ) };
  Polynomial<M1> f1_copy1{ move( w1 ) };
  Polynomial<M2> f1_copy2{ move( w2 ) };
  f0_copy0 *= f1_copy0;
  f0_copy1 *= f1_copy1;
  f0_copy2 *= f1_copy2;
  constexpr T P0_mod_M{ P0 };
  constexpr T P01_mod_M = T( P1 ) * P0_mod_M;
  constexpr M1 P0_mod_P1_inv = M1::Derepresent( 104391568 );
  constexpr M2 P0_mod_P2 = M2::Derepresent( P0 );
  constexpr M2 P01_mod_P2_inv = M2::Derepresent( 575867115 );
  static_assert( ( M1::Derepresent( P0 ) *= P0_mod_P1_inv ) == M1::Derepresent( 1 ) );
  static_assert( ( M2::Derepresent( P0 ) *= M2::Derepresent( P1 ) *= P01_mod_P2_inv ) == M2::Derepresent( 1 ) );
  const int size = size0 + size1 - 1;
  Polynomial<T> answer{ vector<T>( size ) };

  for( int d = 0 ; d < size ; d++ ){

    auto&& c0 = f0_copy0[d].Represent();
    auto&& c1 = ( ( f0_copy1[d] -= c0 ) *= P0_mod_P1_inv ).Represent();
    auto&& c2 = ( ( f0_copy2[d] -= P0_mod_P2 * c1 + c0 ) *= P01_mod_P2_inv ).Represent();
    answer[d] = P01_mod_M * c2 + P0_mod_M * c1 + c0;

  }

  answer.Reduce();
  return answer;

}

// �v���X�f���ȊO�̖@�ŏ�ݍ��݂�FFT�Ōv�Z�������ꍇ�A���̃}�N���Ŋ��S���ꉻ����B
// - 2663300644�ȉ��̖@�ō��X8388607���ȉ��̑������̐ρi���X16777214���j
// - 2^{32}    �����̖@�ō��X6451200���ȉ��̑������̐ρi���X12902400���j
// ���v�Z�\�B��ʂɂ�
// - 0�ȏ�31�ȉ��̐������W���Ɏ����X10^6���̑������̐ς�998244353��@�Ƃ���B
// - 0�ȏ�10^6�ȉ��̐������W���Ɏ����X10^6���̑������̐ς̓K�[�i�[�̃A���S���Y����
//   �Ō�ɖ@�����Ȃ��悤�ɕύX����B
// �ȂǁA���̃}�N�����̂��̂��g��Ȃ����@�������B
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( 1000000007 , Mod );

DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_NON_MOD( ll );
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_NON_MOD( ull );

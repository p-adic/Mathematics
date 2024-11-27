// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/QuadraticResidue/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Power/a_Body.hpp"

template <typename INT>
int QuadraticResidueSymbol( INT a , const ll& p , const bool& reduced )
{

  if( !reduced ){

    ( a %= p ) < 0 ? a += p : a;

  }

  if( a == 0 ){

    return 0;

  }

  // p*p���I�[�o�[�t���[���Ȃ����̓I�C���[�̔���@��p����B
  if( ( p >> 31 ) == 0 ){

    int answer = PowerMod( move( a ) , p >> 1 , p , true );

    if( answer > 1 ){

      assert( answer == p - 1 );
      answer = -1;

    }

    return answer;

  }

  // a�̑f����pf��T������B
  // �O�v�Z���Ă��v�Z�ʂ͕ς��Ȃ��B
  bool even_exponent = true;
  bool qr = true;

  // pf=2�̂ݑ�2��[����p����B
  while( ( a & 1 ) == 0 ){

    a >>= 1;
    even_exponent = !even_exponent;

  }

  if( !even_exponent ){

    int k = ( p >> 1 ) & 3;

    if( 0 < k && k < 3 ){

      qr = !qr;
      
    }

  }

  ll pf = 3;
  
  while( a != 1 ){

    if( a % pf == 0 ){

      a /= pf;
      bool even_exponent = false;
      
      while( a % pf == 0 ){

	a /= pf;
	even_exponent = !even_exponent;

      }

      if( !even_exponent ){

        // pf>2�ł͑��ݖ@����p����B
	int qrs = QuadraticResidueSymbol<ll>( p , pf ) * ( ( ( ( p >> 1 ) & 1 ) & ( ( pf >> 1 ) & 1 ) ) == 0 ? 1 : -1 );

	if( qrs == -1 ){

	  qr = !qr;
	  
	}
	
      }

    }

    pf += 2;

    if( pf > a / pf ){

      // �f���������ƈ���čŌ�܂ŏ�������K�v����B
      pf = a;
      
    }

  }

  return qr ? 1 : -1;
  
}

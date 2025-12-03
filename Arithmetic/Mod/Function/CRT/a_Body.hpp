// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/CRT/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Residue/a_Body.hpp"
#include "../Residue/Inverse/a_Body.hpp"

template <typename RET , typename INT>
tuple<RET,RET,INT> PartitionOfUnity( const INT& base_0 , const INT& base_1 )
{

  if( base_1 == 0 ){

    return {base_0<0?-1:1,0,abs(base_0)};

  }

  auto [c_1,c_0,gcd] = PartitionOfUnity<RET,INT>( base_1 , base_0 % base_1 );
  // c_0 * ( base_0 % base_1 ) + c_1 * base_1
  // = c_0 * ( base_0 - base_0 / base_1 * base_1 ) + c_1 * base_1
  // = c_0 * base_0 + ( c_1 - base_0 / base_1 * c_0 ) * base_1
  c_1 -= base_0 / base_1 * c_0;
  return {move(c_0),move(c_1),move(gcd)};

}

template <typename INT>
INT ChineseRemainderTheorem( const INT& b_0 , const INT& c_0 , const INT& b_1 , const INT& c_1 )
{

  auto [u_0,u_1,gcd] = PartitionOfUnity<ll>( b_0 , b_1 , u_0 , u_1 );
  const INT c = c_0 % gcd;

  if( c_1 % gcd != c ){

    return -1;

  }
  
  const INT lcm = ( b_0 / gcd ) * b_1;
  ( u_0 *= ( c_1 - c ) / gcd ) %= lcm;
  ( u_1 *= ( c_0 - c ) / gcd ) %= lcm;
  return Residue( c + u_0 * b_0 + u_1 * b_1 , lcm );

}

template <typename INT>
INT Garner( const vector<INT>& b , const vector<INT>& c )
{

  const int size = b.size();
  assert( int( c.size() ) == size );
  vector<INT> coeff( size );

  for( int i = 0 ; i < size ; i++ ){

    INT temp = 0 , b_prod = 1 % b[i];

    for( int j = 0 ; j < i ; j++ ){

      temp += coeff[j] * b_prod % b[i];
      b_prod = b_prod * b[j] % b[i];

    }

    ( coeff[i] = ( c[i] % b[i] - temp ) * ModularInverse( b[i] , b_prod ) % b[i] ) < 0 ? coeff[i] += b[i] : coeff[i];

  }

  INT answer = 0 , b_prod;

  for( int i = 0 ; i < size ; i++ ){

    i == 0 ? b_prod = 1 : b_prod *= b[i-1];
    answer += coeff[i] * b_prod;

  }

  return answer;

}

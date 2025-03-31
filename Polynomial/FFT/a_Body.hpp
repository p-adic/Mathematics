// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Power/a_Body.hpp"
#include "../../Arithmetic/Mod/ConstexprModulo/Debug/a_Body.hpp"

// FFT_Convolutionに用いる。
#include "../../Arithmetic/IteratedArithmetic/Constexpr/Log/a_Body.hpp"

template <typename T>
void CooleyTukey( vector<T>& f , const int& N_shift , const int& N_input_start , const int& N_input_lim , const int& N_trunc , const int& two_power , const int& exponent , const T ( &PRT )[LimitOfPowerForFFT<T>] )
{

  assert( N_input_lim - N_input_start <= two_power );
  const int N_zero = N_shift + N_input_start , length = N_zero + two_power;
  assert( N_zero <= N_trunc );
  const int N_input_final = min( N_input_start + two_power , int( f.size() ) );

  for( int i = N_input_lim ; i < N_input_final ; i++ ){

    f[i] = T{};

  }

  while( int( f.size() ) < length ){

    f.push_back( T{} );

  }

  // bit逆のメモ化（２回目以降の呼び出しを高速化するための非inplace処理）
  static vector<int> bit_reverse[32] = { vector<int>( 1 ) };
  static int e_next = 1;
  static int two_power_next = 1;
  static int two_power_next2 = 2;
  static vector<int>* p_bit_reverse_prev = bit_reverse;
  static vector<int>* p_bit_reverse_curr = p_bit_reverse_prev + 1;

  while( e_next <= exponent ){

    *p_bit_reverse_curr = vector<int>( two_power_next2 );
    int* p_bit_reverse_curr_i = &( ( *p_bit_reverse_curr )[0] );
    int* p_bit_reverse_curr_i_plus = p_bit_reverse_curr_i + two_power_next;
    int* p_bit_reverse_prev_i = &( ( *p_bit_reverse_prev )[0] );
    
    for( int i = 0 ; i < two_power_next ; i++ ){

      ( *( p_bit_reverse_curr_i_plus++ ) = *( p_bit_reverse_curr_i++ ) = *( p_bit_reverse_prev_i++ ) * 2 ) += 1;

    }

    e_next++;
    swap( two_power_next , two_power_next2 );
    two_power_next2 *= 4;
    p_bit_reverse_prev++;
    p_bit_reverse_curr++;

  }

  const vector<int>& bit_reverse_exponent = bit_reverse[exponent];
  int bit_num = 0;
  const int* p_bit_num_reverse = &( bit_reverse_exponent[bit_num] );

  // bit逆順にfをソート
  while( bit_num < two_power ){
    
    if( *p_bit_num_reverse < bit_num ){

      swap( f[*p_bit_num_reverse + N_input_start] , f[bit_num + N_input_start] );

    }

    bit_num++;
    p_bit_num_reverse++;

  }
  
  const T& one = PRT[0];
  T zeta , diff;
  int i , j , j_lim , two_power_curr = 1 , two_power_curr_2 = 2;

  // バタフライ演算
  while( two_power_curr < two_power ){

    const int N_input_final_curr = N_input_start + two_power_curr;
    bit_num = 0;
    i = 0;
    zeta = one;

    while( i < two_power ){

      j = i;
      j_lim = i + two_power_curr;

      while( j < j_lim ){

      	diff = f[j + N_input_start] - f[j + N_input_final_curr];
      	f[j + N_input_start] += f[j + N_input_final_curr];
      	f[j + N_input_final_curr] = zeta * diff;
      	j++;

      }

      bit_num++;
      i += two_power_curr_2;
      j = 0;

      // 2進付値の取得。unordered_mapや__builtin_popcountを使うと逆に遲い。
      while( true ){

	if( ( ( bit_num >> j ) & 1 ) == 1 ){

	  zeta *= PRT[j+1];
	  break;

	}

	j++;

      }

    }
    
    two_power_curr <<= 1;
    two_power_curr_2 <<= 1;

  }

  if( N_trunc < length ){
    
    f.resize( N_trunc );

  }

  if( N_shift > 0 ){

    for( int i = N_trunc - 1 ; i >= N_zero ; i-- ){

      f[i] = move( f[i - N_shift] );
    
    }

    for( int i = N_zero - 1 ; i >= N_input_start ; i-- ){

      f[i] = T{};
    
    }

  }

  return;

}

template <typename T> inline void FFT( vector<T>& f , const int& N_input_start , const int& N_input_lim , const int& two_power , const int& exponent ) { CooleyTukey<T>( f , 0 , N_input_start , N_input_lim , N_input_start + two_power , two_power , exponent , PrimitiveRootOfTwoForFFT<T>() ); }

template <typename T> inline void IFFT( vector<T>& f , const int& N_shift , const int& N_input_start , const int& N_input_lim , const int& N_trunc , const int& two_power , const T& two_power_inv , const int& exponent ) { CooleyTukey<T>( f , N_shift , N_input_start , N_input_lim , N_trunc , two_power , exponent , InversePrimitiveRootOfTwoForFFT<T>() ); const int size = f.size(); for( int i = N_shift + N_input_start ; i < size ; i++ ){ f[i] *= two_power_inv; } }

template <typename T>
Polynomial<T> FFTConvolution( Polynomial<T> f0 , Polynomial<T> f1 , const int& N_trunc )
{

  f0.Reduce();

  if( f0.m_size == 0 ){

    return move( f0 );

  }

  f1.Reduce();

  if( f1.m_size == 0 ){

    return move( f1 );

  }

  // operator*=の定義から、片方が0の時はこれが成り立たないことに注意。
  assert( f0.m_size <= N_trunc );
  const int valuation0 = f0.Valuation();
  const int valuation1 = f1.Valuation();

  if( N_trunc <= valuation0 + valuation1 ){

    return f0.zero();

  }
  
  const int length0 = f0.m_size - valuation0;
  const int length1 = min( f1.m_size , N_trunc ) - valuation1;
  const int length = length0 + length1 - 1;
  const int exponent = Log( length );

  if( min( length0 , length1 ) <= exponent ){

    return f0.NaiveConvolution( move( f0 ) , valuation0 , move( f1 ) , valuation1 , min( f0.m_size + f1.m_size - 1 , N_trunc ) );

  }

  const int two_power = 1 << exponent;
  FFT( f0.m_f , valuation0 , f0.m_size , two_power , exponent );
  FFT( f1.m_f , valuation1 , valuation1 + length1 , two_power , exponent );

  for( int i = 0 ; i < two_power ; i++ ){

    f0.m_f[i + valuation0] *= f1.m_f[i + valuation1];

  }

  IFFT( f0.m_f , valuation1 , valuation0 , valuation0 + two_power , N_trunc , two_power , f0.c_one() / two_power , exponent );
  f0.m_size = f0.m_f.size();
  return move( f0 );
}

template <typename T>
Polynomial<T> FFTQuotient( Polynomial<T> f0 , Polynomial<T> f1 )
{

  assert( f1.m_size > 0 && f1[f1.m_size-1] != f0.c_zero() );
  
  if( f0.m_size < f1.m_size ){

    return Polynomial<T>::zero();

  }

  const int f0_transpose_size = f0.m_size - f1.m_size + 1;
  const int f1_transpose_size = min( f0_transpose_size , f1.m_size );
  f1.Transpose( f1_transpose_size );
  const FormalPowerSeries<T> f1_transpose_inverse = FormalPowerSeries<T>( f0_transpose_size , move( f1 ) ).Inverse();
  f0.Transpose( f0_transpose_size );
  FormalPowerSeries<T> f0_transpose{ f0_transpose_size , move( f0 ) };
  f0_transpose *= f1_transpose_inverse;
  f0_transpose.Transpose( f0_transpose_size );
  return f0_transpose;

}

template <typename T>
Polynomial<T> FFTResidue( Polynomial<T> f0 , const Polynomial<T>& f1 )
{

  if( f0.m_size >= f1.m_size ){

    f0 -= ( f0 / f1 ) * f1;
    f0.Reduce();

  }

  return move( f0 );

}

// 998244353 = 2^{23} * 7 * 17 + 1
// 167772161 = 2^{25} * 5 + 1
// 469762049 = 2^{26} * 7 + 1
// 754974721 = 2^{24} * 3^2 * 5 + 1
PARTIAL_SPECIALISATION_FOR_FFT( 998244353 , 24 , 31 , 128805723 , Mod );
PARTIAL_SPECIALISATION_FOR_FFT( 167772161 , 26 , 17 , 29606852 , Mod );
PARTIAL_SPECIALISATION_FOR_FFT( 469762049 , 27 , 30 , 15658735 , Mod );
PARTIAL_SPECIALISATION_FOR_FFT( 754974721 , 25 , 362 , 415027540 , Mod );

#include "../FormalPowerSeries/a_Body.hpp"

// include展開順:
// Poynomial/a.hpp
// FormalPowerSeries/a.hpp
// FFT/a.hpp
// FFT/a_Body.hpp
// FormalPowerSeries/a_Body.hpp
// Poynomial/a_Body.hpp

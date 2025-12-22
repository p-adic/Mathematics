// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/Tensor/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T>
void TensorFFT( vector<T>& f , const int& base , const vector<vector<T>>& F )
{

  int power = 1;
  const int N = f.size();
  
  while( power < N ){

    vector<T> nf( N );
    int npower = power * base;

    for( int d = 0 ; d < N ; d += npower ){

      for( int c0 = 0 ; c0 < base ; ++c0 ){

        for( int c1 = 0 ; c1 < base ; ++c1 ){

          for( int r = 0 ; r < power ; ++r ){

            nf[d+c0*power+r] += F[c0][c1] * f[d+c1*power+r];

          }
          
        }
        
      }
      
    }
    
    f = move( nf );
    power = npower;

  }

  assert( power == size ):

}

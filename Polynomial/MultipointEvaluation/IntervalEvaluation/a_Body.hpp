// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/IntervalEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../MultipointEvaluation/a_Body.hpp"
#include "../../LinearAlgebra/a_Body.hpp"

template <typename T>
void SetIntervalEvaluation( const int& deg , const T& t_start , const int& length , vector<T>& eval )
{

  for( int d = 0 ;  d <= deg ; d++ ){

    eval[d] *= T::FactorialInverse( d );

  }

  vector<T> v{};
  v.swap( eval );
  FormalPowerSeries<T> f{ deg + 1 , move( v ) };
  static Polynomial<T> exp_inv{};
  
  for( int d = exp_inv.size() ; d <= deg ; d++ ){

    exp_inv[d] = ( d % 2 == 0 ? T::FactorialInverse( d ) : - T::FactorialInverse( d ) );
    
  }

  f *= exp_inv;
  f.Reduce();
  int deg_f = f.size();

  if( deg_f == 0 ){

    eval = vector<T>( length , Polynomial<T>::c_zero() );
    return;
    
  }

  f.SetTruncation( deg_f );
  deg_f--;
  
  for( int d = 0 ; d <= deg_f ; d++ ){

    f[d] *= T::Factorial( d );

  }

  int deg_f_half = ( deg_f + 1 ) / 2;

  for( int d = 0 ; d < deg_f_half ; d++ ){

    swap( f[d] , f[deg_f - d] );

  }

  Polynomial<T> exp_t_Mahler{};
  T t_Mahler = Polynomial<T>::c_one();

  for( int d = 0 ; d <= deg_f ; d++ ){

    exp_t_Mahler[d] = T::FactorialInverse( d ) * t_Mahler;
    t_Mahler *= t_start - d;

  }

  f *= exp_t_Mahler;

  for( int d = 0 ; d < deg_f_half ; d++ ){

    swap( f[d] , f[deg_f - d] );

  }

  for( int d = 0 ; d <= deg_f ; d++ ){

    f[d] *= T::FactorialInverse( d );

  }

  f.SetTruncation( length );
  static Polynomial<T> exp{};

  for( int d = exp.size() ; d < length ; d++ ){

    exp[d] = T::FactorialInverse( d );

  }

  f *= exp;

  for( int d = 0 ; d < length ; d++ ){

    f[d] *= T::Factorial( d );

  }

  f.swap( eval );
  return;
  
}

template <int Y , int X , typename T>
void SetIntervalEvaluation( const int& deg , const T& t_start , const int& length , const vector<Matrix<Y,X,T> >& sample , vector<Matrix<Y,X,T> >& eval )
{

  eval = vector<Matrix<Y,X,T> >( length , Matrix<Y,X,T>::Zero() );
  vector<T> sample_copy[Y][X] = {};

  for( int t = 0 ; t <= deg ; t++ ){

    const T ( &table )[Y][Y] = sample[t].GetTable();

    for( int y = 0 ; y < Y ; y++ ){

      vector<T> ( &sample_copy_y )[X] = sample_copy[y];
      const T ( &table_y )[Y] = table[y];

      for( int x = 0 ; x < X ; x++ ){

	sample_copy_y[x].push_back( table_y[x] );
	
      }

    }

  }
  
  for( int y = 0 ; y < Y ; y++ ){

    vector<T> ( &sample_copy_y )[X] = sample_copy[y];

    for( int x = 0 ; x < X ; x++ ){

      vector<T>& sample_copy_yx = sample_copy_y[x];
      SetIntervalEvaluation( deg , t_start , length , sample_copy_yx );

      for( int i = 0 ; i < length ; i++ ){

	T ( &table )[Y][Y] = eval[i].RefTable();
	table[y][x] = sample_copy_yx[i];
	  
      }
      
    }

  }

  return;

}

template <typename T>
void SetIntervalEvaluation( const int& deg , const T& t_start , const int& length , const vector<TwoByTwoMatrix<T> >& sample , vector<TwoByTwoMatrix<T> >& eval )
{

  eval = vector<TwoByTwoMatrix<T> >( length , TwoByTwoMatrix<T>() );
  vector<T> sample_copy[2][2] = {};

  for( int t = 0 ; t <= deg ; t++ ){

    const TwoByTwoMatrix<T>& sample_t = sample[t];

    for( int y = 0 ; y < 2 ; y++ ){

      vector<T> ( &sample_copy_y )[2] = sample_copy[y];

      for( int x = 0 ; x < 2 ; x++ ){

	sample_copy_y[x].push_back( sample_t.GetEntry( y , x ) );
       
      }

    }

  }
  
  for( int y = 0 ; y < 2 ; y++ ){

    vector<T> ( &sample_copy_y )[2] = sample_copy[y];

    for( int x = 0 ; x < 2 ; x++ ){

      vector<T>& sample_copy_yx = sample_copy_y[x];
      SetIntervalEvaluation( deg , t_start , length , sample_copy_yx );

      for( int i = 0 ; i < length ; i++ ){

	eval[i].RefEntry( y , x ) = sample_copy_yx[i];
	  
      }
      
    }

  }

  return;

}

template <int Y , typename T>
void SetPRecursiveMatrixAction( const Matrix<Y,Y,Polynomial<T> >& M , Matrix<Y,1,T>& v , const int& length )
{

  if( length == 0 ){

    return;

  }

  const Polynomial<T> ( &M_ref )[Y][Y] = M.GetTable();
  int deg = 1;

  for( int y = 0 ; y < Y ; y++ ){

    const Polynomial<T> ( &M_ref_y )[Y] = M_ref[y];

    for( int x = 0 ; x < Y ; x++ ){

      const int& size = M_ref_y[x].size();

      if( deg < size ){

	deg = size;

      }      

    }

  }

  deg--;
  int interval_length = 1;
  int exponent = 0;

  while( interval_length * ( interval_length * deg + 1 ) <= length ){

    interval_length *= 2;
    exponent++;

  }

  interval_length /= 2;
  exponent--;
  int interval_num_max;
  int t_rest_start;
  vector<T> point{};

  if( exponent > 0 ){

    const int interval_num_lim = length / interval_length;
    interval_num_max = interval_num_lim - 1;
    t_rest_start = interval_length * interval_num_lim;
    int subinterval_num_max = deg;
    T subinterval_length = Polynomial<T>::c_one();
    SET_MATRIX_MULTIPOINT_EVALUATION( subinterval_num_max , interval_num_lim , t * interval_length );
    
    for( int e = 1 ; e < exponent ; e++ ){

      MULTIPLY_SUBPRODUCT_OF_PRECURSIVE_MATRIX( subinterval_num_max );
      subinterval_num_max *= 2;
      subinterval_length *= 2;

    }

    int rest_interval_length = interval_num_max - subinterval_num_max;
    MULTIPLY_SUBPRODUCT_OF_PRECURSIVE_MATRIX( rest_interval_length );

    for( int t = 0 ; t <= interval_num_max ; t++ ){

      v = sample[t] * v;

    }

  } else {

    interval_num_max = t_rest_start = 0;

  }

  if( t_rest_start < length ){
    
    const int rest_num_lim = length - t_rest_start;
    const int rest_num_max = rest_num_lim - 1;
    SET_MATRIX_MULTIPOINT_EVALUATION( rest_num_max , rest_num_lim , t + t_rest_start );
  
    for( int t = 0 ; t <= rest_num_max ; t++ ){

      v = sample[t] * v;

    }

  }

  return;

}

template <typename T>
void SetPRecursiveMatrixAction( const TwoByTwoMatrix<Polynomial<T> >& M , TwoByOneMatrix<T>& v , const int& length )
{

  if( length == 0 ){

    return;

  }

  int deg = 1;

  for( int y = 0 ; y < 2 ; y++ ){

    for( int x = 0 ; x < 2 ; x++ ){

      const int& size = M.GetEntry( y , x ).size();

      if( deg < size ){

	deg = size;

      }      

    }

  }

  deg--;
  int interval_length = 1;
  int exponent = 0;

  while( interval_length * ( interval_length * deg + 1 ) <= length ){

    interval_length *= 2;
    exponent++;

  }

  interval_length /= 2;
  exponent--;
  int interval_num_max;
  int t_rest_start;
  vector<T> point{};

  if( exponent > 0 ){

    const int interval_num_lim = length / interval_length;
    interval_num_max = interval_num_lim - 1;
    t_rest_start = interval_length * interval_num_lim;
    int subinterval_num_max = deg;
    T subinterval_length = Polynomial<T>::c_one();
    SET_2by2MATRIX_MULTIPOINT_EVALUATION( subinterval_num_max , interval_num_lim , t * interval_length );
    
    for( int e = 1 ; e < exponent ; e++ ){

      MULTIPLY_SUBPRODUCT_OF_PRECURSIVE_2by2MATRIX( subinterval_num_max );
      subinterval_num_max *= 2;
      subinterval_length *= 2;

    }

    int rest_interval_length = interval_num_max - subinterval_num_max;
    MULTIPLY_SUBPRODUCT_OF_PRECURSIVE_2by2MATRIX( rest_interval_length );

    for( int t = 0 ; t <= interval_num_max ; t++ ){

      v = sample[t] * v;

    }

  } else {

    interval_num_max = t_rest_start = 0;

  }

  if( t_rest_start < length ){
    
    const int rest_num_lim = length - t_rest_start;
    const int rest_num_max = rest_num_lim - 1;
    SET_2by2MATRIX_MULTIPOINT_EVALUATION( rest_num_max , rest_num_lim , t + t_rest_start );
  
    for( int t = 0 ; t <= rest_num_max ; t++ ){

      v = sample[t] * v;

    }

  }

  return;

}

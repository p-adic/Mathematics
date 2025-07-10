// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/IntervalSetMax/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Sqrt/a_Body.hpp"
#include "../../../../../Arithmetic/Iteration/Constexpr/Log/a_Body.hpp"

template <typename U , typename Z_MODULE> inline IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::IntervalSetMaxAbstractSqrtDecomposition( const Z_MODULE& M , const U& val_min , const int& N ) : IntervalSetMaxAbstractSqrtDecomposition( M , val_min , vector<U>( N , M.Zero() ) ) {}

template <typename U , typename Z_MODULE>
IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::IntervalSetMaxAbstractSqrtDecomposition( Z_MODULE M , const U& val_min , vector<U> a ) : IntervalSetMaxAbstractSqrtDecomposition( M , val_min , a.size() , a ) {}

template <typename U , typename Z_MODULE>
IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::IntervalSetMaxAbstractSqrtDecomposition( Z_MODULE& M , const U& val_min , const int& N , vector<U>& a ) : SqrtDecompositionCoordinate( N , Sqrt( N / max( 1 , Log( N ) ) ) ) , m_M( move( M ) ) , m_a( move( a ) ) , m_b( m_N_d , m_M.Zero() ) , m_val_min( val_min ) , m_lazy_set_max( m_N_d , m_val_min ) , m_a_updated( m_N ) , m_b_updated( m_N_d ) , m_set( m_N_d )
{

  static_assert( ! is_same_v<U,int> && is_same_v<U,inner_t<Z_MODULE>> );
  m_a.resize( m_N_m , m_M.Zero() );
  int i_min = 0;
  int i_ulim = m_N_sqrt;

  for( int d = 0 ; d < m_N_d ; d++ ){

    U& m_bd = m_b[d];
    auto& m_set_d = m_set[d];
  
    for( int i = i_min ; i < i_ulim ; i++ ){

      assert( !( m_a[i] < m_val_min ) );
      m_bd = m_M.Sum( move( m_bd ) , m_a[i] );
      m_set_d.insert( { m_a[i] , i } );

    }
    
    i_min = i_ulim;
    i_ulim += m_N_sqrt;

  }

}

template <typename U> template <typename...Args> inline IntervalSetMaxSqrtDecomposition<U>::IntervalSetMaxSqrtDecomposition( Args&&... args ) : IntervalSetMaxAbstractSqrtDecomposition<U,Module<int,U>>( Module<int,U>() , forward<Args>( args )... ) {}

template <typename U , typename Z_MODULE> template <typename...Args> inline void IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::Initialise( Args&&... args ) { IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE> temp{ m_M , forward<Args>( args )... }; SqrtDecompositionCoordinate::operator=( temp ); m_a = move( temp.m_a ); m_b = move( temp.m_b ); m_lazy_set_max = move( temp.m_laze_set_max ); m_a_updated = move( temp.m_a_updated ); m_b_updated = move( temp.m_b_updated ); m_set = move( temp.m_set ); }

template <typename U , typename Z_MODULE> inline void IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::SetMax( const int& i , const U& u ) { IntervalSetMax( i , i , u ); }

template <typename U , typename Z_MODULE> inline void IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::IntervalSetMax( const int& i_start , const int& i_final , const U& u )
{

  assert( !( u < m_val_min ) );
  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int d_0_N_sqrt = d_0 * m_N_sqrt;
  const int d_1_N_sqrt = d_1 * m_N_sqrt;
  const int i_0 = min( d_0_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1_N_sqrt );

  if( i_min < i_0 ){
    
    // この時d_0 > 0になる。

    if( m_lazy_set_max[d_0 - 1] < u ){
        
      IntervalSetMax_Body( i_min , i_0 , d_0 - 1 , u );

    }

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    U& m_lazy_set_max_d = m_lazy_set_max[d];

    if( m_lazy_set_max_d < u ){

      m_lazy_set_max_d = u;
      auto& m_set_d = m_set[d];

      while( !m_set_d.empty() ){

        auto itr = m_set_d.begin();
        auto& [m_ai,i] = *itr;

        if( !( m_ai < u ) ){

          break;

        }

        U& m_bd = m_b[d];
        m_bd = m_M.Sum( m_bd , m_M.Inverse( m_ai ) );
        m_a[i] = m_M.Zero();
        m_a_updated[i] = true;
        m_b_updated[d]++;
        m_set_d.erase( itr );

      }

    }

  }

  if( i_1 < i_ulim ){
    
    if( m_lazy_set_max[d_1] < u ){

      // この時d_1 < m_N_dになる。
      IntervalSetMax_Body( i_1 , i_ulim , d_1 , u );
      
    }
    
  }
  
  return;
  
}

template <typename U , typename Z_MODULE> inline void IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::IntervalSetMax_Body( const int& i_min , const int& i_ulim , const int& d , const U& u )
{

  U& m_bd = m_b[d];
  int& m_b_updated_d = m_b_updated[d];
  auto& m_set_d = m_set[d];
  
  for( int i = i_min ; i < i_ulim ; i++ ){

    if( m_a_updated[i] ){

      m_a_updated[i] = false;
      m_b_updated_d--;

    } else if( !( m_a[i] < u ) ){

      continue;

    } else {
      
      m_bd = m_M.Sum( move( m_bd ) , m_M.Inverse( m_a[i] ) );
      m_set_d.erase( { m_a[i] , i } );

    }

    m_set_d.insert( { m_a[i] = u , i } );
    m_bd = m_M.Sum( move( m_bd ) , m_a[i] );

  }

  return;
  
}

template <typename U , typename Z_MODULE> inline U IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::operator[]( const int& i ) { assert( 0 <= i && i < m_N ); return m_a_updated[i] ? m_lazy_set_max[i / m_N_sqrt] : m_a[i]; }
template <typename U , typename Z_MODULE> inline U IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::Get( const int& i ) { return operator[]( i ); }

template <typename U , typename Z_MODULE> inline U IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::IntervalSum( const int& i_start , const int& i_final )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int i_0 = min( d_0 * m_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1 * m_N_sqrt );
  
  U answer = m_M.Zero();

  if( i_min < i_0 ){

    // この時d_0 > 0になる。
    answer = IntervalSum_Body( i_min , i_0 , d_0 - 1 );
    
  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    // Z加群性を使った。
    answer = m_M.Sum( m_M.Sum( move( answer ) , m_b[d] ) , m_M.ScalarProduct( m_b_updated[d] , m_lazy_set_max[d] ) );

  }

  if( i_1 < i_ulim ){

    // この時d_1 < m_N_dになる。
    answer = m_M.Sum( move( answer ) , IntervalSum_Body( i_1 , i_ulim , d_1 ) );

  }

  return answer;
  
}

template <typename U , typename Z_MODULE> inline U IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>::IntervalSum_Body( const int& i_min , const int& i_ulim , const int& d )
{

  U answer = m_M.Zero();
  const U& m_lazy_set_max_d = m_lazy_set_max[d];
  
  for( int i = i_min ; i < i_ulim ; i++ ){

    answer = m_M.Sum( move( answer ) , m_a_updated[i] ? m_lazy_set_max_d : m_a[i] );

  }

  return answer;
  
}

template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>& sd ) { const int& N = sd.size(); for( int i = 0 ; i < N ; i++ ){ ( i > 0 ? os << " " : os ) << sd[i]; } return os; }

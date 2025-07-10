// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Mo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Arithmetic/Sqrt/a_Body.hpp"

template <typename QUERY> inline Mo::Mo( const QUERY& query , int y_dif_sqrt ) : Mo() { Set( query , y_dif_sqrt ); }

template <typename QUERY> inline void Mo::Set( const QUERY& query , int y_dif_sqrt )
{

  m_Q = query.size();

  if( m_Q > 0 ){

    auto [x_start,y_start] = query[0];
    int x_final = x_start;
    int y_final = y_start;

    for( int q = 1 ; q < m_Q ; q++ ){

      auto& [x,y] = query[q];
      x < x_start ? x_start = x : x_final < x ? x_final = x : x_final;
      y < y_start ? y_start = y : y_final < y ? y_final = y : y_final;

    }

    const int x_dif = x_final - x_start + 1;
    const int x_div = x_dif / m_Q;
    const int y_dif = y_final - y_start + 1;
    y_dif_sqrt == 0 ? y_dif_sqrt = RoundUpSqrt( y_dif ) : y_dif_sqrt;
    m_query.resize( m_Y_d = y_dif / y_dif_sqrt + 1 );

    // ΔXとQ log_2 Qの比較を行ってソート方法を決定する。
    if( x_div < 31 && m_Q >> x_div > 0 ){

      BucketSort( query , x_start , x_dif , y_start , y_dif_sqrt );

    } else {

      IntroSort( query , y_start , y_dif_sqrt );

    }

  }

  return;

}

template <typename QUERY> inline void Mo::IntroSort( const QUERY& query , const int& y_start , const int& y_dif_sqrt )
{

  vector<tuple<int,int,int>> intro_sort( m_Q );
  
  for( int q = 0 ; q < m_Q ; q++ ){

    auto& [x,y] = query[q];
    intro_sort[q] = { x , y , q };
      
  }

  sort( intro_sort.begin() , intro_sort.end() );
  
  for( int i = 0 ; i < m_Q ; i++ ){

    auto& [x,y,q] = intro_sort[i];
    m_query[ ( y - y_start ) / y_dif_sqrt ].push_back( { x , y , q } );
      
  }
  
  return;

}

template <typename QUERY> inline void Mo::BucketSort( const QUERY& query , const int& x_start , const int& x_dif , const int& y_start , const int& y_dif_sqrt )
{

  vector<vector<int>> bucket_sort( x_dif );

  for( int q = 0 ; q < m_Q ; q++ ){

    bucket_sort[get<0>( query[q] ) - x_start].push_back( q );

  }
  
  for( int x = 0 ; x < x_dif ; x++ ){

    auto& bucket_x = bucket_sort[x];
    const int size = bucket_x.size();

    for( int i = 0 ; i < size ; i++ ){

      const int& q = bucket_x[i];
      auto& [x,y] = query[q];
      m_query[ ( y - y_start ) / y_dif_sqrt ].push_back( { x , y , q } );

    }
      
  }
  
  return;

}

inline const vector<vector<tuple<int,int,int>>>& Mo::Get() const noexcept { return m_query; }

template <typename F , typename DFxp , typename DFxm , typename DFyp , typename DFym , typename G> vector<decay_t<ret_t<G,ret_t<F,int,int>,int>>> Mo::Solve( F& f , DFxp& dfxp , DFxm& dfxm , DFyp& dfyp , DFym& dfym , G& g ) const
{

  using R1 = ret_t<F,int,int>;
  static_assert( is_invocable_r_v<R1,DFxp,R1,int,int,int> && is_invocable_r_v<R1,DFxm,R1,int,int,int> && is_invocable_r_v<R1,DFyp,R1,int,int,int> && is_invocable_r_v<R1,DFym,R1,int,int,int> );
  using R2 = decay_t<ret_t<G,const R1&,int>>;
  vector<R2> answer( m_Q );

  if( m_Q > 0 ){
    
    int d = 0;
  
    while( m_query[d].empty() ){

      d++;

    }

    auto [x,y,q] = m_query[d][0];
    R1 temp = f( x , y );
    answer[q] = g( temp , q );
    Solve_Body( answer , temp , x , y , dfxp , dfxm , dfyp , dfym , d , 1 , g );

    while( ++d < m_Y_d ){

      Solve_Body( answer , temp , x , y , dfxp , dfxm , dfyp , dfym , d , 0 , g );

    }

  }

  return answer;

}

template <typename F , typename DFxp , typename DFxm , typename DFyp , typename DFym> inline vector<ret_t<F,int,int>> Mo::Solve( F& f , DFxp& dfxp , DFxm& dfxm , DFyp& dfyp , DFym& dfym ) const { using R = ret_t<F,int,int>; auto id = [&]( R r , const int& ) { return move( r ); }; return Solve( f , dfxp , dfxm , dfyp , dfym , id ); }

template <typename R , typename DFxp , typename DFxm , typename DFyp , typename DFym , typename G> void Mo::Solve_Body( vector<R>& answer , R& temp , int& x , int& y , DFxp& dfxp , DFxm& dfxm , DFyp& dfyp , DFym& dfym , const int& d , const int& i_start , G& g ) const
{

  auto& m_query_d = m_query[d];
  const int size = m_query_d.size();
  
  for( int i = i_start ; i < size ; i++ ){

    auto& [x_next,y_next,q] = m_query_d[i];

    if( x < x_next ){
      
      temp = dfxp( move( temp ) , x , y , x_next );
    
    } else if( x > x_next ){

      temp = dfxm( move( temp ) , x , y , x_next );

    }

    x = x_next;

    if( y < y_next ){
      
      temp = dfyp( move( temp ) , x , y , y_next );
    
    } else if( y > y_next ){

      temp = dfym( move( temp ) , x , y , y_next );

    }
    
    y = y_next;
    answer[q] = g( temp , q );

  }

  return;

}

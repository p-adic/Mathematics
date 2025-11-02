// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/AlgebraicGeneration/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Group/a_Body.hpp"
#include "../../Utility/Set/Map/a_Body.hpp"

template <typename MONOID , typename GROUP , typename FUNC , typename U> template <typename V>
AlgebraicGenerator<MONOID,GROUP,FUNC,U>::AlgebraicGenerator( MONOID M , GROUP G , FUNC f , const vector<V>& gen , const int& len ) : m_M( move( M ) ) , m_G( move( G ) ) , m_f( move( f ) ) , m_div( 2 ) , m_len() , m_len_max( len )
{

  static_assert( is_same_v<inner_t<MONOID>,U> && is_same_v<inner_t<GROUP>,U> && is_invocable_r_v<U,FUNC,const U&> && is_constructible_v<U,V> );
  assert( len >= 1 );
  const U& one = m_M.One();
  m_div[0][one] = {one,one};
  m_len[one];

  for( auto& s : gen ){

    if( s != one ){

      m_div[1][s] = {s,one};
      m_len[s] = 1;

    }

  }

  for( int l = 2 ; l <= m_len_max ; l++ ){

    m_div.push_back( {} );

    for( auto& [s,q] : m_div[1] ){

      for( auto& [u,p] : m_div[l-1] ){

        const U su = m_M.Product( s , u );

        if( m_len.count( su ) == 0 ){

          m_len[su] = l;
          m_div[l][su] = {s,u};

        }

      }

    }

  }

}

template <typename MONOID , typename GROUP , typename FUNC , typename U>
tuple<bool,vector<U>,vector<U>> AlgebraicGenerator<MONOID,GROUP,FUNC,U>::Express( const U& u , const bool& opt_max )
{

  int l0 = 0 , l_opt = -1;
  vector<vector<U>> v = {{},{}};

  while( l0 <= m_len_max && ( l_opt == -1 || l0 < l_opt ) ){
  	
    for( auto& [u0,p0] : m_div[l0] ){

      const U u1 = m_G.Product( m_G.Inverse( m_f( u0 ) ) , u );

      if( m_len.count( u1 ) > 0 ){

        auto& l1 = m_len[u1];

        if( l_opt == -1 || ( opt_max ? l1 : l0 + l1 ) < l_opt ){

          l_opt = max(l0,l1);
          v = {{u0},{u1}};

        }

      }

    }

    l0++;
    
  }

  if( l_opt != -1 ){

    for( auto& vi : v ){

      while( !vi.empty() ){

       auto& p = vi.back();
       auto& m = m_len[p];

       if( m > 1 ){

         auto& [p0,p1] = m_div[m][p];
         p = p0;
         vi.push_back( p1 );

       } else if( m == 0 ){

         vi.pop_back();

       } else {

         break;

       }

     }
     
   
   }
   
 }

 return {l_opt!=-1,move(v[0]),move(v[1])};

}

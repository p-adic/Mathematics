// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/a_Body.hpp

#pragma once
#include "a.hpp"

// FloorSumCompositionに使う。
#include "../../Polynomial/Cumulative/a_Body.hpp"
#include "../../Arithmetic/Mod/Function/Residue/a_Body.hpp"
#include "../../Arithmetic/IteratedArithmetic/Constexpr/Log/a_Body.hpp"

template <typename INT>
INT FloorSum( const INT& y , const INT& d , const INT& q , const INT& n )
{

  if( n == 0 ){

    return 0;
    
  } else if( n == 1 ){

    return Quotient( y , q );

  }

  // q=1の時value_lim=0となり再帰が終了する。
  const INT r_0 = Modulo( y , q );
  const INT r_1 = Modulo( d , q );
  const INT value_lim = Quotient( r_0 + r_1 * n , q );
  INT answer = Quotient( y , q ) * n + Quotient( d , q ) * ( n >> 1 ) * ( n - ( ( n & 1 ) ^ 1 ) );
  
  if( value_lim != 0 ){

    const INT r_1_n_approx = value_lim * q - r_0;
    const INT e = Modulo( r_1_n_approx , r_1 );
    // r_1 == 0と仮定するとvalue_lim == r_0 / qすなわちvalue_lim == 0となり矛盾する。
    // (d,q)->(q,r_1)はユークリッドの互除法なのでO(log_2 min(d,q))回の再帰となる。
    answer += ( n - Quotient( r_1_n_approx + ( r_1 - 1 ) , r_1 ) ) * value_lim + FloorSum<INT>( e == 0 ? 0 : r_1 - e , q , r_1 , value_lim );
    
  }
  
  return answer;
  
}

template <typename T , typename INT , int deg_max>
const vector<vector<T>>& FloorSumComposition_Body( const INT& y , const INT& d , const INT& q , const INT& n , const int& D01 , const bool& init )
{
  
  static Map<tuple<INT,INT,INT,INT>,vector<vector<T>>> memory{};

  if( init ){

    memory.clear();

  }
  
  auto& answer = memory[{y,d,q,n}];

  if( int( answer.size() ) < D01 ){

    assert( q > 0 && n >=0 && D01 <= deg_max + 1 );
    const T& one = T::one();
    static vector<Polynomial<T>> s{};

    // 累積和多項式の係数sの前計算O(D01^2 log_2 D01)
    while( int( s.size() ) < D01 ){

      const int j = s.size();
      s.push_back( MonomialSum<T,deg_max>( j ) );

      if( j != 0 ){

        // Sn[j]でn-1までの和を考えるためn^jの分を差し引く。
        // ただしj=0の時は0^0=1の分と打ち消し合う。
        s[j][j] -= one;

      }
    
    }

    const T& zero = T::zero();
    static vector<vector<T>> coef_prep{};

    // 再帰係数coefの前計算に使うcoef_prepの前計算O(D01^3)／前計算済みか確認O(D01)
    for( int k = 0 ; k < D01 ; k++ ){

      if( int( coef_prep.size() ) <= k ){

        coef_prep.push_back( vector<T>( k , zero ) );

        for( int j1 = 0 ; j1 < k ; j1++ ){

          for( int j2 = j1 ; j2 < k ; j2++ ){

            coef_prep[k][j1] += T::FactorialInverse( k - j2 ) * T::FactorialInverse( j2 - j1 ) * ( ( k & 1 ) == ( j2 & 1 ) ? 1 : -1 );

          }

          coef_prep[k][j1] *= T::Factorial( k ) * T::FactorialInverse( j1 );

        }

      }

    }

    static vector<vector<vector<vector<T>>>> coef{};

    // 再帰係数coefの前計算O(D01^4)／前計算済みか確認O(D01^2)
    for( int j = 0 ; j < D01 ; j++ ){

      if( int( coef.size() ) <= j ){

        coef.push_back( vector<vector<vector<T>>>() );

      }

      const int k_ulim = D01 - j;
    
      for( int k = 0 ; k < k_ulim ; k++ ){

        if( int( coef[j].size() ) <= k ){

          coef[j].push_back( vector( k , vector<T>( j + 2 , zero ) ) );

          auto& coef_jk = coef[j][k];

          for( int j1 = 0 ; j1 < k ; j1++ ){

            for( int k1 = 0 ; k1 < j + 2 ; k1++ ){

              coef_jk[j1][k1] = coef_prep[k][j1] * s[j][k1];
          
            }

          }

        }

      }

    }
  
    const T n_mod{ n };
    vector<T> Sn( D01 , zero );
  
    // 累積和多項式の値Snの計算O(D01^2)
    for( int j = 0 ; j < D01 ; j++ ){

      Sn[j] = s[j]( n_mod );

    }

    const INT d_0 = Modulo( d , q );
    vector temp( D01 , vector<T>() );

    if( d_0 == 0 ){

      for( int j = 0 ; j < D01 ; j++ ){

        temp[j] = vector<T>( D01 - j , zero );
        temp[j][0] = Sn[j];

      }

    } else if( n != 0 ){

      const INT y_0 = Modulo( y , q );
      const INT m = ( y_0 + d_0 * ( n - 1 ) ) / q;
      const T m_mod{ m };
      vector<T> m_power( D01 , one );

      // mの冪乗m_powerの計算O(D01)
      for( int k = 1 ; k < D01 ; k++ ){

        m_power[k] = m_power[k-1] * m_mod;

      }

      // 再帰深度O(log_2 min(d,q))
      const auto& prev = FloorSumComposition_Body<T,INT,deg_max>( q + d_0 - y_0 - 1 , q , d_0 , m , D01 , false );

      // 再帰式の計算O(D01^4)
      for( int j = 0 ; j < D01 ; j++ ){

        const int k_ulim = D01 - j;
        temp[j] = vector<T>( k_ulim , zero );
      
        for( int k = 0 ; k < k_ulim ; k++ ){

          temp[j][k] = Sn[j] * m_power[k];

          for( int j1 = 0 ; j1 <= k - 1 ; j1++ ){
        
            for( int k1 = 0 ; k1 <= j + 1 ; k1++ ){
        
              temp[j][k] += prev[j1][k1] * coef[j][k][j1][k1];

            }

          }
      
        }

      }

    }

    const T d_1{ Quotient( d , q ) };
    const T y_1{ Quotient( y , q ) };

    // (y,d) ->(y_0,d_0)への帰着O(D01^4)
    for( int j = 0 ; j < D01 ; j++ ){

      if( int( answer.size() ) <= j ){

        answer.push_back( vector<T>() );

      }

      const int k_ulim = D01 - j;

      for( int k = 0 ; k < k_ulim ; k++ ){

        if( int( answer[j].size() ) <= k ){

          answer[j].push_back( zero );

          if( n != 0 ){
            
            T y_1_power = one;

            for( int k1 = 0 ; k1 <= k ; k1++ ){

              const int k2_max = k - k1;
              T d_1_power = one;

              for( int k2 = 0 ; k2 <= k2_max ; k2++ ){

                answer[j][k] += temp[j+k2][k-k1-k2] * T::FactorialInverse( k2 ) * T::FactorialInverse( k1 ) * T::FactorialInverse( k - k1 - k2 ) * y_1_power * d_1_power;
                d_1_power *= d_1;

              }

              y_1_power *= y_1;

            }

            answer[j][k] *= T::Factorial( k );

          }

        }

      }

    }

  }

  // 前計算合計O(D01^4))
  // 再帰計算合計O(D01^4 log_2 min(d,q))
  return answer;

}

template <typename T , typename INT , int deg_max> T FloorSumComposition( const INT& y , const INT& d , const INT& q , const INT& n , const vector<vector<T>>& f )
{

  const int D0 = f.size();
  int D01 = 0;

  for( int j = 0 ; j < D0 ; j++ ){

    D01 = max( D01 , j + int( f[j].size() ) );

  }

  auto& coef = FloorSumComposition_Body<T,INT,deg_max>( y , d , q , n , D01 , true );
  T answer{};

  for( int j = 0 ; j < D0 ; j++ ){

    const int D1 = f[j].size();
    
    for( int k = 0 ; k < D1 ; k++ ){

      answer += f[j][k] * coef[j][k];

    }

  }

  return answer;

}

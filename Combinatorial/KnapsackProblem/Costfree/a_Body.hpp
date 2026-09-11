// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Algebra/Monoid/a_Body.hpp"
#include "../../../Utility/BinarySearch/a_Body.hpp"

template <typename INT>
INT CostfreeKnapsackSmallValues( const int& N , const vector<INT>& value , const INT& value_bound , const INT& value_sum_bound )
{

  INT sum = 0;
  int i = -1;

  while( ++i < N ){

    // value_boundの定義はvalue_sum_bound以下のvalueの最大値であることに注意。
    // 以下価値value_boundより大きいものは価値0とみなす。
    if( value[i] > value_bound ){

      continue;

    }

    if( sum + value[i] > value_sum_bound ){
        
        break;

    }

    sum += value[i];
      
  }

  if( i == N ){

    return sum;

  }

  const INT value_bound2 = value_bound << 1;
  // 価値の総和vが(value_sum_bound - value_bound,value_sum_bound + value_bound]に
  // 属すような選択方法のうち、まず項目0,...,i-1を全て選択しその後
  // (1) value_sum_bound < vである場合に0,...,i-1のいずれかの削除をする。
  // (2) v <= value_sum_boundである場合にi,...,N-1のいずれかの追加をする。
  // という操作のみからなる操作列oprで得られるもの全体を考える。
  // 各oprに対し選択情報が更新されたi未満の項目番号の下限（存在しなければi-1）を
  // updated_num_min[opr]と置いた時、vごとにoprを渡らせた時の
  // updated_num_min[opr]の最大値を
  // u_v := u[v - ( value_sum_bound - value_bound + 1 )]
  // に格納して管理する。ただしvを実現するoprが存在しない場合はu_vを-1か0で定める。
  // 特にu_v>=0である場合、u_v未満の番号に対応する項目が全て選択されているままの
  // 操作列optがvに対し構成できていることになる。
  vector<INT> u( value_bound , -1 );
  // 削除ステップの更新の都合、削除ステップに影響する添字だけ0に変更。
  u.resize( value_bound2 );
  // sumは0,...,i-1までの価値の総和（oprは空の操作）でありi-1が格納される。
  u[sum - ( value_sum_bound - value_bound + 1 )] = --i;
  
  while( ++i < N ){

    if( value[i] > value_bound ){

      continue;

    }

    auto u_prev = u;
    
    // 項目iの追加ステップ。
    for( INT v = 0 ; v < value_bound ; v++ ){

      auto& u_v_i = u[v + value[i]];
      // 項目iを追加した場合の更新番号の最大値と元の更新番号の最大値で比較。
      u_v_i = max( u_v_i , u_prev[v] );

    }

    // 削除ステップ。
    // 価値の総和がvalue_sum_bound - value_bound以下の選択に項目iを追加する操作を
    // 削除ステップで実現するためにvを逆順に探索する。
    for( INT v = value_bound2 - 1 ; v >= value_bound ; v-- ){

      auto& j_ulim = u[v];

      // u[v]未満の各jに対応する項目が全て選択される操作列が存在しているが、
      // そこからu_v未満の各jに対応する項目を好きなだけ削除して得られる操作列を考える。
      // ただしj < u_prev[v]の時、u_prev[v]の構成時に用いた操作列から項目jを削除した
      // 操作列oprを考えると
      // updated_num_max[opr] = j
      // となるので、u[v - value[j]]がjとなる場合は過去の削除ステップで既に
      // u_prev[v - value[j]]がj以上となっている。従ってjはu[v]以上の範囲だけ探索すれば良い。
      for( INT j = u_prev[v] ; j < j_ulim ; j++ ){

        if( value[j] > value_bound ){

          continue;

        }

        auto& u_v_j = u[v - value[j]];
        u_v_j = max( u_v_j , j );

      }
      
    }

  }

  // sumの定義からv >= 0に辿り着く間にuの非自明成分が見付かるので、
  // INTがunsignedでも問題ない。
  for( INT v = value_bound - 1 ; v >= 0 ; v-- ){

    if( u[v] != -1 ){

      return v + ( value_sum_bound - value_bound + 1 );

    }

  }
  
  abort();
  return -1;

}

template <typename U , typename COMM_MONOID>
U AbstractCostfreeKnapsackSmallItems( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound )
{

  const int N = value.size();
  const U& one = M.One();
  U answer = one;

  if( N == 1 ){

    if( !( value_sum_bound < value[0] ) ){
      
      answer = value[0];

    }

  } else if( N > 1 ){

    const int N_half_left = N >> 1;
    const int N_half_right = N - N_half_left;
    unordered_map<int,int> valuation{};

    for( int i = 0 ; i < N_half_right ; i++ ){

      valuation[1<<i] = i;

    }
    
    const int power_left = 1 << N_half_left;
    vector<U> value_sum_left( power_left , one );

    for( int s = 1 ; s < power_left ; s++ ){

      const int lsb = s & -s;
      value_sum_left[s] = M.Product( value_sum_left[s ^ lsb] , value[valuation[lsb]] );

    }

    const int power_right = 1 << N_half_right;
    vector<U> value_sum_right( power_right , one );

    for( int s = 1 ; s < power_right ; s++ ){

      const int lsb = s & -s;
      value_sum_right[s] = M.Product( value_sum_right[s ^ lsb] , value[N_half_left + valuation[lsb]] );

    }

    sort( value_sum_right.begin() , value_sum_right.end() );

    for( int s = 0 ; s < power_left ; s++ ){

      auto& value_sum_left_s = value_sum_left[s];

      if( !( value_sum_bound < value_sum_left_s ) ){
	
        MAX_LEQ( t , 0 , power_right - 1 , M.Product( value_sum_left_s , value_sum_right[t] ) , value_sum_bound );
        answer = max( answer , M.Product( value_sum_left_s , value_sum_right[t] ) );

      }

    }
    
  }

  return answer;
  
}

template <typename INT> inline INT CostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound ) { INT value_bound = 0; for( auto& v : value ){ assert( 0 <= v ); if( v <= value_sum_bound ){ value_bound = max( value_bound , v ); } } const int N = value.size(); return N >= 60 || value_bound >> ( N >> 1 ) == 0 ? CostfreeKnapsackSmallValues( N , value , value_bound , value_sum_bound ) : AbstractCostfreeKnapsackSmallItems( AdditiveMonoid<INT>() , value , value_sum_bound ); }


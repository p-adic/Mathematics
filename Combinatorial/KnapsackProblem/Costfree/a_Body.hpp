// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Algebra/Monoid/a_Body.hpp"

template <typename INT>
INT CostfreeKnapsackFewValues( const int& N , const vector<INT>& value , const INT& value_bound , const INT& value_sum_bound )
{

  INT answer = 0;
  int i = -1;

  while( ++i < N && answer <= value_sum_bound ){

    auto& value_i = value[i];
    assert( 0 <= value_i && value_i <= value_bound );
    answer += value[i];

  }

  if( i == N ){

    return answer;

  }

  const INT value_bound2 = value_bound << 1;
  // ���l�̑��av��(value_sum_bound - value_bound,value_sum_bound + value_bound]��
  // �����悤�ȑI����@�̂����A�܂�����0,...,i-1��S�đI�������̌�
  // (1) value_sum_bound < v�ł���ꍇ��0,...,i-1�̂����ꂩ�̍폜������B
  // (2) v <= value_sum_bound�ł���ꍇ��i,...,N-1�̂����ꂩ�̒ǉ�������B
  // �Ƃ�������݂̂���Ȃ鑀���opr�œ�������̑S�̂��l����B
  // �eopr�ɑ΂��I����񂪍X�V���ꂽi�����̍��ڔԍ��̉����i���݂��Ȃ����i-1�j��
  // updated_num_min[opr]�ƒu�������Av���Ƃ�opr��n�点������updated_num_min[opr]�̍ő�l��
  // u_v := u[v - ( value_sum_bound - value_bound + 1 )]
  // �Ɋi�[���ĊǗ�����B������v����������opr�����݂��Ȃ��ꍇ��u_v��-1��0�Œ�߂�B
  // ����u_v>=0�ł���ꍇ�Au_v�����̔ԍ��ɑΉ����鍀�ڂ��S�đ����I����@���\���ł��Ă��邱�ƂɂȂ�B
  vector<INT> u( value_bound2 , -1 );

  for( INT v = value_bound ; v < value_bound2 ; v++ ){

    // �폜�X�e�b�v�̍X�V�̓s���A�폜�X�e�b�v�ɉe������Y������0�ɕύX�B
    u[v] = 0;

  }

  // answer - value[i]��0,...,i-1�܂ł̉��l�̑��a�iopr�͋�̑���j�ł���i-1���i�[�����B
  u[answer -= value[i-1] + ( value_sum_bound - value_bound + 1 )] = i - 1;
  
  while( ++i < N ){

    auto& value_i = value[i];
    assert( 0 <= value_i && value_i <= value_bound );
    auto u_prev = u;
    
    // ����i�̒ǉ��X�e�b�v�B
    for( INT v = 0 ; v < value_bound ; v++ ){

      auto& u_v_i = u[v + value_i];
      // ����i��ǉ������ꍇ�̍X�V�ԍ��̍ő�l�ƌ��̍X�V�ԍ��̍ő�l�Ŕ�r�B
      u_v_i = max( u_v_i , u_prev[v] );

    }

    // �폜�X�e�b�v�B
    // ���l�̑��a��value_sum_bound - value_bound�ȉ��̑I���ɍ���i��ǉ����鑀���
    // �폜�X�e�b�v�Ŏ������邽�߂�v���t���ɒT������B
    for( INT v = value_bound2 - 1 ; v >= value_bound ; v-- ){

      auto& j_ulim = u[v];

      // u[v]�����̊ej�ɑΉ����鍀�ڂ��S�đI������鑀��񂪑��݂��Ă��邪�A
      // ��������u_v�����̊ej�ɑΉ����鍀�ڂ��D���Ȃ����폜���ē����鑀�����l����B
      // ������j < u_prev[v]�̎��Au_prev[v]�̍\�����ɗp��������񂩂獀��j���폜����
      // �����opr���l�����
      // updated_num_max[opr] = j
      // �ƂȂ�̂ŁAu[v - value[j]]��j�ƂȂ�ꍇ�͉ߋ��̍폜�X�e�b�v�Ŋ���
      // u_prev[v - value[j]]��j�ȏ�ƂȂ��Ă���B�]����j��u[v]�ȏ�͈̔͂����T������Ηǂ��B
      for( INT j = u_prev[v] ; j < j_ulim ; j++ ){

	auto& u_v_j = u[v - value[j]];
	u_v_j = max( u_v_j , j );

      }
      
    }

  }

  // answer�̒�`����v >= 0�ɒH�蒅���Ԃ�u�̔񎩖����������t����̂ŁAINT��unsigned�ł����Ȃ��B
  for( INT v = value_bound - 1 ; v >= 0 ; v-- ){

    if( u[v] != -1 ){

      return v + ( value_sum_bound - value_bound + 1 );

    }

  }
  
  abort();
  return -1;

}

template <typename U , typename COMM_MONOID>
U AbstractCostfreeKnapsackFewItems( COMM_MONOID M , const vector<U>& value , const U& value_bound , const U& value_sum_bound )
{

  const int N = value.size();
  const U& one = M.One();
  assert( !( value_sum_bound < one ) );
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
      auto& value_sum_right_s = value_sum_right[s] = M.Product( value_sum_right[s ^ lsb] , value[N_half_left + valuation[lsb]] );
      value_sum_bound < value_sum_right_s ? value_sum_right_s = one : value_sum_right_s;

    }

    sort( value_sum_right.begin() , value_sum_right.end() );

    for( int s = 0 ; s < power_left ; s++ ){

      auto& value_sum_left_s = value_sum_left[s];

      if( !( value_sum_bound < value_sum_left_s ) ){
	
	BS2( t , 0 , power_right - 1 , M.Product( value_sum_left_s , value_sum_right[t] ) , value_sum_bound );
	answer = max( answer , M.Product( value_sum_left_s , value_sum_right[t] ) );

      }

    }
    
  }

  return answer;
  
}

template <typename INT> inline INT CostfreeKnapsack( const vector<INT>& value , const INT& value_bound , const INT& value_sum_bound ) { assert( 1 <= value_bound && value_bound <= value_sum_bound ); const int N = value.size(); return value_bound >> ( N >> 1 ) == 0 ? CostfreeKnapsackFewValues( N , value , value_bound , value_sum_bound ) : AbstractCostfreeKnapsackFewItems( AdditiveMonoid<INT>() , value , value_bound , value_sum_bound ); }


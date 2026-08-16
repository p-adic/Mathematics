// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/DigitCondition/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Utility/Tuple/Wrap/a_Body.hpp"

#include "../../Arithmetic/Iteration/a_Body.hpp"
#include "../../Utility/Vector/a_Body.hpp"

template <typename COND>
int MinimumDigitConditionWitnessBody( COND& cond , const int& r , const int& D , const int& base )
{

  static vector<int> memory{};

  if( memory.empty() ){

    const int power = Power<int>( base , D );
    memory.resize( power , -1 );
    int last = -1;

    for( int i = 0 ; i < power ; i++ ){

      if( cond( i ) ){

        for( int j = last + 1 ; j <= i ; j++ ){

          memory[j] = i - j;

        }

        last = i;

      }

    }

  }

  return memory.at( r );

}

template <typename COND> bool CheckDigitCondition( COND& cond , ll n , const int& D , const int& base )
{

  static const int power = Power<int>( base , D );

  if( MinimumDigitConditionWitnessBody( cond , n % power , D , base ) == 0 ){

    return true;

  }

  if( n < power ){

    return false;

  }

  return CheckDigitCondition( cond , move( n /= base ) , D , base );

}

template <typename RET , typename COND>
RET MinimumDigitConditionWitness( COND& cond , ll n , const int& D , const int& base , const bool& not_satisfy )
{

  if( !not_satisfy && CheckDigitCondition( cond , n , D , base ) ){

    return forward<RET>( n );

  }
  
  static const int power = Power<int>( base , D );
  const int memory = MinimumDigitConditionWitnessBody( cond , n % power , D , base );
  assert( memory != 0 );
  return memory == -1 ? MinimumDigitConditionWitness<RET>( cond , move( n /= base ) , D , base , true ) * base : forward<RET>( n += memory );

}

template <typename RET , typename COND>
vector<Pair<Pair<RET,ll>,Tuple<RET,RET,ll>>> MinimumDigitConditionWitnessSumBody( COND& cond , ll n , const int& D , const int& base , const int& power )
{

  const int q = power / base;
  vector<Pair<Pair<RET,ll>,Tuple<RET,RET,ll>>> answer( q );

  while( n >= 0 && n % power != power - 1 ){

    const int s = n % q;
      
    if( CheckDigitCondition( cond , n , D , base ) ){

      answer[s][O] += { RET{ n } , 1 };

    } else {

      answer[s][I] += { MinimumDigitConditionWitness<RET>( cond , n , D , base , true ) , RET{ n } , 1 };

    }
      
    n--;

  }

  if( n >= 0 ){

    const ll m = n / power;
    const RET aps = ArithmeticProgressionSum<RET>( m );
    auto b = MinimumDigitConditionWitnessSumBody<RET>( cond , move( n /= base ) , D , base , power );

    for( int i = 0 ; i < power ; i++ ){

      const int s = i % q , t = i / base , r = i % base , memory = MinimumDigitConditionWitnessBody( cond , i , D , base );
      
      if( memory == 0 ){

        answer[s][O] += { aps * power + ( m + 1 ) * i , m + 1 };

      } else {

        answer[s][O] += { b[t][O][O] * base + b[t][O][I] * r , b[t][O][I] };
        answer[s][I] += { memory == -1 ? b[t][I][O] * base : b[t][I][I] * base + b[t][I][II] * ( memory + r ) , b[t][I][I] * base + b[t][I][II] * r , b[t][I][II] };

      }

    }

  }
  
  return answer;

}

template <typename RET , typename COND>
Pair<RET,ll> MinimumDigitConditionWitnessSum( COND& cond , ll n , const int& D , const int& base )
{

  static const int power = Power<int>( base , D );
  auto v = MinimumDigitConditionWitnessSumBody<RET>( cond , move( n ) , D , base , power );
  Pair<RET,ll> answer{};

  for( auto& [v0,v1] : v ){

    auto& [s0,s1,c] = v1;
    answer += v0;
    answer += {s0,c};

  }
  
  return answer;

}


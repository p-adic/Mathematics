// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/VLArray/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "VLArray/a_Body.hpp"

inline void BijSum1N( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 ) { return BijSum1N( to_VLArray<dim>( N , infty() ) , n , n_1 , n_2 ); }
inline INT_TYPE_FOR_DIM BijSumN1( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 ) { return BijSumN1( to_VLArray<dim>( N , infty() ) , n_1 , n_2 ); }

inline VLArray<INT_TYPE_FOR_DIM> BijProd1N( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n ) { return BijProd1N( to_VLArray<dim>( N , infty() ) , n ); }
inline void BijProd1N( const INT_TYPE_FOR_DIM& N , const INT_TYPE_FOR_DIM& n , VLArray<INT_TYPE_FOR_DIM>& a_n ) { BijProd1N(to_VLArray<dim>( N , infty() ) , n , a_n ); }

inline INT_TYPE_FOR_DIM BijProdN1( const VLArray<INT_TYPE_FOR_DIM>& a_n ) { return BijProdN1( to_VLArray<dim>( a_n.size() , infty() ) , a_n ); }


template <typename INT> inline INT Factorial( const INT& n , const INT& n_min , const string& mode ) { return ModularFactorial<INT,INT>( n , n_min , mode ); }

template <typename INT1 , typename INT2> inline INT1 ModularFactorial( const INT2& n , const INT2& n_min , const string& mode ) { return mode == "loop" ? ModularFactorialLoopMethod<INT1,INT2>( n , n_min ) : ModularFactorialNormalMethod<INT1,INT2>( n , n_min ); }

template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod( const INT2& n )
{

  // const�Q�ƕԂ��Ȃ̂ŐÓIconst�ϐ���Ԃ��B
  if( n < 1 ){

    static const INT1 one = 1;
    return one;

  }
  
  static VLArray<INT2> memory_n{};
  static VLArray<INT1> memory_answer{};
  
  auto itr_n = memory_n.begin() , end_n = memory_n.end();
  auto itr_answer = memory_answer.begin();

  while( itr_n != end_n ){

    if( *itr_n == n ){

      return *itr_answer;
      
    }

    itr_n++;
    itr_answer++;

  }

  const INT1 answer = n * ModularFactorialNormalMethod<INT1,INT2>( n - 1 );
  memory_n.push_front( n );
  memory_answer.push_front( answer );  
  return memory_answer.front();

}

template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod( const INT2& n , const INT2& n_min )
{

  if( n_min == 1 ){

    return ModularFactorialNormalMethod<INT1,INT2>( n );

  }

  return ModularFactorialNormalMethod_Body<INT1,INT2>( n , n_min );
  
}

template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod_Body( const INT2& n , const INT2& n_min )
{
  
  // const�Q�ƕԂ��Ȃ̂ŐÓIconst�ϐ���Ԃ��B
  if( n < n_min ){

    static const INT1 one = 1;
    return one;

  }

  static VLArray<INT2> memory_n{};
  static VLArray<VLArray<INT2> > memory_n_min{};
  static VLArray<VLArray<INT1> > memory_answer{};
  VLArray<INT2>* p_n_min = nullptr;
  VLArray<INT1>* p_answer = nullptr;
  
  auto itr_n = memory_n.begin() , end_n = memory_n.end();
  auto itr_n_min = memory_n_min.begin();
  auto itr_answer = memory_answer.begin();

  while( itr_n != end_n && p_n_min == nullptr ){

    if( *itr_n == n ){

      p_n_min = &( *itr_n_min );
      p_answer = &( *itr_answer );

    }

    itr_n++;
    itr_n_min++;
    itr_answer++;

  }

  if( p_n_min == nullptr ){

    memory_n.push_front( n );
    memory_n_min.push_front( VLArray<INT2>() );
    memory_answer.push_front( VLArray<INT1>() );
    p_n_min = &( memory_n_min.front() );
    p_answer = &( memory_answer.front() );

  }

  auto itr_n_min_current = p_n_min->begin() , end_n_min_current = p_n_min->end();
  auto itr_answer_current = p_answer->begin();

  while( itr_n_min_current != end_n_min_current ){

    if( *itr_n_min_current == n_min ){

      return *itr_answer_current;

    }

    itr_n_min_current++;
    itr_answer_current++;

  }

  const INT1 answer = ModularFactorialNormalMethod<INT1,INT2>( n , n_min + 1 ) * n_min;
  p_n_min->push_front( n_min );
  p_answer->push_front( answer );  
  return p_answer->front();

}

template <typename INT1 , typename INT2>
INT1 ModularFactorialLoopMethod( const INT2& n , const INT2& n_min )
{

  INT1 f = 1;

  for( INT2 i = n_min ; i <= n ; i++ ){

    f *= i;

  }

  return f;

}

template <typename INT1 , typename INT2> inline INT1 ModularFactorialInverse( const INT2& n , const INT2& n_min , const string& mode ) { return mode == "loop" ? ModularFactorialInverseLoopMethod<INT1,INT2>( n , n_min ) : ModularFactorialInverseNormalMethod<INT1,INT2>( n , n_min ); }

template <typename INT1 , typename INT2>
const INT1& ModularFactorialInverseNormalMethod( const INT2& n )
{

  // const�Q�ƕԂ��Ȃ̂ŐÓIconst�ϐ���Ԃ��B
  if( n < 1 ){

    static const INT1 one = 1;
    return one;

  }
  
  static VLArray<INT2> memory_n{};
  static VLArray<INT1> memory_answer{};

  auto itr_n = memory_n.begin() , end_n = memory_n.end();
  auto itr_answer = memory_answer.begin();

  while( itr_n != end_n ){

    if( *itr_n == n ){

      return *itr_answer;

    }

    itr_n++;
    itr_answer++;

  }

  const INT1 answer = ModularFactorialInverseNormalMethod<INT1,INT2>( n - 1 ) / n;
  memory_n.push_front( n );
  memory_answer.push_front( answer );  
  return memory_answer.front();

}

template <typename INT1 , typename INT2>
const INT1& ModularFactorialInverseNormalMethod( const INT2& n , const INT2& n_min )
{

  if( n_min == 1 ){

    return ModularFactorialInverseNormalMethod<INT1,INT2>( n );

  }

  return ModularFactorialInverseNormalMethod_Body<INT1,INT2>( n , n_min );

}

template <typename INT1 , typename INT2>
const INT1& ModularFactorialInverseNormalMethod_Body( const INT2& n , const INT2& n_min )
{
  
  // const�Q�ƕԂ��Ȃ̂ŐÓIconst�ϐ���Ԃ��B
  if( n < n_min ){

    static const INT1 one = 1;
    return one;

  }

  static VLArray<INT2> memory_n{};
  static VLArray<VLArray<INT2> > memory_n_min{};
  static VLArray<VLArray<INT1> > memory_answer{};
  VLArray<INT2>* p_n_min = nullptr;
  VLArray<INT1>* p_answer = nullptr;
  
  auto itr_n = memory_n.begin() , end_n = memory_n.end();
  auto itr_n_min = memory_n_min.begin();
  auto itr_answer = memory_answer.begin();

  while( itr_n != end_n && p_n_min == nullptr ){

    if( *itr_n == n ){

      p_n_min = &( *itr_n_min );
      p_answer = &( *itr_answer );

    }

    itr_n++;
    itr_n_min++;
    itr_answer++;

  }

  if( p_n_min == nullptr ){

    memory_n.push_front( n );
    memory_n_min.push_front( VLArray<INT2>() );
    memory_answer.push_front( VLArray<INT1>() );
    p_n_min = &( memory_n_min.front() );
    p_answer = &( memory_answer.front() );

  }

  auto itr_n_min_current = p_n_min->begin() , end_n_min_current = p_n_min->end();
  auto itr_answer_current = p_answer->begin();

  while( itr_n_min_current != end_n_min_current ){

    if( *itr_n_min_current == n_min ){

      return *itr_answer_current;

    }

    itr_n_min_current++;
    itr_answer_current++;

  }

  const INT1 answer = ModularFactorialInverseNormalMethod<INT1,INT2>( n , n_min + 1 ) / (INT1)n_min;
  p_n_min->push_front( n_min );
  p_answer->push_front( answer );  
  return p_answer->front();

}

template <typename INT1 , typename INT2>
INT1 ModularFactorialInverseLoopMethod( const INT2& n , const INT2& n_min )
{

  INT1 f = 1;

  for( INT2 i = n_min ; i <= n ; i++ ){

    f /= i;

  }

  return f;

}

template <typename INT>
INT Combination( const INT& n , const INT& m , const string& mode )
{

  if( n < m ){

    return 0;

  }

  if( mode == "loop" ){

    return CombinationLoopMethod<INT>( n , m );

  }

  if( mode == "factorial normal" ){

    return CombinationFactorialNormalMethod<INT>( n , m );

  }

  if( mode == "factorial loop" ){

    return CombinationFactorialLoopMethod<INT>( n , m );

  }

  if( mode == "modular factorial inverse normal" ){

    return CombinationModularFactorialInverseNormalMethod<INT>( n , m );

  }

  if( mode == "modular factorial inverse loop" ){

    return CombinationModularFactorialInverseLoopMethod<INT>( n , m );

  }

  return CombinationNormalMethod<INT>( n , m );

}

template <typename INT>
const INT& CombinationNormalMethod( const INT& n , const INT& m )
{

  // const�Q�ƕԂ��Ȃ̂ŐÓIconst�ϐ���Ԃ��B
  if( m == 0 ){

    static const INT one = 1;
    return one;

  }
  
  static VLArray<INT> memory_n{};
  static VLArray<VLArray<INT> > memory_m{};
  static VLArray<VLArray<INT> > memory_answer{};
  VLArray<INT>* p_m = nullptr;
  VLArray<INT>* p_answer = nullptr;

  auto itr_n = memory_n.begin() , end_n = memory_n.end();
  auto itr_m = memory_m.begin();
  auto itr_answer = memory_answer.begin();

  while( itr_n != end_n && p_m == nullptr ){

    if( *itr_n == n ){

      p_m = &( *itr_m );
      p_answer = &( *itr_answer );

    }

    itr_n++;
    itr_m++;
    itr_answer++;

  }

  if( p_m == nullptr ){

    memory_n.push_front( n );
    memory_m.push_front( VLArray<INT>() );
    memory_answer.push_front( VLArray<INT>() );
    p_m = &( memory_m.front() );
    p_answer = &( memory_answer.front() );

  }

  const INT size = p_m->size();

  // p_m�ɂ�{...,3,2,1}�Ɠ����Ă����̂�m <= size�̎���m�����t����B
  if( m <= size ){

    auto itr_m_current = p_m->begin() , end_m_current = p_m->end();
    auto itr_answer_current = p_answer->begin();

    while( itr_m_current != end_m_current ){

      if( *itr_m_current == m ){

	return *itr_answer_current;

      }

      itr_m_current++;
      itr_answer_current++;

    }

  }
  
  const INT answer = ( CombinationNormalMethod<INT>( n , m - 1 ) * ( n - m + 1 ) ) / m;
  p_m->push_front( m );
  p_answer->push_front( answer );  
  return p_answer->front();

}

template <typename INT>
INT CombinationLoopMethod( const INT& n , const INT& m )
{

  const INT m_comp = n - m;
  const INT m_copy = m_comp < m ? m_comp : m;
  INT answer = 1;

  for( INT i = 0 ; i < m_copy ; i++ ){

    answer *= ( n - i );
    answer /= i + 1;

  }
  
  return answer;

}

template <typename INT> inline INT CombinationFactorialNormalMethod( const INT& n , const INT& m ) { return Factorial<INT>( n , n - m + 1 , "normal" ) / Factorial<INT>( m , 1 , "normal" ); }

template <typename INT> inline INT CombinationFactorialLoopMethod( const INT& n , const INT& m ) { return Factorial<INT>( n , n - m + 1 , "loop" ) / Factorial<INT>( m , 1 , "loop" ); }

template <typename INT> inline INT CombinationModularFactorialInverseNormalMethod( const INT& n , const INT& m ) { return Factorial<INT>( n , n - m + 1 , "normal" ) * ModularFactorialInverse<INT,INT>( m , 1 , "normal" ); }

template <typename INT> inline INT CombinationModularFactorialInverseLoopMethod( const INT& n , const INT& m ) { return Factorial<INT>( n , n - m + 1 , "loop" ) * ModularFactorialInverse<INT,INT>( m , 1 , "loop" ); }


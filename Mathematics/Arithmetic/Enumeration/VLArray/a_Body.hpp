// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/VLArray/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "VLArray/a_Body.hpp"

inline void BijSum1N( const uint& N , const uint& n , uint& n_1 , uint& n_2 ) { return BijSum1N( to_VLArray<dim>( N , infty() ) , n , n_1 , n_2 ); }
inline uint BijSumN1( const uint& N , const uint& n_1 , const uint& n_2 ) { return BijSumN1( to_VLArray<dim>( N , infty() ) , n_1 , n_2 ); }

inline VLArray<uint> BijProd1N( const uint& N , const uint& n ) { return BijProd1N( to_VLArray<dim>( N , infty() ) , n ); }
inline void BijProd1N( const uint& N , const uint& n , VLArray<uint>& a_n ) { BijProd1N(to_VLArray<dim>( N , infty() ) , n , a_n ); }

inline uint BijProdN1( const VLArray<uint>& a_n ) { return BijProdN1( to_VLArray<dim>( a_n.size() , infty() ) , a_n ); }


template <typename INT> inline INT Factorial( const INT& n , const INT& n_min , const string& mode ) { return ModularFactorial<INT,INT>( n , n_min , mode ); }

template <typename INT1 , typename INT2> inline INT1 ModularFactorial( const INT2& n , const INT2& n_min , const string& mode ) { return mode == "loop" ? ModularFactorialLoopMethod<INT1,INT2>( n , n_min ) : ModularFactorialNormalMethod<INT1,INT2>( n , n_min ); }

template <typename INT1 , typename INT2>
const INT1& ModularFactorialNormalMethod( const INT2& n , const INT2& n_min )
{

  // const�Q�ƕԂ��Ȃ̂ŐÓIconst�ϐ���Ԃ��B
  if( n < n_min ){

    static const INT1 one = 1;
    return one;

  }
  
  if( n == n_min ){

    static VLArray<INT1> memory_n_min{};
    const INT1 n_min_copy = n_min;
    
    if( ! memory_n_min.empty() ){

      const INT1& memory_n_min_back = memory_n_min.back();
      
      if( memory_n_min_back == n_min_copy  ){

	return memory_n_min_back;

      }

    }

    memory_n_min.push_back( n_min_copy );
    return memory_n_min.back();

  }
  
  static VLArray<INT2> memory_n{};
  static VLArray<INT2> memory_n_min{};
  static VLArray<INT1> memory_answer{};

  auto itr_n = memory_n.begin() , end_n = memory_n.end();
  auto itr_n_min = memory_n_min.begin();
  auto itr_answer = memory_answer.begin();

  while( itr_n != end_n ){

    if( *itr_n == n && *itr_n_min == n_min ){

      return *itr_answer;

    }

    itr_n++;
    itr_n_min++;
    itr_answer++;

  }

  const INT1 answer = n_min == 1 ? n * ModularFactorialNormalMethod<INT1,INT2>( n - 1 ) : ModularFactorialNormalMethod<INT1,INT2>( n , n_min + 1 ) * n_min;
  memory_n.push_front( n );
  memory_n_min.push_front( n_min );
  memory_answer.push_front( answer );  
  return memory_answer.front();

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
const INT1& ModularFactorialInverseNormalMethod( const INT2& n , const INT2& n_min )
{

  // const�Q�ƕԂ��Ȃ̂ŐÓIconst�ϐ���Ԃ��B
  if( n < n_min ){

    static const INT1 one = 1;
    return one;

  }
  
  if( n == n_min ){

    static VLArray<INT1> memory_n_min_inv{};
    const INT1 n_min_inv_copy = 1 / (INT1)n_min;
    
    if( ! memory_n_min_inv.empty() ){

      const INT1& memory_n_min_inv_back = memory_n_min_inv.back();
      
      if( memory_n_min_inv_back == n_min_inv_copy  ){

	return memory_n_min_inv_back;

      }

    }

    memory_n_min_inv.push_back( n_min_inv_copy );
    return memory_n_min_inv.back();

  }
  
  static VLArray<INT2> memory_n{};
  static VLArray<INT2> memory_n_min{};
  static VLArray<INT1> memory_answer{};

  auto itr_n = memory_n.begin() , end_n = memory_n.end();
  auto itr_n_min = memory_n_min.begin();
  auto itr_answer = memory_answer.begin();

  while( itr_n != end_n ){

    if( *itr_n == n && *itr_n_min == n_min ){

      return *itr_answer;

    }

    itr_n++;
    itr_n_min++;
    itr_answer++;

  }

  const INT1 answer = n_min == 1 ? ModularFactorialInverseNormalMethod<INT1,INT2>( n - 1 ) / n : ModularFactorialInverseNormalMethod<INT1,INT2>( n , n_min + 1 ) / n_min;
  memory_n.push_front( n );
  memory_n_min.push_front( n_min );
  memory_answer.push_front( answer );  
  return memory_answer.front();

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

  const INT m_comp = n - m;

  if( m_comp < m ){

    return Combination<INT>( n , m_comp , mode );

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
  static VLArray<INT> memory_m{};
  static VLArray<INT> memory_answer{};

  auto itr_n = memory_n.begin() , end_n = memory_n.end();
  auto itr_m = memory_m.begin();
  auto itr_answer = memory_answer.begin();

  while( itr_n != end_n ){

    if( *itr_n == n && *itr_m == m ){

      return *itr_answer;

    }

    itr_n++;
    itr_m++;
    itr_answer++;

  }

  const INT answer = ( CombinationNormalMethod<INT>( n , m - 1 ) * ( n - m + 1 ) ) / m;
  memory_n.push_front( n );
  memory_m.push_front( m );
  memory_answer.push_front( answer );  
  return memory_answer.front();

}

template <typename INT>
INT CombinationLoopMethod( const INT& n , const INT& m )
{

  INT c = 1;

  for( INT i = 0 ; i < m ; i++ ){

    c *= ( n - i );
    c /= i + 1;

  }
  
  return c;

}

template <typename INT> inline INT CombinationFactorialNormalMethod( const INT& n , const INT& m ) { return Factorial<INT>( n , n - m + 1 , "normal" ) / Factorial<INT>( m , 1 , "normal" ); }

template <typename INT> inline INT CombinationFactorialLoopMethod( const INT& n , const INT& m ) { return Factorial<INT>( n , n - m + 1 , "loop" ) / Factorial<INT>( m , 1 , "loop" ); }

template <typename INT> inline INT CombinationModularFactorialInverseNormalMethod( const INT& n , const INT& m ) { return Factorial<INT>( n , n - m + 1 , "normal" ) * ModularFactorialInverse<INT,INT>( m , 1 , "normal" ); }

template <typename INT> inline INT CombinationModularFactorialInverseLoopMethod( const INT& n , const INT& m ) { return Factorial<INT>( n , n - m + 1 , "loop" ) * ModularFactorialInverse<INT,INT>( m , 1 , "loop" ); }


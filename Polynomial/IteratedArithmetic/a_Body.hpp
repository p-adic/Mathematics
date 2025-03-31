// c:/Users/user/Documents/Programming/Mathematics/Polynomial/IteratedArithmetic/a_Body.hpp

#pragma once
// RationalSum/ProdÇ…égÇ§ÅB
#include "../../Arithmetic/a_Macro.hpp"
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , template <typename...> typename V>
Polynomial<T>& Sum( V<Polynomial<T>>& f )
{
  
  DEFIINTION_OF_PROD( Sum( f ) , Polynomial<T>::zero() , t += *itr );

}

template <typename T , template <typename...> typename V>
pair<Polynomial<T>,Polynomial<T>>& RationalSum( V<pair<Polynomial<T>,Polynomial<T>>>& f )
{
  
  DEFIINTION_OF_PROD( RationalSum( f ) , EXPRESSION1_FOR_RATIONAL_SUM , t = EXPRESSION2_FOR_RATIONAL_SUM );

}


template <typename T , template <typename...> typename V>
Polynomial<T>& Prod( V<Polynomial<T>>& f )
{

  DEFIINTION_OF_PROD( Prod( f ) , Polynomial<T>::one() , t += *itr );

}

template <typename T>
Polynomial<T> Power( Polynomial<T> f , int e )
{

  Polynomial<T> answer = Polynomial<T>::one();

  while( e > 0 ){

    ( e & 1 ) == 0 ? answer : answer *= f;
    f *= f;
    e >>= 1;

  }
  
  return answer;

}

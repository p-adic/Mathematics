// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/AlgebraicGeneration/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1130844 (+.+,*10000)

#include "../../Group/a.hpp"
#include "../../Utility/Set/Map/a.hpp"

template <typename MONOID , typename GROUP , typename FUNC , typename U = inner_t<MONOID>>
class AlgebraicGenerator
{

private:
  MONOID m_M;
  GROUP m_G;
  FUNC m_f;
  vector<Map<U,pair<U,U>>> m_div;
  Map<U,int> m_len;
  int m_len_max;

public:
  template <typename V> AlgebraicGenerator( MONOID M , GROUP G , FUNC f , const vector<V>& gen , const int& len );

  tuple<bool,vector<U>,vector<U>> Express( const U& u , const bool& opt_max );

};


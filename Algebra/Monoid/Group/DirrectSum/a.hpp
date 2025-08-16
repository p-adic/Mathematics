// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/DirrectSum/a.hpp

#pragma once
#include "../a.hpp"

template <typename U , typename GROUP>
class DirectSumGroup :
  virtual public VirtualGroup<pair<int,vector<U>>> ,
  public PointedSet<pair<int,vector<U>>>
{
private:
  GROUP m_G;
  int m_dim;
  // データ構造に渡す際にコピーしてしまうので局所変数にしない。
  const int* m_p_index;
  
public:
  inline DirectSumGroup( GROUP G , const int& index , const int& dim );
  inline pair<int,vector<U>> Transfer( const pair<int,vector<U>>& v );
  pair<int,vector<U>> Product( pair<int,vector<U>> v0 , const pair<int,vector<U>>& v1 );

  inline pair<int,vector<U>> Wrap( const int& index , const U& u ) const noexcept;

};
template <typename GROUP> DirectSumGroup( GROUP , const int& , const int& ) -> DirectSumGroup<inner_t<GROUP>,GROUP>;


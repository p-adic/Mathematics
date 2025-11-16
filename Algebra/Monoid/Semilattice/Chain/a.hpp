// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semilattice/Chain/a.hpp

#pragma once
#include "../a.hpp"

// 小さい方からm_length個の成分をマージする。
template <typename U>
class AscendingChainSemilattice :
  virtual public VirtualMeetSemilattice<vector<U>> ,
  public PointedSet<vector<U>>
{

private:
  int m_length;

public:
  inline AscendingChainSemilattice( int length = 2 );
  inline vector<U> Product( vector<U> a0 , const vector<U>& a1 );
  
};

// 大きい方からm_length個の成分をマージする。
template <typename U>
class DescendingChainSemilattice :
  virtual public VirtualMeetSemilattice<vector<U>> ,
  public PointedSet<vector<U>>
{

private:
  int m_length;

public:
  inline DescendingChainSemilattice( int length = 2 );
  inline vector<U> Product( vector<U> a0 , const vector<U>& a1 );
  
};


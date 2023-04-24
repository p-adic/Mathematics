// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/Monoid/a.hpp

#pragma once
#include "a_Macro.hpp"

// （可換とは限らない）モノイド(T,m_T:T^2->T,e_T:1->T)と非負整数Nをパラメータとする。
// 単位元による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// 区間積取得O(log_2 N)

// 一点更新O((log_2 N)^2)
// そのうちの区間積取得と一点更新は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法を一般のモノイドに拡張することで実装
template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT>
class MonoidBIT
{
private:
  T m_a[N];
  T m_fenwick_0[N + 1];
  T m_fenwick_1[N + 1];

public:
  static const T& g_e;

  inline MonoidBIT();
  inline MonoidBIT( const T ( &a )[N] );
  inline MonoidBIT( T ( &&a )[N] );

  inline const T& operator[]( const int& i ) const;
  inline const T& Get( const int& i ) const;
  T IntervalProduct( const int& i_start , const int& i_final );

  void Set( const int& i , const T& n );

};

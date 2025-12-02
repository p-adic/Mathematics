// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/IntervalSetMax/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1138062 (IntervalSetMax,Get)

#include "../Coordinate/a.hpp"

// 入力の範囲内で要件
// (1) Mがoperator<(const U&const U&)に関するUの全順序Z加群構造である。
// を満たす場合にのみサポート。

// M.Zero()による初期化O(N log N)
// 配列による初期化O(N log N)

// 一点取得O(1)
// M.Sum()に関する区間積取得O((N log N)^{1/2})

// 一点最大値更新O(log(N/log(N)))
// 区間最大値更新O((N log N)^{1/2})
template <typename U , typename Z_MODULE>
class IntervalSetMaxAbstractSqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  Z_MODULE m_M;
  vector<U> m_a;
  vector<U> m_b;
  U m_val_min;
  vector<U> m_lazy_set_max;
  vector<bool> m_a_updated;
  vector<int> m_b_updated;

  // m_lazy_set_max[d]より大きい成分をm_set[d]に格納する。
  vector<set<pair<U,int>>> m_set;
  
public:
  inline IntervalSetMaxAbstractSqrtDecomposition( const Z_MODULE& M , const U& val_min , const int& N = 0 );
  IntervalSetMaxAbstractSqrtDecomposition( Z_MODULE M , const U& val_min , vector<U> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void SetMax( const int& i , const U& u );
  inline void IntervalSetMax( const int& i_start , const int& i_final , const U& u );

  // 参照返しでないことに注意
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalSum( const int& i_start , const int& i_final );

private:
  IntervalSetMaxAbstractSqrtDecomposition( Z_MODULE& M , const U& val_min , const int& N , vector<U>& a );
  inline void IntervalSetMax_Body( const int& i_min , const int& i_ulim , const int& d , const U& u );
  inline U IntervalSum_Body( const int& i_min , const int& i_ulim , const int& d );
  
};
template <typename Z_MODULE , typename...Args> IntervalSetMaxAbstractSqrtDecomposition( Z_MODULE M , Args&&... args ) -> IntervalSetMaxAbstractSqrtDecomposition<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U>
class IntervalSetMaxSqrtDecomposition :
  public IntervalSetMaxAbstractSqrtDecomposition<U,Module<int,U>>
{

public:
  template <typename...Args> inline IntervalSetMaxSqrtDecomposition( Args&&... args );

};
template <typename U , typename...Args> IntervalSetMaxSqrtDecomposition( const U& val_min , Args&&... args ) -> IntervalSetMaxSqrtDecomposition<U>;

template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , IntervalSetMaxAbstractSqrtDecomposition<U,Z_MODULE>& sd );

// - 正則Z加群を乗せる時は
//   IntervalSetMaxSqrtDecomposition<ll> sd( ll( -1e18 ) , A );
// - AbstractModuleを乗せる時は
//   IntervalSetMaxAbstractSqrtDecomposition sd( AbstructModule( 0 , action , AbstractMonoid( product , unit ) ) , val_min , A );
// とすればよい。


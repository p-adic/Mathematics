// c:/Users/user/Documents/Programming/Mathematics/Analysis/Probability/Distribution/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1137281 (ExpectedSumSquare)

// 分布の和とスカラー倍を管理する型。
template <typename MODINT>
class Distribution
{

private:
  vector<MODINT> m_val;
  vector<MODINT> m_freq;

public:
  inline Distribution( vector<MODINT> val = {} , vector<MODINT> freq = {} );
  inline Distribution( const Distribution<MODINT>& d );

  inline Distribution<MODINT>& operator+=( const Distribution<MODINT>& d );
  inline Distribution<MODINT>& operator-=( const Distribution<MODINT>& d );
  inline Distribution<MODINT>& operator*=( const MODINT& c );
  inline Distribution<MODINT>& operator/=( const MODINT& c );

  inline Distribution<MODINT> operator+( const Distribution<MODINT>& d ) const;
  inline Distribution<MODINT> operator-( const Distribution<MODINT>& d ) const;
  inline Distribution<MODINT> operator*( const MODINT& c ) const;
  inline Distribution<MODINT> operator/( const MODINT& c ) const;

  template <typename INT = int> inline MODINT E( const INT& exponent = 1 ) const;
  inline MODINT V() const;

};

// 独立分布の和の二乗の期待値を求める。
template <typename MODINT> MODINT ExpectedSumSquare( const vector<Distribution<MODINT>>& d );

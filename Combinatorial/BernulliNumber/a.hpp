// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/BernulliNumber/a.hpp

#pragma once

// verify:https://judge.yosupo.jp/submission/176740

template <typename T , int length>
class BernulliNumberCalculator
{

private:
  // Bernulli数B_0=1, B_1=-1/2, B_2=1/6, ..., B_{length-1}を格納する。
  // negative = falseの場合はB_1のみ1/2に変更する。
  T m_val[length];

public:
  // 計算量O(length log length)で構築する。
  inline BernulliNumberCalculator( const bool& negative = true );
  inline const T& operator[]( const int& i ) const;

};

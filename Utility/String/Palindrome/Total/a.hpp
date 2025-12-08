// c:/Users/user/Documents/Programming/Mathematics/Utility/String/Palindrome/Total/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1139493 (count)

// 構築 O(N)
// 連続部分列の回文判定 O(1)
// 空でない連続部分回文の個数計算 O(N)
class TotalPalindrome
{

private:
  int m_N;
  vector<int> m_d;

public:
  template <typename STR> TotalPalindrome( const STR& S );

  inline bool IsPalindrome( const int& l , const int& r ) const noexcept;
  inline ll count() const noexcept;

};

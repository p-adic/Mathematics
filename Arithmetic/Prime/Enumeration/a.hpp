// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/971476（IsComposite）

// エラトステネスの篩 O(L log log L)
// 動的な素数列挙より計算量が悪いが除算を用いないので十分速い。

// m_lengthの値は
// val_limit = 316 -> 65
// val_limit = 10^3 -> 168
// val_limit = 10^4 -> 1229
// val_limit = 10^5 -> 9592
// val_limit = 2×10^5 -> 17984
// 以下コンパイル畤計算の上限回数262144を超過。非constexpr変数を初期化すればよい。
// val_limit = 316228 -> 27293（実行時間4[ms]）
// val_limit = 10^6 -> 78498（実行時間8[ms]）
// val_limit = 10^7 -> 664579（実行時間93[ms]）
// val_limit = 10^8 -> 5761455（実行時間2839[ms]）
template <int val_limit , int length_max = val_limit>
class PrimeEnumeration
{

private:
  bool m_is_composite[val_limit];
  int m_val[length_max];
  int m_length;

public:
  inline constexpr PrimeEnumeration();

  // 1+n個目の素数を返す。
  inline const int& operator[]( const int& i ) const;
  inline constexpr const int& Get( const int& i ) const;

  // length_max個目の素数までで割り切れる合成数であるか否かを判定する。
  inline constexpr const bool& IsComposite( const int& n ) const;

  // val_limit未満の素数の個数Pi(val_limit)を返す。
  inline constexpr const int& length() const noexcept;

};

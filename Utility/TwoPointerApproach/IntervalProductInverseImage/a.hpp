// c:/Users/user/Documents/Programming/Mathematics/Utility/TwoPointerApproach/IntervalProductInverseImage/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1131039 (Enumerate)

// オーバーフロー対策とメモリ節約で累積積を用いずに尺取り法で実装したもの。

// 入力の範囲内で要件
// (1) MがUのoperator<に関する全順序群構造である。
// (2) aの各成分がM.One()以上である。
// が成り立つ場合にのみサポート。

// Mに関する右区間積a[i]...a[j]（または左区間積a[j]...a[i]）がuと等しい区間[i,j]の個数を計算する。
template <typename GROUP , typename U> ll CountIntervalProductInverseImage( GROUP M , const vector<U>& a , const U& u , const bool& right = true );

// 追加で入力の範囲内で要件
// (2)' aの各成分がM.One()より大きい。
// が成り立つ場合にのみサポート。

// Mに関する右区間積a[i]...a[j]（または左区間積a[j]...a[i]）がuと等しい区間[i,j]をj昇順で列挙する。
template <typename GROUP , typename U> vector<pair<int,int>> EnumerateIntervalProductInverseImage( GROUP M , const vector<U>& a , const U& u , const bool& right = true );

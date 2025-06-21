// c:/Users/user/Documents/Programming/Mathematics/Utility/String/SuffixArray/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1100475

// https://qiita.com/izu_nori/items/3f4a32342fffb755ce5b
// をもとに実装。
// sの長さをNとし、s[i,i+2^d)の比較と整合的な番号付けをdoublingで計算していくことで
// O(N(log N)^2)でsuffix arrayを求める。
template <typename STR> vector<int> ManberMyers( const STR& s );

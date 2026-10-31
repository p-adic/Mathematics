// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Subsequence/Distinct/a.hpp

#pragma once

// https://yukicoder.me/problems/no/3566/editorial
// を参考に実装。

// 文字の種類数をCと置く。

// Sの連続とは限らない非空部分列と一致する列であって先頭がvalidであるものの種類数を部分列DPで
// O(C+S.size())で求める。
template <typename T , typename VEC , typename CHAR , typename VALID> T SubsequenceDP( const VEC& S , const CHAR& zero , const int& C , VALID valid );

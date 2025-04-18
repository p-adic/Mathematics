// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/PartitionNumber/a.hpp

#pragma once
// verify:
// PartitionNumberのpython版 (https://yukicoder.me/submissions/1021227)
// UpperBoundedPartitionNumber (https://yukicoder.me/submissions/1021223)


// n以下の非負整数iを正整数の昇順和に分割する個数をanswer[i]に格納する。（O(n^2)）
template <typename INT> vector<INT> PartitionNumber( const int& n );
// n以下の非負整数iをj以上の正整数の昇順和に分割する個数をanswer[i][j]に格納する。（O(n^2)）
template <typename INT> vector<vector<INT>> LowerBoundedPartitionNumber( const int& n );
// n以下の非負整数iをj以下の正整数の昇順和に分割する個数をanswer.first[i][j]に格納する。（O(n^2)）
template <typename INT> vector<vector<INT>> UpperBoundedPartitionNumber( const int& n );
// n以下の非負整数iを非負整数j個の昇順和に分割する個数や
// n以下の非負整数iを正整数j個以下の昇順和に分割する個数とも等しい。


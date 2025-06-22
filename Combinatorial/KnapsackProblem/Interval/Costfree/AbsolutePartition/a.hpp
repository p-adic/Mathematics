// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/Costfree/AbsolutePartition/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1100699

// 入力の範囲内で要件
// (1) INTは符号つき数の型である。
// を満たす場合にのみサポート。
// 計算量O(partition_size*N)でanswer[i]にvalueの長さiの始切片を高々partition_size個の
// 区間に分割した時の区間和の絶対和の最大値を格納する。
template <typename INT> vector<INT> MaximisationIntervalSumAbsoluteSum( const vector<INT>& value , const int& partition_size );
// 三角不等式より、i>=partition_sizeならば高々partition_size個とちょうどpartition_size個の
// 最大値は同じ。

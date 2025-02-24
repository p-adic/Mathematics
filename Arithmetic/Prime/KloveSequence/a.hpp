// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/KloveSequence/a.hpp

#pragma once


// ROBERT E. DRESSLER, SUMS OF DISTINCT PRIMES, Nordisk Matematisk Tidskrift, Vol. 21, No. 1 (1973), pp. 31--32.
// TORLEIV KLOVE, SUMS OF DISTINCT PRIMES, Nordisk Matematisk Tidskrift, Vol. 21, No. 4 (1974), pp. 138--140.
// をもとに実装。
// 1+i番目の素数以上の相異なる素数有限個の和で表せない最小の非負整数を返す。
uint GetKloveSequence( const uint& i ) noexcept;
// https://oeis.org/A007414
// [p(i),Klove(i)]:
// [2,6]
// [3,9]
// [5,27]
// [7,45]
// [11,45]
// [13,57]
// [17,75]
// [19,81]
// [23,87]
// [29,105] <- ここから非常に遅くなる。

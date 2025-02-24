// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/KloveSequence/a.hpp

#pragma once


// ROBERT E. DRESSLER, SUMS OF DISTINCT PRIMES, Nordisk Matematisk Tidskrift, Vol. 21, No. 1 (1973), pp. 31--32.
// TORLEIV KLOVE, SUMS OF DISTINCT PRIMES, Nordisk Matematisk Tidskrift, Vol. 21, No. 4 (1974), pp. 138--140.
// �����ƂɎ����B
// 1+i�Ԗڂ̑f���ȏ�̑��قȂ�f���L���̘a�ŕ\���Ȃ��ŏ��̔񕉐�����Ԃ��B
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
// [29,105] <- ����������ɒx���Ȃ�B

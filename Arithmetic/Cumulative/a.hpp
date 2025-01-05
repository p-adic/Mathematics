// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Cumulative/a.hpp

#pragma once
// verify:
// https://atcoder.jp/contests/abc379/submissions/61409472 (Sum, ArithmeticProgressionSum)

// M��T�̃��m�C�h�\���ł���ꍇ�ɂ̂݃T�|�[�g�B
// T�̗v�f�̗��M�Ɋւ��鑍��𕪊������Ōv�Z���A���̌��ʂ�Ԃ��B
// V<T>��erase�����K�v������B
template <typename T , template <typename...> typename V , typename MONOID> T MonoidalProd( MONOID M , V<T> f );
template <typename T , template <typename...> typename V> inline T Sum( V<T> f );
template <typename T , template <typename...> typename V> inline T Prod( V<T> f , T unit = 1 );

// ����l����d�̓��������r�ȉ��܂ł̑��a�����B
// 0 <= l , r <= 4e9�Ȃ��INT = ll�ŃI�[�o�[�t���[���������B
// 0 <= l , r <= 6e9�Ȃ��INT = ull�ŃI�[�o�[�t���[���������B
template <typename INT> inline INT ArithmeticProgressionSum( const INT& l , INT r , const INT& d = 1 );
template <typename INT> inline INT ArithmeticProgressionSum( const INT& r );

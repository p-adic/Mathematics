// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sum/a.hpp

#pragma once
// verify:
// https://atcoder.jp/contests/abc379/submissions/61409472 (Sum, ArithmeticProgressionSum)
// https://yukicoder.me/submissions/1015838 (GeometricProgressionLinearCombinationSum)

// f����łȂ��ꍇ�ɂ̂݃T�|�[�g�B
// T�̗v�f�̗��ope�Ɋւ��鍶�����I������𒼂Ɍv�Z���A���̌��ʂ�Ԃ��B
template <typename T , template <typename...> typename V , typename OPR> T LeftConnectiveProd( const V<T>& f , OPR opr );
template <typename T , template <typename...> typename V> inline T Sum( const V<T>& f );
template <typename T , template <typename...> typename V> inline T Prod( const V<T>& f );
template <typename T , template <typename...> typename V> inline T Max( const V<T>& f );
template <typename T , template <typename...> typename V> inline T Min( const V<T>& f );

// init * ( t ^ exponent )��Ԃ�
template <typename T , typename UINT> T Power( T t , UINT exponent , T init = 1 );


// ����l����d�̓��������r�ȉ��܂ł̑��a�����B
// 0 <= l , r <= 4e9�Ȃ��INT = ll�ŃI�[�o�[�t���[���������B
// 0 <= l , r <= 6e9�Ȃ��INT = ull�ŃI�[�o�[�t���[���������B
template <typename INT> inline INT ArithmeticProgressionSum( const INT& l , INT r , const INT& d = 1 );
template <typename INT> inline INT ArithmeticProgressionSum( const INT& r );


// ���͈͓͂̔��ŗv��
// (1) T��operator+,operator-,operator*�Ɋւ��ĒP�ʓI���Ȃ��B
// (2) exponent_max >= 0�ł���B
// (3) rate - 1��0�łȂ��Ȃ��(1)�̒P�ʓI�\���Ɋւ��ĉt�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ���䐔��init,init*rate,...,init*rate^exponent_max�̑��a��
// O((log exponent_max)+�t���v�Z��)�ŋ��߂�B
template <typename T , typename UINT> inline T GeometricProgressionSum( T rate , UINT exponent_max , const T& init = 1 );

// ���͈͓͂̔��Œǉ��̗v��
// (4) T{}��(1)�̒P�ʓI���\���Ɋւ��ĉ��@�I�P�ʌ��ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ���䐔��̐��`�a�̑��a��P�ɓ��䐔��̑��a�̐��`�a�Ƃ��ċ��߂�B
template <typename T , typename UINT>
T GeometricProgressionLinearCombinationSum( vector<T> rate , vector<UINT> exponent_max , const vector<T>& init );

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Iteration/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://atcoder.jp/contests/abc379/submissions/61409472 (Sum, ArithmeticProgressionSum<ll>)
// https://yukicoder.me/submissions/1064893 (ArithmeticProgressionSum<MP>)
// https://yukicoder.me/submissions/1065726 (GeometricProgression<MP>)
// https://yukicoder.me/submissions/1015838 (GeometricProgressionLinearCombinationSum<QuadraticExtension<MP>>)

// t��f��opr�Ɋւ��鍶�����I������𒼂Ɍv�Z���A���̌��ʂ�Ԃ��B
template <typename T , typename U , template <typename...> typename V , typename OPR> T LeftConnectiveProd( T t , const V<U>& f , OPR opr );
// Sum<ll>( vector<int>() )�Ȃǂ̍\���͂ł��Ȃ��̂ŁA�����Sum( 0LL , vector<int>() )���l����B
template <typename T , typename U , template <typename...> typename V> inline T Sum( const V<U>& f );
template <typename T , typename U , template <typename...> typename V> inline T Prod( const V<U>& f );

template <typename T> inline T& SetMax( T& n );
template <typename T , typename U , typename... Args> inline T& SetMax( T& t0 , const U& u1 , const Args&... args );
template <typename T> inline T& SetMin( T& n );
template <typename T , typename U , typename... Args> inline T& SetMin( T& t0 , const U& u1 , const Args&... args );
template <typename T , template <typename...> typename V> inline const T& Max( const V<T>& f );
template <typename T , typename U , typename...Args> inline T Max( T t0 , const U& t1 , const Args&... args );
template <typename T , template <typename...> typename V> inline const T& Min( const V<T>& f );
template <typename T , typename U , typename...Args> inline T Min( T t0 , const U& t1 , const Args&... args );

// init * ( t ^ exponent )��Ԃ�
template <typename T , typename UINT> T Power( const T& t , const UINT& exponent , T init = 1 );
template <typename T> inline T PowerMemorisation( const T& t , const int& exponent );


// ����l����d�̓��������r�ȉ��܂ł̑��a�����B
// 0 <= l , r <= 4e9�Ȃ��INT = ll�ŃI�[�o�[�t���[���������B
// 0 <= l , r <= 6e9�Ȃ��INT = ull�ŃI�[�o�[�t���[���������B
template <typename INT> inline INT ArithmeticProgressionSum( const INT& l , const INT& r , const INT& d = 1 );
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

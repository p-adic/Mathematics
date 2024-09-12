// c:/Users/user/Documents/Programming/Contest/ProblemCreation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "ExecuteSolution/a_Body.hpp"
#include "GenerateSamples/a_Body.hpp"
#include "RearrangeSamples/a_Body.hpp"
#include "WriteInSamples/a_Body.hpp"

// "../../Utility/StdStream/a_Body.hpp"��include�����B
#include "../../Utility/BinarySearch/a_Body.hpp"
#include "../../Utility/TwoPointerApproach/a_Body.hpp"

// �f�[�^�\���p
template <typename T> inline T Addition( const T& t0 , const T& t1 ) { return t0 + t1; }
template <typename T> inline T Xor( const T& t0 , const T& t1 ){ return t0 ^ t1; }
template <typename T> inline T Multiplication( const T& t0 , const T& t1 ) { return t0 * t1; }
template <typename T> inline const T& Zero() { static const T z{}; return z; }
template <typename T> inline const T& One() { static const T o = 1; return o; }
template <typename T> inline T AdditionInv( const T& t ) { return -t; }
template <typename T> inline T Id( const T& v ) { return v; }
template <typename T> inline T Min( const T& a , const T& b ){ return a < b ? a : b; }
template <typename T> inline T Max( const T& a , const T& b ){ return a < b ? b : a; }

// �f�o�b�O�p
inline void AlertAbort( int n ) { CERR( "abort�֐����Ă΂�܂����Bassert�}�N���̃��b�Z�[�W���o�͂���Ă��Ȃ��ꍇ�̓I�[�o�[�t���[�̗L�����m�F�����Ă��������B" ); }
void AutoCheck( int& exec_mode , const bool& use_getline );
inline void Solve();
inline void Experiment();
inline void SmallTest();
inline void RandomTest();
inline void BreakPoint( const int& LINE ) {}

#ifdef USE_GETLINE
  CEXPR( bool , use_getline , true );
#else
  CEXPR( bool , use_getline , false );
#endif

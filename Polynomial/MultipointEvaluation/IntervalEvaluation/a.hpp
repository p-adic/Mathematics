// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/IntervalEvaluation/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../a.hpp"

// deg < eval.size()�̎��̂݃T�|�[�g
// f(0),f(1),...,f(deg)��eval[0],eval[1],...,eval[deg]�ɓ�����deg���ȉ��̑�����f�ɑ΂��A
// f(t_start),f(t_start+1)...,f(t_start+length-1)��eval�Ɋi�[�������B
template <typename T>
void SetIntervalEvaluation( const int& deg , const T& t_start , const int& length , vector<T>& eval );

// deg < sample.size()�̎��̂݃T�|�[�g
// M(0),M(1),...,M(deg)��sample[0],sample[1],...,sample[deg]�ɓ�����deg���ȉ��̑������W���s��M�ɑ΂��A
// M(t_start),M(t_start+1)...,M(t_start+length-1)��eval�Ɋi�[����B
template <int Y , int X , typename T>
void SetIntervalEvaluation( const int& deg , const T& t_start , const int& length , const vector<Matrix<Y,X,T> >& sample , vector<Matrix<Y,X,T> >& eval );
template <typename T>
void SetIntervalEvaluation( const int& deg , const T& t_start , const int& length , const vector<TwoByTwoMatrix<T> >& sample , vector<TwoByTwoMatrix<T> >& eval );

// T��length�ȉ��̐��������t�ɂ���̂ł���ꍇ�̂݃T�|�[�g
// M(length-1) ... M(1) M(0) v�̌v�Z���ʂ�v�Ɋi�[�������B
template <int Y , typename T>
void SetPRecursiveMatrixAction( const Matrix<Y,Y,Polynomial<T> >& M , Matrix<Y,1,T>& v , const int& length );
template <typename T>
void SetPRecursiveMatrixAction( const TwoByTwoMatrix<Polynomial<T> >& M ,TwoByOneMatrix<T>& v , const int& length );

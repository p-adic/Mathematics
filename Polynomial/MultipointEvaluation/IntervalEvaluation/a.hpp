// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/IntervalEvaluation/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../a.hpp"

// deg < eval.size()の時のみサポート
// f(0),f(1),...,f(deg)がeval[0],eval[1],...,eval[deg]に等しいdeg次以下の多項式fに対し、
// f(t_start),f(t_start+1)...,f(t_start+length-1)をevalに格納し直す。
template <typename T>
void SetIntervalEvaluation( const int& deg , const T& t_start , const int& length , vector<T>& eval );

// deg < sample.size()の時のみサポート
// M(0),M(1),...,M(deg)がsample[0],sample[1],...,sample[deg]に等しいdeg次以下の多項式係数行列Mに対し、
// M(t_start),M(t_start+1)...,M(t_start+length-1)をevalに格納する。
template <int Y , int X , typename T>
void SetIntervalEvaluation( const int& deg , const T& t_start , const int& length , const vector<Matrix<Y,X,T> >& sample , vector<Matrix<Y,X,T> >& eval );
template <typename T>
void SetIntervalEvaluation( const int& deg , const T& t_start , const int& length , const vector<TwoByTwoMatrix<T> >& sample , vector<TwoByTwoMatrix<T> >& eval );

// Tがlength以下の正整数を可逆にする体である場合のみサポート
// M(length-1) ... M(1) M(0) vの計算結果をvに格納し直す。
template <int Y , typename T>
void SetPRecursiveMatrixAction( const Matrix<Y,Y,Polynomial<T> >& M , Matrix<Y,1,T>& v , const int& length );
template <typename T>
void SetPRecursiveMatrixAction( const TwoByTwoMatrix<Polynomial<T> >& M ,TwoByOneMatrix<T>& v , const int& length );

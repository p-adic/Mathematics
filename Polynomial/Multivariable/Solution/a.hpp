// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Multivariable/Solution/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Arithmetic/Mod/a.hpp"

// Pが素数である場合のみサポート
template <INT_TYPE_FOR_MOD P , int D>
void CheckSolvable( vector<MultivariablePolynomial<Mod<P>,D> >& F , bool& solvable );
template <INT_TYPE_FOR_MOD P , int D>
void CheckSolvableNoRedundantZero( vector<MultivariablePolynomial<Mod<P>,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<Mod<P> >& LC_F , int& size_F , bool& solvable );

template <INT_TYPE_FOR_MOD P , int D>
void Solve( vector<MultivariablePolynomial<Mod<P>,D> >& F , AffineSpace<Mod<P>,D>& x , bool& solvable );
template <INT_TYPE_FOR_MOD P , int D>
void SolveNoRedundantZero( vector<MultivariablePolynomial<Mod<P>,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<Mod<P> >& LC_F , int& size_F , AffineSpace<Mod<P>,D>& x , bool& solvable );

template <INT_TYPE_FOR_MOD P , int D>
void FindSolutionFromReducedGroebnerBasis( vector<MultivariablePolynomial<Mod<P>,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<Mod<P> >& LC_F , int& size_F , AffineSpace<Mod<P>,D>& x );

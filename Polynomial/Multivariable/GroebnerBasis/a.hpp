// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Multivariable/GroebnerBasis/a.hpp

#pragma once
#include "../a.hpp"

template <typename T , int D>
void DevideNoRedundantZero( MultivariablePolynomial<T,D>& f , const vector<MultivariablePolynomial<T,D> >& F );
template <typename T , int D>
void DevideNoRedundantZero( MultivariablePolynomial<T,D>& f , const vector<MultivariablePolynomial<T,D> >& F , const vector<MultivariablePolynomialIndex<D> >& LT_F , const vector<T>& LC_F );
template <typename T , int D>
void DevideNoRedundantZero( MultivariablePolynomial<T,D>& f , const vector<MultivariablePolynomial<T,D> >& F , const vector<MultivariablePolynomialIndex<D> >& LT_F , const vector<T>& LC_F , const vector<int>& use );


template <typename T , int D> inline auto LeadingTerm( MultivariablePolynomial<T,D>& f ) -> typename enable_if< equal_to<int>()( 0 , D ) , MultivariablePolynomialIndex<D> >::type;
template <typename T , int D> inline auto LeadingTerm( MultivariablePolynomial<T,D>& f ) -> typename enable_if< less_equal<int>()( 1 , D ) , MultivariablePolynomialIndex<D> >::type;
template <typename T , int D> inline auto LeadingTermNoRedundantZero( const MultivariablePolynomial<T,D>& f ) -> typename enable_if< equal_to<int>()( 0 , D ) , MultivariablePolynomialIndex<D> >::type;
template <typename T , int D> inline auto LeadingTermNoRedundantZero( const MultivariablePolynomial<T,D>& f ) -> typename enable_if< less_equal<int>()( 1 , D ) , MultivariablePolynomialIndex<D> >::type;


template <typename T , int D> 
void SetLeadingTermsNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<T>& LC_F , const int& size );


template <typename T , int D> inline MultivariablePolynomial<T,D> SMultivariablePolynomial( MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,D>& f1 );
template <typename T , int D>
MultivariablePolynomial<T,D> SMultivariablePolynomialNoRedundantZero( const MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,D>& f1 );
template <typename T , int D>
MultivariablePolynomial<T,D> SMultivariablePolynomialNoRedundantZero( const MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,D>& f1 , const MultivariablePolynomialIndex<D>& LT0 , const MultivariablePolynomialIndex<D>& LT1 , const T& LC0 , const T& LC1 );


template <typename T , int D>
vector<MultivariablePolynomial<T,D> > GroebnerBasis( vector<MultivariablePolynomial<T,D> >& F );
template <typename T , int D>
vector<MultivariablePolynomial<T,D> > GroebnerBasisNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F );
template <typename T , int D>
vector<MultivariablePolynomial<T,D> > GroebnerBasisNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<T>& LC_F , vector<int>& i_F , vector<int>& j_F , int& size );

template <typename T , int D>
vector<MultivariablePolynomial<T,D> > ReducedGroebnerBasis( vector<MultivariablePolynomial<T,D> >& F );
template <typename T , int D>
vector<MultivariablePolynomial<T,D> > ReducedGroebnerBasisNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F );
template <typename T , int D>
vector<MultivariablePolynomial<T,D> > ReducedGroebnerBasisNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<T>& LC_F , int& size );

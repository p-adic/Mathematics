// c:/Users/user/Documents/Programming/Mathematics/Polynomial/FFT/NonProth/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../a.hpp"

// verify:
// https://yukicoder.me/submissions/1062322ÅiPolynomial, llÅj
// https://yukicoder.me/submissions/1062332 (FormalPowerSeries, ll)
// https://yukicoder.me/submissions/1062331 (Polynomial, Mod<258280327>)

template <typename T , template <INT_TYPE_FOR_MOD> typename MINT , typename REPRESENT>
Polynomial<T> NonProthFFTConvolution( const Polynomial<T>& f0 , const Polynomial<T>& f1 , REPRESENT represent );

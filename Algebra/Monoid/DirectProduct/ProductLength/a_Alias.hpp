// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/DirectProduct/ProductLength/a_Alias.hpp

#pragma once

template <typename U , typename INT = int>
using SumLengthMonoid = ProductLengthMonoid<AdditiveMonoid<U>,INT>;

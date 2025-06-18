// c:/Users/user/Documents/Programming/Mathematics/Utility/String/RollingHash/Double/a_Alias.hpp

#pragma once

template <uint M0 , uint M1 , typename INT = int>
using DoubleRollingHash = RollingHashPair<RollingHash<Mod<M0>,INT>,RollingHash<Mod<M1>,INT>>;

template <uint M0 , uint M1 , uint M2 , typename INT = int>
using TripleRollingHash = RollingHashPair<DoubleRollingHash<M0,M1,INT>,RollingHash<Mod<M2>,INT>>;


// c:/Users/user/Documents/Programming/Mathematics/Utility/Tuple/Wrap/a_Alias.hpp

#pragma once

template <typename T , typename U> using Pair = Tuple<T,U>;
template <typename INT> using T2 = Pair<INT,INT>;
template <typename INT> using T3 = Tuple<INT,INT,INT>;
template <typename INT> using T4 = Tuple<INT,INT,INT,INT>;

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once

// 1+i番目の素数を返す
template <typename INT> const INT& GetPrime( const INT& i ) noexcept;

// i<Nの時に1+i番目の素数を返す
template <typename INT , INT N> const INT& GetPrimeBounded( const INT& i );

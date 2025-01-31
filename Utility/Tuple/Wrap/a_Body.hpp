// c:/Users/user/Documents/Programming/Mathematics/Utility/Tuple/Wrap/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename...Types> inline Tuple<Types...>::Tuple( Types&&... args ) : tuple<Types...>( move( args )... ) {}
template <typename...Types> template <typename...Args> inline Tuple<Types...>::Tuple( Args&&... args ) : tuple<Types...>( forward<Args>( args )... ) {}

template <typename...Types> template <int n> inline auto& Tuple<Types...>::operator[]( const TupleAccessIndex<n>& i ) noexcept { return get<n>( *this ); }
template <typename...Types> template <int n> inline const auto& Tuple<Types...>::operator[]( const TupleAccessIndex<n>& i ) const noexcept { return get<n>( *this ); }

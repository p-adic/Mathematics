// c:/Users/user/Documents/Programming/Mathematics/Utility/Tuple/Wrap/a.hpp

#pragma once

template <int n>
class TupleAccessIndex
{};

template <typename...Types>
class Tuple :
public tuple<Types...>
{

public:
  inline Tuple( Types&&... args );
  template <typename...Args> inline Tuple( Args&&... args );
  
  template <int n> inline auto& operator[]( const TupleAccessIndex<n>& i ) noexcept;
  template <int n> inline const auto& operator[]( const TupleAccessIndex<n>& i ) const noexcept;

};

// structural binding—p
template <typename...Types>
class tuple_size<Tuple<Types...>> :
  public tuple_size<tuple<Types...>>
{};

template <size_t n , typename...Types>
class tuple_element<n,Tuple<Types...>> :
  public tuple_element<n,tuple<Types...>>
{};

#include "a_Alias.hpp"

constexpr TupleAccessIndex<0> O{};
constexpr TupleAccessIndex<1> I{};
constexpr TupleAccessIndex<2> II{};
constexpr TupleAccessIndex<3> III{};

template <typename RET , template <typename...> typename PAIR , typename INT> T2<RET> cast( const PAIR<INT,INT>& t );
template <typename RET , typename INT> T3<RET> cast( const tuple<INT,INT,INT>& t );
template <typename RET , typename INT> T4<RET> cast( const tuple<INT,INT,INT,INT>& t );

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Iteration/Truncated/a.hpp

#pragma once

// O(log_2 e + 1)
template <typename INT1 , typename INT2> ll TruncatedPower( ll n , INT1 e , const INT2& bound );

// O(log_2 e log_2 n + 1)
template <typename INT1 , typename INT2> INT2 RoundDownRoot( const INT1& e , const INT2& n );

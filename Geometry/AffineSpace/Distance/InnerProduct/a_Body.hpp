// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/InnerProduct/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , template <typename...> typename PAIR> INT InnerProduct( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 ) { return get<0>( v0 ) * get<0>( v1 ) + get<1>( v0 ) * get<1>( v1 ); }
template <typename INT> INT InnerProduct( const tuple<INT,INT,INT>& v0 , const tuple<INT,INT,INT>& v1 ) { return get<0>( v0 ) * get<0>( v1 ) + get<1>( v0 ) * get<1>( v1 ) + get<2>( v0 ) * get<2>( v1 ); }
template <typename INT> INT InnerProduct( const tuple<INT,INT,INT,INT>& v0 , const tuple<INT,INT,INT,INT>& v1 ) { return get<0>( v0 ) * get<0>( v1 ) + get<1>( v0 ) * get<1>( v1 ) + get<2>( v0 ) * get<2>( v1 ) + get<3>( v0 ) * get<3>( v1 ); }
template <typename INT> INT InnerProduct( const vector<INT>& v0 , const vector<INT>& v1 ) { const int size = v0.size(); assert( int( v1.size() ) == size ); INT answer{}; for( int i = 0 ; i < size ; i++ ){ answer += v0[i] * v1[i]; } return answer; }

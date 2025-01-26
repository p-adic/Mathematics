// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/InnerProduct/a.hpp

#pragma once

template <typename INT , template <typename...> typename PAIR> INT InnerProduct( const PAIR<INT,INT>& v0 , const PAIR<INT,INT>& v1 );
template <typename INT> INT InnerProduct( const tuple<INT,INT,INT>& v0 , const tuple<INT,INT,INT>& v1 );
template <typename INT> INT InnerProduct( const tuple<INT,INT,INT,INT>& v0 , const tuple<INT,INT,INT,INT>& v1 );
template <typename INT> INT InnerProduct( const vector<INT>& v0 , const vector<INT>& v1 );

// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSequence/a.hpp

#pragma once

// O(val_max-val_min+1)�ŒP�������̌������߂�B
// val_max-val_min+1���傫����size���������ꍇ�͍ċA�œ񍀌W�������߂�����悢�B
template <typename MODINT> inline MODINT CountNonStrictlyIncreasingSequence( const int& size , const int& val_min , const int& val_max );
template <typename MODINT> inline MODINT CountStrictlyIncreasingSequence( const int& size , const int& val_min , const int& val_max );


// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Permutation/a.hpp

#pragma once
#include <algorithm>

template <int size_max> inline NextPermutation( int ( &P )[size_max] , const int& size );
template <int size_max> inline PreviousPermutation( int ( &P )[size_max] , const int& size );

// P��0,...,size-1�̏���
template <int size_max> long long InversionNumber( const int ( &P )[size_max] const int& size );

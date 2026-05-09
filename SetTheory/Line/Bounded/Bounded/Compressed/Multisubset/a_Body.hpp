// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Multisubset/a_Body.hpp"

template <typename INT1 , typename INT2> inline CompressedSortedMultiSet<INT1,INT2>::CompressedSortedMultiSet( const vector<INT1>& query ) : CompressedSortedSet<INT1,INT2>( query ) {}


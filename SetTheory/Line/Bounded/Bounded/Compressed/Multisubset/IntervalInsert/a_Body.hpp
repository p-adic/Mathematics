// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/IntervalInsert/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Multisubset/IntervalInsert/a_Body.hpp"

template <typename INT1 , typename INT2> inline IntervalInsertCompressedSortedMultiSet<INT1,INT2>::IntervalInsertCompressedSortedMultiSet( const vector<INT1>& query ) : AbstractCompressedSortedSet<INT,IntervalAddBIT>( query ) {}

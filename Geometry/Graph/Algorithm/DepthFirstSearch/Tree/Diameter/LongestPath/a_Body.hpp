// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/Diameter/LongestPath/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../RootingDP/a_Body.hpp"
#include "../../../../../../../Algebra/Monoid/Semilattice/Chain/a_Body.hpp"
#include "../../../../../../../Utility/Vector/a_Body.hpp"

template <typename DFST> inline vector<vector<int>> LongestPath( DFST& dfst , const int& K , const bool& distinct_branch ) { return RerootingDP( dfst , DescendingChainSemilattice<int>{ K } , [&]( vector<int> u , const int& i ){ return move( ++u ); } , [&]( const vector<int>& u , const bool& is_child , const int& k , const int& j ){ return u.empty() ? vector{ 0 } : distinct_branch ? vector{ u[0] } : u; } ); }

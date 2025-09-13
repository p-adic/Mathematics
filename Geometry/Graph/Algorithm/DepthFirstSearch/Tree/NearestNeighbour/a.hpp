// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/NearestNeighbour/a.hpp

#pragma once
#include "../a.hpp"

// i‚©‚ç‘cæ‚ğ’H‚Á‚½‚ÉÅ‚à‹ß‚¢subset‚Ì“_‚ğanswer[i]‚ÉŠi”[‚·‚éB
// ‘¶İ‚µ‚È‚¢ê‡‚Í-1‚ğŠi”[‚·‚éB
template <typename DFST> vector<int> NearestNeighbourOnRootedTree( DFST& dfst , const vector<bool>& subset );
template <typename DFST> inline vector<int> NearestNeighbourOnRootedTree( DFST& dfst , const vector<int>& subset );

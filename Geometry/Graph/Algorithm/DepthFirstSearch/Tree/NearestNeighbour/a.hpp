// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/NearestNeighbour/a.hpp

#pragma once
#include "../a.hpp"

// i����c���H�������ɍł��߂�subset�̓_��answer[i]�Ɋi�[����B
// ���݂��Ȃ��ꍇ��-1���i�[����B
template <typename DFST> vector<int> NearestNeighbourOnRootedTree( DFST& dfst , const vector<bool>& subset );
template <typename DFST> inline vector<int> NearestNeighbourOnRootedTree( DFST& dfst , const vector<int>& subset );

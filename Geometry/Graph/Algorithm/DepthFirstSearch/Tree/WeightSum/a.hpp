// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/WeightSum/a.hpp

#pragma once

// ���t���؂�{���_��,������̋����̑��a,2�_�W���Ԃ̋����̑��a�i�d���Ȃ��j}���DP�ŋ��߂�B
template <typename TREE , typename PREV_WEIGHT , typename INT> Tuple<int,INT,INT> TreeWeightSum( const TREE& T , PREV_WEIGHT pw , const int& root = 0 );
template <typename TREE , typename INT> inline Tuple<int,INT,INT> TreeWeightSum( const TREE& T , const int& root = 0 );


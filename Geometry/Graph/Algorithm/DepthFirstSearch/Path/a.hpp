// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Path/a.hpp

#pragma once

// EXEC��void (&exec)( const T& )�ɑ�������^�B

// ���_����V�A�o�����̍ő�l��D_max�A�o�H���̍ő�l��L_max�ƒu���B
// ���vO(V+D_max^L_max)�Ōo�Hp��S�T����exec(p)�����s����B
// �Ⴆ�΃O���b�h�Ȃ�O(4^{HW})�ŏ������AHW=13���x�����x�B
template <typename GRAPH , typename T , typename EXEC> void PathExhausiveSearch( GRAPH& G , const T& start , const T& goal , const EXEC& exec );

// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a.hpp

// verify: https://yukicoder.me/submissions/915732

#pragma once
#include "a_Macro.hpp"

DECLARATION_OF_FIRST_SEARCH( Breadth );

// (V,E)�ɂ�����init����̐[�����i�[�iO((init�̘A������)+(init�̘A�������ɂ�����E�̃T�C�Y�̍��v))�j
// ���B�ł��Ȃ��_�͐[���̑����-1���i�[�B
template <int V_max,list<int> E(const int&)>
void SetDepth( const int& V , const int& init , int ( &depth )[V_max] );
// �T���^��bfs�����������ė��p����B
template <int V_max,list<int> E(const int&)>
void SetDepth( BreadthFirstSearch<V_max,E>& bfs , const int& V , const int& init , int ( &depth )[V_max] );

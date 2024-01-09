// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a.hpp

// verify:
// https://yukicoder.me/submissions/942426�iNext�ɂ��S�T��j
// https://yukicoder.me/submissions/942436�i�A�������擾�j

#pragma once
#include "a_Macro.hpp"

DECLARATION_OF_FIRST_SEARCH( Breadth );

// (V,E)�ɂ�����init����̐[�����i�[�iO((init�̘A������)+(init�̘A�������ɂ�����E�̃T�C�Y�̍��v))�j
// ���B�ł��Ȃ��_�͐[���̑����-1���i�[�B
template <list<int> E(const int&)>
void SetDepth( const int& V , const int& init , vector<int>& );
// �T���^��bfs�����������ė��p����B
template <list<int> E(const int&)>
void SetDepth( BreadthFirstSearch<E>& bfs , const int& V , const int& init , vector<int>& depth );

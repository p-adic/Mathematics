// c:/Users/user/Documents/Programming/Utility/Search/DepthFirst/a.hpp

#pragma once
#include "../BreadthFirst/a_Macro.hpp"

DECLARATION_OF_FIRST_SEARCH( Depth );

// dfs.init()����̐[�����v�Z�B
template <int V_max,list<int> E(const int&)>
void SetDepth( const DepthFirstSearch<V_max,E>& dfs , ( &depth )[V_max] );

// dfs.init()����̐[���D��T���ɂ����Ċe�m�[�h�ɑ΂�������O�ɒT�������אڃm�[�h���v�Z�B
template <int V_max,list<int> E(const int&)>
void SetPrev( DepthFirstSearch<V_max,E>& dfs );

// dfs.init()����̐[���D��T���̒T�����̋t�����v�Z�B
template <int V_max,list<int> E(const int&)>
void SetReversedVertex( DepthFirstSearch<V_max,E>& dfs , int ( &reversed_vertex )[V_max] );

// dfs.SetPrev()��dfs.SetReversedVertex()���Ăяo���Ă���̂ݎg�p�\�B
// dfs.init()����̐[���D��T���ɂ����Ċe�m�[�h�ɑ΂��������ɒT�������אڃm�[�h�S�Ă��v�Z�B
template <int V_max>
void SetChildren( const DepthFirstSearch<V_max,E>& dfs , list<int> ( &edge )[V_max] );

// dfs.init()����̐[���D��T���ɂ����鍂�����v�Z�B
template <int V_max>
void SetHeight( const DepthFirstSearch<V_max,E>& dfs  , const int ( &reversed_vertex )[V_max] , ( &height )[V_max] );

// dfs.init()����̐[���D��T���ɂ����Ċe�m�[�h�ɑ΂��������ɒT�������אڃm�[�h�̌����v�Z�B
template <int V_max>
void SetNumberOfChildren( const DepthFirstSearch<V_max,E>& dfs  , const int ( &reversed_vertex )[V_max] , ( &count )[V_max] );

// �e�m�[�h�̍��� < 2^digit�̎��̂݃T�|�[�g�B
// dfs.init()����̐[���D��T���ɂ����Ċe�m�[�h�ɑ΂�������O�ɒT�������אڃm�[�h�v�Z�̔���������O�v�Z�B
template <int V_max,list<int> E(const int&),int digit = 16>
void SetDoublingAncestor( const DepthFirstSearch<V_max,E>& dfs , ( &doubling )[digit][V_max] );

// �e�m�[�h�̍��� < 2^digit�̎��̂݃T�|�[�g�B
// dfs.init()����̐[���D��T���ɂ����ăm�[�hi���O�ɒT�������אڃm�[�h�v�Z��n�񔽕������B
template <int V_max,int digit = 16>
void Ancestor( int i , int n , const ( &doubling )[digit][V_max] );

// �e�m�[�h�̍��� < 2^digit�̎��̂݃T�|�[�g�B
// dfs.init()����̐[���D��T���ɂ����ăm�[�hi,j�ɑ΂�������O�ɒT�������אڃm�[�h�v�Z�𔽕��������ē�����m�[�h�̂��������񐔂��ł����Ȃ����̂��v�Z�B
template <int V_max,list<int> E(const int&),int digit = 16>
int LCA( const DepthFirstSearch<V_max,E>& dfs , int i , int j , const ( &doubling )[digit][V_max] , const ( &depth )[V_max] );

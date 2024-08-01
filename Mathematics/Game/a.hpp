// c:/Users/user/Documents/Programming/Mathematics/Game/a.hpp

#pragma once

// Edge�̓Q�[���̏�ԑJ�ڂ�\���ʑ�edge:T->T^{<\infty}�ɑ�������^�B
template <typename Edge , typename T> const bool& IsWinningState( Edge& edge , const T& t , const bool& reset = false );

// AEdge�̓Q�[���̏�ԑJ�ڂ̘a�ւ̕�����\���ʑ�aedge:T->(T^{<\infty})^{<\infty}�ɑ�������^�B
// �ea in aedge(t)�͂��̃Q�[���a��t�̑J�ڐ�ɑΉ�����z��B
template <typename AEdge , typename T> const int& GrundyNumber( AEdge& aedge , const T& t , const bool& reset = false );

// c:/Users/user/Documents/Programming/Mathematics/Game/a.hpp

#pragma once

// ���肪���݂��Ȃ��ꍇ�ɕ����ƂȂ�Q�[���̏��s���v�Z����B
// Edge�̓Q�[���̏�ԑJ�ڂ�\���ʑ�edge:T->T^{<\infty}�ɑ�������^�B
template <typename Edge , typename T> const bool& IsWinningState( Edge& edge , const T& t , const bool& reset = false );

// ���肪���݂��Ȃ��ꍇ�ɕ����ƂȂ�Q�[���̃O�����f�B�����v�Z����B
// AEdge�̓Q�[���̏�ԑJ�ڂ̘a�ւ̕�����\���ʑ�aedge:T->(T^{<\infty})^{<\infty}�ɑ�������^�B
// �ea in aedge(t)�͂��̃Q�[���a��t�̑J�ڐ�ɑΉ�����z��B
template <typename AEdge , typename T> const int& GrundyNumber( AEdge& aedge , const T& t , const bool& reset = false );

// ���肪���݂��Ȃ��ǖʂ�{0,1}�l�s�ϗʂ��ŏ��ɗ^������萔C�ƈ�v����ꍇ��
// �����ƂȂ�Q�[���ŕK���ƂȂ�C�S�̂̏W����2�i�@�Ōv�Z����B
template <typename Edge , typename T , typename INVARIANT> const int& WinningConstantsOf( Edge& edge , const T& t , const INVARIANT& invariant , const bool& reset = false );

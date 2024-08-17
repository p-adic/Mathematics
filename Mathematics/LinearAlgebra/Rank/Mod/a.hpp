// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

// �ȉ�MODINT�͑f����@�Ƃ��鐮���^�ł���ꍇ�̂݃T�|�[�g�B


// �K�i��

// A��L�~M�s��ł���ꍇ�ɁA
// A�����[��됬����1�ł���K�i����rank��Ԃ��iO(LM min{L,M})�j�B
template <typename MODINT> int RowEchelonForm( vector<vector<MODINT>>& A );


// �g��W���s��̊Ȗ�K�i��

// A��L�~M�s���L���c�x�N�g��N�����������g��W���s��ł���ꍇ�ɁA
// A�ɑ΂��W���s��̊Ȗ񉻁{�g��W���s��̍��[��됬����1�ł���K�i�����{���A
// {�W���s��̊K��,�u�Ή�����A���ꎟ���������S�ĉ������v�̐^�U}��Ԃ��iO(L(M+N)min{L,M+N})�j�B
// ���̈�ӑ��ݐ��͌W���s��̊K����M���ۂ��Ŕ���\�A���̍ۂ̉����s�x�N�g�������B
template <typename MODINT> pair<int,bool> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , const int& N = 1 );
// �������Ȃ��Ƃ��P���݂���ꍇ�͂����solution/solutions�Ɋi�[����B
template <typename MODINT> pair<int,bool> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , vector<MODINT>& solution );
template <typename MODINT> pair<int,bool> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , vector<vector<MODINT>>& solutions , const int& N );


// �Ȗ�

// A��L�~M�s��ł��肩�Ȗ񉻂ł���ꍇ�ɁA
// A���Ȗ񉻂�rank��Ԃ��iO(LM min{L,M})�j�B
template <typename MODINT> inline int ReducedRowEchelonForm( vector<vector<MODINT>>& A );


// ����������

// A��L�������s��ł���ꍇ�ɁA
// A�������Ȃ��A�̋t�s����i�[���A�����łȂ��Ȃ��0�������s���Ԃ��iO(L^3)�j�B
template <typename MODINT> vector<vector<MODINT>> Inverse( const vector<vector<MODINT>>& A );


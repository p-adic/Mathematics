// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/1012652 (LinearRelation)


// �ȉ�MODINT�͑f����@�Ƃ��鐮���^�ł���ꍇ�̂݃T�|�[�g�B


// �K�i��

// A��L�~M�s��ł���ꍇ�ɁA
// A�����[��됬����1�ł���K�i����rank��Ԃ��iO(LM min{L,M})�j�B
template <typename MODINT> int RowEchelonForm( vector<vector<MODINT>>& A );


// �g��W���s��̊Ȗ�K�i��

// A��L�~M�s���L���c�x�N�g��N�����������g��W���s��ł���ꍇ�ɁA
// A�ɑ΂��W���s��̊Ȗ񉻁{�g��W���s��̍��[��됬����1�ł���K�i�����{���A
// {�W���s��̊K��,�������݂���?��:0�������s��}��Ԃ��iO(L(M+N)min{L,M+N})�j�B
// �������݂���ꍇ�̈�Ӑ��͌W���s��̊K����M���ۂ��Ŕ���\�B
template <typename MODINT> pair<int,vector<MODINT>> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A );
// {�W���s��̊K��,���̗L���̃x�N�g��,�������ɕ��ׂ��s��}��Ԃ��iO(L(M+N)min{L,M+N})�j�B
template <typename MODINT> tuple<int,vector<bool>,vector<vector<MODINT>>> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , const int& N );


// �Ȗ�

// A��L�~M�s��ł���ꍇ�ɁA
// A���Ȗ񉻂�rank��Ԃ��iO(LM min{L,M})�j�B
template <typename MODINT> inline int ReducedRowEchelonForm( vector<vector<MODINT>>& A );


// ����������

// A��L�������s��ł���ꍇ�ɁA
// A�������Ȃ��A�̋t�s����i�[���A�����łȂ��Ȃ��0�������s���Ԃ��iO(L^3)�j�B
template <typename MODINT> vector<vector<MODINT>> Inverse( const vector<vector<MODINT>>& A );


// �ꎟ�֌W���v�Z

// A��L�~M�s��ł���ꍇ�ɁAA���Ȗ񉻂�
// {�K��,�ꎟ�]��?�񎩖��Ȉꎟ�֌W���̌W��:���}��Ԃ��iO(LM min{L,M})�j�B
template <typename MODINT> pair<int,vector<MODINT>> LinearRelation( vector<vector<MODINT>>& A );

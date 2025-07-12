// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/ParallelBinarySearch/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/988997

// GRAPH�͕�Edge:T->(T \times ...)^{< \omega}�����O���t�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) v_min <= v_max
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// O( ( |V_G| + |E_G| + |additional_edge| + Q + min( v_max - v_min + 1 , Q log Q ) )
//    ��( |V_G| ) log( v_max - v_min + 1 ) )��
// G�̕ӂ𒷂�0�Ƃ���additional_edge��ǉ��������̊e[s,t] in query��l^�����������߂�B
template <typename T , typename INT , typename GRAPH> vector<INT> ParallelBinaryUnionFind( GRAPH& G , const INT& v_min , const INT& v_max , const map<INT,vector<pair<T,T>>>& additional_edge , const vector<pair<T,T>>& query );
template <typename T , typename INT , typename GRAPH> inline vector<INT> ParallelBinaryUnionFind( const int& size , const INT& v_min , const INT& v_max , const map<INT,vector<pair<int,int>>>& additional_edge , const vector<pair<int,int>>& query );

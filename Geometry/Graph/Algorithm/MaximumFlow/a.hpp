// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/MaximumFlow/a.hpp

#pragma once
#ubckude "../../a.hpp"

// verify:
// https://yukicoder.me/submissions/973269

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U(�e��))^{< \omega})�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) R�͑S�����A�[�x���Q�\���ł���B
// (1) V�̊e�v�fu,v�ɑ΂��A��u->v���������݂��Ȃ��B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// Dinic�@��p����B
// �P��n�_�P��I�_�ő嗬�H�T��O(|V_G|^2 |E_G|)
template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
class AbstractMaximumFlow
{

private:
  GRAPH& m_G;
  ABEL_GROUP m_M;

public:
  inline AbstractMaximumFlow( GRAPH& G , ABEL_GROUP M );

  // ���͈͓͂̔��ŗv��
  // (1) many_edges=true����path_length!=-1�Ȃ�΁A�n�_����̃p�X�̕ӂ̖{����path_length�ȉ��B
  // (2) many_edges=false�Ȃ�΁Apath_length=-1�B
  // �𖞂��ꍇ�ɂ̂݃T�|�[�g�B
  // ��1�����ɗ��ʂ̍ő�l�A��2������
  // ��i�����Ɂuvi���n�_�Ƃ����vi->vj���Ƃ�{vj,���ɗ�������}�̃f�[�^���i�[�����z��v���i�[�����z��
  // ��Ԃ��B
  pair<U,vector<vector<tuple<T,U>>>> GetFlow( const T& t_start , const T& t_final );

};
template <typename GRAPH , typename ABEL_GROUP>  AbstractMaximumFlow( GRAPH& G , ABEL_GROUP M ) -> AbstractMaximumFlow<inner_t<GRAPH>,GRAPH,inner_t<ABEL_GROUP>,ABEL_GROUP>;

template <typename T , typename GRAPH , typename U>
class MaximumFlow :
  public AbstractMaximumFlow<T,GRAPH,U,AdditiveGroup<U>>
{

public:
  inline MaximumFlow( GRAPH& G , const U& dummy );

};
template <typename GRAPH , typename U> MaximumFlow( GRAPH& G , const U& dummy ) -> MaximumFlow<inner_t<GRAPH>,GRAPH,U>;

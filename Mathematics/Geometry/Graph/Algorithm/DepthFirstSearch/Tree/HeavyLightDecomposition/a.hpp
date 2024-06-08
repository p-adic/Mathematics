// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/HeavyLightDecomposition/a.hpp

#pragma once
#include "../a.hpp"


// TREE��Graph<Edge>�ƕ\����A��T=(V_T,E_T)�ɑ�������^�B����V_T�̌^��int�Ɍ�����B
// ������E_T�͕�V_T -> (V_T \times ...)^{< \omega}�ɑ�������֐��I�u�W�F�N�g�B

// ���͈͓͂̔���
// (1) T�������O���t�Ƃ��Ă̖؂ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �\�zO(|V_T| log |V_T|)

// ������̃p�X�擾O(1)�i�Q�Ƃ����vector�̃T�C�Y��O(log |V_T|)�j
// �����؎擾O(1)

// �p�X�a�擾O((log |V_T|)^2)�i���\�b�h�Ȃ��B������̃p�X�擾��LCA��BIT�Ȃǂ𕹗p�j
// �����ؘa�擾O(log |V_T|)�i���\�b�h�Ȃ��B�����؎擾��BIT�Ȃǂ𕹗p�j

template <typename TREE>
class HeavyLightDecomposiion :
  public DepthFirstSearchOnTree<TREE>
{

private:
  // m_HL[i]�ɂ�HL������̔z��̑�i�����ɑΉ�����m�[�h�ԍ����i�[�B
  vector<int> m_HL;
  vector<int> m_HL_inv;

  // m_path[i]�ɂ�root����i�ւ̃p�X�ɑΉ�����m_HL�̕��[l,r]�����i�[�B
  vector<vector<pair<int,int>>> m_path;

  // m_subtree[i]�ɂ̓m�[�h�ԍ�i�̃m�[�h�����Ƃ��镔���؂ɑΉ�����m_HL�̕��[l,r]���i�[�B
  vector<pair<int,int>> m_subtree;

public:
  inline HeavyLightDecomposiion( TREE& T , const int& root = 0 , const int& digit = 0 );

  inline const int& RearragedNodeNumber( const int& n ) const;
  inline const int& RearragedNodeNumber_inv( const int& i ) const;

  // ��ʂ�path i->j�ł̊֐�f�̃p�X�a�Ȃǂ��v�Z���������́A(f(m_HL[i]))_i��BIT�Ȃǂɏ悹
  // (PathFromRoot(i)�ł�f�̑��a)+(PathFromRoot(j)�ł�f�̑��a)
  // -(PathFromRoot(LCA(i,j))�ł�f�̑��a)
  // ���v�Z����΂悢�B
  inline const vector<pair<int,int>>& PathFromRoot( const int& i ) const;

  inline const pair<int,int> Subtree( const int& i ) const;
  
};

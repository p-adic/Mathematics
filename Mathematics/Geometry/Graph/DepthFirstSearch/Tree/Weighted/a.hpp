// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Weighted/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/957446�i�d�ݕs�g�p��WDepth,WHeaviness,WAncestor,WLCA�j
// https://yukicoder.me/submissions/957499�iWLCA�j

// TREE��Graph<Edge>�ƕ\����A��T=(V_T,E_T)�ɑ�������^�B����V_T�̌^��int�Ɍ�����B
// E_T�͏d�ݕt����V_T -> (V_T \times U \times ...)^{< \omega}�ɑ�������֐��I�u�W�F�N�g�B

// ���͈͓͂̔���
// (1) T�������O���t�Ƃ��Ă̖؂ł���B
// (2) M��U�̃��m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �\�zO(|V_T|)

// ������̕ӂ̖{���i�[���j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j
// �t����̕ӂ̖{���̍ő�^�ŏ��l�i�����j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j
// �����؂̕ӂ̖{���i�T�C�Y�j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j

// ������̕ӂ̏d�ݑ���i�d�ݕt���[���j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j
// M���S�������m�C�h�\���ł���ꍇ�ɗt����̕ӂ̏d�ݑ���̍ő�^�ŏ��l�i�d�ݕt�������j�擾
//   O(|V_T|)�i��x�ڈȍ~��O(1)�j
// M�����ȏꍇ�ɕ����؂̕ӂ̏d�ݑ���i�d�ݕt���T�C�Y�j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j

// �ؓ��I�v��@O(|V_T|)
// �S���ʖؓ��I�v��@O(|V_T|)

// �ȉ��A���͈͓͂̔���
// (3) �e�m�[�h�̗t����̕ӂ̖{�� < 2^digit
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ��c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
// �ŋߐڋ��ʐ�c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
template <typename TREE , typename U , typename MONOID>
class DepthFirstSearchOnWeightedTree :
  public DepthFirstSearchOnTree<TREE>
{

private:
  MONOID m_M;

  // �e�m�[�h�ւ̕ӂ̏d�݂��i�[�B
  // �������e�m�[�h�����݂��Ȃ��ꍇ��M.One()���i�[�B
  vector<U> m_wprev;
  
  // ������̕ӂ̏d�݂̉E�^������i�[���j���i�[�B
  vector<U> m_wdepth_r;
  vector<U> m_wdepth_l;
  bool m_set_wdepth;

  // �t����̕ӂ̏d�݂̉E�^������i�����j���i�[�B
  vector<U> m_wheight_max_r;
  vector<U> m_wheight_max_l;
  vector<U> m_wheight_min_r;
  vector<U> m_wheight_min_l;
  bool m_set_wheight;

  // �����؂̕ӂ̏d�݂̑���i�d���j���i�[�B
  vector<U> m_wheaviness;
  bool m_set_wheaviness;

  // �_�u�����O��{��c�m�[�h,�ӂ̏d���̉E����,�ӂ̏d���̍�����}���i�[�B
  vector<vector<tuple<int,U,U>>> m_wdoubling;
  bool m_set_wdoubling;

public:
  inline DepthFirstSearchOnWeightedTree( TREE& T , MONOID M , const int& root = 0 , const int& digit = 0 );

  inline const U& WDepth( const int& i , const bool& right = true );
  inline const U& WHeight( const int& i , const bool& maximum = true , const bool& right = true );
  inline const U& WHeaviness( const int& i );

  // n�K�̐eParent^n( i )��i���炻���܂ł̕ӂ̏d�݂̉E�^�������Ԃ��B
  pair<int,U> WAncestor( int i , int n , const bool& right = true );
  // {i��j�̍ŋߐڋ��ʑc��k,i����k�܂ł̕ӂ̏d�݂̉E����,j����k�܂ł̕ӂ̏d�݂̍�����}��Ԃ��B
  tuple<int,U,U> WLCA( int i , int j );
  // �X��LCA����i,j���ɐi�߂�ꍇ�ɐi�񂾐�̒��_�̃��x����i_prev,j_prev�Ɋi�[����B
  tuple<int,U,U> WLCA( int i , int j , int& i_prev , int& j_prev );

private:
  void SetWDepth();
  void SetWHeight();
  void SetWHeaviness();
  void SetWDoubling();

};
template <typename TREE , typename MONOID , typename...Args> DepthFirstSearchOnWeightedTree( TREE& T , MONOID M , const Args&... args ) -> DepthFirstSearchOnWeightedTree<TREE,inner_t<MONOID>,MONOID>;

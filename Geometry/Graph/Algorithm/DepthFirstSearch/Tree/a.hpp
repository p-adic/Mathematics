// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/957468�iDepth,Heaviness�j

#include "../a.hpp"

// TREE��Graph<Edge>�ƕ\����A��T=(V_T,E_T)�ɑ�������^�B����V_T�̌^��int�Ɍ�����B
// ������E_T�͕�V_T -> (V_T \times ...)^{< \omega}�ɑ�������֐��I�u�W�F�N�g�B

// ���͈͓͂̔���
// (1) T�������؂ł��邩�Aroot�����Ƃ��t�Ɍ������L���؂ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �\�zO(|V_T|)

// ������̕ӂ̖{���i�[���j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j
// �t����̕ӂ̖{���̍ő�^�ŏ��l�i�����j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j
// �����؂̕ӂ̖{���i�d���j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j

// ���a: ./Diameter/
// HL����: ./HeaviLightDecomposition/
// LCA: ./LCA/
// �ŋߖT�T��: ./NearestNeighbour/
// ��DP: ./RootingDP/
// �d�ݕt����: ./Weighted/
// ������̋����̑��a�����2�_�ԋ����̑��a: ./WeightSum/
template <typename TREE>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<int,TREE> ,
  public PointedSet<int>
{

protected:
  // size()�͑c��N���X��BreadFirstSearch�ɒ�`�B
  
  // �������DFS���Ƀm�[�h�ԍ����i�[�B
  vector<int> m_node_num;

  // �q�m�[�h�̃m�[�h�ԍ����i�[�B
  vector<vector<int>> m_children;
  // �e�m�[�h��j�Ƃ�����m_children[j]�̉��Ԗڂ̐��������i�[�B
  // �������e�m�[�h�����݂��Ȃ�����-1���i�[�B
  vector<int> m_children_num;
  bool m_set_children;

  // ������̋����i�[���j���i�[�B
  vector<int> m_depth;
  bool m_set_depth;

  // �t����̋����i�����j���i�[�B
  vector<int> m_height_max;
  vector<int> m_height_min;
  bool m_set_height;

  // �����؂̕ӂ̖{���i�T�C�Y�j���i�[�B
  vector<int> m_heaviness;
  bool m_set_heaviness;

public:
  inline DepthFirstSearchOnTree( TREE& T , const int& root = 0 );
  inline void Initialise() = delete;
  inline void Initialise( const int& init ) = delete;
  inline void Shift( const int& init ) = delete;

  inline const int& Root() const;
  inline const int& Parent( const int& i );
  inline const vector<int>& Children( const int& i );
  inline const int& Depth( const int& i );
  inline const int& Height( const int& i , const bool& maximum = true );
  inline const int& Heaviness( const int& i );
  // �����O���t�Ƃ��Ă̎�����Ԃ��B
  inline int Degree( const int& i );
  // root�����Ƃ������ɗt�ł��邩�ۂ���Ԃ��B������root=-1�͌��݂̍���root��u��������B
  inline bool IsLeaf( const int& i , const int& root = -1 );

  // �������DFS���Ƀm�[�h��ԍ��Â���B
  // reversed = true�̏ꍇ�͋A�肪�����ł͂Ȃ��s���������̋t���ł��邱�Ƃɒ��ӁB
  inline const int& NodeNumber( const int& i , const bool& reversed = false ) const;
  // ���ʂ̐e�����m�[�h�Ԃŏ����ɔԍ��Â���B
  inline const int& ChildrenNumber( const int& i );
  // Ord�͑S�����̑�ord:N \times N^2 -> {0,1}�ɑ�������^�B
  // �e�m�[�hi�̎q�m�[�h�̊i�[����ord( i , - , - )�����ɕύX����B
  template <typename Ord> inline void ReorderChildren( Ord& ord );
    
private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetHeaviness();

};

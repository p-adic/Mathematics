// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/957468�iDepth,Heaviness,Ancestor,LCA�j
// https://yukicoder.me/submissions/957397�iRootingDP�j
// https://yukicoder.me/submissions/957399�iRerootingDP�j
// https://yukicoder.me/submissions/957400�iRerootingDP�j

// TREE��Graph<Edge>�ƕ\����A��T=(V_T,E_T)�ɑ�������^�B����V_T�̌^��int�Ɍ�����B
// ������E_T�͕�V_T -> (V_T \times ...)^{< \omega}�ɑ�������֐��I�u�W�F�N�g�B

// ���͈͓͂̔���
// (1) T�������O���t�Ƃ��Ă̖؂ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �\�zO(|V_T|)

// ������̕ӂ̖{���i�[���j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j
// �t����̕ӂ̖{���̍ő�^�ŏ��l�i�����j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j
// �����؂̕ӂ̖{���i�d���j�擾O(|V_T|)�i��x�ڈȍ~��O(1)�j

// �ؓ��I�v��@O(|V_T|)
// �S���ʖؓ��I�v��@O(|V_T|)

// �ȉ��A���͈͓͂̔���
// (2) �e�m�[�h�̗t����̕ӂ̖{�� < 2^digit
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
// ��c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
// �ŋߐڋ��ʐ�c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
template <typename TREE>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<int,TREE>
{

protected:
  // DFS���Ƀm�[�h�ԍ����i�[�B
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

  int m_digit;
  vector<vector<int>> m_doubling;
  bool m_set_doubling;

public:
  inline DepthFirstSearchOnTree( TREE& T , const int& root = 0 , const int& digit = 0 );
  inline void Initialise( ) = delete;
  inline void Initialise( const int& init ) = delete;
  inline void Shift( const int& init ) = delete;

  inline const int& Root() const;
  inline const int& Parent( const int& i );
  inline const vector<int>& Children( const int& i );
  inline const int& Depth( const int& i );
  inline const int& Height( const int& i , const bool& maximum = true );
  inline const int& Heaviness( const int& i );

  // �T�����Ƀm�[�h��ԍ��Â���B
  inline const int& NodeNumber( const int& i , const bool& reversed = false ) const;
  // ���ʂ̐e�����m�[�h�Ԃŏ����ɔԍ��Â���B
  inline const int& ChildrenNumber( const int& i );  

  // ���͈͓͂̔��ŗv��
  // (1) �e�m�[�h�̍��� < 2^digit
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // n�K�̐eParent^n( i )��Ԃ��B
  int Ancestor( int i , int n );

  // ���͈͓͂̔��ŗv��
  // (1) �e�m�[�h�̍��� < 2^digit
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // i��j�̍ŋߐڋ��ʑc���Ԃ��B
  inline int LCA( int i , int j );
  // LCA����i,j���ɐi�߂�ꍇ�ɐi�񂾐�̒��_�̃��x����i_prev,j_prev�Ɋi�[����B
  int LCA( int i , int j , int& i_prev , int& j_prev );

  // U�͓K���Ȍ^�AF�͎ʑ�f:U^{< \omega} \times N -> U�ɑ�������^�B
  // �^���_�̂��߂�f�̓f�t�H���g�����ŌĂяo���\�Ƃ���B
  // ���͈͓͂̔��ŗv��
  // (2) �C�ӂ̔񕉐���n,i��T�̗v�f�݂̂���Ȃ�C�ӂ̒���n�̔C�ӂ̗�(u1,...,un)��
  //     ���̕��ъ���(v1,...,vn)�ɑ΂�f((u1,...,un),i)=f((v1,...,vn),i)�ł���B
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // dp[j] = f(j�̎q�m�[�hk��n��dp[k]�̗�,j)
  // �𖞂����z��dp�̍��ł̒ldp[root]��O(|V_T|)�ŋ��߂�B
  template <typename F> ret_t<F> RootingDP( F& f );

  // U�͓K���Ȍ^�AF�͎ʑ�f:U \times N ->U�ɑ�������^�A
  // E�͎ʑ�g:U \times \{0,1\} \times N^2 -> U�ɑ�������^�B
  // ���͈͓͂̔��ŗv��
  // (1) M��U�̃��m�C�h�\���ł���B�i�ȉ����Z��*�ƒu���j
  // (2) �C�ӂ̔񕉐���n,i��T�̗v�f�݂̂���Ȃ�C�ӂ̒���n�̔C�ӂ̗�(u1,...,un)��
  //     ���̕��ъ���(v1,...,vn)�ɑ΂�
  //     f(u1*u2*...*un,j)=f(v1*v2*...*vn,j)�ł���B
  //     �i�Ⴆ��L��W�̉����m�C�h�\���ł���j
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // dp[i][j] =
  // f(i�����Ƃ݂Ȃ�������j�̎q�m�[�hk��n��g(dp[i][k],j��i�̎q��,k,j)��M�Ɋւ����,j)
  // �𖞂�����d�z��dp�̑Ίp����dp[i][i]��O(|V_T|)�ŋ��߂�d�Ɋi�[����B
  template <typename U , typename COMM_MONOID , typename F , typename G> void RerootingDP( COMM_MONOID M , F& f , G& g , vector<U>& d );
  // f�̓m�[�hj���Ƃ̃f�[�^�i�O���t�\���Ɉˑ����Ȃ��j�Ag�͗L����b?(j,k):(k,j)���Ƃ̃f�[�^�ɑΉ��B
  // �Ⴆ�΁u�p�X�̐��v�����߂鎞��m_T���a�Af��+1�i�t���ǂ����Ɋ֌W�Ȃ��j�Ag��id�ł悢�B

private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetHeaviness();

  // LCA()���ĂԑO��Ancestor()�o�R�Ŋ��S�Ƀ_�u�����O��ݒ肷��B
  // �x���]�����Ă��܂�
  // ../../../../Function/Iteration/Doubling/
  // �̃_�u�����O�ł͑�p���Ȃ��B
  void SetDoubling();

};

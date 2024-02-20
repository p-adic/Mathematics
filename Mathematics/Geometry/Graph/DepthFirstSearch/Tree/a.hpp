// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/953264�iRootingDP�j
// https://yukicoder.me/submissions/953265�iRerootingDP�j
// https://yukicoder.me/submissions/953266�iRerootingDP�j

// digit��Ancestor��LCA�ɂ̂ݎg�p�B���i��0�ŗǂ��B
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144

// inner_t<TREE>==int�ł���TREE��Graph�ł���T�������O���t�Ƃ��Ă̖؂ł���ꍇ�ɂ̂݃T�|�[�g�B
template <typename TREE>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<int,TREE>
{

private:
  vector<int> m_reversed;

  vector<vector<int>> m_children;
  vector<int> m_children_num;
  bool m_set_children;

  vector<int> m_depth;
  bool m_set_depth;

  vector<int> m_height;
  bool m_set_height;

  vector<int> m_weight;
  bool m_set_weight;

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
  inline const int& Height( const int& i );
  inline const int& Weight( const int& i );

  // �T�����Ƀm�[�h��ԍ��Â���B
  inline const int& NodeNumber( const int& i , const bool& reversed = false ) const;
  // ���ʂ̐e�����m�[�h�Ԃŏ����ɔԍ��Â���B
  inline const int& ChildrenNumber( const int& i );  

  // �e�m�[�h�̍��� < 2^digit�̏ꍇ�̂݃T�|�[�g�B
  // n�K�̐eParent^n( i )��Ԃ��B
  int Ancestor( int i , int n );
  int LCA( int i , int j );
  // LCA����i,j���ɐi�߂�ꍇ�ɐi�񂾐�̒��_�̃��x����i_prev,j_prev�Ɋi�[����B
  int LCA( int i , int j , int& i_prev , int& j_prev );

  // U��K���Ȍ^�Ƃ��A
  // F�͎ʑ�f:U^{< \omega} \times N -> U�ɑ�������^�B
  // �^���_�̂��߂�f�̓f�t�H���g�����ŌĂяo���\�Ƃ���B

  // ���͈͓͂̔��ŗv��
  // (2) �C�ӂ̔񕉐���n,i��T�̗v�f�݂̂���Ȃ�C�ӂ̒���n�̔C�ӂ̗�(u1,...,un)��
  //     ���̕��ъ���(v1,...,vn)�ɑ΂�f((u1,...,un),i)=f((v1,...,vn),i)�ł���B
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // dp[j] = f(j�̎q�m�[�hk��n��dp[k]�̗�,j)
  // �𖞂����z��dp�̍��ł̒ldp[m_init]��O(m_V)�ŋ��߂�B
  template <typename F> ret_t<F> RootingDP( F& f );

  // U��K���Ȍ^�Ƃ��A
  // F�͎ʑ�f:U \times N ->U�ɑ�������^�B
  // E�͎ʑ�g:U \times \{0,1\} \times N^2 -> U�ɑ�������^�B

  // ���͈͓͂̔��ŗv��
  // (1) M��U�̃��m�C�h�\���ł���B�i�ȉ����Z��*�ƒu���j
  // (2) �C�ӂ̔񕉐���n,i��T�̗v�f�݂̂���Ȃ�C�ӂ̒���n�̔C�ӂ̗�(u1,...,un)��
  //     ���̕��ъ���(v1,...,vn)�ɑ΂�
  //     f(u1*u2*...*un,j)=f(v1*v2*...*vn,j)�ł���B
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // dp[i][j] =
  // f(i�����Ƃ݂Ȃ�������j�̎q�m�[�hk��n��g(dp[i][k],j��i�̎q��,k,j)��M�Ɋւ����,j)
  // �𖞂�����d�z��dp�̑Ίp����dp[i][i]��O(|V_T|)�ŋ��߂�d�Ɋi�[����B
  template <typename MONOID , typename F , typename G> void RerootingDP( MONOID M , F& f , G& g , vector<inner_t<MONOID>>& d );
  // f�̓m�[�hj���Ƃ̃f�[�^�i�O���t�\���Ɉˑ����Ȃ��j�Ag�͗L����b?(j,k):(k,j)���Ƃ̃f�[�^�ɑΉ��B
  // �Ⴆ�΁u�p�X�̐��v�����߂鎞��m_T���a�Af��+1�i�t���ǂ����Ɋ֌W�Ȃ��j�Ag��id�ł悢�B

private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetWeight();

  // �e�m�[�h�̍��� < 2^digit�̏ꍇ�̂݃T�|�[�g�B
  // LCA()���ĂԑO��Ancestor()�o�R�Ŋ��S�Ƀ_�u�����O��ݒ肷�邽�߁A
  // �x���]�����Ă��܂�
  // ../../../../Mathematics/Function/Iteration/Doubling/
  // �̃_�u�����O�ł͑�p���Ȃ��B
  void SetDoubling();

};

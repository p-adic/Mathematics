// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/919091�iRootingDP�j
// https://yukicoder.me/submissions/938101�iRerootingDP�j

// digit��Ancestor��LCA�ɂ̂ݎg�p�B���i��0�ŗǂ��B
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <int V_max,list<int> E(const int&),int digit = 0>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<V_max,E>
{

private:
  int m_reversed[V_max];

  vector<vector<int> > m_children;
  vector<int> m_children_num;
  bool m_set_children;

  vector<int> m_depth;
  bool m_set_depth;

  vector<int> m_height;
  bool m_set_height;

  vector<int> m_weight;
  bool m_set_weight;

  vector<int> m_doubling[digit];
  bool m_set_doubling;

public:
  inline DepthFirstSearchOnTree( const int& V , const int& root );
  inline void Reset( const int& init ) = delete;
  inline void Shift( const int& init ) = delete;

  inline const int& Root() const;
  inline const int& Parent( const int& i ) const;
  inline const vector<int>& Children( const int& i );
  inline const int& Depth( const int& i ) const;
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

  // ���͈͓͂̔��ŗv��
  // (2) �C�ӂ̔񕉐���n,i��T�̗v�f�݂̂���Ȃ�C�ӂ̒���n�̔C�ӂ̗�(t1,...,tn)��
  //     ���̕��ъ���(s1,...,sn)�ɑ΂�f((t1,...,tn),i)=f((s1,...,sn),i)�ł���B
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // dp[j] = f(j�̎q�m�[�hk��n��dp[k]�̗�,j)
  // �𖞂����z��dp�̍��ł̒ldp[m_init]��O(m_V)�ŋ��߂�B
  template <typename T , T f(const list<T>&,const int&)> T RootingDP();

  // (T,m_T:T^2->T,e_T:1->T)�����͈͓͂̔��ŗv��
  // (1) (T,m_T:T^2->T,e_T:1->T)�����m�C�h�ł���
  // (2) �C�ӂ̔񕉐���n,i��T�̗v�f�݂̂���Ȃ�C�ӂ̒���n�̔C�ӂ̗�(t1,...,tn)��
  //     ���̕��ъ���(s1,...,sn)�ɑ΂�
  //     f(m_T(...m_T(t1,t2),...tn),j)=f(m_T(...m_T(s1,s2),...sn),j)�ł���B
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // dp[i][j] = f(i�����Ƃ݂Ȃ�������j�̎q�m�[�hk��n��g(dp[i][k],j��i�̎q��,k,j)��m_T�Ɋւ����,j)
  // �𖞂�����d�z��dp�̑Ίp����dp[i][i]��O(m_V)�ŋ��߂�d�Ɋi�[����B
  template <typename T , T m_T(const T&,const T&) ,const T& e_T() , T f(const T&,const int&), T g(const T&,const bool&,const int&,const int&)> void RerootingDP( T ( &d )[V_max] );
  // f�̓m�[�hj���Ƃ̃f�[�^�Ag�͗L����b?(j,k):(k,j)���Ƃ̃f�[�^�ɑΉ��B

private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetWeight();

  // �e�m�[�h�̍��� < 2^digit�̏ꍇ�̂݃T�|�[�g�B
  // LCA()���ĂԑO��Ancestor()�o�R�Ŋ��S�Ƀ_�u�����O��ݒ肷�邽�߁A
  // �x���]������../../../../Mathematics/Function/Iteration/Doubling/�̃_�u�����O�ő�p���Ȃ��B
  void SetDoubling();

};

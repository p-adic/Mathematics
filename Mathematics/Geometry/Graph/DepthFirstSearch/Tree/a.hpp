// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

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
  int Ancestor( int i , int n );
  int LCA( int i , int j );
  int LCA( int i , int j , int& i_prev , int& j_prev );

  // (T,m_T:T^2->T)�����͈͓͂̔��ŗv��
  // - T�̔C�ӂ̗v�ft0,t1,t2�ɑ΂�m_T(m_T(t0,t1),t_2)=m_T(m_T(t0,t2),t_1)�ł���B
  // �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
  // dp[j] = j�̎q�m�[�hk��n��m_T(-,dp[k])��a[j]�ւ̓K�p����
  // �𖞂����z��dp�̍��ł̒ldp[m_init]��O(m_V)�ŋ��߂�B
  template <typename T , T m_T(const T&,const T&)> T RootingDP( const ( &a )[V_max] );
  // (T,m_T:T^2->T,e_T:1->T)�������m�C�h�̏ꍇ�̂݃T�|�[�g�B
  // dp[i][j] = f(i�����Ƃ݂Ȃ�������j�̎q�m�[�hk��n��dp[i][k]��m_T�Ɋւ����,j)
  // �𖞂�����d�z��dp�̑Ίp����dp[i][i]��O(m_V)�ŋ��߂�d�Ɋi�[����B
  template <typename T , T m_T(const T&,const T&) ,const T& e_T() , T f(const T&,const int&)> void RerootingDP( T ( &d )[V_max] );
  
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

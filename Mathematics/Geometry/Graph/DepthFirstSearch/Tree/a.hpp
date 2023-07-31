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
  // ���������������ꍇ�A�ȉ��ŕs�v�Ȃ��̂������B
  int m_reversed[V_max];

  vector<int> m_children[V_max];
  int m_children_num[V_max];
  bool m_set_children;

  int m_depth[V_max];

  int m_height[V_max];
  bool m_set_height;

  int m_weight[V_max];
  bool m_set_weight;

  int m_doubling[digit][V_max];
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

  // (T,m_T:T^2->T,e_T:1->T)�������m�C�h�̏ꍇ�̂݃T�|�[�g�B
  // dp[i][j] = f(i�����Ƃ݂Ȃ�������j�̎q�m�[�hk��n��dp[i][k]��m_T�Ɋւ����,j)
  // �𖞂�����d�z��dp�̑Ίp����dp[i][i]��O(m_V)�ŋ��߂�d�Ɋi�[����B
  template <typename T , T m_T(const T&,const T&) ,const T& e_T() , T f(const T&,const int&)> void RerootingDP( T ( &d )[V_max] );
  
private:
  void SetChildren();
  void SetHeight();
  void SetWeight();

  // �e�m�[�h�̍��� < 2^digit�̏ꍇ�̂݃T�|�[�g�B
  // LCA()���ĂԑO��Ancestor()�o�R�Ŋ��S�Ƀ_�u�����O��ݒ肷�邽�߁A
  // �x���]������../../../../Mathematics/Function/Iteration/Doubling/�̃_�u�����O�ő�p���Ȃ��B
  void SetDoubling();

};

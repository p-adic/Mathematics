// c:/Users/user/Documents/Programming/Utility/Search/DepthFirst/Tree/a.hpp

#pragma once
#include "../a.hpp"

template <int V_max,list<int> E(const int&),int digit = 0>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<V_max,E>
{

private:
  // ���������������ꍇ�A�ȉ��ŕs�v�Ȃ��̂������B
  int m_reversed[V_max];

  list<int> m_children[V_max];
  bool m_set_children;

  int m_depth[V_max];
  bool m_set_depth;

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
  inline const int& root() const;

  inline const int& parent( const int& i );
  inline const list<int>& children( const int& i );
  inline const int& depth( const int& i );
  inline const int& height( const int& i );
  inline const int& weight( const int& i );

  // �e�m�[�h�̍��� < 2^digit�̎��̂݃T�|�[�g�B
  int Ancestor( int i , int n );
  int LCA( const int& i );

private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetWeight();

  // �e�m�[�h�̍��� < 2^digit�̎��̂݃T�|�[�g�B
  // LCA()���ĂԑO��Ancestor()�o�R�Ŋ��S�Ƀ_�u�����O��ݒ肷�邽�߁A
  // �x���]������../../../../Mathematics/Function/Iteration/Doubling/�̃_�u�����O�ő�p���Ȃ��B
  void SetDoubling();

};

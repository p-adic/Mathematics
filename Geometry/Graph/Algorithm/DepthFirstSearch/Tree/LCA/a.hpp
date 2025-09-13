// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/LCA/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/957468�iAncestor,LCA�j

#include "../a.hpp"

// �ȉ��A���͈͓͂̔���
// (2) �e�m�[�h�̗t����̕ӂ̖{�� < 2^digit
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
// ��c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
// �ŋߐڋ��ʐ�c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
template <typename DFST>
class AncestorDoubling
{

protected:
  DFST* m_p_dfst;
  int m_size;
  vector<vector<int>> m_doubling;

public:
  inline AncestorDoubling( DFST& dfst );

  // n�K�̐eParent^n( i )��Ԃ��B
  int Ancestor( DFST& dfst , int i , int n );

  // {i��j�̍ŋߐڋ��ʑc��,LCA����i���ɐi�߂�ꍇ�ɐi�񂾐�̒��_�̃��x��,��j��}��Ԃ��B
  tuple<int,int,int> LCA( DFST& dfst , int i , int j );

private:
  const vector<int>& Get( const int& d );
  
};

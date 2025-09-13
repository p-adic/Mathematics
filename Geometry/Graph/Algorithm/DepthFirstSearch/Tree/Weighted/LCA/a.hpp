// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/Tree/Weighted/LCA/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../a.hpp"

// ��c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
// �ŋߐڋ��ʐ�c�擾O(|V_T| digit)�i��x�ڈȍ~��O(digit)�j
template <typename DFST , typename MONOID , typename U>
class WAncestorDoubling
{

protected:
  DFST* m_p_dfst;
  MONOID* m_p_M;
  int m_size;
  // {��c�m�[�h,�ӂ̏d���̉E����,�ӂ̏d���̍�����}���i�[�B
  vector<vector<tuple<int,U,U>>> m_wdoubling;

public:
  inline WAncestorDoubling( DFST& dfst );

  // {n�K�̐eParent^n( i ),�����܂ł̂̕ӂ̏d�݂̉E�^������}��Ԃ��B
  pair<int,U> WAncestor( DFST& dfst , int i , int n , const bool& right = true );

  // {i��j�̍ŋߐڋ��ʑc��,LCA����i���ɐi�߂�ꍇ�ɐi�񂾐�̒��_�̃��x��,��j��,
  // i����̏d�݂̉E����,j����̏d�݂̍�����}��Ԃ��B
  tuple<int,int,int,U,U> WLCA( DFST& dfst , int i , int j );

private:
  const vector<int>& Get( const int& d );
  
};
template <typename DFSWT> WAncestorDoublng( DFSWT ) -> WAcestorDoubling<DFSWT,decldecay_t(declval<DSFWT>().Monoid()),decldecay_t(declval<DSFWT>().WDepth(0))>;

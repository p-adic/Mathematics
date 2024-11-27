// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Optimisation/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Sqrt/a.hpp"

// FUNC�͎ʑ�N->U�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) operator<(const U&,const U&)�͑S�����ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// func�̍ŏ��l�̌���O(N^{1/2})�ŋ��߂�B
// �Ⴆ��U=Z��func���ߎ��I�ɒP���Ȋ֐��̐�Βl�ł���ꍇ�ɐ��x���悭�Ȃ�B
class SqrtDecompositionOptimisation :
  public SqrtDecompositionCoordinate
{

private:
  vector<int> m_rand;
  
public:
  template <typename...Args> inline SqrtDecompositionOptimisation( const int& N = 0 , const Args&... args );
  
  template <typename...Args> inline void Initialise( const Args&... args );

  template <typename FUNC> int Minimise( FUNC& func );
  
};

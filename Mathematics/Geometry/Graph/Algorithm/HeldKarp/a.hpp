// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/HeldKarp/a.hpp

#pragma once

// verify:
// https://atcoder.jp/contests/typical-algorithm/submissions/59801372

#include "../../a.hpp"
#include "../../../../Algebra/Monoid/a.hpp"

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U)^{< \omega})�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) M�͑S�������m�C�h�\���ł���B
// (1) E_G�̒l�̊e�����̑�2������M.One()�ȏ�ł���B
// (2) infty��E_G�̒l�̊e�����̑�2����|V_G|�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �o�R�_�̌���F�ƒu���B
// �P��n�_���o�R�_�S�I�_�ŒZ�o�H�T��O((|V_G| + |E_G|)x 2^F)
template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
class AbstractHeldKarp :
  public PointedSet<U>
{
private:
  GRAPH& m_G;
  // �R���X�g���N�^�Ɉ������K�v��MultiplicativeMonoid�Ȃǂ�static�����o�֐��ɂ��
  // �Q�ƕԂ������ɂ����A�R���X�g���N�^�̕Ԃ�l�ł���E�Ӓl���󂯎�邱�Ƃ����e�������̂�
  // ���Ӓl�Q�Ƃɂ͂��Ȃ��B
  COMM_MONOID m_M;

public:
  inline AbstractHeldKarp( GRAPH& G , COMM_MONOID M , const U& infty );
  inline U GetDistance( const T& t_start , const vector<T>& t_factor , const T& t_final , const bool& revisitable );
  vector<U> GetDistance( const T& t_start , const vector<T>& t_factor , const bool& revisitable );

};
template <typename GRAPH , typename U , typename COMM_MONOID> AbstractHeldKarp( GRAPH& G , COMM_MONOID M , const U& infty ) -> AbstractHeldKarp<inner_t<GRAPH>,GRAPH,U,COMM_MONOID>;

template <typename T , typename GRAPH>
class HeldKarp :
  public AbstractHeldKarp<T,GRAPH,ll,AdditiveMonoid<ll>>
{

public:
  inline HeldKarp( GRAPH& G , const ll& infty = 1e18 );

};
template <typename GRAPH , typename...ARGS> HeldKarp( GRAPH& G , const ARGS&... args ) -> HeldKarp<inner_t<GRAPH>,GRAPH>;

// -���_0�ȊO��x�������K��ł��Ȃ��ꍇ��revistable = false�Ƃ���
//  vector<int> factor( N - 1 ); FOR( i , 1 , N ){ factor[i-1] = i; }
// -���_0���܂߂Ĉ�x�������K��ł��Ȃ��ꍇ��revistable = false�Ƃ���
//  vector<int> factor( N - 1 ); FOR( i , 1 , N ){ factor[i-1] = i; }
// �Ƃ���K�v�����邱�Ƃɒ��ӁB

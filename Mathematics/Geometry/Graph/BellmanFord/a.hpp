// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BellmanFord/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../Algebra/Monoid/a.hpp"

// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/GRL_1_B/judge/8795916/C++17�i�o�H�����Ȃ��j

// GRAPH�̓O���tG=(V_G,E_G:T->(T \times U)^{< \omega})�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (0) M�͑S���������m�C�h�\���ł���B
// (1) infty��E_G�̒l�̊e�����̑�2����|V_G|�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O(|V_G| |E_G|)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(|V_G| |E_G|)
template <typename GRAPH , typename MONOID , typename U>
class AbstractBellmanFord :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  // �R���X�g���N�^�Ɉ������K�v��MultiplicativeMonoid�Ȃǂ�static�����o�֐��ɂ��
  // �Q�ƕԂ������ɂ����A�R���X�g���N�^�̕Ԃ�l�ł���E�Ӓl���󂯎�邱�Ƃ����e�������̂�
  // ���Ӓl�Q�Ƃɂ͂��Ȃ��B
  MONOID m_M;

public:
  inline AbstractBellmanFord( GRAPH& G , MONOID M , const U& infty );

  // ���̕H�����݂����false�A���݂��Ȃ����true���1�����ɕԂ��B
  tuple<bool,vector<U>> GetDistance( const inner_t<GRAPH>& t_start , const bool& dummy = true );
  template <template <typename...> typename V> tuple<bool,vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& dummy = true );
  tuple<bool,vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const bool& dummy = true );
  
};

template <typename GRAPH>
class BellmanFord :
  public AbstractBellmanFord<GRAPH,AdditiveMonoid<>,ll>
{

public:
  inline BellmanFord( GRAPH& G );
  
};

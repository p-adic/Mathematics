// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/01/a.hpp

#pragma once
#include "../../a.hpp"

// verify:
// https://yukicoder.me/submissions/953236�iGetWeight�j

// GRAPH��{0,1}�ʐF�t����Edge:T->(T \times \{0,1\})^{< \omega}�����O���t�ɑ�������^�B

// �\�z O(1)/O(|V_G|)�i��������/�������j
// Next()�̔�����init���瓞�B�\�Ȓ��_��S�T�� O(init�̘A�������ɂ�����ӂ̖{��)
// Next()�̔�����Shift()�őS�T�� O(|V_G|+|E_G|)
// init����̓��B�\������Ƌ����v�Z O(init�̘A�������ɂ�����ӂ̖{��)
template <typename T , typename GRAPH>
class ZeroOneBreadthFirstSearch
{

protected:
  GRAPH& m_G;
  // ���K��_��m_prev�Ɋi�[���邽�߂̕ϐ��Bm_next����̎���Next()�̖߂�l�B
  T m_not_found;
  bool m_initialised;
  // ���̒T���_�������i�[�B
  list<T> m_next;

  // �ȉ�GRAPH��Graph�łȂ��ꍇ�͓Y����Enumeration�����ނ��Ƃɒ��ӁB
  // 0:���ڑ��A1:�O�ɐڑ��A2:���ɐڑ��A3:�T���ς�
  vector<int> m_found;
  // ���B�ς݂����B�ς݂̓_����ӂ�H���ē��B�����ꍇ�A���̓_���i�[�B
  vector<T> m_prev;
  // �T�����_�̎n�_����̏d�݂��i�[�B
  vector<int> m_weight;
  
public:
  inline ZeroOneBreadthFirstSearch( GRAPH& G , const T& not_found );
  template <typename Arg> inline ZeroOneBreadthFirstSearch( GRAPH& G , const T& not_found , Arg&& init );

  // m_next��m_found��m_prev��m_weight������������B
  inline void Initialise();
  // m_next��m_found��m_prev��m_weight���������������init���ŏ��̒T���_�ɐݒ肷��B
  inline void Initialise( const T& init );
  inline void Initialise( list<T> inits );
  // m_next���������������m_found��m_prev��m_weight��񏉊�������init�����̒T���_�ɐݒ肷��B
  inline void Shift( const T& init );
  inline void Shift( list<T> inits );

  inline const int& size() const;
  inline int& found( const T& t );
  inline const T& prev( const T& t );
  inline const int& weight( const T& t );

  T Next();

  // m_next�Ɋi�[����Ă��関���B�_�i���������_�ł�init/inits�j���瓞�B�ł��関���B�_�̏d�݂�
  // m_weight�Ɋi�[���A���B�ł��Ȃ������B�_������B�_�͏d�݂̑����-1���i�[�B
  inline void SetWeight();
  // m_next�Ɋi�[����Ă��関���B�_�i���������_�ł�init/inits�j����goal�̐[�����v�Z���A
  // m_weight�Ɋi�[������ŎQ�ƂŕԂ��B
  inline const int& GetWeight( const T& t_goal );

};

// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/01/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/946047�i�o�H�����Ȃ��j

// GRAPH��{0,1}�ʐF�t����Edge:N->(N \times \{0,1\})^{< \omega}�����O���t�ɑ�������^�B

// �\�z O(1)/O(|V_G|)�i��������/�������j
// Next()�̔�����init���瓞�B�\�Ȓ��_��S�T�� O(init�̘A�������ɂ�����ӂ̖{��)
// Next()�̔�����Shift()�őS�T�� O(|V_G|+|E_G|)
// init����̓��B�\������Ƌ����v�Z O(init�̘A�������ɂ�����ӂ̖{��)
template <typename GRAPH>
class ZeroOneBreadthFirstSearch
{

protected:
  GRAPH& m_G;
  bool m_initialised;
  // ���̒T���_�������i�[�B
  list<int> m_next;
  // 0:���ڑ��A1:�O�ɐڑ��A2:���ɐڑ��A3:�T���ς�
  vector<int> m_found;
  // ���B�ς݂����B�ς݂̓_����ӂ�H���ē��B�����ꍇ�A���̓_���i�[�B
  vector<int> m_prev;
  // �T�����_�̎n�_����̏d�݂��i�[�B
  vector<int> m_weight;
  
public:
  inline ZeroOneBreadthFirstSearch( GRAPH& G );
  inline ZeroOneBreadthFirstSearch( GRAPH& G , const int& init );

  // m_next��m_found��m_prev��m_weight������������B
  inline void Initialise();
  // m_next��m_found��m_prev��m_weight���������������init���ŏ��̒T���_�ɐݒ肷��B
  inline void Initialise( const int& init );
  // m_next���������������m_found��m_prev��m_weight��񏉊�������init�����̒T���_�ɐݒ肷��B
  inline void Shift( const int& init );

  inline const int& size() const;
  inline int& found( const int& i );
  inline const int& prev( const int& i );
  inline const int& weight( const int& i );

  int Next();

  // �ŏ��̖����B�_�i���������_�ł�init�j���瓞�B�ł��関���B�_�̏d�݂�m_weight�Ɋi�[���A
  // ���B�ł��Ȃ������B�_������B�_�͏d�݂̑����-1���i�[�B
  inline void SetWeight();
  // ���������Next()�̔�����init����goal�܂ł̏d�݂��v�Z����B
  inline const int& GetWeight( const int& init , const int& goal );

};

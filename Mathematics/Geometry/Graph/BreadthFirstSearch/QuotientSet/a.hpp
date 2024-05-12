// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/QuotientSet/a.hpp

#pragma once
#include "a.hpp"

//verify:
// https://yukicoder.me/submissions/981290�iShift,Next�j

// GRAPH�͕�Edge:T->(T \times ...)^{< \omega}������MemorisationGraph�łȂ�
// ���S�O���t�ɑ�������^�B

// �\�z O(1)/O(|V_G|)�i��������/�������j
// Next()�̔�����init���瓞�B�\�Ȓ��_��S�T�� O(init�̘A�������ɂ�����ӂ̖{��)
// Next()�̔�����Shift()�őS�T�� O(|V_G|+|E_G|)
// init����̓��B�\������Ɛ[���v�Z O(init�̘A�������ɂ�����ӂ̖{��)
// �A�������̐F�����Ɛ����グ O(|V_G|+|E_G|) 
template <typename T , typename GRAPH>
class QuotientSetSearch
{

protected:
  GRAPH& m_G;
  // ���K��_��m_prev�Ɋi�[���邽�߂̕ϐ��Bm_next����̎���Next()�̖߂�l�B
  T m_not_found;
  // ���̒T���_�������i�[�B�iInitialise��Shift�ł��������Ȃ��̂�vector�ł悢�j
  vector<T> m_next;

  // �ȉ�GRAPH��Graph�łȂ��ꍇ�͓Y����Enumeration�����ނ��Ƃɒ��ӁB
  // �A�������S�̂�T���ς݂��ۂ����i�[�B
  vector<bool> m_found;
  // ���l�ނ̑�\�����i�[�B
  // GRAPH��Graph�łȂ��ꍇ�͓Y����Enumeration�����ނ��Ƃɒ��ӁB
  vector<T> m_repr;

public:
  inline QuotientSetSearch( GRAPH& G , const T& not_found );
  template <typename Arg> inline QuotientSetSearch( GRAPH& G , const T& not_found , Arg&& init );

  // m_found��m_prev������������B
  inline void Initialise();
  // m_next��m_found���������������init���ŏ��̒T���_�ɐݒ肷��B
  inline void Initialise( const T& init );
  inline void Initialise( vector<T> inits );
  // m_next���������������m_found��񏉊�������init�����̒T���_�ɐݒ肷��B
  inline void Shift( const T& init );
  inline void Shift( vector<T> inits );

  // G�̃T�C�Y���擾�B
  inline const int& size() const noexcept;
  inline vector<bool>::reference found( const T& t );
  inline const T& repr( const T& t );

  inline T Next();

  // �A�������̑�\���ɂ��F�����ƘA�����������i�[�B
  pair<const vector<T>&,int> Get();

};

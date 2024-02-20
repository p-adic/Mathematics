// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/953232�i��n�_Shift�̔����ɂ�鑽�_BFS�ł̑S�T���j
// https://yukicoder.me/submissions/953226�iSetConnectedComponent�j
// https://yukicoder.me/submissions/953225�i��n�_��GetDistance�j

// GRAPH�͕�Edge:T->T^{< \omega}�����O���t�ɑ�������^�B

// �\�z O(1)/O(|V_G|)�i��������/�������j
// Next()�̔�����init���瓞�B�\�Ȓ��_��S�T�� O(init�̘A�������ɂ�����ӂ̖{��)
// Next()�̔�����Shift()�őS�T�� O(|V_G|+|E_G|)
// init����̓��B�\������Ɛ[���v�Z O(init�̘A�������ɂ�����ӂ̖{��)
// �A�������̐F�����Ɛ����グ O(|V_G|+|E_G|) 
template <typename T , typename GRAPH>
class VirtualBreadthFirstSearch
{

protected:
  GRAPH& m_G;
  // ���K��_��m_prev�Ɋi�[���邽�߂̕ϐ��Bm_next����̎���Next()�̖߂�l�B
  T m_not_found;
  bool m_initialised;
  // ���̒T���_�������i�[�B
  list<T> m_next;

  // �ȉ�GRAPH��Graph�łȂ��ꍇ�͓Y����Enumeration�����ނ��Ƃɒ��ӁB
  // m_next�Ɋi�[���ꂽ���Ƃ����邩�ۂ��B
  vector<bool> m_found;
  // ���B�ς݂����B�ς݂̓_����ӂ�H����Next()�œ��B�����ꍇ�A���̓_���i�[�B
  // GRAPH��Graph�łȂ��ꍇ�͓Y����Enumeration�����ނ��Ƃɒ��ӁB
  vector<T> m_prev;

public:
  inline VirtualBreadthFirstSearch( GRAPH& G , const T& not_found );
  template <typename Arg> inline VirtualBreadthFirstSearch( GRAPH& G , const T& not_found , Arg&& init );

  // m_next��m_found��m_prev������������B
  inline void Initialise();
  // m_next��m_found��m_prev���������������init���ŏ��̒T���_�ɐݒ肷��B
  inline void Initialise( const T& init );
  inline void Initialise( list<T> inits );
  // m_next���������������m_found��m_prev��񏉊�������init�����̒T���_�ɐݒ肷��B
  inline void Shift( const T& init );
  inline void Shift( list<T> inits );

  inline const int& size() const noexcept;
  inline vector<bool>::reference found( const T& t );
  inline const T& prev( const T& t );

  inline T Next();

  // �ȉ�T==int����GRAPH��Graph�ł���ꍇ�ɂ̂݃T�|�[�g�B
  // m_next�Ɋi�[����Ă��関���B�_�i���������_�ł�init/inits�j���瓞�B�ł��関���B�_�̐[�����i�[���A
  // ���B�ł��Ȃ������B�_������B�_�͐[���̑����-1���i�[�B
  vector<int> GetDistance();
  // �����O���t�ł���ꍇ�ɂ̂݃T�|�[�g�B
  // �����B�_�̑S�̂̂Ȃ������O���t�ɂ�����A�������̐F�����ƘA�����������i�[�B
  void SetConnectedComponent( vector<int>& cc_num , int& count );

private:
  virtual void Push( list<T>& next , const T& t ) = 0;

};

template <typename T , typename GRAPH>
class BreadthFirstSearch :
  public VirtualBreadthFirstSearch<T,GRAPH>
{

public:
  template <typename...Args> inline BreadthFirstSearch( GRAPH& G , const T& not_found , Args&&... args );

private:
  inline void Push( list<T>& next , const T& t );

};


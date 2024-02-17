// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/945886�i���_BFS�ɂ��S�T���j
// https://yukicoder.me/submissions/945907�i���_BFS�ɂ��A�������擾�j
// https://yukicoder.me/submissions/951954�iGetDistance�j

// GRAPH�͕�Edge:N->N^{< \omega}�����O���t�ɑ�������^�B

// �\�z O(1)/O(|V_G|)�i��������/�������j
// Next()�̔�����init���瓞�B�\�Ȓ��_��S�T�� O(init�̘A�������ɂ�����ӂ̖{��)
// Next()�̔�����Shift()�őS�T�� O(|V_G|+|E_G|)
// init����̓��B�\������Ɛ[���v�Z O(init�̘A�������ɂ�����ӂ̖{��)
// �A�������̐F�����Ɛ����グ O(|V_G|+|E_G|) 
template <typename GRAPH>
class VirtualBreadthFirstSearch :
  public PointedSet<int>
{

protected:
  GRAPH& m_G;
  bool m_initialised;
  // ���̒T���_�������i�[�B
  list<int> m_next;
  // ���B�ς݂��ۂ����i�[�B
  vector<bool> m_found;
  // ���B�ς݂����B�ς݂̓_����ӂ�H���ē��B�����ꍇ�A���̓_���i�[�B
  vector<int> m_prev;

public:
  inline VirtualBreadthFirstSearch( GRAPH& G );
  inline VirtualBreadthFirstSearch( GRAPH& G , const int& init );

  // m_next��m_found��m_prev������������B
  inline void Initialise();
  // m_next��m_found��m_prev���������������init���ŏ��̒T���_�ɐݒ肷��B
  inline void Initialise( const int& init );
  // m_next���������������m_found��m_prev��񏉊�������init�����̒T���_�ɐݒ肷��B
  inline void Shift( const int& init );

  inline const int& size() const noexcept;
  inline vector<bool>::reference found( const int& i );
  inline const int& prev( const int& i );

  inline int Next();

  // �ŏ��̖����B�_�i���������_�ł�init�j���瓞�B�ł��関���B�_�̐[�����i�[���A
  // ���B�ł��Ȃ������B�_������B�_�͐[���̑����-1���i�[�B
  vector<int> GetDistance();
  // �����O���t�ł���ꍇ�ɂ̂݃T�|�[�g�B
  // �����B�_�̑S�̂̂Ȃ������O���t�ɂ�����A�������̐F�����ƘA�����������i�[�B
  void SetConnectedComponent( vector<int>& cc_num , int& count );

private:
  virtual void Push( list<int>& next , const int& i ) = 0;

};

template <typename GRAPH>
class BreadthFirstSearch :
  public VirtualBreadthFirstSearch<GRAPH>
{

public:
  template <typename...Args> inline BreadthFirstSearch( GRAPH& G , const Args&... args );

private:
  inline void Push( list<int>& next , const int& i );

};


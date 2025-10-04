// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/Debug/a.hpp

#pragma once
// �f�o�b�O�o�͂ƃC���X�^���XID��ǉ��������́B
// �e�T���X�e�b�v�̌v�Z�ʂ�O(V)�ǉ�����邱�Ƃɒ��ӁB

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
  // ���B�ς݂����B�ς݂̓_����ӂ�H����Next()�œ��B����ꍇ�A
  // ���߂ē��B���鎞�ɒʂ�ӂ̎n�_���i�[�B
  // GRAPH��Graph�łȂ��ꍇ�͓Y����Enumeration�����ނ��Ƃɒ��ӁB
  vector<T> m_prev;

  string m_ID;

public:
  inline VirtualBreadthFirstSearch( GRAPH& G , const T& not_found );
  // �n�_��init�ɐݒ肷��B
  template <typename Arg> inline VirtualBreadthFirstSearch( GRAPH& G , const T& not_found , Arg&& init );

  // m_next��m_found��m_prev������������B
  inline void Initialise();
  // m_next��m_found��m_prev���������������init���ŏ��̒T���_�ɐݒ肷��B
  inline void Initialise( const T& init );
  template <template <typename...> typename VEC> inline void Initialise( VEC<T> inits );
  // m_next���������������m_found��m_prev��񏉊�������init�����̒T���_�ɐݒ肷��B
  inline void Shift( const T& init );
  template <template <typename...> typename VEC> inline void Shift( VEC<T> inits );

  // G�̃T�C�Y���擾�B
  inline const int& size() const noexcept;
  inline vector<bool>::reference found( const T& t );
  inline const T& prev( const T& t );

  inline T Next();

  // m_next�Ɋi�[����Ă��関���B�_�i���������_�ł�init/inits�j���瓞�B�ł��関���B�_�̐[����
  // �i�[�����z���Ԃ��B���������B�ł��Ȃ������B�_������B�_�͐[���̑����-1���i�[����B
  template <typename U = T> auto GetDistance() -> enable_if_t<is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,Map<T,int>>;
  template <typename U = T> auto GetDistance() -> enable_if_t<!is_same_v<GRAPH,MemorisationGraph<U,decldecay_t(declval<GRAPH>().edge())>>,vector<int>>;
  
  // GRAPH��MemorisationGraph�łȂ������O���t�i�̗L�����j�ł���ꍇ�ɂ̂݃T�|�[�g�B
  // {�����B�_�̑S�̂̂Ȃ������O���t�ɂ�����A�������̐F����,���̋t��,�F�̎�ސ�}���i�[�B
  tuple<vector<int>,vector<vector<T>>,int> GetConnectedComponent();

  // m_next�Ɋi�[����Ă��関���B�_���瓞�B�ł��関���B�_��T�����Ɋi�[����B
  vector<T> GetNodeEnumeration();
  
  // m_next�Ɋi�[����Ă��関���B�_���瓞�B�ł��関���B�_���A�肪�����Ɋi�[����B
  // �s���������̋t���ł͂Ȃ����Ƃɒ��ӁB
  vector<T> GetReversedNodeEnumeration();

private:
  virtual void Push( list<T>& next , const T& t ) = 0;
  template <typename PATH> inline void Push( list<T>& next , const PATH& p );

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


// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Function/Map/a.hpp"

// verify:
// https://yukicoder.me/submissions/942862�iDijstra�j
// https://yukicoder.me/submissions/942864�iMemorisationDijkstra�j
// https://yukicoder.me/submissions/942865�iEnumerationDijkstra�j
// https://yukicoder.me/submissions/942866�iEnumerationDijkstra�j

// E�͎ʑ�edge:T->(T \times U)^{< \omega}�ɑ�������^�B
// ���������s������ꍇ��E�̒�`��O�v�Z���Ȃ��ł��̓s�x�v�Z�����邱�ƁB
// O((size+|edge|)log size)���Ԃɍ���Ȃ��ꍇ�́A
// �n�_����̋������i�[���Ĉ�ԋ߂����K��_��S�T��ŒT���������X�V����O(size^2)�ł������B
template <typename T , typename U , typename E>
class Dijkstra_Body
{

protected:
  int m_size;

private:
  U m_infty;
  U m_found;
  E m_edge;

public:
  inline Dijkstra_Body( const int& size , const U& infty , const U& found , E edge );
  // �o�H�����݂��Ȃ��ꍇ�̕Ԃ�l��m_infty
  U Solve( const T& t_start , const T& t_final );
  U Solve( const T& t_start , const T& t_final , list<T>& path );
  void Solve( const T& t_start , vector<U>& weight );
  void Solve( const T& t_start , vector<U>& weight , vector<list<T>>& path );
  
  const U& Infty() const;
  
private:
  virtual const U& Unit() const = 0;
  virtual U Addition( const U& , const U& ) const = 0;
  virtual T e( const int& i ) = 0;
  virtual int e_inv( const T& t ) = 0;
  virtual void Reset();

};

// ���͈͓͂̔��ŗv��
// (1) edge�̒l�̊e�����̑�2������0�ȏ�ł���B
// (2) 2^{31}-1��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// (6) V�̊e�v�fu,v�ɑ΂��A��u->v���������݂���ꍇ�͏d�݂��ŏ��̂��̂��O��push����Ă���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|edge|)log size)
// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H��������O((size+|edge|)log size)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|edge|)log size)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(size^2 + |edge| log size)
template <typename E>
class Dijkstra :
  public Dijkstra_Body<int,ll,E>
{

public:
  inline Dijkstra( const int& size , E edge );
  
private:
  inline const ll& Unit() const;
  inline ll Addition( const ll& , const ll& ) const;
  inline int e( const int& i );
  inline int e_inv( const int& t );

};

template <typename T , typename U , typename M_U , typename E_U , typename E>
class MonoidForDijkstra :
  public Dijkstra_Body<T,U,E>
{

private:
  M_U m_m_U;
  E_U m_e_U;

public:
  inline MonoidForDijkstra( const int& size , M_U m_U , E_U e_U , const U& infty , const U& found , E edge );

private:
  inline const U& Unit() const;
  inline U Addition( const U& , const U& ) const;

};

// ���͈͓͂̔��ŗv��
// (1) edge�̒l�̊e�����̑�2������e_U()�ȏ�ł���B
// (2) infty��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\���邢���Ȃ鍀�����傫���B
// (3) found��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\�����Ainfty�Ƃ��قȂ�B
// (4) (U,m_U:U^2->U,e_U:1->U)��bool operator<(const U&,const U&)�Ɋւ��đS�������m�C�h�ł���B
// (6) V�̊e�v�fu,v�ɑ΂��A��u->v���������݂���ꍇ�͏d�݂��ŏ��̂��̂��O��push����Ă���B
// (7) edge�̓f�t�H���g�����ɂ��Ăяo���\�i���_�⏕�ɗp����j
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|edge|)(log size)^2)
// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H��������O((size+|edge|)(log size)^2)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|edge|)(log size)^2)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(size^2 log size + |edge|(log size)^2)
template <typename T , typename U , typename M_U , typename E_U , typename E>
class MemorisationDijkstra :
  public MonoidForDijkstra<T,U,M_U,E_U,E>
{

private:
  int m_length;
  Map<T,int> m_memory;
  vector<T> m_memory_inv;

public:
  template <typename U2> inline MemorisationDijkstra( const int& size , M_U m_U , E_U e_U , const U& infty , const U2& found , E edge );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );
  inline void Reset();

};
template<typename U , typename U2 , typename M_U , typename E_U , typename E> MemorisationDijkstra( const int& , M_U , E_U , const U& , const U2& , E ) -> MemorisationDijkstra<decltype(declval<E>()(0).front().first),U,M_U,E_U,E>;

// ���͈͓͂̔��ŗv��
// (1) edge�̒l�̊e�����̑�2������e_U()�ȏ�ł���B
// (2) infty��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\���邢���Ȃ鍀�����傫���B
// (3) found��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\�����Ainfty�Ƃ��قȂ�B
// (4) (U,m_U:U^2->U,e_U:1->U)��bool operator<(const U&,const U&)�Ɋւ��đS�������m�C�h�ł���B
// (5) (enum_T,enum_T_inv)���݂��ɋt�ʑ��ł���B
// (6) V�̊e�v�fu,v�ɑ΂��A��u->v���������݂���ꍇ�͏d�݂��ŏ��̂��̂��O��push����Ă���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|edge|)log size)
// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H��������O((size+|edge|)log size)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|edge|)log size)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(size^2 + |edge| log size)
template <typename T , typename Enum_T , typename Enum_T_inv , typename U , typename M_U , typename E_U , typename E>
class EnumerationDijkstra :
  public MonoidForDijkstra<T,U,M_U,E_U,E>
{

private:
  Enum_T m_enum_T;
  Enum_T_inv m_enum_T_inv;
  
public:
  template <typename U2> inline EnumerationDijkstra( const int& size , Enum_T enum_T , Enum_T_inv enum_T_inv , M_U m_U , E_U e_U , const U& infty , const U2& found , E edge );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );

};
template<typename Enum_T , typename Enum_T_inv , typename U , typename U2 , typename M_U , typename E_U , typename E> EnumerationDijkstra( const int& , Enum_T , Enum_T_inv , M_U , E_U , const U& , const U2& , E ) -> EnumerationDijkstra<decltype(declval<Enum_T>()(0)),Enum_T,Enum_T_inv,U,M_U,E_U,E>;

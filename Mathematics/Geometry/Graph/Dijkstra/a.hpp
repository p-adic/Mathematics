// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Function/Map/a.hpp"

// verify:
// https://yukicoder.me/submissions/942531
// https://yukicoder.me/submissions/942534

// ���������s������ꍇ��E�̒�`��O�v�Z���Ȃ��ł��̓s�x�v�Z�����邱�ƁB
// O((size+|E|)log size)���Ԃɍ���Ȃ��ꍇ�́A
// �n�_����̋������i�[���Ĉ�ԋ߂����K��_��S�T��ŒT���������X�V����O(size^2)�ł������B
template <typename T , typename U , list<pair<T,U> > E(const T&)>
class DijkstraBody
{

private:
  int m_size;
  U m_infty;
  U m_found;

public:
  inline DijkstraBody( const int& size , const U& infty , const U& found );
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
  virtual void Reset() = 0;

};

// ���͈͓͂̔��ŗv��
// (1) E�̒l�̊e�����̑�2������0�ȏ�ł���B
// (2) 2^{31}-1��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\���邢���Ȃ鐔�����傫���B
// (6) V�̊e�v�fu,v�ɑ΂��A��u->v���������݂���ꍇ�͏d�݂��ŏ��̂��̂��O��push����Ă���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|E|)log size)
// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H��������O((size+|E|)log size)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|E|)log size)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(size^2 + |E| log size)
template <list<pair<int,ll> > E(const int&)>
class Dijkstra :
  public DijkstraBody<int,ll,E>
{

public:
  inline Dijkstra( const int& size );
  
private:
  inline const ll& Unit() const;
  inline ll Addition( const ll& , const ll& ) const;
  inline int e( const int& i );
  inline int e_inv( const int& t );
  inline void Reset();

};

// ���͈͓͂̔��ŗv��
// (1) E�̒l�̊e�����̑�2������e_U()�ȏ�ł���B
// (2) infty��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\���邢���Ȃ鍀�����傫���B
// (3) found��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\�����Ainfty�Ƃ��قȂ�B
// (4) (U,m_U:U^2->U,e_U:1->U)��bool operator<(const U&,const U&)�Ɋւ��đS�������m�C�h�ł���B
// (6) V�̊e�v�fu,v�ɑ΂��A��u->v���������݂���ꍇ�͏d�݂��ŏ��̂��̂��O��push����Ă���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|E|)(log size)^2)
// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H��������O((size+|E|)(log size)^2)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|E|)(log size)^2)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(size^2 log size + |E|(log size)^2)
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&)>
class MemorisationDijkstra :
  public DijkstraBody<T,U,E>
{

private:
  int m_length;
  Map<T,int> m_memory;
  vector<T> m_memory_inv;

public:
  inline MemorisationDijkstra( const int& size , const U& infty = 9223372036854775807 , const U& found = -1 );
  
private:
  inline const U& Unit() const;
  inline U Addition( const U& , const U& ) const;
  inline T e( const int& i );
  inline int e_inv( const T& t );
  inline void Reset();

};

// ���͈͓͂̔��ŗv��
// (1) E�̒l�̊e�����̑�2������e_U()�ȏ�ł���B
// (2) infty��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\���邢���Ȃ鍀�����傫���B
// (3) found��E�̒l�̊e�����̑�2����size�ȉ��̘a�ŕ\�����Ainfty�Ƃ��قȂ�B
// (4) (U,m_U:U^2->U,e_U:1->U)��bool operator<(const U&,const U&)�Ɋւ��đS�������m�C�h�ł���B
// (5) (enum_T,enum_T_inv)���݂��ɋt�ʑ��ł���B
// (6) V�̊e�v�fu,v�ɑ΂��A��u->v���������݂���ꍇ�͏d�݂��ŏ��̂��̂��O��push����Ă���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|E|)log size)
// �P��n�_�P��I�_�ŒZ�o�H�T���^�o�H��������O((size+|E|)log size)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H�����Ȃ�O((size+|E|)log size)
// �P��n�_�S�I�_�ŒZ�o�H�T���^�o�H��������O(size^2 + |E| log size)
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , T enum_T(const int&) , int enum_T_inv(const T&)>
class EnumerationDijkstra :
  public DijkstraBody<T,U,E>
{

public:
  inline EnumerationDijkstra( const int& size , const U& infty = 9223372036854775807 , const U& found = -1 );
  
private:
  inline const U& Unit() const;
  inline U Addition( const U& , const U& ) const;
  inline T e( const int& i );
  inline int e_inv( const T& t );
  inline void Reset();

};


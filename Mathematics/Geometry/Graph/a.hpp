// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/a.hpp

#pragma once
#include "a_Macro.hpp"
#includ "../../Algebra/a.hpp"
#includ "../../Function/Map/a.hpp"

// verify:
// https://yukicoder.me/submissions/945899�iGraph�AE:T->list<T>�j
// https://yukicoder.me/submissions/945900�iEnumerationGraph�AE:T->list<T>�j
// https://yukicoder.me/submissions/945907�iMemorisationGraph�AE:T->list<T>�j
// https://yukicoder.me/submissions/945903�iGraph�AE:T->list<T \times N>�j
// https://yukicoder.me/submissions/945905�iEnumerationGraph�AE:T->list<T \times N>�j
// https://yukicoder.me/submissions/945906�iMemorisationGraph�AE:T->list<T \times N>�j

// Enumeration:N->R1-->T��Enumeration_inv:T->R2-->N�݂͌��ɋt�ʑ��ł��鉼�z�֐��B
template <typename T , typename R1 , typename R2 , typename E>
class VirtualGraph :
  virtual public UnderlyingSet<T>;
{

private:
  int m_size;
  // �z��ւ̎Q�Ƃ�Ԃ��֐��I�u�W�F�N�g���\�z���ĕԂ��֐��̕Ԃ�l�Ȃǂ̉E�Ӓl���󂯎�邱�Ƃ�
  // ���e�������̂ō��Ӓl�Q�Ƃɂ͂��Ȃ��B
  E m_edge;

public:
  inline VirtualGraph( const int& size , E edge );
  virtual R1 Enumeration( const int& i ) = 0;
  virtual R2 Enumeration_inv( const T& t ) = 0;
  inline void Reset();
  inline const int& size() const noexcept;
  inline E& edge() noexcept;
  inline ret_t<E,T> Edge( const T& t );

};

template <typename E>
class Graph :
  virtual public VirtualGraph<int,const int&,const int&,E>
{
  
public:
  inline Graph( const int& size , E edge );
  inline const int& Enumeration( const int& i );
  inline const int& Enumeration_inv( const int& t );
  template <typename F> inline Graph<F> GetGraph( F edge ) const;

};

template <typename T , typename Enum_T , typename Enum_T_inv , typename E>
class EnumerationGraph :
  virtual public VirtualGraph<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>
{

private:
  Enum_T& m_enum_T;
  Enum_T_inv& m_enum_T_inv;
  
public:
  inline EnumerationGraph( const int& size , Enum_T& enum_T , Enum_T_inv& enum_T_inv , E edge );
  inline ret_t<Enum_T,int> Enumeration( const int& i );
  inline ret_t<Enum_T_inv,T> Enumeration_inv( const T& t );
  template <typename F> inline EnumerationGraph<T,Enum_T,Enum_T_inv,F> GetGraph( F edge ) const;

};
template <typename Enum_T , typename Enum_T_inv , typename E> EnumerationGraph( const int& size , Enum_T enum_T , Enum_T_inv enum_T_inv , E edge ) -> EnumerationGraph<decldecay_t(declval<Enum_T>()(0)),Enum_T,Enum_T_inv,E>;

// ���_�⏕�̂��߂�E::operator()�̓f�t�H���g�������K�v�B
template <SFINAE_FOR_GRAPH = nullptr>
class MemorisationGraph :
  virtual public VirtualGraph<T,T,const int&,E>
{

private:
  int m_length;
  vector<T> m_memory;
  Map<T,int> m_memory_inv;
  
public:
  inline MemorisationGraph( const int& size , E edge );
  // push_back����\���̂���vector�Ȃ̂ŎQ�Ƃɂ��Ȃ��悤�ɒ���
  inline T Enumeration( const int& i );
  inline const int& Enumeration_inv( const T& t );
  inline void Reset();
  template <typename F> inline MemorisationGraph<T,F> GetGraph( F edge ) const;

};
template <typename E> MemorisationGraph( const int& size , E edge ) -> MemorisationGraph<decldecay_t(declval<E>()().back()),E>;
template <typename E> MemorisationGraph( const int& size , E edge ) -> MemorisationGraph<decldecay_t(get<0>(declval<E>()().back())),E>;

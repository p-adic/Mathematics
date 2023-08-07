// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/CumulativeProd/a.hpp

#pragma once
#include "../../../../Geometry/Graph/DepthFirstSearch/Tree/a.hpp"

// ���͈͓͂̔��ŗv��
// (1) (T,m_T:T^2->T,i_T:T->T)���Q�ł���B
// �����藧�ꍇ�̂݃T�|�[�g�B�i�P�ʌ��͈����ɓn���Ȃ��Ă悢�j
template <typename T , T m_T(const T&,const T&), T i_T(const T&) , int size_max>
class CumulativeProd_Body
{

protected:
  int m_size;
  T m_a[size_max];
  T m_a_reverse[size_max];

public:
  inline CumulativeProd_Body( const int& size );
  // i����ւ�path��i=v_0->...->v_k=j�̎�m_a[v_0]...m_a[v_k]��
  // Prod��t����Prod�Ɋւ��Čv�Z����B
  inline T PathProd( const int& i , const int& j );

private:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};


// �ʏ�̔z���̗ݐϐρB
template <typename T , T m_T(const T&,const T&), T i_T(const T&) , int size_max>
class CumulativeProd
{

public:
  inline CumulativeProd( const T ( &a )[size_max] , const int& size );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};


// �؏�̗ݐϐρB

// ���͈͓͂̔��ŗv��
// (2) �O���t(V,E)�͖����O���t�Ƃ��Ė؂ł���B
// (3) 0�����Ƃ������̊e�m�[�h�̍�����2^digit�����ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <typename T , T m_T(const T&,const T&), T i_T(const T&) , list<int> E(const int&) , int size_max , int digit>
class CumulativeProdOnTree
{

private:
  DepthFirstSearchOnTree<size_max,E,digit> m_dfst;

public:
  inline CumulativeProdOnTree( const T ( &a )[size_max] , const int& V );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};

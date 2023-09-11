// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/Tree/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Geometry/Graph/DepthFirstSearch/Tree/a.hpp"

// �؏�̗ݐϐρB

// ���͈͓͂̔��ŗv��
// (1) (T,m_T:T^2->T,i_T:T->T)���Q�ł���B
// (2) �O���t(V,E)�͖����O���t�Ƃ��Ė؂ł���B
// (3) 0�����Ƃ������̊e�m�[�h�̍�����2^digit�����ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , list<int> E(const int&) , int size_max , int digit>
class CumulativeProdOnTree �F
  public CumulativeProd_Body<T,m_T,i_T,size_max>
{

private:
  DepthFirstSearchOnTree<size_max,E,digit> m_dfst;

public:
  inline CumulativeProdOnTree( const T ( &a )[size_max] , const int& V );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};

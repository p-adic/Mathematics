// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/Tree/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Geometry/Graph/DepthFirstSearch/Tree/a.hpp"

// ��ʂ̖؏�̗ݐϐρB
// ���͈͓͂̔��ŗv��
// (1) M��U�̌Q�\���ł���B
// (2) T�������O���t�Ƃ��Ė؂ł���B
// (3) 0�����Ƃ�������T�̊e�m�[�h�̍�����2^digit�����ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <typename TREE , typename GROUP>
class CumulativeProdOnTree :
  public PathProdImplementation<inner_t<GROUP>,GROUP>
{

private:
  DepthFirstSearchOnTree<TREE> m_dfst;

public:
  template <typename V> inline CumulativeProdOnTree( TREE T , const vector<V>& a , const int& digit , GROUP M );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};

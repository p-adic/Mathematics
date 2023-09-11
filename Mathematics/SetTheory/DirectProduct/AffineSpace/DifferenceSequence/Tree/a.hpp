// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/Tree/a.hpp

#pragma once
#include "../a.hpp"

// �X��̊K������B

// ���͈͓͂̔��ŗv��
// (1) �O���t(V,E)�͗L���O���t�Ƃ��Ċe�A�������������؂ł���B
// (2) (V,E)�̊e��v0->v1�ɑ΂�v0 = E_inv(v1)�����藧�B
// (3) (V,E)�̊e�A�������̍�v�ɑ΂�E_inv(v) = v�����藧�B
// (4) (enum_V:N->V,enum_V_inv:V->N)�݂͌��ɋt�ʑ��ł���B
// (5) (V,E)�̊e��v0->v1�ɑ΂�e_inv(v0) < e_inv(v1)�����藧�B
// (6) (T,m_T:T^2->T,e_T:1->T)�͉����m�C�h�ł���B
// (7) (U,inv_U:U->U)��㰓����Z���W���ł���B
// (8) o_U:U�~T->T��(U,inv_U)����(T,m_T,e_T)�̉t���S�̂̌Q�ւ̏����^��m_T�̍����ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B�i�Ⴆ��T�����Q��U=T��o_U��������T�̉��Z�j

// e_T()�ɂ�鏉����O(size_max)

// ��_���O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j
// ��_�擾O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j

// ��_���ZO(1)�i��p��x���]�����Ȃ��j
// �����؉��ZO(1+t_final�̃T�C�Y)�i��p��x���]������j
// ���@O(size)�i��p�̒x���]������������j
template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max>
class DifferenceSequenceOnTree :
  public DifferenceSequenceBody<V,T,U,size_max>
{

public:
  inline DifferenceSequenceOnTree( const int& size );
  
private:
  inline list<V> Edge( const V& v ) const;
  inline V Edge_inv( const V& v ) const;
  inline V e( const int& i ) const;
  inline int e_inv( const V& v ) const;
  inline const T& Unit() const;
  inline T& Addition( const T& t0 , T& t1 ) const;
  inline U Inverse( const U& u ) const;
  inline T& Action( const U& u , T& t ) const;

};

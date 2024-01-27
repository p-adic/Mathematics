// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a.hpp

#pragma once
#include "../../../../Graph/Array/a.hpp"

// ����ɑ΂���imos�@
// https://imoz.jp/algorithms/imos_method.html
// ��X��̉��Q�ɒl�����֐��Ɉ�ʉ������f�[�^�\���B
template <typename T , typename U>
class VirtualDifferenceSequence
{

public:
  // ��p�̒x���]�����������Ă���l��������B
  virtual void Set( const T& t , const U& u ) = 0;
  // ��p�̒x���]�����������Ă���l���Q�Ƃ���B
  virtual const U& Get( const T& t ) = 0;
  // ��p�̒x���]�������������Ɍ��X�̒l���Q�Ƃ���B
  virtual U& Ref( const T& t ) = 0;

  // v�ł̒l��u��x���]�������ɉ��Z����B
  virtual void Add( const T& t , const U& u ) = 0;

  // �v��
  // (1) t_start����t_final�̊e�v�f�ւ̗L���p�X�����݂���B
  // (2) t_final�̗v�f�Ԃ̗L���p�X�����݂��Ȃ��B
  // �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
  // ����
  // (1) t_start����t�ւ̗L���p�X�����݂���B
  // (2) t_final�̂�����̗v�f�����t�ւ̗L���p�X�����݂��Ȃ��B
  // �𖞂���T�̊e�v�ft�ɑ΂��At�ł̒l��u��x���]���ŉ��Z����B
  virtual void SubTreeAdd( const T& t_start , const list<T>& t_final , const U& u ) = 0;

};

// ��ʂ̐X��̊K������B
// ���͈͓͂̔��ŗv��
// (1) G��T�̗L���O���t�Ƃ��Ă̐X�\���ł���B
// (2) M��U�̉��Q�\���ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B
template <typename T , typename FOREST , typename U , typename GROUP>
class AbstractDifferenceSequence
{

protected:
  FOREST m_G;
  list<T> m_root;
  vector<int> m_prev;
  vector<U> m_a;
  vector<U> m_lazy_addition;
  GROUP m_M;
  bool m_updated;

public:
  inline AbstractDifferenceSequence( FOREST G , GROUP M );
  inline AbstractDifferenceSequence( FOREST G , vector<U> a , GROUP M );
  // ��p�̒x���]�����������Ă���l��������B
  inline void Set( const T& t , const U& u );
  // ��p�̒x���]�����������Ă���l���Q�Ƃ���B
  inline const U& Get( const T& t );
  // ��p�̒x���]�������������Ɍ��X�̒l���Q�Ƃ���B
  inline U& Ref( const T& t );

  // t�ł̒l��u��x���]�������ɉ��Z����B
  inline void Add( const T& t , const U& u );
  // t_start�����Ƃ��镔���؂���ut_final�̊e���������Ƃ��镔���؂��獪�����������́v������������
  // �̊e���_�ł̒l��u��x���]�������ɉ��Z����B
  void SubTreeAdd( const T& t_start , const list<T>& t_final , const U& u );

  inline DifferenceSequenceBody<T,U>& operator+=( const DifferenceSequenceBody<T,U>& a );

private:
  // ��p�̒x���]������������B
  void Update();

};
template <typename FOREST , typename GROUP> AbstractDifferenceSequence( FOREST G , GROUP M ) -> AbstractDifferenceSequence<inner_t<FOREST>,FOREST,inner_t<GROUP>,GROUP>;
template <typename FOREST , typename U , typename GROUP> AbstractDifferenceSequence( FOREST G , vector<U> a , GROUP M ) -> AbstractDifferenceSequence<inner_t<FOREST>,FOREST,U,GROUP>;

// �ʏ�̔z���̊K������B
// ���͈͓͂̔��ŗv��
// (2) M��U�̉��Q�\���ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// M.Zero()�ɂ�鏉����O(size_max)
// �z��ɂ�鏉����O(size_max)

// ��_���O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j
// ��_�擾O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j

// ��_���ZO(1)�i��p��x���]�����Ȃ��j
// �n�ؕЉ��ZO(1)�i��p��x���]������j
// �I�ؕЉ��ZO(1)�i��p��x���]������j
// ��ԉ��ZO(1)�i��p��x���]������j
// ���@O(size)�i��p�̒x���]������������j
template <typename U , typename GROUP>
class DifferenceSequence :
  virtual public AbstractDifferenceSequence<LinearGraph,U>
{

public:
  inline DifferenceSequence( const int& size , GROUP M );
  inline DifferenceSequence( vector<U> a , GROUP M );

  inline void InitialSegmentAdd( const int& t_start , const U& u );
  inline void FinalSegmentAdd( const int& t_final , const U& u );
  inline void IntervalAdd( const int& t_start , const int& t_final , const U& u );

};


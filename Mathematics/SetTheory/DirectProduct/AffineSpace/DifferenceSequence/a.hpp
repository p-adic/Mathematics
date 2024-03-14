// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../Graph/Array/a.hpp"

// verify:
// https://yukicoder.me/submissions/950084�iAbstract�A�돉�����A��_�擾�A�����؉��Z�j
// https://yukicoder.me/submissions/953509�iAbstract�A�돉�����A��_�擾�A�����؉��Z�j

// ����ɑ΂���imos�@
// https://imoz.jp/algorithms/imos_method.html
// ��X��̉��Q�ɒl�����֐��Ɉ�ʉ������f�[�^�\���B
// �ݐϘa��BIT�ƈ���āA�ʏ�̔z��ŊǗ��������ɃI�[�o�[�t���[���Ȃ��Ȃ��
// imos�@�ł����܂�I�[�o�[�t���[���Ȃ��̂�U = int�ł��ǂ��B
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
// (2) Prev��G�̐e�m�[�h��Ԃ��֐��I�u�W�F�N�g�ł���B
// (3) M��U�̉��Q�\���ł���B
// (4) G��Eumeration_inv�͏����ۑ��ł���B
//     �܂�C�ӂ̕�v_0->v_1�ɑ΂�G.Enumeration_inv(v_0)<G.Enumeration_inv(v_1)�ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B
// (2),(3)��Update()�̒萔�{�������Ɏg�p�B����炪���藧���Ȃ��Ă��v�Z�ʂ̃I�[�_�[��ς�����
// �����ł��邪����筂����p�Ă��łȂ��B

// M.Zero()�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_���O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j
// ��_�擾O(size)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j

// ��_���ZO(1)�i��p��x���]�����Ȃ��j
// �����؉��ZO(1)�i��p��x���]������j
// ���@O(size)�i��p��x���]�����Ȃ��j
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP>
class AbstractDifferenceSequence
{

protected:
  // �T���A���S���Y���ƈ���ĊO������̃O���t�̕ύX�������Ȃ��B
  FOREST m_G;
  PREV m_Prev;
  GROUP m_M;
  vector<U> m_a;
  vector<U> m_lazy_addition;
  bool m_updated;

public:
  inline AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M );
  inline AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M , vector<U> a );

  inline void Initialise( vector<U> a );
  // ��p�̒x���]�����������Ă���l��������B
  inline void Set( const T& t , const U& u );
  // ��p�̒x���]�����������Ă���l���Q�Ƃ���B
  inline const U& Get( const T& t );
  // ��p�̒x���]�������������Ɍ��X�̒l���Q�Ƃ���B
  inline U& Ref( const T& t );

  // t�ł̒l��u��x���]�������ɉ��Z����B
  inline void Add( const T& t , const U& u );
  // t_start�����Ƃ��镔���؂���ut_final�̊e���������Ƃ��镔���؂��獪�����������́v������������
  // �̊e���_�ł̒l��u��x���]�����ĉ��Z����B
  void SubTreeAdd( const T& t_start , const list<T>& t_final , const U& u );

  inline AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>& operator+=( const vector<U>& a );

private:
  // ��p�̒x���]������������B
  void Update();

};
template <typename FOREST , typename PREV , typename GROUP> AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M ) -> AbstractDifferenceSequence<inner_t<FOREST>,FOREST,PREV,inner_t<GROUP>,GROUP>;
template <typename FOREST , typename PREV , typename U , typename GROUP> AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M , vector<U> ) -> AbstractDifferenceSequence<inner_t<FOREST>,FOREST,PREV,U,GROUP>;

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
template <typename U>
class DifferenceSequence :
  virtual public AbstractDifferenceSequence<int,LinearGraph,int(const int&) noexcept,U,AdditiveGroup<U>>
{

public:
  inline DifferenceSequence( const int& size = 0 );
  inline DifferenceSequence( vector<U> a );

  inline void InitialSegmentAdd( const int& t_start , const U& u );
  inline void FinalSegmentAdd( const int& t_final , const U& u );
  inline void IntervalAdd( const int& t_start , const int& t_final , const U& u );

private:
  static inline int PrevOf( const int& t_start ) noexcept;
  
};


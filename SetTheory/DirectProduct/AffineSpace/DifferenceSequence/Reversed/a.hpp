// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/Reversed/a.hpp

#pragma once

#include "../../../../../Geometry/Graph/Linear/Prev/a.hpp"

// verify:
// https://yukicoder.me/submissions/972253�i�돉�����A��ԉ��Z�A�����؎擾�j
// https://yukicoder.me/submissions/972228�iAbstract�A�돉�����A��ԉ��Z�A��_�擾�j

// ����ɑ΂���imos�@
// https://imoz.jp/algorithms/imos_method.html
// ��X��̉��Q�ɒl�����֐��Ɉ�ʉ������f�[�^�\���𔽓]�������́B
// �t����́i���K�j�K��������Ǘ�����B

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// (2) G��T�̗L���O���t�Ƃ��Ă̐X�\���ł���B
// (3) prev��G.Enumeration_inv�Ɋւ���e�m�[�h�Ƃ̑Ή�N->N \cup {-1}��Ԃ��֐��I�u�W�F�N�g
//     �ł���A���������m�[�h�ɑΉ�����ԍ��ɑ΂��Ă�-1��Ԃ����̂ł���B
// (4) G.Enumeration�͏������^�ł���A
//     �܂�i <= j��G.Enumeration(i) <- G.Enumeration(j)�͓��l�ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B
// (3)��prev��z��őO�v�Z�����|E_G|���傫���ꍇ��筂����Ƃɒ��ӁB
// (4)�����藧���Ȃ��ꍇ��TopologicalSortedForest(G)���g���ăO���t��ύX����B

// M.Zero()�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_���O(min(|m_degree|,|m_degree-1|)*size)
// ��_���ZO(min(|m_degree|,|m_degree-1|)|m_degree|*size)
// �n�ؕЉ��ZO(|m_degree-1|*size)
// ��ԉ��ZO(|m_degree-1|*size)

// ��_�擾O(|m_degree|*size)/O(m_G.Edge(t).size() + |m_degree+1|*size)
// �I�ؕИa�擾O(|m_degree+1|*size)
// �����ؘa�擾O(t_outside.size() + |m_degree+1|*size)
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP>
class AbstractReversedDifferenceSequence
{

protected:
  // �T���A���S���Y���ƈ���ĊO������̃O���t�̕ύX�������Ȃ��B
  FOREST m_G;
  // m_G.Enumeration_inv�Ɋւ���e�m�[�h�Ƃ̑Ή���Ԃ��֐��I�u�W�F�N�g�B
  PREV m_prev;
  GROUP m_M;

  // �t����̊K��������Ǘ��B
  vector<U> m_a;
  // �K������̊K���i-1�̎��͗ݐϘa�j���Ǘ��B
  int m_degree;

public:
  inline AbstractReversedDifferenceSequence( FOREST G , PREV prev , GROUP M , int degree = 1 );
  inline AbstractReversedDifferenceSequence( FOREST G , PREV prev , GROUP M , vector<U> a , int degree = 0 );

  template <typename...Args> inline void Initialise( Args&&... args );

  inline void Set( const T& t , const U& u , const int& degree = 0 );
  // degree�K�̊K�������t�ł̒l��u�����Z����B
  inline void Add( const T& t , const U& u , const int& degree = 0 );

  // degree+1�K�̊K�������p����degree�K�̊K������̒l��u�����Z����B
  inline void InitialSegmentAdd( const T& t_final , const U& u , const int& degree = 0 );
  inline void IntervalAdd( const T& t_start , const T& t_final , const U& u , const int& degree = 0 );

  // 0�K�̒l���擾����B
  inline U operator[]( const T& t );
  // degree�K�̊K������̒l���擾����B
  inline const U& Get( const T& t , const int& degree = 0 );

  inline const U& FinalSegmentSum( const T& t_start , const int& degree = 0 );
  // �v��
  // (1) t_start����t_outsides�̊e�v�f�ւ̗L���p�X�����݂���B
  // (2) t_outsides�̗v�f�����Ƃ��镔���؊Ԃ̌���肪��ł���B
  // �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
  // t_start�����Ƃ��镔���؂���ut_final�̊e���������Ƃ��镔���؁v�����������̂̊e���_��n��
  // degree-1�K�̊K�������p����degree�K�̊K������̒l�̑��a���擾����B
  inline U SubtreeSum( const T& t_start , const vector<T>& t_outisde , const int& degree = 0 );

private:
  inline AbstractReversedDifferenceSequence( FOREST& G , PREV& prev , GROUP& M , vector<U> a , int degree , int dummy );

  inline void Shift( const int& degree );
  inline void Shift( const int& degree_min , const int& degree_max );
  void Integrate();
  void Differentiate();

};
template <typename FOREST , typename PREV , typename GROUP , typename...Args> AbstractReversedDifferenceSequence( FOREST G , PREV orev , GROUP M , Args&&... args ) -> AbstractReversedDifferenceSequence<inner_t<FOREST>,FOREST,PREV,inner_t<GROUP>,GROUP>;

// �ʏ�̔z���̊K��������E�����������́B
// ���͈͓͂̔��ŗv��
// (2) M��U�̉��Q�\���ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// M.Zero()�ɂ�鏉����O(size_max)
// �z��ɂ�鏉����O(size_max)

// ��_���O(min(|m_degree|,|m_degree-1|)*size)
// ��_���ZO(min(|m_degree|,|m_degree-1|)|m_degree|*size)
// �n�ؕЉ��ZO(|m_degree-1|*size)
// ��ԉ��ZO(|m_degree-1|*size)

// ��_�擾O(min(|m_degree|,|m_degree-1|)*size)
// ��Ԙa�擾O(|m_degree+1|*size)
template <typename U = ll>
class ReversedDifferenceSequence :
  virtual public AbstractReversedDifferenceSequence<int,LinearGraph,LinearPrev,U,AdditiveGroup<U>>
{

public:
  inline ReversedDifferenceSequence( const int& size = 0 , int degree = 1 );
  inline ReversedDifferenceSequence( vector<U> a , int degree = 0 );

  inline U IntervalSum( const int& t_start , const int& t_final , const int& degree = 0 );

private:
  inline ReversedDifferenceSequence( const int& size , vector<U>& a , int degree );
  
};


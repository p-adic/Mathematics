// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/a.hpp

#pragma once
#include "../../Linear/a.hpp"
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/941558
// https://yukicoder.me/submissions/941553
// https://yukicoder.me/submissions/941556
// https://atcoder.jp/contests/abc087/submissions/50885973�i�|�e���V�����j

// GRAPH�͕�Edge:T->(T \times ...)^{< \omega}�����O���t�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// - �\�z O(|V_G| + |E_G| ��(|V_G|))

// - ��_���擾 O(��(|V_G|))
// - �S���擾 O(|V_G|)
// - �����擾 O(1)

// - ��_�ԃ|�e���V�����擾 O(��(|V_G|))
// - ��_�ڍ� O(��(|V_G|))
template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
class AbstractUnionFindForest
{

private:
  GRAPH& m_G;
  ABEL_GROUP m_M;
  int m_root_size;
  vector<int> m_pred;
  vector<int> m_height;
  // m_w[num]��num�Ԗڂ�node��root�Ȃ��0�Aroot�łȂ��Ȃ�ΐenode����̃p�X�̕����t���d�݂�Ԃ��B
  // Graft�Ɛ����I�ȉ�x�����݂���ꍇ�ɂ�x[num]-x[�enode]��Ԃ����ƂƓ����B
  vector<U> m_w;
  bool m_solvable;
  
public:
  AbstractUnionFindForest( GRAPH& G , ABEL_GROUP M );

  // t��root���v�Z���ĕԂ��B
  // Enumeration����̂�const�Q�Ƃɂ��Ȃ��B
  const decltype( ( declval<GRAPH>().Enumeration(0) ) ) RootOfNode( const T& );
  // root��S�ĕԂ��B
  template <template <typename...> typename V> vector<T> GetRoot() const;

  // t1����t0�֌������p�X�̕����t���d�݂�Ԃ��B
  // Graft�Ɛ����I�ȉ�x�����݂��鎞��x[t0]-x[t1]�̎擾�Ɠ����B
  inline U Potential( const T& t0 , const T& t1 );

  // ���_����Ԃ�
  inline const int& NodeSize() const noexcept;
  // �A����������Ԃ�
  inline const int& RootSize() const noexcept;

  // t1����t0�֕����t���d��w�̗L���ӂ����ԑ���Ɛ����I��
  // �Ȃ�悤��root��ڍ��B�����t���d�݂̐����������Ȃ��ꍇ��false��Ԃ��B
  // �Ԃ�l��x[t0]-x[t1]=w�̉��̗L���Ɠ����B
  const bool& Graft( const T& t0 , const T& t1 , const U& w = U() );
  template <typename PATH> inline const bool& Graft( const T& t0 , const PATH& t1 );
  const bool& Solvable() const noexcept;
  
};
template <typename GRAPH , typename ABEL_GROUP> AbstractUnionFindForest( GRAPH& G , ABEL_GROUP M ) -> AbstractUnionFindForest<inner_t<GRAPH>,GRAPH,inner_t<ABEL_GROUP>,ABEL_GROUP>;

template <typename U = int>
class UnionFindForest :
  public LinearGraph ,
  public AbstractUnionFindForest<int,LinearGraph,U,AdditiveGroup<U>>
{

public:
  inline UnionFindForest( const int& size );

};

// �A�����ɉ��Z���s���@�\�͂Ȃ��B�i2��a�̊Ǘ��ȂǁA����p�����������肵�����̂Łj
// �O���ɔz���p�ӂ��A�A���������ۂ���RootOfNode�Ŕ��肵�Ȃ���
// ���Z���s���Ƃ悢�B
// (1) �A���������Ƃ̒��_���Ȃ�Avector<int> weight( N , 1 );�Ɖ��Z�B
// (2) �A���������Ƃ̒��_����2��a���Ǘ�����Ȃ�A(1)�ɉ����Đς̔{����������p�B
// (3) �A���������Ƃ̒��_���X�g�Ȃ�vector<vector<int>> vertex = {{0},{1},...,{N-1}}�ƃ}�[�W�B

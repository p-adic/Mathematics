// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/UnionFindForest/a.hpp

#pragma once
#include "../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/941558
// https://yukicoder.me/submissions/941553
// https://yukicoder.me/submissions/941556
// https://atcoder.jp/contests/abc087/submissions/50885973�i�|�e���V�����j

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// - �\�z O(size)

// - ��_���擾 O(��(size))
// - �S���擾 O(size)
// - �����擾 O(1)

// - ��_�ԃ|�e���V�����擾 O(��(size))
// - ��_�ڍ� O(��(size))
template <typename U , typename GROUP>
class AbstractUnionFindForest
{

private:
  GROUP m_M;
  int m_node_size;
  int m_root_size;
  vector<int> m_pred;
  vector<int> m_height;
  // m_w[num]��num�Ԗڂ�node��root�Ȃ��0�Aroot�łȂ��Ȃ�ΐenode����̃p�X�̕����t���d�݂�Ԃ��B
  // Graft�Ɛ����I�ȉ�x�����݂���ꍇ�ɂ�x[num]-x[�enode]��Ԃ����ƂƓ����B
  vector<U> m_w;
  
public:
  inline AbstractUnionFindForest( const int& size , GROUP M );

  // num�Ԗڂ�node��root���v�Z���ĕԂ��B
  const int& RootOfNode( const int& num );
  // root��S�Ċi�[����B
  template <template <typename...> typename V> void SetRoot( V<int>& a ) const;

  // num1�Ԗڂ�node����num0�Ԗڂ�node�֌������p�X�̕����t���d�݂�Ԃ��B
  // Graft�Ɛ����I�ȉ�x�����݂��鎞��x[num0]-x[num1]�̎擾�Ɠ����B
  inline U Potential( const int& num0 , const int& num1 );

  // 
  inline const int& size( const bool& node = true ) const noexcept;

  // num1�Ԗڂ�node����num0�Ԗڂ�node�֕����t���d��w�̗L���ӂ����ԑ���Ɛ����I��
  // �Ȃ�悤��root��ڍ��B�����t���d�݂̐����������Ȃ��ꍇ��false��Ԃ��B
  // �Ԃ�l��x[num0]-x[num1]=w�̉��̗L���Ɠ����B
  bool Graft( const int& num0 , const int& num1 , const U& w = 0 );
  
};
template <typename GROUP> AbstractUnionFindForest( const int& size , GROUP M ) -> AbstractUnionFindForest<inner_t<GROUP>,GROUP>;

template <typename U = int>
class UnionFindForest :
  public AbstractUnionFindForest<U,AdditiveGroup<U>>
{

public:
  inline UnionFindForest( const int& size );

};

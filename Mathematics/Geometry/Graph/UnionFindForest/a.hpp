// c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/941551
// https://atcoder.jp/contests/abc087/submissions/48976736�i�����t���d�݁j

// T�����@�ɂ��ĉ��Q���Ȃ��ꍇ�ɂ̂݃T�|�[�g�B

// - �\�z O(size)

// - ��_���擾 O(��(size))
// - �S���擾 O(root�̌�)
// - �����擾 O(1)

// - ��_�����t���d�ݎ擾 O(��(size))
// - ��_�ڍ� O(��(size))
template <typename T = int>
class UnionFindForest
{

private:
  uint m_node_size;
  uint m_root_size;
  vector<uint> m_pred;
  vector<uint> m_length;
  // m_left_root[0]�͍��[��root
  vector<uint> m_left_root;
  // m_right_root[m_size-1]�͉E�[��root
  vector<uint> m_right_root;
  // m_w[num]��num�Ԗڂ�node��root�Ȃ��0�Aroot�łȂ��Ȃ�ΐenode�֌������p�X�̕����t���d��
  vector<T> m_w;
  
public:
  UnionFindForest( const uint& size );

  // num�Ԗڂ�node��root���v�Z���ĕԂ��B
  const uint& RootOfNode( const uint& num );
  // root��S�Ċi�[����B
  template <template <typename...> typename V> void SetRoot( V<uint>& a ) const;

  // num1�Ԗڂ�node����num0�Ԗڂ�node�֌������p�X�̕����t���d�݂�Ԃ��B
  inline T Weight( const uint& num0 , const uint& num1 );
  
  inline const uint& SizeOfNode() const noexcept;
  inline const uint& SizeOfRoot() const noexcept;

  // num1�Ԗڂ�node����num0�Ԗڂ�node�֕����t���d��w�̗L���ӂ����ԑ���Ɛ����I��
  // �Ȃ�悤��root��ڍ��B�����t���d�݂̐����������Ȃ��ꍇ��false��Ԃ��B
  bool Graft( const uint& num0 , const uint& num1 , const T& w = 0 );
  
};

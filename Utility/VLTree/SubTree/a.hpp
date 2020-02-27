// c:/Users/user/Documents/Programming/Utility/VLTree/SubTree/a.hpp

#pragma once
#include "../Entry/a.hpp"

template <typename T> class IteratorOfVLTree;
template <typename T> class ConstIteratorOfVLTree;
template <typename T> class VLConstSubTree;
template <typename T> class VLTree;
template <typename Arg> class WrappedType;

template <typename T>
class VLSubTree
{

  friend VLConstSubTree<T>;
  friend VLTree<T>;
  
private:
  EntryOfVLTree<T> m_e;
  EntryOfVLTree<T>& m_root;
  uint m_size;

private:
  // T�͈���0�̃R���X�g���N�^�����N���X�̂݋��e�B
  // �f�X�g���N�^��delete���Z�q���Ă΂Ȃ����߁AVLTree�o�R�ł����Ăяo���Ă͂����Ȃ��B
  inline VLSubTree();

  // T�͈���0�̃R���X�g���N�^�����N���X�̂݋��e�B
  // �f�X�g���N�^��delete���Z�q���Ă΂Ȃ����߁AVLTree�o�R�ł����Ăяo���Ă͂����Ȃ��B
  template <typename Arg1 , typename... Arg2> inline VLSubTree( const Arg1& , const Arg2&... );
  
  // T������0�̃R���X�g���N�^�������Ȃ��N���X�̏ꍇ�Ɏg�p�B
  // �f�X�g���N�^��delete���Z�q���Ă΂Ȃ����߁AVLTree�o�R�ł����Ăяo���Ă͂����Ȃ��B
  template <typename Arg> inline VLSubTree( const WrappedType<Arg>& t );

  // �����I�ɑ�����Z�q���o�R���ăR�s�[���Ă��邽�߁A�\�z���ꂽ�؂ւ̕ύX���R�s�[���ւ͔��f����Ȃ��B
  // �f�X�g���N�^��delete���Z�q���Ă΂Ȃ����߁AVLTree�o�R�ł����Ăяo���Ă͂����Ȃ��B
  inline VLSubTree( const VLSubTree<T>& );

  // const_cast���s�����߁AVLConstSubTree�o�R�ł����Ăяo���Ă͂����Ȃ��B
  inline VLSubTree( const ConstIteratorOfVLTree<T>& );

  // ���ږ؂��\�z���ĕԂ����߁A�߂�l�̖؂ւ̕ύX�����g�ւ����f���ꂤ��B
  // VLTree���o�R���Ȃ��Ă��Ăяo���ėǂ��B
  inline VLSubTree( EntryOfVLTree<T>& );

public:
  virtual ~VLSubTree() = default;

  // CutBranches��push_RightMost�ŐV���ɖ؂��\�z���邽�߁A�\�z���ꂽ�؂ւ̕ύX��operator=�̃R�s�[���ւ͔��f����Ȃ��������؂Ƃ��Ă̖��ߍ��ݐ�ւ͔��f�����B
  VLSubTree<T>& operator=( const VLSubTree<T>& );
  
  inline const uint& size() const noexcept;
  inline void CutBranches();
  void CutBranches( const T& );
  void CutLeaf();
  inline bool IsLeaf() const noexcept;

  // �����؂��\�z���ĕԂ����߁A�����؂ւ̕ύX�����g�ւ����f�����B
  inline VLSubTree<T> LeftMostSubTree();
  inline VLSubTree<T> RightMostSubTree();
  
  // �����؂̃R�s�[���\�z���ĕԂ����߁A�����؂ւ̕ύX�����g�ւ͔��f����Ȃ��B
  VLTree<T> LeftMostSubTreeCopy() const;
  VLTree<T> RightMostSubTreeCopy() const;
  
  inline void push_RightMost() const noexcept;
  template <typename Arg1 , typename... Arg2> void push_RightMost( const Arg1& , const Arg2&... );

  // �����؂̃R�s�[���\�z���đ}�����邽�߁A���g�ւ̕ύX�������؂ւ͔��f����Ȃ��B
  template <typename... Args> void push_RightMost( const VLSubTree<T>& , const Args&... );
  template <typename... Args> void push_RightMost( const VLTree<T>& , const Args&... );

  template <typename Arg> void push_LeftMost( const Arg& );
  
  void pop_RightMost();
  void pop_LeftMost();
  void pop_Root();

  template <typename... Args> inline void push_back( const Args&... );
  template <typename Arg> inline void push_front( const Arg& );
  inline void pop_back();
  inline void pop_front();

  using iterator = IteratorOfVLTree<T>;
  using const_iterator = ConstIteratorOfVLTree<T>;

  // *this��const�ł���ꍇ�Ɋm����const_iterator�Ԃ������邽�߂ɁAiterator�Ԃ��͔�const�ɂ���K�v������B
  inline iterator LeftMostNode() noexcept;
  inline const_iterator LeftMostNode() const noexcept;
  inline iterator RightMostNode() noexcept;
  inline const_iterator RightMostNode() const noexcept;
  iterator LeftMostLeaf() noexcept;
  const_iterator LeftMostLeaf() const noexcept;
  iterator RightMostLeaf() noexcept;
  const_iterator RightMostLeaf() const noexcept;
  inline iterator Root() noexcept;
  inline const_iterator Root() const noexcept;

  // iterator�̉E�ɐV����Leaf���\�z����B
  template <typename Arg> void insert( const iterator& , const Arg& );

  // RightMost�ł���ꍇ��root�ւ̃C�e���[�^��Ԃ��B
  iterator erase( iterator& );

  // Root��Node�̃��x���ɒ��ړǂݏ������s���B
  inline const T& GetRoot() const noexcept;
  inline void SetRoot( const T& );
  void SetNode( const iterator& , const T& );

  // �����؂��\�z���ĕԂ����߁A�����؂ւ̕ύX�����g�ւ����f�����B
  VLSubTree<T> operator[]( const uint& );
  VLSubTree<T> operator[]( iterator& );
  
  // �萔�����؂��\�z���ĕԂ����߁A�����؂ւ̕ύX�����g�ւ͔��f����Ȃ��B
  VLConstSubTree<T> operator[]( const const_iterator& ) const;

  // �����؂̃R�s�[���\�z���ĕԂ����߁A�����؂ւ̕ύX�����g�ւ͔��f����Ȃ��B
  VLTree<T> GetBranchCopy( const uint& ) const;
  VLTree<T> GetBranchCopy( const iterator& ) const;
  VLTree<T> GetBranchCopy( const const_iterator& ) const;
  
  // �����؂̃R�s�[���\�z���đ}�����邽�߁A���g�ւ̕ύX�������؂ւ͔��f����Ȃ��B
  void Concatenate( const VLSubTree<T>& );
  void Concatenate( const iterator& , const VLSubTree<T>& );

  bool CheckContain( const iterator& ) const noexcept;
  bool CheckContain( const const_iterator& ) const noexcept;

  string Display() const;
  
};

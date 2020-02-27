// c:/Users/user/Documents/Programming/Utility/VLTree/Iterator/a.hpp

#pragma once

template <typename T> class EntryOfVLTree;
template <typename T> class ConstIteratorOfVLTree;
template <typename T> class VLSubTree;
template <typename T> class EntryOfVLArray;

template <typename T>
class IteratorOfVLTree
{

  friend ConstIteratorOfVLTree<T>;
  friend VLSubTree<T>;
  friend EntryOfVLArray<IteratorOfVLTree<T> >;

private:
  EntryOfVLTree<T>* m_p;

private:
  // SequentialIteratorOVLTree�o�R�ł̂݌Ăяo���\�B
  inline IteratorOfVLTree() noexcept;

public:
  inline IteratorOfVLTree( EntryOfVLTree<T>* const& ) noexcept;
  inline IteratorOfVLTree( const IteratorOfVLTree<T>& ) noexcept;
  
  inline T& operator*() const;
  inline T* operator->() const;
  IteratorOfVLTree<T>& operator=( const IteratorOfVLTree<T>& ) noexcept;

  // �ʏ�ƈقȂ莩�g�ւ̎Q�Ƃ�n���B
  IteratorOfVLTree<T>& operator++( int ) noexcept;
  IteratorOfVLTree<T>& operator--( int ) noexcept;

  // ������0�̎��͉������Ȃ��B���̎���m_leftmost_node�ɐi��ŃC���N�������g�A���̎���m_rightmost_node�ɐi��Ńf�B�N�������g�B
  IteratorOfVLTree<T>& operator[]( const int& );
  
  inline bool IsLeaf() const noexcept;
  inline bool IsLeftMost() const noexcept;
  inline bool IsRightMost() const noexcept;
  inline bool IsValid() const noexcept;

};

template <typename T>
class ConstIteratorOfVLTree
{

  friend VLSubTree<T>;
  friend EntryOfVLArray<ConstIteratorOfVLTree<T> >;

private:
  EntryOfVLTree<T>* m_p;


private:
  // SequentialConstIteratorOVLTree�o�R�ł̂݌Ăяo���\�B
  inline ConstIteratorOfVLTree() noexcept;
  
public:
  inline ConstIteratorOfVLTree( EntryOfVLTree<T>* const& ) noexcept;
  inline ConstIteratorOfVLTree( const ConstIteratorOfVLTree<T>& ) noexcept;
  inline ConstIteratorOfVLTree( const IteratorOfVLTree<T>& ) noexcept;

  inline const T& operator*() const;
  inline const T* operator->() const;
  ConstIteratorOfVLTree<T>& operator=( const ConstIteratorOfVLTree<T>& ) noexcept;
  ConstIteratorOfVLTree<T>& operator=( const IteratorOfVLTree<T>& ) noexcept;

  // �ʏ�ƈقȂ莩�g�ւ̎Q�Ƃ�n���B
  ConstIteratorOfVLTree<T>& operator++( int ) noexcept;
  ConstIteratorOfVLTree<T>& operator--( int ) noexcept;

  // ������0�̎��͉������Ȃ��B���̎���m_leftmost_node�ɐi��ŃC���N�������g�A���̎���m_rightmost_node�ɐi��Ńf�B�N�������g�B
  ConstIteratorOfVLTree<T>& operator[]( const int& );

  inline bool IsLeaf() const noexcept;
  inline bool IsLeftMost() const noexcept;
  inline bool IsRightMost() const noexcept;
  inline bool IsValid() const noexcept;

  static inline bool Equal( const IteratorOfVLTree<T>& , const IteratorOfVLTree<T>& ) noexcept;
  static inline bool Equal( const ConstIteratorOfVLTree<T>& , const IteratorOfVLTree<T>& ) noexcept;
  static inline bool Equal( const IteratorOfVLTree<T>& , const ConstIteratorOfVLTree<T>& ) noexcept;
  static inline bool Equal( const ConstIteratorOfVLTree<T>& , const ConstIteratorOfVLTree<T>& ) noexcept;

};

template <typename T> inline bool operator==( const IteratorOfVLTree<T>& , const IteratorOfVLTree<T>& ) noexcept;
template <typename T> inline bool operator!=( const IteratorOfVLTree<T>& , const IteratorOfVLTree<T>& ) noexcept;

template <typename T> inline bool operator==( const ConstIteratorOfVLTree<T>& , const IteratorOfVLTree<T>& ) noexcept;
template <typename T> inline bool operator!=( const ConstIteratorOfVLTree<T>& , const IteratorOfVLTree<T>& ) noexcept;

template <typename T> inline bool operator==( const IteratorOfVLTree<T>& , const ConstIteratorOfVLTree<T>& ) noexcept;
template <typename T> inline bool operator!=( const IteratorOfVLTree<T>& , const ConstIteratorOfVLTree<T>& ) noexcept;

template <typename T> inline bool operator==( const ConstIteratorOfVLTree<T>& , const ConstIteratorOfVLTree<T>& ) noexcept;
template <typename T> inline bool operator!=( const ConstIteratorOfVLTree<T>& , const ConstIteratorOfVLTree<T>& ) noexcept;

// c:/Users/user/Documents/Programming/Utility/VLArray/a.hpp

#pragma once
#include "Entry/a.hpp"

#include "a_Alias.hpp"

template <typename T> class IteratorOfVLArray;
template <typename T> class ConstIteratorOfVLArray;
template <typename Arg> class WrappedType;

template <typename T>
class VLArray
{

private:
  EntryOfVLArray<T> m_e;
  EntryOfVLArray<T>* const m_p_e;
  uint m_size;
  
public:
  // T�͈���0�̃R���X�g���N�^�����N���X�̂݋��e�B
  inline VLArray();
  template <typename Arg1 , typename... Arg2> inline VLArray( const Arg1& , const Arg2&... );
  inline VLArray( const VLArray<T>& );

  // T������0�̃R���X�g���N�^�������Ȃ��N���X�̏ꍇ�Ɏg�p�B
  template <typename Arg> inline VLArray( const WrappedType<Arg>& t );
  
  inline ~VLArray();
  
  VLArray<T>& operator=( const VLArray<T>& );
  
  inline const uint& size() const noexcept;
  inline void clear();
  inline bool empty() const noexcept;
  inline T& front();
  inline const T& front() const;
  inline T& back();
  inline const T& back() const;
  
  inline void push_back() const noexcept;
  template <typename Arg1 , typename... Arg2> void push_back( const Arg1& , const Arg2&... );
  template <typename Arg> void push_front( const Arg& );
  void pop_back();
  void pop_front();

  using iterator = IteratorOfVLArray<T>;
  using const_iterator = ConstIteratorOfVLArray<T>;

  // *this��const�ł���ꍇ�Ɋm����const_iterator�Ԃ������邽�߂ɁAiterator�Ԃ��͔�const�ɂ���K�v������B
  inline iterator begin() noexcept;
  inline const_iterator begin() const noexcept;
  inline iterator end() noexcept;
  inline const_iterator end() const noexcept;
  template <typename Arg> void insert( const iterator& , const Arg& );
  iterator erase( iterator& );

  T& operator[]( const uint& );
  const T& operator[]( const uint& ) const;

  bool CheckContain( const iterator& ) const noexcept;
  bool CheckContain( const const_iterator& ) const noexcept;

  string Display() const;

private:
  void EmptyToArray( const VLArray<T>& a );

};

template <typename T> VLArray<T> to_VLArray( const uint& , const T& );
template <typename T> inline VLMatrix<1,T> to_VLMatrix( const uint& , const T& );
template <typename T> inline VLMatrix<2,T> to_VLMatrix( const uint& , const uint& , const T& );
template <typename T> inline VLMatrix<3,T> to_VLMatrix( const uint& , const uint& , const uint& , const T& );

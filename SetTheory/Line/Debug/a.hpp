// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Debug/a.hpp

#pragma once
#include "../Iterator/a.hpp"

// �f�o�b�O�p�Ƀf�o�b�O�o�͂�set���̂��̂�ǉ��������́B
// �e�v�Z�ʂ�O(m_size)������邱�Ƃɒ��ӁB

template <typename INT>
class LineSubset
{

private:
  // ���[l,r]���Ƃ�m_l[r] = l�Ƃ��Ē����̕����W�����Ǘ�����B
  map<INT,INT> m_l;
  int m_size;

  set<INT> m_set;

public:
  inline LineSubset();
  
  using iterator = IteratorOfLineSubset<INT>;
  
  void insert( const INT& i ) noexcept;
  void IntervalInsert( const INT& i_start , const INT& i_final ) noexcept;
  void erase( const INT& i ) noexcept;
  // itr���C���N�������g���ď��������A����ւ̎Q�Ƃ�Ԃ��B
  inline iterator& erase( iterator& itr );

  inline int count( const INT& i ) const noexcept;
  bool find( const INT& i ) const noexcept;

  inline const int& size() const noexcept;
  inline bool empty() const noexcept;

  inline iterator begin() const noexcept;
  inline iterator end() const noexcept;

  inline iterator MaximumLeq( const INT& i ) const noexcept;
  inline iterator MaximumLt( const INT& i ) const noexcept;
  inline iterator MinimumGeq( const INT& i ) const noexcept;
  inline iterator MinimumGt( const INT& i ) const noexcept;

  inline INT Maximum() const;
  inline INT Minimum() const;

  // i���܂ޘA��������Ԃ��B���݂��Ȃ��ꍇ��[1+1,i-1]��Ԃ��B
  pair<INT,INT> ConnectedComponentOf( const INT& i ) const noexcept;

  inline const map<INT,INT>& GetConnectedComponent() const noexcept;

  inline void Display() const noexcept;
  
};

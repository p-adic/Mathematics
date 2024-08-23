// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/a.hpp

#pragma once
#include "Iterator/a.hpp"

// verify:
// https://yukicoder.me/submissions/1002789�iinsert, erase, ConnectedComponentOf�j

// �\�zO(1)
// ��_�}��O(log Q)
// ��ԑ}��O(log Q)�i�ς��j
// ��_�폜O(log Q)
// ��ԍ폜O(log Q)�i�ς��j
// ��_�A������O(log Q)
// �T�C�Y�擾O(1)

// �擪�C�e���[�^�擾O(1)
// �����C�e���[�^�擾O(1)
// ���/�����񕪒T��O(log Q)

// �ő�l/�ŏ��l�擾O(1)

// ��_�A�������擾O(log Q)

template <typename INT>
class LineSubset
{

private:
  // ���[l,r]���Ƃ�m_l[r] = l�Ƃ��Ē����̕����W�����Ǘ�����B
  map<INT,INT> m_l;
  int m_size;

public:
  using iterator = IteratorOfLineSubset<INT>;
  
  void insert( const INT& i ) noexcept;
  void IntervalInsert( const INT& i_start , const INT& i_final ) noexcept;
  void erase( const INT& i ) noexcept;
  // itr���C���N�������g���ď��������A����ւ̎Q�Ƃ�Ԃ��B
  inline iterator& erase( iterator& itr );
  void IntervalErase( const INT& i_start , const INT& i_final ) noexcept;

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
  
};

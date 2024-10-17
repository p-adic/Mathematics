// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/Debug/a.hpp

#pragma once
#include "../../Iterator/a.hpp"

#include "../../../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"

// �f�o�b�O�p�Ƀf�o�b�O�o�͂�multiset��ǉ��������́B
// �e�����̌v�Z�ʂ�O(size)�����邱�Ƃɒ��ӁB

template <typename INT , typename RET_NOR , typename RET_DEN>
class VirtualBoundedLineMultiSubset :
  public Debug
{

protected:
  INT m_lbound;
  INT m_ubound;
  BIT<INT> m_ds;

  string m_name;
  multiset<INT> m_S;
  multiset<INT> m_S_comp;

public:
  inline VirtualBoundedLineMultiSubset();
  
  using iterator = IteratorOfBoundedLineSubset<VirtualBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>,INT>;
  
  inline void insert( const INT& i , const INT& c = 1 );
  inline void erase( const INT& i , const INT& c = 1 );
  // itr���C���N�������g���ď��������A����ւ̎Q�Ƃ�Ԃ��B
  inline iterator& erase( iterator& itr );
  inline void EraseAll( const INT& i );
  inline void clear();

  inline int count( const INT& i ) noexcept;
  bool find( const INT& i ) noexcept;

  inline int InitialSegmentCount( const INT& i_final );
  inline int IntervalCount( const INT& i_start , const INT& i_final );

  // VVV�d���x���񕉂̏ꍇ�̂݃T�|�[�g�inoexcept���O��Ă��邱�Ƃɒ��Ӂj
  inline bool empty();

  inline iterator begin();
  inline iterator end();

  inline iterator MaximumLeq( const INT& i , const INT& k = 0 );
  inline iterator MaximumLt( const INT& i , const INT& k = 0 );
  inline iterator MinimumGeq( const INT& i , const INT& k = 0 );
  inline iterator MinimumGt( const INT& i , const INT& k = 0 );

  inline INT Maximum( const INT& k = 0 );
  inline INT Minimum( const INT& k = 0 );
  // AAA�d���x���񕉂̏ꍇ�̂݃T�|�[�g

  inline const INT& lbound() const noexcept;
  inline const INT& ubound() const noexcept;

  void Display() noexcept;

protected:
  virtual bool InRange( const INT& i ) = 0;
  virtual RET_NOR Normalise( const INT& i ) = 0;
  virtual RET_DEN Denormalise( const decay_t<RET_NOR>& d ) = 0;

};

template <typename INT>
class BoundedLineMultiSubset :
  virtual public VirtualBoundedLineMultiSubset<INT,INT,INT>
{

public:
  inline BoundedLineMultiSubset( const INT& lbound , const INT& ubound );

protected:
  inline bool InRange( const INT& i );
  inline INT Normalise( const INT& i );
  inline INT Denormalise( const INT& d );

};

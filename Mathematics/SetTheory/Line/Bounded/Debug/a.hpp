// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Debug/a.hpp

#pragma once
#include "../Iterator/a.hpp"
#include "../../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"

// �f�o�b�O�p�Ƀf�o�b�O�o�͂�set��ǉ��������́B
// �e�����̌v�Z�ʂ�O(size)�����邱�Ƃɒ��ӁB

template <typename INT , typename RET_NOR , typename RET_DEN>
class VirtualBoundedLineSubset :
  public Debug
{

protected:
  INT m_lbound;
  INT m_ubound;
  BIT<INT> m_ds;

  string m_name;
  set<INT> m_S;

public:
  inline VirtualBoundedLineSubset();
  
  using iterator = IteratorOfBoundedLineSubset<VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>,INT>;
  
  inline void insert( const INT& i );
  inline void erase( const INT& i ) noexcept;
  // itr���C���N�������g���ď��������A����ւ̎Q�Ƃ�Ԃ��B
  inline iterator& erase( iterator& itr );
  inline void clear();

  inline INT count( const INT& i ) noexcept;
  bool find( const INT& i ) noexcept;

  inline INT InitialSegmentCount( const INT& i_final );
  inline INT IntervalCount( const INT& i_start , const INT& i_final );
  inline bool empty() noexcept;

  inline iterator begin() noexcept;
  inline iterator end() noexcept;

  inline iterator MaximumLeq( const INT& i , const INT& k = 0 );
  inline iterator MaximumLt( const INT& i , const INT& k = 0 );
  inline iterator MinimumGeq( const INT& i , const INT& k = 0 );
  inline iterator MinimumGt( const INT& i , const INT& k = 0 );

  inline INT Maximum( const INT& k = 0 );
  inline INT Minimum( const INT& k = 0 );

  // i���܂ޘA�������̉E�[��Ԃ��B���݂��Ȃ��ꍇ��i-1��Ԃ��B
  INT RightEndPointOf( const INT& i , int d = -1 , int comp_minus = -1 , const bool& in = false );
  // i���܂ޘA�������̍��[��Ԃ��B���݂��Ȃ��ꍇ��i+1��Ԃ��B
  INT LeftEndPointOf( const INT& i , int d = -1 , int comp_minus = -1 , const bool& in = false );

  // i���܂ޘA��������Ԃ��B���݂��Ȃ��ꍇ��[1+1,i-1]��Ԃ��B
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false );

  vector<pair<INT,INT>> GetConnectedComponent() noexcept;

  inline const INT& lbound() const noexcept;
  inline const INT& ubound() const noexcept;

  void Display() noexcept;

private:
  virtual bool InRange( const INT& i ) = 0;
  virtual RET_NOR Normalise( const INT& i ) = 0;
  virtual RET_DEN Denormalise( const decay_t<RET_NOR>& d ) = 0;

};

template <typename INT>
class BoundedLineSubset :
  virtual public VirtualBoundedLineSubset<INT,INT,INT>
{

public:
  inline BoundedLineSubset( const INT& lbound , const INT& ubound , const bool& output_mode = true );

private:
  inline bool InRange( const INT& i );
  inline INT Normalise( const INT& i );
  inline INT Denormalise( const INT& d );

};

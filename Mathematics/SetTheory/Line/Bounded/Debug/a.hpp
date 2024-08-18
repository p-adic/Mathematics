// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Debug/a.hpp

#pragma once
#include "../Iterator/a.hpp"
#include "../../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"

// �f�o�b�O�p�Ƀf�o�b�O�o�͂�set��ǉ��������́B
// �e�����̌v�Z�ʂ�O(size)�����邱�Ƃɒ��ӁB

template <typename INT , template <typename...> typename DATA_STR>
class AbstractBoundedLineSubset
{

protected:
  INT m_lbound;
  INT m_ubound;
  DATA_STR<INT> m_ds;

  set<INT> m_S;

public:
  inline AbstractBoundedLineSubset( const INT& lbound , const INT& ubound );
  
  using iterator = IteratorOfBoundedLineSubset<INT,DATA_STR>;
  
  inline void insert( const INT& i );
  inline void erase( const INT& i );
  // itr���C���N�������g���ď��������A����ւ̎Q�Ƃ�Ԃ��B
  inline iterator& erase( iterator& itr );

  inline int count( const INT& i ) noexcept;
  bool find( const INT& i ) noexcept;

  inline int InitialSegmentSize( const INT& i_final ) noexcept;
  inline int IntervalSize( const INT& i_start , const INT& i_final ) noexcept;
  inline bool empty() noexcept;

  inline iterator begin() noexcept;
  inline iterator end() const noexcept;

  inline iterator MaximumLeq( const INT& i ) noexcept;
  inline iterator MaximumLt( const INT& i ) noexcept;
  inline iterator MinimumGeq( const INT& i ) noexcept;
  inline iterator MinimumGt( const INT& i ) noexcept;

  inline INT Maximum();
  inline INT Minimum();

  // i���܂ޘA�������̉E�[��Ԃ��B���݂��Ȃ��ꍇ��i-1��Ԃ��B
  INT RightEndPointOf( const INT& i ) noexcept;
  // i���܂ޘA�������̍��[��Ԃ��B���݂��Ȃ��ꍇ��i+1��Ԃ��B
  INT LeftEndPointOf( const INT& i ) noexcept;

  // i���܂ޘA��������Ԃ��B���݂��Ȃ��ꍇ��[1+1,i-1]��Ԃ��B
  inline pair<INT,INT> ConnectedComponentOf( const INT& i ) noexcept;

  vector<pair<INT,INT>> GetConnectedComponent() noexcept;

  inline const INT& lbound() const noexcept;
  inline const INT& ubound() const noexcept;

  void Display() noexcept;

};

#include "../a_Alias.hpp"

// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/a.hpp

#pragma once
#include "Iterator/a.hpp"

#ifdef DEBUG
  #include "../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"
#else
  #include "../../DirectProduct/AffineSpace/BIT/a.hpp"
#endif

// verify:
// https://yukicoder.me/submissions/1008247 (insert, erase, ConnectedComponentOf)

// �\�zO(ubound - lbound)
// ��_�}��O(log (ubound - lbound))
// ��_�폜O(log (ubound - lbound))
// ��_�A������O(log (ubound - lbound))
// ��ԗv�f���擾O(log (ubound - lbound))

// �擪�C�e���[�^�擾O(log (ubound - lbound))
// �����C�e���[�^�擾O(log (ubound - lbound))
// ���/�����񕪒T��O(log (ubound - lbound))

// �ő�l/�ŏ��l�擾O(log (ubound - lbound))

// ��_�A�������擾O(log (ubound - lbound))
// �S�A�������擾O(�A�������� log (ubound - lbound))

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
class VirtualBoundedLineSubset
{

protected:
  INT m_lbound;
  INT m_ubound;
  DATA_STR<INT> m_ds;

public:
  using iterator = IteratorOfBoundedLineSubset<VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN,DATA_STR>,INT>;
  
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

protected:
  virtual bool InRange( const INT& i ) = 0;
  virtual RET_NOR Normalise( const INT& i ) = 0;
  virtual RET_DEN Denormalise( const decay_t<RET_NOR>& d ) = 0;

};

template <typename INT , template <typename...> typename DATA_STR>
class AbstractBoundedLineSubset :
  virtual public VirtualBoundedLineSubset<INT,INT,INT,DATA_STR>
{

public:
  inline AbstractBoundedLineSubset( const INT& lbound , const INT& ubound );

protected:
  inline bool InRange( const INT& i );
  inline INT Normalise( const INT& i );
  inline INT Denormalise( const INT& d );

};

#include "a_Alias.hpp"


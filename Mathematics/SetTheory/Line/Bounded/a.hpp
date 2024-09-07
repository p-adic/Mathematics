// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/a.hpp

#pragma once
#include "Iterator/a.hpp"

#ifdef DEBUG
  #include "../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"
#else
  #include "../../DirectProduct/AffineSpace/BIT/a.hpp"
#endif

// verify:
// https://yukicoder.me/submissions/1002456 (insert, erase, ConnectedComponentOf)

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

template <typename INT , template <typename...> typename DATA_STR>
class AbstractBoundedLineSubset
{

protected:
  INT m_lbound;
  INT m_ubound;
  DATA_STR<INT> m_ds;

public:
  inline AbstractBoundedLineSubset( const INT& lbound , const INT& ubound );
  
  using iterator = IteratorOfBoundedLineSubset<INT,DATA_STR>;
  
  inline void insert( const INT& i );
  inline void erase( const INT& i );
  // itr���C���N�������g���ď��������A����ւ̎Q�Ƃ�Ԃ��B
  inline iterator& erase( iterator& itr );

  inline int count( const INT& i ) noexcept;
  bool find( const INT& i ) noexcept;

  inline int InitialSegmentCount( const INT& i_final ) noexcept;
  inline int IntervalCount( const INT& i_start , const INT& i_final ) noexcept;
  inline bool empty() noexcept;

  inline iterator begin() noexcept;
  inline iterator end() noexcept;

  inline iterator MaximumLeq( const INT& i , const int& k = 0 ) noexcept;
  inline iterator MaximumLt( const INT& i , const int& k = 0 ) noexcept;
  inline iterator MinimumGeq( const INT& i , const int& k = 0 ) noexcept;
  inline iterator MinimumGt( const INT& i , const int& k = 0 ) noexcept;

  inline INT Maximum( const int& k = 0 );
  inline INT Minimum( const int& k = 0 );

  // i���܂ޘA�������̉E�[��Ԃ��B���݂��Ȃ��ꍇ��i-1��Ԃ��B
  INT RightEndPointOf( const INT& i , const bool& in = false ) noexcept;
  // i���܂ޘA�������̍��[��Ԃ��B���݂��Ȃ��ꍇ��i+1��Ԃ��B
  INT LeftEndPointOf( const INT& i , const bool& in = false ) noexcept;

  // i���܂ޘA��������Ԃ��B���݂��Ȃ��ꍇ��[1+1,i-1]��Ԃ��B
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) noexcept;

  vector<pair<INT,INT>> GetConnectedComponent() noexcept;

  inline const INT& lbound() const noexcept;
  inline const INT& ubound() const noexcept;

};

#include "a_Alias.hpp"

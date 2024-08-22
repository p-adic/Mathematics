// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/a.hpp

#pragma once
#include "Iterator/a.hpp"
#include "../../../DirectProduct/AffineSpace/BIT/a.hpp"

// verify:
// https://yukicoder.me/submissions/1002458 (insert,erase,ConnectedComponentOf)

// �񕉂ɐ�������BoundedLineSubset�̒萔�{�������ŁB

// �\�zO(ubound)
// ��_�}��O(log ubound)
// ��_�폜O(log ubound)
// ��_�A������O(log ubound)
// ��ԃT�C�Y�擾O(log ubound)

// �擪�C�e���[�^�擾O(log ubound)
// �����C�e���[�^�擾O(log ubound)
// ���/�����񕪒T��O(log ubound)

// �ő�l/�ŏ��l�擾O(log ubound)

// ��_�A�������擾O(log ubound)
// �S�A�������擾O(�A�������� log ubound)

template <typename INT , template <typename...> typename DATA_STR>
class AbstractNonNegativeLineSubset
{

protected:
  INT m_ubound;
  DATA_STR<INT> m_ds;

public:
  inline AbstractNonNegativeLineSubset( const INT& ubound );
  
  using iterator = IteratorOfNonNegativeLineSubset<INT,DATA_STR>;
  
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

  inline const INT& ubound() const noexcept;

};

#include "a_Alias.hpp"

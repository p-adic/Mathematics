// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/a.hpp

#pragma once
#include "../a.hpp"

// �\�zO(ubound - lbound)
// ��_�}��O(log(ubound - lbound))
// ��_�폜O(log(ubound - lbound))
// ��_�A������O(log(ubound - lbound))
// ��ԗv�f���擾O(log(ubound - lbound))

// �擪�C�e���[�^�擾O(log(ubound - lbound))
// �����C�e���[�^�擾O(log(ubound - lbound))
// ���/�����񕪒T��O(log(ubound - lbound))

// �ő�l/�ŏ��l�擾O(log(ubound - lbound))

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
class AbstractBoundedLineMultiSubset :
  virtual public VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN,DATA_STR>
{
  
public:
  inline void insert( const INT& i , const INT& c = 1 );
  inline void erase( const INT& i , const INT& c = 1 );
  inline void EraseAll( const INT& i );

  // VVV�d���x���񕉂̏ꍇ�̂݃T�|�[�g
  // delete����Ă��Ȃ����̂�VirtualBoundedLineSubset���Œ�`����Ă���B
  // inline bool empty() noexcept;

  // inline iterator begin() noexcept;
  // inline iterator end() noexcept;

  // inline iterator MaximumLeq( const INT& i , const INT& k = 0 );
  // inline iterator MaximumLt( const INT& i , const INT& k = 0 );
  // inline iterator MinimumGeq( const INT& i , const INT& k = 0 );
  // inline iterator MinimumGt( const INT& i , const INT& k = 0 );

  // inline INT Maximum( const INT& k = 0 );
  // inline INT Minimum( const INT& k = 0 );
  
  INT RightEndPointOf( const INT& i , const bool& in = false ) = delete;
  INT LeftEndPointOf( const INT& i , const bool& in = false ) = delete;
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) = delete;
  vector<pair<INT,INT>> GetConnectedComponent() noexcept = delete;
  // AAA�d���x���񕉂̏ꍇ�̂݃T�|�[�g

};

template <typename INT>
class BoundedLineMultiSubset :
  public BoundedLineSubset<INT> ,
  public AbstractBoundedLineMultiSubset<INT,INT,INT,BIT>
{
  
public:
  inline BoundedLineMultiSubset( const INT& lbound , const INT& ubound );

};

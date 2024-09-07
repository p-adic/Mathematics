// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/a.hpp

#pragma once

#ifdef DEBUG
  #include "../Debug/a.hpp"
#else
  #include "../a.hpp"
#endif

// �\�zO(ubound - lbound)
// ��_�}��O(log(ubound - lbound))
// ��_�폜O(log(ubound - lbound))
// ��_�A������O(log(ubound - lbound))
// ��ԗv�f���擾O(log(ubound - lbound))

// �擪�C�e���[�^�擾O(log(ubound - lbound))
// �����C�e���[�^�擾O(log(ubound - lbound))
// ���/�����񕪒T��O(log(ubound - lbound))

// �ő�l/�ŏ��l�擾O(log(ubound - lbound))

// �C�e���[�^�͗v�f�̏d���𖳎����邱�Ƃɒ��ӁB
template <typename INT, template <typename...> typename DATA_STR>
class AbstractBoundedLineMultiSubset :
  public AbstractBoundedLineSubset<INT,DATA_STR>
{
  
public:
  inline AbstractBoundedLineMultiSubset( const INT& lbound , const INT& ubound );
  
  inline void insert( const INT& i , const int& c = 1 );
  inline void erase( const INT& i , const int& c = 1 );
  inline void EraseAll( const INT& i );

  // VVV�d���x���񕉂̏ꍇ�̂݃T�|�[�g
  // inline bool empty() noexcept;

  // inline iterator begin() noexcept;
  // inline iterator end() const noexcept;

  // inline iterator MaximumLeq( const INT& i , const int& k = 0 ) noexcept;
  // inline iterator MaximumLt( const INT& i , const int& k = 0 ) noexcept;
  // inline iterator MinimumGeq( const INT& i , const int& k = 0 ) noexcept;
  // inline iterator MinimumGt( const INT& i , const int& k = 0 ) noexcept;

  // inline INT Maximum( const int& k = 0 );
  // inline INT Minimum( const int& k = 0 );
  // AAA�d���x���񕉂̏ꍇ�̂݃T�|�[�g
  
  INT RightEndPointOf( const INT& i , const bool& in = false ) noexcept = delete;
  INT LeftEndPointOf( const INT& i , const bool& in = false ) noexcept = delete;
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) noexcept = delete;
  vector<pair<INT,INT>> GetConnectedComponent() noexcept = delete;
  
};

#include "a_Alias.hpp"


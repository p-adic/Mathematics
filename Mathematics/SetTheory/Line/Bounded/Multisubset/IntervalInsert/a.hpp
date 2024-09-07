// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/a.hpp

#pragma once

#ifdef DEBUG
  #include "../../Debug/a.hpp"
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a.hpp"
#else
  #include "../../a.hpp"
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp"
#endif

// �\�zO(ubound - lbound)
// ��_�}��O(log(ubound - lbound))
// ��_�폜O(log(ubound - lbound))
// ��_�A������O(log(ubound - lbound))
// ��ԗv�f���擾O(log(ubound - lbound))

// �擪�C�e���[�^�擾O((log(ubound - lbound))^2)
// �����C�e���[�^�擾O((log(ubound - lbound))^2)
// ���/�����񕪒T��O((log(ubound - lbound))^2)

// �ő�l/�ŏ��l�擾O((log(ubound - lbound))^2)

// �C�e���[�^�͗v�f�̏d���𖳎����邱�Ƃɒ��ӁB
template <typename INT, template <typename...> typename DATA_STR>
class AbstractIntervalInsertBoundedLineMultiSubset :
  public AbstractBoundedLineSubset<INT,DATA_STR>
{
  
public:
  inline AbstractIntervalInsertBoundedLineMultiSubset( const INT& lbound , const INT& ubound );
  
  inline void insert( const INT& i , const int& c = 1 );
  inline void IntervalInsert( const INT& i_start , const INT& i_final , const int& c = 1 );
  inline void erase( const INT& i , const int& c = 1 );
  inline void EraseAll( const INT& i );
  inline void IntervalErase( const INT& i_start , const INT& i_final , const int& c = 1 );

  INT RightEndPointOf( const INT& i , const bool& in = false ) noexcept = delete;
  INT LeftEndPointOf( const INT& i , const bool& in = false ) noexcept = delete;
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) noexcept = delete;
  vector<pair<INT,INT>> GetConnectedComponent() noexcept = delete;
  
};

#include "a_Alias.hpp"


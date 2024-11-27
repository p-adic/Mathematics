// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/a.hpp

#pragma once

#include "../a.hpp"

#ifdef DEBUG
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a.hpp"
#else
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp"
#endif

// �\�zO(ubound - lbound)
// ��_�}��O(log(ubound - lbound))
// ��ԑ}��O(log(ubound - lbound))
// ��_�폜O(log(ubound - lbound))
// ��ԍ폜O(log(ubound - lbound))
// ��_�A������O(log(ubound - lbound))
// ��ԗv�f���擾O(log(ubound - lbound))

// �擪�C�e���[�^�擾O((log(ubound - lbound))^2)
// �����C�e���[�^�擾O((log(ubound - lbound))^2)
// ���/�����񕪒T��O((log(ubound - lbound))^2)

// �ő�l/�ŏ��l�擾O((log(ubound - lbound))^2)

// �C�e���[�^�͗v�f�̏d���𖳎����邱�Ƃɒ��ӁB
template <typename INT , typename RET_NOR , typename RET_DEN>
class AbstractIntervalInsertBoundedLineMultiSubset :
  public AbstractBoundedLineMultiSubset<INT,RET_NOR,RET_DEN,IntervalAddBIT>
{
  
public:
  inline void IntervalInsert( const INT& i_start , const INT& i_final , const INT& c = 1 );
  inline void IntervalErase( const INT& i_start , const INT& i_final , const INT& c = 1 );

};

template <typename INT>
class IntervalInsertBoundedLineMultiSubset :
  public AbstractBoundedLineSubset<INT,IntervalAddBIT> ,
  public AbstractIntervalInsertBoundedLineMultiSubset<INT,INT,INT>
{
  
public:
  inline IntervalInsertBoundedLineMultiSubset( const INT& lbound , const INT& ubound );

};

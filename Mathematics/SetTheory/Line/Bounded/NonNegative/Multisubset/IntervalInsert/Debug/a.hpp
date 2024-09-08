// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/IntervalInsert/Debug/a.hpp

#pragma once
#include "../../../../Multisubset/IntervalInsert/Debug/a.hpp"

// �f�o�b�O�p�Ƀf�o�b�O�o�͂�multiset��ǉ��������́B
// �e�����̌v�Z�ʂ�O(size)�����邱�Ƃɒ��ӁB

template <typename INT>
class IntervalInsertNonNegativeLineMultiSubset :
  virtual public VirtualIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>
{

public:
  inline IntervalInsertNonNegativeLineMultiSubset( const INT& ubound );


protected:
  inline bool InRange( const INT& i );
  inline constexpr const INT& Normalise( const INT& i );
  inline constexpr const INT& Denormalise( const INT& d );

};

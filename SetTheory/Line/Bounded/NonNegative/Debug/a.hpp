// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Debug/a.hpp

#pragma once
#include "../../Debug/a.hpp"

// �f�o�b�O�p�Ƀf�o�b�O�o�͂�set��ǉ��������́B
// �e�����̌v�Z�ʂ�O(size)�����邱�Ƃɒ��ӁB

template <typename INT>
class NonNegativeLineSubset :
  public VirtualBoundedLineSubset<INT,const INT&,const INT&>
{

public:
  inline NonNegativeLineSubset( const INT& ubound , const bool& output_mode = true );

private:
  inline bool InRange( const INT& i );
  inline constexpr const INT& Normalise( const INT& i );
  inline constexpr const INT& Denormalise( const INT& d );

};

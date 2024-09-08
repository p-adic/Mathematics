// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/Debug/a.hpp

#pragma once
#include "../../../Multisubset/Debug/a.hpp"

// �f�o�b�O�p�Ƀf�o�b�O�o�͂�multiset��ǉ��������́B
// �e�����̌v�Z�ʂ�O(size)�����邱�Ƃɒ��ӁB

template <typename INT>
class CompressedLineMultiSubset :
  public VirtualBoundedLineMultiSubset<INT,const INT&,const INT&>
{

protected:
  vector<INT> m_sorted_coord;
  Map<INT,int> m_sorted_coord_inv;

public:
  inline CompressedLineMultiSubset( const vector<INT>& query );

protected:
  inline bool InRange( const INT& i );
  inline const INT& Normalise( const INT& i );
  inline const INT& Denormalise( const INT& d );

};


// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/Debug/a.hpp

#pragma once
#include "../../../Multisubset/Debug/a.hpp"

// �f�o�b�O�p�Ƀf�o�b�O�o�͂�multiset��ǉ��������́B
// �e�����̌v�Z�ʂ�O(size)�����邱�Ƃɒ��ӁB

template <typename INT>
class CompressedSortedMultiSet :
  public VirtualBoundedLineMultiSubset<INT,const int&,const INT&>
{

protected:
  vector<INT> m_sorted_coord;
  map<INT,int> m_sorted_coord_inv;

public:
  inline CompressedSortedMultiSet( const vector<INT>& query );

protected:
  inline bool InRange( const INT& i );
  inline const int& Normalise( const INT& i );
  inline const INT& Denormalise( const int& d );

};


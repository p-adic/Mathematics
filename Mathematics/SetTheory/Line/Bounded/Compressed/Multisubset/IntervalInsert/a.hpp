// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/IntervalInsert/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Multisubset/IntervalInsert/a.hpp"

// �\�zO(size log size)
// ��_�}��O(log size)
// ��_�폜O(log size)
// ��_�A������O(log size)
// ��ԗv�f���擾O(log size)

// �擪�C�e���[�^�擾O((log size)^2)
// �����C�e���[�^�擾O((log size)^2)
// ���/�����񕪒T��O((log size)^2)

// �ő�l/�ŏ��l�擾O((log size)^2)

// �C�e���[�^�͗v�f�̏d���𖳎����邱�Ƃɒ��ӁB
template <typename INT>
class IntervalInsertCompressedSortedMultiSet :
  public AbstractCompressedSortedSet<INT,IntervalAddBIT> ,
  public AbstractIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>
{
  
public:
  inline IntervalInsertCompressedSortedMultiSet( const vector<INT>& query );

};


// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Multisubset/a.hpp"

// verify:
// https://yukicoder.me/submissions/1008610�iinsert, InitialSegmentCount, IntervalCount�j

// BoundedLineMultiSubset�̒萔�{�������B

// �\�zO(ubound)
// ��_�}��O(log ubound)
// ��_�폜O(log ubound)
// ��_�A������O(log ubound)
// ��ԗv�f���擾O(log ubound)

// �擪�C�e���[�^�擾O(log ubound)
// �����C�e���[�^�擾O(log ubound)
// ���/�����񕪒T��O(log ubound)

// �ő�l/�ŏ��l�擾O(log ubound)

// ��_�A�������擾O(log ubound)
// �S�A�������擾O(�A�������� log ubound)

// �C�e���[�^�͗v�f�̏d���𖳎����邱�Ƃɒ��ӁB

template <typename INT>
class NonNegativeLineMultiSubset :
  public NonNegativeLineSubset<INT> ,
  public AbstractBoundedLineMultiSubset<INT,const INT&,const INT&,BIT>
{
  
public:
  inline NonNegativeLineMultiSubset( const INT& ubound );

};

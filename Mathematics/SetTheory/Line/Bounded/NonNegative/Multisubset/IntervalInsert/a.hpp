// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/IntervalInsert/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Multisubset/IntervalInsert/a.hpp"

// �\�zO(ubound)
// ��_�}��O(log ubound)
// ��ԑ}��O(log ubound)
// ��_�폜O(log ubound)
// ��ԍ폜O(log ubound)
// ��_�A������O(log ubound)
// ��ԗv�f���擾O(log ubound)

// �擪�C�e���[�^�擾O((log ubound)^2)
// �����C�e���[�^�擾O((log ubound)^2)
// ���/�����񕪒T��O((log ubound)^2)

// �ő�l/�ŏ��l�擾O((log ubound)^2)

// �C�e���[�^�͗v�f�̏d���𖳎����邱�Ƃɒ��ӁB
template <typename INT>
class IntervalInsertNonNegativeLineMultiSubset :
  public AbstractNonNegativeLineSubset<INT,IntervalAddBIT> ,
  public AbstractIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>
{
  
public:
  inline IntervalInsertNonNegativeLineMultiSubset( const INT& ubound );

};


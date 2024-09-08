// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Multisubset/a.hpp"

// �\�zO(size log size)
// ��_�}��O(log size)
// ��_�폜O(log size)
// ��_�A������O(log size)
// ��ԗv�f���擾O(log size)

// �擪�C�e���[�^�擾O(log size)
// �����C�e���[�^�擾O(log size)
// ���/�����񕪒T��O(log size)

// �ő�l/�ŏ��l�擾O(log size)

// �C�e���[�^�͗v�f�̏d���𖳎����邱�Ƃɒ��ӁB
template <typename INT>
class CompressedLineMultiSubset :
  public CompressedLineSubset<INT> ,
  public AbstractBoundedLineMultiSubset<INT,const INT&,const INT&,BIT>
{
  
public:
  inline CompressedLineMultiSubset( const vector<INT>& query );

};

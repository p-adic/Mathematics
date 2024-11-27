// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/1008252 (insert,erase,ConnectedComponentOf)

// �񕉂ɐ�������BoundedLineSubset�̒萔�{�������ŁB

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

template <typename INT , template <typename...> typename DATA_STR>
class AbstractNonNegativeLineSubset :
  virtual public VirtualBoundedLineSubset<INT,const INT&,const INT&,DATA_STR>
{

protected:

public:
  inline AbstractNonNegativeLineSubset( const INT& ubound );

protected:
  inline bool InRange( const INT& i );
  inline constexpr const INT& Normalise( const INT& i );
  inline constexpr const INT& Denormalise( const INT& d );

};

#include "a_Alias.hpp"

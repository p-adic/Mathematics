// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/FloydWarshall/a.hpp

#pragma once
#include "../../a.hpp"
#include "../../../../Algebra/Monoid/Semirng/MeetSemirng/a.hpp"

// verify:
// https://yukicoder.me/submissions/1108900�iGet�j

// �\�zO(size^3)

// ��ӒZ�kO(size^2)

// �S�o�H�̏d�݂̉����擾O(1)
// �ŒZ�o�H�擾O(1)
template <typename U , typename IDEMPOTENT_SEMIRNG>
class AbstractFloydWarshall
{

private:
  IDEMPOTENT_SEMIRNG m_R;
  int m_size;
  vector<vector<U>> m_weight;
  vector<vector<int>> m_prev;

public:
  // d���֐��e���v���[�g�Œu�������Ă��������팸�͌����߂Ȃ��B
  inline AbstractFloydWarshall( IDEMPOTENT_SEMIRNG R , vector<vector<U>> d = {} );

  void Initialise( vector<vector<U>> d = {} );

  // ���͈͓͂̔��ŗv��
  // (1) u��R�̏�@�Ɋւ���non-negative�ł���B
  // (2) start != goal�ł���B
  // �����藧�ꍇ�̂݃T�|�[�g�B
  // �����O���t�̏ꍇ�͔��Ό����̕ӂ��ǉ�����K�v�����邱�Ƃɒ��ӁB
  void SetMeet( const int& start , const int& goal , U u );

  // ���͈͓͂̔��ŗv��
  // (1) R��U�̔�P�ʓI���\���ŉ��@���p���I�Ȃ��́B�܂�
  //   (1-1)���@�Ȃɂ���meet�����i��㰓����Q�j�ł���B
  //   (1-2)��@*�ɂ��Ĕ��Q�ł���B
  //   (1-3)��@�����@�ɑ΂����z�I�ł���B
  //   �𖞂����B�ȉ��Ȃ̒�߂铙������������<=�ƒu���A�ȂɊւ���P�ʌ���infty�ƒu���B
  // (2) d�̒l��R�̏�@�Ɋւ���non-negative�A�܂�
  //     - U�̔C�ӂ̗v�fs��d�̔C�ӂ̒lt�ɑ΂�
  //       - s<=s*t
  //       - s<=t*s
  //     �ł���B
  // (3) infty�łȂ�d�̒lsize�ȉ���R�Ɋւ���ς�infty���\���Ȃ��B
  // (4) �um_R���P�ʓI�ł���d�̑Ίp�������P�ʌ��ł���v�����藧���Ȃ��Ȃ��start!=goal�ł���B
  // �����藧�ꍇ�ɂ̂݃T�|�[�g�B

  // ������<=���������S�����ł���ꍇ�A(1-3)��
  // (1-3)' *��<=�Ɋւ��锼�������Q���Z�A�܂�
  //     - U�̔C�ӂ̗v�fs,t,u�ɑ΂�s<=t�Ȃ��
  //       - u*s <= u*t
  //       - s*u <= t*u
  //     �ł���B
  // �Ɠ��l�ł��邱�Ƃɒ��ӁB

  // �S�o�H�̏�@�I�d�݁iedge���Ƃ̏d�݂�R�Ɋւ���ρj��
  // �ȂɊւ��鉺���i���ϐ��������Ȃւ̓K�p�l�j��Ԃ��B
  inline const U& Get( const int& start , const int& goal ) const;

  // ���͈͓͂̔��ŗv��
  // (1)' R��bool operator<(const U&,const U&)�Ɋւ���min�g���s�J����P�ʓI���ł���B�܂�
  //   (1-1)' <���ő匳infty�����S�����ł���B
  //     �i�ȉ�<�̒�߂铙�����S������<=�ƒu���j
  //   (1-2)' R�̏�@*�����Q���Z�ł���B
  //   (1-3)' *��<=�Ɋւ��锼�������Q���Z�A�܂�
  //     - U�̔C�ӂ̗v�fs,t,u�ɑ΂�s<=t�Ȃ��
  //       - u*s <= u*t
  //       - s*u <= t*u
  //   �ł���B
  // (2) d�̒l��R�̏�@�Ɋւ���non-negative�A�܂�
  //     - U�̔C�ӂ̗v�fs��d�̔C�ӂ̒lt�ɑ΂�
  //       - s<=s*t
  //       - s<=t*s
  //     �ł���B
  // (3) infty�łȂ�d�̒lsize�ȉ���R�Ɋւ���ς�infty���\���Ȃ��B
  // (4) start!=goal�ł���B
  // �����藧�ꍇ�ɂ̂݃T�|�[�g�B

  // �e�Q�_�Ԃ̍ŒZ�o�H�ɂ�����prev��Ԃ��B
  // �������ŒZ�o�H�����݂��Ȃ��ꍇ��prev��-1�ƒ�߂�B
  inline const int& prev( const int& start , const int& goal ) const;

  inline const U& infty() const noexcept;
  
};
template <typename IDEMPOTENT_SEMIRNG> AbstractFloydWarshall( IDEMPOTENT_SEMIRNG ) -> AbstractFloydWarshall<inner_t<IDEMPOTENT_SEMIRNG>,IDEMPOTENT_SEMIRNG>;

// �R�X�g�̘a�ł͂Ȃ��ő�l���v�Z�������ꍇ��
// AbstractMonoid M{ Max<ll> , 0LL };
// AbstractTropicalSemirng R{ ll(1e18) , M };
// AbstractFloydWarshall fw{ R , w }; vector<vector<ll>> d = fw.GetDistance();
// �Ƃ���΂悢�B

template <typename U>
class FloydWarshall :
  public AbstractFloydWarshall<U,AdditiveTropicalSemirng<U>>
{

public:
  inline FloydWarshall( U infty_U , vector<vector<U>> d = {} );

};

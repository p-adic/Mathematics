// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/FloydWarshall/a.hpp

#pragma once
#include "../../a.hpp"
#include "../../../../Algebra/Monoid/Semirng/MeetSemirng/a.hpp"

// verify:
// https://yukicoder.me/submissions/978050�iGetDistance�j

// �\�zO(1)

// �S�o�H�̏d�݂̉����擾O(size^3)
// �ŒZ�o�H�擾O(size^3)
template <typename U , typename IDEMPOTENT_SEMIRNG>
class AbstractFloydWarshall
{

private:
  IDEMPOTENT_SEMIRNG m_R;
  int m_size;
  const vector<vector<U>>* m_p_d;

public:
  // d���֐��e���v���[�g�Œu�������Ă��������팸�͌����߂Ȃ��B
  inline AbstractFloydWarshall( IDEMPOTENT_SEMIRNG R , const vector<vector<U>>& d = {} );

  inline void Initialise( const vector<vector<U>>& d = {} );

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
  // �����藧�ꍇ�ɂ̂݃T�|�[�g�B

  // ������<=���������S�����ł���ꍇ�A(1-3)��
  // (1-3)' *��<=�Ɋւ��锼�������Q���Z�A�܂�
  //     - U�̔C�ӂ̗v�fs,t,u�ɑ΂�s<=t�Ȃ��
  //       - u*s <= u*t
  //       - s*u <= t*u
  //     �ł���B
  // �Ɠ��l�ł��邱�Ƃɒ��ӁB

  // O(size^3)�őS�o�H�̏�@�I�d�݁iedge���Ƃ̏d�݂�R�Ɋւ���ρj��
  // �ȂɊւ��鉺���i���ϐ��������Ȃւ̓K�p�l�j���v�Z�B
  vector<vector<U>> GetDistance();

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
  // �����藧�ꍇ�ɂ̂݃T�|�[�g�B

  // O(size^3)��{�e�Q�_�Ԃ̋���,�e�Q�_�Ԃ̍ŒZ�o�H�ɂ�����prev}��Ԃ��B
  // �������ŒZ�o�H�����݂��Ȃ��ꍇ��prev��-1�ƒ�߂�B
  pair<vector<vector<U>>,vector<vector<int>>> GetPath();

};
template <typename IDEMPOTENT_SEMIRNG> AbstractFloydWarshall( IDEMPOTENT_SEMIRNG ) -> AbstractFloydWarshall<inner_t<IDEMPOTENT_SEMIRNG>,IDEMPOTENT_SEMIRNG>;

template <typename U>
class FloydWarshall :
  public AbstractFloydWarshall<U,AdditiveTropicalSemirng<U>>
{

public:
  inline FloydWarshall( U infty_U , const vector<vector<U>>& d = {} );

};

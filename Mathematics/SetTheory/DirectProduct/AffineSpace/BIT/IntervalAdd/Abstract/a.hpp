// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Abstract/a.hpp

#pragma once
#include "../../Abstract/a.hpp"

// verify:
// https://yukicoder.me/submissions/947868�i��_���Z�A��ԉ��Z�A��_�擾�j

// ���Z��operator+=�Ȃǂŗ^�����Ă���ꍇ�͓��ꉻ�ł͂Ȃ�
// ../a.hpp
// ���g�����ƂŃt�@�C���e�ʂ��팸����B

// ���͈͓͂̔��ŗv��
// (1) M��U��Z���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �z��ɂ�鏉����O(size)

// ��_�擾O(log_2 size)
// �n�ؕИa�擾O(log_2 size)
// ��Ԙa�擾O(log_2 size)

// ��_�X�VO(log_2 size)
// m_M.Sum()�ɂ���_�X�VO(log_2 size)
// m_M.Sum()�ɂ���ԍX�VO(log_2 size)
// �z��̉��Z�ɂ��S�̍X�VO(size)
template <typename U , typename Z_MODULE>
class AbstractIntervalAddBIT
{
private:
  int m_size;
  Z_MODULE m_M;
  // ��֐��̔����̕��̊K������i(i-1)a_{i-1} - ia_i�j�̊Ǘ�
  AbstractBIT<U,Z_MODULE> m_bit_0;
  // �K������ia_i - a_{i-1}�j�̊Ǘ�
  AbstractBIT<U,Z_MODULE> m_bit_1;
  
public:
  AbstractIntervalAddBIT( Z_MODULE M , const vector<U>& a = vector<U>() );

  inline void Set( const int& i , const U& u );
  inline void Set( const vector<U>& a );

  inline AbstractIntervalAddBIT<U,Z_MODULE>& operator+=( const vector<U>& a );
  inline void Add( const int& i , const U& u );
  inline void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );
  
};
template <typename Z_MODULE> AbstractIntervalAddBIT( Z_MODULE M ) -> AbstractIntervalAddBIT<inner_t<Z_MODULE>,Z_MODULE>;

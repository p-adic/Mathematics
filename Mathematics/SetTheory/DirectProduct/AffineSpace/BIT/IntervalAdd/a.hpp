// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Algebra/Monoid/Group/Module/a.hpp"

// verify:
// https://yukicoder.me/submissions/961776�i��_���Z�A��ԉ��Z�A��_�擾�j

// ���͈͓͂̔��ŗv��
// (1) M��U��Z���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �z��ɂ�鏉����O(size)

// ��_�擾O(log_2 size)
// �n�ؕИa�擾O(log_2 size)
// ��Ԙa�擾O(log_2 size)

// ��_���O(log_2 size)
// m_M.Sum()�ɂ���_���ZO(log_2 size)
// m_M.Sum()�ɂ���ԉ��ZO(log_2 size)
// ���@O(size)
template <typename U , typename Z_MODULE>
class AbstractIntervalAddBIT
{
  
protected:
  Z_MODULE m_M;
  // ������1���炵�����̊K������̔����i-(i-1)(a_i - a_{i-1})�j��BIT�ŊǗ�
  AbstractBIT<U,Z_MODULE> m_bit_0;
  // �K������ia_i - a_{i-1}�j��BIT�ŊǗ�
  AbstractBIT<U,Z_MODULE> m_bit_1;
  
public:
  AbstractIntervalAddBIT( Z_MODULE M , const int& size = 0 );
  AbstractIntervalAddBIT( Z_MODULE M , const vector<U>& a );
  inline AbstractIntervalAddBIT( const AbstractIntervalAddBIT<U,Z_MODULE>& bit );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& i , const U& u );
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

template <typename U = ll>
class IntervalAddBIT :
  public AbstractIntervalAddBIT<U,Module<int,U>>
{

public:
  template <typename...Args> inline IntervalAddBIT( const Args&... args );
  
};
template <typename U> IntervalAddBIT( const vector<U>& a ) -> IntervalAddBIT<U>;

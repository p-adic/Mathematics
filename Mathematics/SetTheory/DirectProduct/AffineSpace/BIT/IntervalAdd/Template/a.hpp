// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Template/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942892�i�돉�����A��_���Z�A��ԉ��Z�A��_�擾�j

// ���Z��operator+=�łȂ��ꍇ�Ɏg�p
// M_T�͏�Zm_T:T^2->T�ɑ�������^�B
// I_T�͋t��i_T:T->T�ɑ�������^�B
// O_T�̓X�J���[�{o_T:N \times T->T�ɑ�������^�B

// ���͈͓͂̔��ŗv��
// (1) (T,m_T:T^2->T,e_T:1->T,o_T:N \times T->T)��N���Q�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// e_T()�ɂ�鏉����O(size)
// �z��ɂ�鏉����O(size)

// ��_�擾O(log_2 size)
// �n�ؕИa�擾O(log_2 size)
// ��Ԙa�擾O(log_2 size)

// ��_�X�VO(log_2 size)
// m_T�ɂ���_�X�VO(log_2 size)
// m_T�ɂ���ԍX�VO(log_2 size)
// �z��̉��Z�ɂ��S�̍X�VO(size)
template <typename T , typename M_T , typename I_T , typename O_T>
class AbstractIntervalAddBIT
{
private:
  M_T m_m_T;
  T m_e_T;
  I_T m_i_T;
  O_T m_o_T;
  int m_size;
  // ��֐��̔����̕��̊K������i(i-1)a_{i-1} - ia_i�j�̊Ǘ�
  AbstractBIT<T,M_T,I_T> m_bit_0;
  // �K������ia_i - a_{i-1}�j�̊Ǘ�
  AbstractBIT<T,M_T,I_T> m_bit_1;
  
public:
  inline AbstractIntervalAddBIT( M_T m_T , T e_T , I_T i_T , O_T o_T , const int& size = 0 );
  inline AbstractIntervalAddBIT( M_T m_T , T e_T , I_T i_T , O_T o_T , const vector<T>& a );

  inline AbstractIntervalAddBIT<T,M_T,I_T,O_T>& operator=( AbstractIntervalAddBIT<T,M_T,I_T,O_T>&& a );

  inline void Set( const int& i , const T& n );
  inline void Set( const vector<T>& a );
  inline void Initialise( const int& size = 0 );

  inline AbstractIntervalAddBIT<T,M_T,I_T,O_T>& operator+=( const vector<T>& a );
  inline void Add( const int& i , const T& n );
  inline void IntervalAdd( const int& i_start , const int& i_final , const T& n );

  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline T operator[]( const int& i ) const;
  inline T Get( const int& i ) const;
  inline T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
};

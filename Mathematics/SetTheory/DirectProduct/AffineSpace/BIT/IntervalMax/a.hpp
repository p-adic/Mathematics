// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a.hpp

#pragma once
#include "../a_Macro.hpp"
#include "../../../../../Algebra/Monoid/Semilattice/a.hpp"

// verify:
// https://yukicoder.me/submissions/982703�iIntervalMaxBIT�ASetMax, IntervalMax�j
// https://yukicoder.me/submissions/979134�iIntervalMinBIT�ASetMin, IntervalMin�j

// ���͈͓͂̔��ŗv��
// (1) M��U�̉�㰓����m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �z��ɂ�鏉����O(size)

// ��_�擾O(1)
// M.Product()�Ɋւ���LSB�ؕАώ擾O(1)�ileft:a[j-(j&-j)]*...*a[j-1]�Aright:a[j-1]*...*a[j+(j&-j)-1]�j
// M.Product()�Ɋւ����Ԑώ擾O(log_2 size)

// ��_���O((log_2 size)^2)
// M.Product()�Ɋւ����_��ZO(log_2 size)�i������㰓�����p����j
// M.Product()�Ɋւ����ԏ�ZO(i_final-i_start+log_2 size)�i������㰓�����p����j

// u���z������iu�ɋz�������j�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)
// �i���݂��Ȃ��ꍇ��size�ȏ�̍ŏ���2㰁~2-1��Ԃ��̂ŁAsize�ȏ�ł��邱�ƂŔ���\�j

// ���̂����̋�Ԑώ擾�ƈ�_��Z��
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// �̎�@����ʂ̉�㰓����m�C�h�Ɋg�����邱�ƂŎ���
template <typename U , typename COMM_IDEM_MONOID>
class IdempotentMonoidBIT
{
private:
  COMM_IDEM_MONOID m_M;
  int m_size;
  vector<U> m_a;
  vector<U> m_fenwick_0;
  vector<U> m_fenwick_1;
  int m_power;

public:
  inline IdempotentMonoidBIT( COMM_IDEM_MONOID M , const int& size = 0 );
  inline IdempotentMonoidBIT( COMM_IDEM_MONOID M , vector<U> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  void Set( const int& i , const U& u );

  void Multiply( const int& i , const U& u );
  void IntervalMultiply( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline const U& LSBSegmentProduct( const int& j , const bool& left = true ) const;
  U IntervalProduct( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( IntervalProduct( 0 , i ) , i )��true�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��
  // 2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int BinarySearch( const F& f );
  // IntervalProduct( 0 , i )��u���z������imax���Z�Ȃ�u�ȏ�Amin���Z�Ȃ�u�ȉ��ƂȂ�j
  // i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  int BinarySearch( const U& u );

private:
  inline void Construct();
  
};
template <typename COMM_IDEM_MONOID> IdempotentMonoidBIT( COMM_IDEM_MONOID M ) -> IdempotentMonoidBIT<inner_t<COMM_IDEM_MONOID>,COMM_IDEM_MONOID>;

// �ȉ��͓��͈͂̔͂ŗv��
// (1)' bool operator<(const U&,const U&)���S�����ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
template <typename U>
class IntervalMaxBIT :
  public IdempotentMonoidBIT<U,MaxSemilattice<U>>
{

public:
  template <typename...Args> inline IntervalMaxBIT( const U& zero_U , Args&&... args );
  inline void SetMax( const int& i , const U& u );
  inline void IntervalSetMax( const int& i_start , const int& i_final , const U& u );
  inline const U& LSBSegmentMax( const int& j , const bool& left = true ) const;
  inline U IntervalMax( const int& i_start , const int& i_final );

};

template <typename U>
class IntervalMinBIT :
  public IdempotentMonoidBIT<U,MinSemilattice<U>>
{

public:
  template <typename...Args> inline IntervalMinBIT( const U& infty_U , Args&&... args );
  inline void SetMin( const int& i , const U& u );
  inline void IntervalSetMin( const int& i_start , const int& i_final , const U& u );
  inline const U& LSBSegmentMin( const int& j , const bool& left = true ) const;
  inline U IntervalMin( const int& i_start , const int& i_final );

};

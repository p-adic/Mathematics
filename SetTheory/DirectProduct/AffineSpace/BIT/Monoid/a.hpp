// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Abstract/Monoid/a.hpp

#pragma once
#include "../a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/961779�i��_����A��Ԑρj

// ���͈͓͂̔��ŗv��
// (1) M��U�̃��m�C�h�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �z��ɂ�鏉����O(size)

// ��_�擾O(1)
// LSB�ؕАώ擾O(1)�ileft:a[j-(j&-j)]*...*a[j-1]�Aright:a[j-1]*...*a[j+(j&-j)-1]�j
// ��Ԑώ擾O(log_2 size)�ia[i_start]*...*a[i_final]�j

// ��_���O((log_2 size)^2)

// �ȉ��͓��͈͓͂̔��ŗv��
// (2) operator<(const U&,const U&)�Ɋւ���M��U�̑S�������m�C�h�\���ł���B
// (3) �e������M.One()��菬�����Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �n�ؕАς�u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��O(log_2 size)

// ���̂����̋�Ԑώ擾�ƈ�_�����
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// �̎�@����ʂ̃��m�C�h�Ɋg�����邱�ƂŎ���
template <typename U , typename MONOID>
class MonoidBIT
{
private:
  MONOID m_M;
  int m_size;
  vector<U> m_a;
  vector<U> m_fenwick_0;
  vector<U> m_fenwick_1;
  int m_power;

public:
  inline MonoidBIT( MONOID M , const int& size = 0 );
  inline MonoidBIT( MONOID M , vector<U> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  void Set( const int& i , const U& u );

  inline const int& size() const noexcept;
  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline const U& LSBSegmentProduct( const int& j , const bool& left = true ) const;
  U IntervalProduct( const int& i_start , const int& i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times int -> {0,1}�ɑ�������^�B
  // f( IntervalProduct( 0 , i ) , i )��true�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��
  // 2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int Search( const F& f );
  // IntervalProduct( 0 , i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N��Ԃ��B
  inline int Search( const U& u );
  
};
template <typename MONOID , typename...Args> MonoidBIT( MONOID M , Args&&... args ) -> MonoidBIT<inner_t<MONOID>,MONOID>;

template <class Traits , typename U , typename MONOID> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const MonoidBIT<U,MONOID>& bit ) { auto&& size = bit.size(); for( int i = 0 ; i < size ; i++ ){ ( i == 0 ? os : os << " " ) << bit[i]; } return os; }

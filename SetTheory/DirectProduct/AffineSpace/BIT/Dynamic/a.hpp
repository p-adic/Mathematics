// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Dynamic/a.hpp

#pragma once
#include "../a_Macro.hpp"
#include "../../../../../Algebra/Monoid/Group/a.hpp"
#include "../../../../../Utility/Set/Map/a.hpp"

// vector��Map<int,->�ɕύX���AAccess��Replace��ǉ��������́B

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������M.Inverse()���g���͔̂z�񏉊�����Set��IntervalSum�ƒP���֌W�Ɋւ����Ԃł�
// Search�݂̂Ȃ̂ŁA�돉����Add��InitialSegmentSum�Ƃ��̑���Search�����g��Ȃ��ꍇ��
// M.Inverse()���D���ɐݒ肵��M��U�̉����m�C�h�\���Ƃ��ėǂ��B

// M.Zero�ɂ�鏉����O(1)

// ��_�擾expected O(log_2 size)
// M.Sum()�ɂ��LSB�ؕИa�擾expected O(1)�ia[j-(j&-j)]+...+a[j-1]�j
// M.Sum()�ɂ��n�ؕИa�擾expected O(log_2 size)
// M.Sum()�ɂ���Ԙa�擾expected O(log_2 size)

// ��_���expected O(log_2 size)
// M.Sum()�ɂ���_���Zexpected O(log_2 size)

// �ȉ��͓��͈͓͂̔��ŗv��
// (2) operator<(const U&,const U&)�Ɋւ���M��U�̑S�������Q�\���ł���B
// (3) �e������M.Zero()��菬�����Ȃ��B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// M.Sum()�ɂ��n�ؕИa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��expected O(log_2 size)
// ���[�_���Œ肵������M.Sum()�ɂ���Ԙa��u�ȏ�ƂȂ�v�f�̓Y���̍ŏ��l�̓񕪒T��expected O(log_2 size)
template <typename U , typename ABELIAN_GROUP , typename INT>
class AbstractDynamicBIT
{
protected:
  ABELIAN_GROUP m_M;
  INT m_size;
  Map<INT,U> m_fenwick;
  INT m_power;
  
public:
  inline AbstractDynamicBIT( ABELIAN_GROUP M , const INT& size );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const INT& i , const U& u );
  void Add( const INT& i , const U& u );

  inline const INT& size() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U operator[]( const INT& i );
  inline U Get( const INT& i );
  inline const U& LSBSegmentSum( const INT& j ) const;
  U InitialSegmentSum( const INT& i_final );
  inline U IntervalSum( INT i_start , INT i_final );

  // F�͐Ϗ����Ɋւ��ĒP���Ȏʑ�f:U \times INT -> {0,1}�ɑ�������^�B
  // f( InitialSegmentSum( i ) , i )��true�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N�ȏ�̍ŏ���2㰁~2-1��Ԃ��iN�ȏ�ł��邱�ƂŔ��ʉ\�j�B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> INT Search( const F& f );
  // f( IntervalSum( i_start , i ) , i )��true�ƂȂ�i_start�ȏ��i�����݂���ꍇ��
  // ���̍ŏ��l��2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline INT Search( const INT& i_start , const F& f );

  // InitialSegmentSum( i )��u�ȏ�ƂȂ�i�����݂���ꍇ�ɂ��̍ŏ��l��2�i�@�ŒT���B
  // ���݂��Ȃ��ꍇ��N��Ԃ��B
  inline INT Search( const U& u );
  // IntervalSum( i_start , i )��u�ȏ�ƂȂ�i_start�ȏ��i�����݂���ꍇ�ɂ��̍ŏ��l��
  // 2�i�@�ŒT���B���݂��Ȃ��ꍇ��N��Ԃ��B
  inline INT Search( const INT& i_start , const U& u );

private:
  inline void Construct();
  inline U Access( const INT& i , U u ) noexcept;
  inline void Replace( const INT& i , U u ) noexcept;
  
};
template <typename ABELIAN_GROUP , typename INT> AbstractDynamicBIT( ABELIAN_GROUP M , const INT& ) -> AbstractDynamicBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP,INT>;

template <typename U = ll , typename INT = int>
class DynamicBIT :
  public AbstractDynamicBIT<U,AdditiveGroup<U>,INT>
{

public:
  template <typename...Args> inline DynamicBIT( const Args&... args );

};

template <class Traits , typename U , typename ABELIAN_GROUP , typename INT> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractDynamicBIT<U,ABELIAN_GROUP,INT>& bit );

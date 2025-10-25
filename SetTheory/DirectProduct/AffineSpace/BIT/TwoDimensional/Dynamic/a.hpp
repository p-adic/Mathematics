// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/Dynamic/a.hpp

#pragma once

#include "../../../../../../Algebra/Monoid/Group/a.hpp"
#include "../../../../../../Utility/Set/Map/a.hpp"

// vector��Map<int,->�ɕύX���AAccess��Replace��ǉ��������́B

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������M.Inverse()���g���͔̂z�񏉊�����Set��RectangleSum�݂̂Ȃ̂ŁA
// �돉������Add��InitialRectangleSum�����g��Ȃ��ꍇ��
// M.Inverse()���D���ɐݒ肵��M��U�̉����m�C�h�\���Ƃ��ėǂ��B

// �돉����O(1)

// ��_�擾expected O(log_2 X log_2 Y)
// M.Sum()�ɂ��LSB�ؕЋ�`�a�擾expected O(1)�i[x-(x&-x),x-1] \times [y-(y&-y),y-1]�j
// M.Sum()�ɂ��n�ؕЋ�`�a�擾expected O(log_2 X log_2 Y)
// M.Sum()�ɂ���`�a�擾expected O(log_2 X log_2 Y)

// ��_���expected O(log_2 X log_2 Y)
// M.Sum()�ɂ���_���Zexpected O(log_2 X log_2 Y)

// AbstractDynamicBIT���d�ɂ���Ύ����ł��邪�A
// �e���삪expected O((log_2 X)(Map�̃T�C�Y�̕���))�ɂȂ邱�Ƃɒ��ӁB
template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalDynamicBIT
{
protected:
  ABELIAN_GROUP m_M;
  ll m_X;
  ll m_Y;
  Map<ll,Map<ll,U>> m_fenwick;
  
public:
  inline AbstractTwoDimensionalDynamicBIT( ABELIAN_GROUP M , const ll& X , const ll& Y );

  inline void Initialise( const ll& X , const ll& Y );
  inline void Set( const ll& x , const ll& y , const U& u );
  void Add( const ll& x , const ll& y , const U& u );

  inline const ll& X() const noexcept;
  inline const ll& Y() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U Get( const ll& x , const ll& y );
  inline const U& LSBRectangleSum( const ll& i , const ll& j ) const;
  U InitialRectangleSum( const ll& x_final , const ll& y_final );
  inline U RectangleSum( ll x_start , ll x_final , ll y_start , ll y_final );

private:
  inline U Access( const ll& i , const ll& j , U u ) noexcept;
  inline void Replace( const ll& i , const ll& j , U u ) noexcept;
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractTwoDimensionalDynamicBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractTwoDimensionalDynamicBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class TwoDimensionalDynamicBIT :
  public AbstractTwoDimensionalDynamicBIT<U,AdditiveGroup<U>>
{

public:
  inline TwoDimensionalDynamicBIT( const ll& X = 0 , const ll& Y = 0 );

};

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalDynamicBIT<U,ABELIAN_GROUP>& bit );

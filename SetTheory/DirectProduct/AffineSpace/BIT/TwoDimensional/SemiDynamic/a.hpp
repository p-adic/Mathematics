// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/SemiDynamic/a.hpp

#pragma once

#include "../../../../../../Algebra/Monoid/Group/a.hpp"
#include "../../../../../../Utility/Set/Map/a.hpp"

// vector<vector<>>��vector<Map<int,->>�ɕύX���AAccess��Replace��ǉ��������́B

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������M.Inverse()���g���͔̂z�񏉊�����Set��RectangleSum�݂̂Ȃ̂ŁA
// �돉������Add��InitialRectangleSum�����g��Ȃ��ꍇ��
// M.Inverse()���D���ɐݒ肵��M��U�̉����m�C�h�\���Ƃ��ėǂ��B

// �돉����O(X)

// ��_�擾expected O(log_2 X log_2 Y)
// M.Sum()�ɂ��LSB�ؕЋ�`�a�擾expected O(1)�i[x-(x&-x),x-1] \times [y-(y&-y),y-1]�j
// M.Sum()�ɂ��n�ؕЋ�`�a�擾expected O(log_2 X log_2 Y)
// M.Sum()�ɂ���`�a�擾expected O(log_2 X log_2 Y)

// ��_���expected O(log_2 X log_2 Y)
// M.Sum()�ɂ���_���Zexpected O(log_2 X log_2 Y)

// AbstractBIT��AbstractDynamicBIT���d�ɂ���Ύ����ł��邪�A
// �e���삪expected O((log_2 X)(Map�̃T�C�Y�̕���))�ɂȂ邱�Ƃɒ��ӁB
template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalSemiDynamicBIT
{
protected:
  ABELIAN_GROUP m_M;
  int m_X;
  ll m_Y;
  vector<Map<ll,U>> m_fenwick;
  
public:
  inline AbstractTwoDimensionalSemiDynamicBIT( ABELIAN_GROUP M , const int& X , const ll& Y );

  inline void Initialise( const int& X , const ll& Y );
  inline void Set( const int& x , const ll& y , const U& u );
  void Add( const int& x , const ll& y , const U& u );

  inline const int& X() const noexcept;
  inline const ll& Y() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U Get( const int& x , const ll& y );
  inline const U& LSBRectangleSum( const int& i , const ll& j ) const;
  U InitialRectangleSum( const int& x_final , const ll& y_final );
  inline U RectangleSum( int x_start , int x_final , ll y_start , ll y_final );

private:
  inline U Access( const int& i , const ll& j , U u ) noexcept;
  inline void Replace( const int& i , const ll& j , U u ) noexcept;
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractTwoDimensionalSemiDynamicBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractTwoDimensionalSemiDynamicBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class TwoDimensionalSemiDynamicBIT :
  public AbstractTwoDimensionalSemiDynamicBIT<U,AdditiveGroup<U>>
{

public:
  inline TwoDimensionalSemiDynamicBIT( const int& x = 0 , const ll& Y = 0 );

};

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalSemiDynamicBIT<U,ABELIAN_GROUP>& bit );

// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/a.hpp

#pragma once

#include "../../../../../Algebra/Monoid/Group/a.hpp"

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// ������M.Inverse()���g���͔̂z�񏉊�����Set��RectangleSum�݂̂Ȃ̂ŁA
// �돉������Add��InitialRectangleSum�����g��Ȃ��ꍇ��
// M.Inverse()���D���ɐݒ肵��M��U�̉����m�C�h�\���Ƃ��ėǂ��B

// M.Zero()�ɂ�鏉����O(X \times Y)
// �z��ɂ�鏉����O(X \times Y)

// ��_�擾O(log_2 X log_2 Y)
// M.Sum()�ɂ��LSB�ؕЋ�`�a�擾O(1)�i[x-(x&-x),x-1] \times [y-(y&-y),y-1]�j
// M.Sum()�ɂ��n�ؕЋ�`�a�擾O(log_2 X log_2 Y)
// M.Sum()�ɂ���`�a�擾O(log_2 X log_2 Y)

// ��_���O(log_2 X log_2 Y)
// M.Sum()�ɂ���_���ZO(log_2 X log_2 Y)

// AbstractBIT���d�ɂ���Ύ����ł��邪�A
// ���Z�̒�`�̂��߂ɗ]�v��friend�w�肪�K�v�Ȃ̂Œ��ڎ�������B
template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalBIT
{
protected:
  ABELIAN_GROUP m_M;
  int m_X;
  int m_Y;
  vector<vector<U>> m_fenwick;
  
public:
  inline AbstractTwoDimensionalBIT( ABELIAN_GROUP M , const int& X = 0 , const int& Y = 0 );
  inline AbstractTwoDimensionalBIT( ABELIAN_GROUP M , const vector<vector<U>>& a );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& x , const int& y , const U& u );
  void Add( const int& x , const int& y , const U& u );

  inline const int& X() const noexcept;
  inline const int& Y() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U Get( const int& x , const int& y );
  inline const U& LSBRectangleSum( const int& i , const int& j ) const;
  U InitialRectangleSum( const int& x_final , const int& y_final );
  inline U RectangleSum( int x_start , int x_final , int y_start , int y_final );

};
template <typename ABELIAN_GROUP , typename...Args> AbstractTwoDimensionalBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractTwoDimensionalBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class TwoDimensionalBIT :
  public AbstractTwoDimensionalBIT<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline TwoDimensionalBIT( const Args&... args );

};
template <typename U> TwoDimensionalBIT( const vector<vector<U>>& a ) -> TwoDimensionalBIT<U>;

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>& bit );

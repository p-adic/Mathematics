// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/IntervalAdd/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../../Algebra/Monoid/Group/Module/a.hpp"

// ���͈͓͂̔��ŗv��
// (1) M��U��Z���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �돉����O(X \times Y)
// �z��ɂ�鏉����O(X \times Y)

// ��`�a�擾O(log_2 X log_2 Y)

// ��_���O(log_2 X log_2 Y)
// M.Sum()�ɂ���`���ZO(log_2 X log_2 Y)
template <typename U , typename Z_MODULE>
class AbstractTwoDimensionalIntervalAddBIT
{

private:
  Z_MODULE m_M;
  // �K������ia_i - a_{i-1}�j����鑀���D
  // ������1���炵�����̊K������̔����i-(i-1)(a_i - a_{i-1})�j����鑀���F�ƒu���B
  // x������D�Ay������D�������̂��Q����BIT�ŊǗ��i��`�a����_�擾�ɑΉ��j
  AbstractTwoDimensionalBIT<U,Z_MODULE> m_bit00;
  // x������D�Ay������F�������̂��Q����BIT�ŊǗ��i��`�a��y�����̗ݐϘa-��_�擾�̒萔�{�ɑΉ��j
  AbstractTwoDimensionalBIT<U,Z_MODULE> m_bit01;
  // x������F�Ay������D�������̂��Q����BIT�ŊǗ��i��`�a��x�����̗ݐϘa-��_�擾�̒萔�{�ɑΉ��j
  AbstractTwoDimensionalBIT<U,Z_MODULE> m_bit10;
  // x������F�Ay������F�������̂��Q����BIT�ŊǗ��i��`�a����`�a-x�����̗ݐϘa-y�����̗ݐϘa+��_�擾�̒萔�{�ɑΉ��j
  AbstractTwoDimensionalBIT<U,Z_MODULE> m_bit11;
  
public:
  inline AbstractTwoDimensionalIntervalAddBIT( Z_MODULE M , const int& X = 0 , const int& Y = 0 );
  inline AbstractTwoDimensionalIntervalAddBIT( Z_MODULE M , vector<vector<U>> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& x , const int& y , const U& u );
  inline void Add( const int& x , const int& y , const U& u );
  void IntervalAdd( int x_start , int x_final , int y_start , int y_final , const U& u );

  inline const int& X() const noexcept;
  inline const int& Y() const noexcept;
  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U Get( const int& x , const int& y );
  inline U InitialRectangleSum( const int& x , const int& y );
  inline U RectangleSum( int x_start , int x_final , int y_start , int y_final );
  
};
template <typename Z_MODULE , typename...Args> AbstractTwoDimensionalIntervalAddBIT( Z_MODULE M , const Args&... args ) -> AbstractTwoDimensionalIntervalAddBIT<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U = ll>
class TwoDimensionalIntervalAddBIT :
  public AbstractTwoDimensionalIntervalAddBIT<U,Module<int,U>>
{

public:
  template <typename...Args> inline TwoDimensionalIntervalAddBIT( Args&&... args );

};
template <typename U> TwoDimensionalIntervalAddBIT( vector<vector<U>> a ) -> TwoDimensionalIntervalAddBIT<U>;

template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalIntervalAddBIT<U,Z_MODULE>& bit );

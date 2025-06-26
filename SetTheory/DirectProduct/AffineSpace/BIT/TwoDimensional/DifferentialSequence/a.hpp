// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TwoDimensional/DifferentialSequence/a.hpp

#pragma once
#include "../a.hpp"

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �돉����O(X \times Y)
// �z��ɂ�鏉����O(X \times Y)

// ��_�擾O(log_2 X log_2 Y)

// ��_���O(log_2 X log_2 Y)
// M.Sum()�ɂ���`���ZO(log_2 X log_2 Y)
template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalDifferenceSequenceBIT :
  public AbstractTwoDimensionalBIT<U,ABELIAN_GROUP>
{

public:
  inline AbstractTwoDimensionalDifferenceSequenceBIT( ABELIAN_GROUP M , const int& X = 0 , const int& Y = 0 );
  inline AbstractTwoDimensionalDifferenceSequenceBIT( ABELIAN_GROUP M , vector<vector<U>> a );

  inline AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>& operator=( AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>&& bit );
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& x , const int& y , const U& u );
  inline void Add( const int& x , const int& y , const U& u );
  void IntervalAdd( int x_start , int x_final , int y_start , int y_final , const U& u );

  // const�Q�ƂłȂ����Ƃɒ��ӁB
  inline U Get( const int& x , const int& y );

private:
  inline AbstractTwoDimensionalDifferenceSequenceBIT( ABELIAN_GROUP& M , const vector<vector<U>>& a , const bool& dummy );
  static vector<vector<U>> Differentiate( ABELIAN_GROUP& M , vector<vector<U>> a );
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractTwoDimensionalDifferenceSequenceBIT( ABELIAN_GROUP M , const Args&... args ) -> AbstractTwoDimensionalDifferenceSequenceBIT<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class TwoDimensionalDifferenceSequenceBIT :
  public AbstractTwoDimensionalDifferenceSequenceBIT<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline TwoDimensionalDifferenceSequenceBIT( Args&&... args );

};
template <typename U> TwoDimensionalDifferenceSequenceBIT( vector<vector<U>> a ) -> TwoDimensionalDifferenceSequenceBIT<U>;

template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , AbstractTwoDimensionalDifferenceSequenceBIT<U,ABELIAN_GROUP>& bit );

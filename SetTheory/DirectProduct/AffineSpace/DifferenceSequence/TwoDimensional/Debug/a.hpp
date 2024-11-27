// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/TwoDimensional/Debug/a.hpp

#pragma once

// �f�o�b�O�p�ɃG���[�o�͂�ǉ��������́B
// �e�͈͍X�V��O(size_X*size_Y)�ǉ�����邱�Ƃɒ��ӁB


// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a.hpp

#pragma once

template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalDifferenceSequence
{

private:
  ABELIAN_GROUP m_M;
  int m_size_X;
  int m_size_Y;

  // (0,0)����̊K��������Ǘ��B
  vector<vector<U>> m_a;
  // �K������̊K���i-1�̎��͗ݐϘa�j���Ǘ��B
  int m_degree;
  
public:
  inline AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const int& size_X , const int& size_Y , int degree = 1 );
  inline AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const vector<vector<U>>& a = {} , int degree = 0 );

  template <typename...Args> inline void Initialise( Args&&... args );
  const int& size_X() const noexcept;
  const int& size_Y() const noexcept;

  // �f�o�b�O�o�͗p
  const vector<vector<U>>& Get() const noexcept;

  // degree�K�̊K�������(i_x,i_y)�ł̒l��u��������B
  inline void Set( const int& i_x , const int& i_y , const U& u , const int& degree = 0 );
  // degree�K�̊K�������(i_x,i_y)�ł̒l��u�����Z����B
  inline void Add( const int& i_x , const int& i_y , const U& u , const int& degree = 0 );

  // degree+1�K�̊K�������p����degree�K�̊K�������(i_x,i_y)�ł̒l��u�����Z����B
  inline void RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const U& u , const int& degree = 0 );

  // degree�K�̊K������̒l���擾����B
  inline const U& Get( const int& i_x , const int& i_y , const int& degree = 0 );

  // ����
  // (1) -1 <= i_final_x < m_size_X
  // (2) -1 <= i_final_y < m_size_Y
  // �𖞂����ꍇ�̂݃T�|�[�g�Bdegree-1�K�̊K�������p����degree�K�̊K������̒l�̑��a
  // a[0][i_start_y]...a[i_final_x][i_start_y]...
  // a[0][i_final_y]...a[i_final_x][i_final_y]
  // ��M�Ɋւ��Čv�Z����B
  inline const U& InitialRectangleSum( const int& i_x , const int& i_y , const int& degree = 0 );

  // ����
  // (1) 0 <= i_start_x����i_start_x-1 <= i_final_x < m_size_X
  // (2) 0 <= i_start_y����i_start_y-1 <= i_final_y < m_size_Y
  // �𖞂����ꍇ�̂݃T�|�[�g�Bdegree-1�K�̊K�������p����degree�K�̊K������̒l�̑��a
  // a[i_start_x][i_start_y]...a[i_final_x][i_start_y]...
  // a[i_start_x][i_final_y]...a[i_final_x][i_final_y]
  // ��M�Ɋւ��Čv�Z����B
  inline U RectangleSum( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const int& degree = 0 );

private:
  inline void Shift( const int& degree );
  void Integrate();
  void Differentiate();
  
};
template <typename ABELIAN_GROUP> AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const int& size_X , const int& size_Y ) -> AbstractTwoDimensionalDifferenceSequence<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class TwoDimensionalDifferenceSequence :
  public AbstractTwoDimensionalDifferenceSequence<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline TwoDimensionalDifferenceSequence( Args&&... args );

};


// �f�o�b�O�o�͗p
template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>& tdds );

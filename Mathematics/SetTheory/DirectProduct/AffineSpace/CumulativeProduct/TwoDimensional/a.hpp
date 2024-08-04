// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/CumulativeProduct/TwoDimensional/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/961862�i��`�a�j

// �Q�����z���̗ݐϘa�B
// �͈͍X�V���K�v�ȏꍇ�͑���ɂQ�����K��������g�p�B


// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �����藧�ꍇ�̂݃T�|�[�g�B

// �z��ɂ�鏉����O(size_X*size_Y)

// �n��`�aO(1)
// ��`�aO(1)
template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalCumulativeSum
{

private:
  ABELIAN_GROUP m_M;
  int m_size_X;
  int m_size_Y;
  vector<vector<U>> m_a;

public:
  AbstractTwoDimensionalCumulativeSum( ABELIAN_GROUP M , const int& size_X , const int& size_Y );
  AbstractTwoDimensionalCumulativeSum( ABELIAN_GROUP M , const vector<vector<U>>& a = {} );

  template <typename...Args> inline void Initialise( const Args&... args );
  
  // ����
  // (1) -1 <= i_final_x < m_size_X
  // (2) -1 <= i_final_y < m_size_Y
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // a[0][i_start_y]...a[i_final_x][i_start_y]...
  // a[0][i_final_y]...a[i_final_x][i_final_y]
  // ��M�Ɋւ��Čv�Z����B
  inline const U& InitialRectangleSum( const int& i_x , const int& i_y ) const;

  // ����
  // (1) 0 <= i_start_x����i_start_x-1 <= i_final_x < m_size_X
  // (2) 0 <= i_start_y����i_start_y-1 <= i_final_y < m_size_Y
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // a[i_start_x][i_start_y]...a[i_final_x][i_start_y]...
  // a[i_start_x][i_final_y]...a[i_final_x][i_final_y]
  // ��M�Ɋւ��Čv�Z����B
  inline U RectangleSum( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y );

};
template <typename ABELIAN_GROUP , typename...Args> AbstractTwoDimensionalCumulativeSum( ABELIAN_GROUP , const Args&... ) -> AbstractTwoDimensionalCumulativeSum<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;


template <typename U = ll>
class TwoDimensionalCumulativeSum :
  public AbstractTwoDimensionalCumulativeSum<U,AdditiveGroup<U>>
{

public:
  inline TwoDimensionalCumulativeSum( const int& size_X , const int& size_Y );
  inline TwoDimensionalCumulativeSum( const vector<vector<U>>& a = {} );
  
};

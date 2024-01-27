// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/CumulativeProd/TwoDimensional/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/947062�i��`�a�j

// �Q�����z���̗ݐϘa�B
// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �����藧�ꍇ�̂݃T�|�[�g�B

// �z��ɂ�鏉����O(size_X*size_Y)

// �n��`�aO(1)
// ��`�aO(1)
template <typename U , typename ABELIAN_GROUP>
class TwoDimensionalCumulativeSum
{

private:
  int m_size_X;
  int m_size_Y;
  ABELIAN_GROUP m_M; 
  vector<vector<U>> m_a;

public:
  TwoDimensionalCumulativeSum( const vector<vector<U>>& a , ABELIAN_GROUP M );

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

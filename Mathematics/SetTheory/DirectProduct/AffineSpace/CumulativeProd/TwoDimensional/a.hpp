// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/CumulativeProd/TwoDimensional/a.hpp

#pragma once

// �Q�����z���̗ݐϘa�B
// ���͈͓͂̔��ŗv��
// (1) (T,m_T:T^2->T,e_T:1->T,i_T:T->T)�����Q�ł���B
// �����藧�ꍇ�̂݃T�|�[�g�B

// �z��ɂ�鏉����O(size_X*size_Y)

// �n��`�aO(1)
// ��`�aO(1)
template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&)>
class TwoDimensionalCumulativeSum
{

private:
  int m_size_X;
  int m_size_Y;
  vector<vector<T> > m_a;
  
public:
  TwoDimensionalCumulativeSum( const vector<vector<T> >& a );
  template <int size_X_max , int size_Y_max> TwoDimensionalCumulativeSum( const T ( &a )[size_X_max][size_Y_max] , const int& size_X , const int& size_Y );

  // ����
  // (1) -1 <= i_final_x < m_size_X
  // (2) -1 <= i_final_y < m_size_Y
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // a[0][i_start_y]...a[i_final_x][i_start_y]...
  // a[0][i_final_y]...a[i_final_x][i_final_y]
  // ��m_T�Ɋւ��Čv�Z����B
  inline const T& InitialRectangleSum( const int& i_x , const int& i_y ) const;

  // ����
  // (1) 0 <= i_start_x����i_start_x-1 <= i_final_x < m_size_X
  // (2) 0 <= i_start_y����i_start_y-1 <= i_final_y < m_size_Y
  // �𖞂����ꍇ�̂݃T�|�[�g�B
  // a[i_start_x][i_start_y]...a[i_final_x][i_start_y]...
  // a[i_start_x][i_final_y]...a[i_final_x][i_final_y]
  // ��m_T�Ɋւ��Čv�Z����B
  inline T RectangleSum( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y ) const;

};

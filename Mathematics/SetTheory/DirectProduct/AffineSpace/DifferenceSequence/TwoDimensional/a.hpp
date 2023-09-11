// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a.hpp

#pragma once

// 2�����z���̊K������B��{�I��2����imos�@
// https://imoz.jp/algorithms/imos_method.html
// �ɏ����B

// ���͈͓͂̔��ŗv��
// (6) (T,operator+:T^2->T,T(),operator-:T->T)�͉��Q�ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// init�ɂ�鏉����O(size_X*size_Y)
// �z��ɂ�鏉����O(size_X*size_Y)

// ��_���O(size_X*size_Y)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j
// ��_�擾O(size_X*size_Y)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j

// ��_���ZO(1)�i��p��x���]�����Ȃ��j
// �n��`���ZO(1)�i��p��x���]������j
// ��`���ZO(1)�i��p��x���]������j
// ���@O(size_X*size_Y)�i��p�̒x���]������������j
template <typename T>
class TwoDimensionalDifferenceSequence
{

private:
  int m_size_X;
  int m_size_Y;
  vector<vector<T> > m_a;
  vector<vector<T> > m_lazy_addition;
  bool m_updated;
  
public:
  inline TwoDimensionalDifferenceSequence( const vector<vector<T> >& a );
  inline TwoDimensionalDifferenceSequence( vector<vector<T> >&& a );
  inline TwoDimensionalDifferenceSequence( const int& size_X , const int& size_Y );
  template <int size_X_max , int size_Y_max> inline TwoDimensionalDifferenceSequence( const T ( &a )[size_X_max][size_Y_max] , const int& size_X , const int& size_Y );

  
  // ��p�̒x���]�����������Ă���l��������B
  inline void Set( const int& i_x , const int& i_y , const T& t );
  // ��p�̒x���]�����������Ă���l���Q�Ƃ���B
  inline const T& Get( const int& i_x , const int& i_y );
  // ��p�̒x���]�������������Ɍ��X�̒l���Q�Ƃ���B
  inline T& Ref( const int& i_x , const int& i_y );

  // (i_x,i_y)�ł̒l��y��x���]�������ɉ��Z����B
  inline void Add( const int& i_x , const int& i_y , const T& t );

  // t��x���]���ŉ��Z����B
  inline void RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const T& t );
  // t��x���]���Ō��Z����B
  inline void RectangleSubtract( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const T& t );

  // ��p�̒x���]�����������Ă���S�̂����Z����B
  inline TwoDimensionalDifferenceSequence<T>& operator+=( const TwoDimensionalDifferenceSequence<T>& a );

  // ��p�̒x���]������������B
  void Update();

};

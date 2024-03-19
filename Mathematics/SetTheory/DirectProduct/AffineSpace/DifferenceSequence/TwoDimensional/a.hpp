// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/961862�i�돉�����A��_�擾�A��`���Z�j
// https://yukicoder.me/submissions/961857�i�돉�����A��_�擾�A��`���Z�j

// �Q�����z���̊K������B��{�I�ɂQ����imos�@
// https://imoz.jp/algorithms/imos_method.html
// �ɏ����B

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// M.Zero()�ɂ�鏉����O(size_X*size_Y)
// �z��ɂ�鏉����O(size_X*size_Y)

// ��_���O(size_X*size_Y)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j
// ��_�擾O(size_X*size_Y)�i��p�̒x���]������������B���X��p�̒x���]�����Ȃ��ꍇ��O(1)�j

// ��_���ZO(1)�i��p��x���]�����Ȃ��j
// �n��`���ZO(1)�i��p��x���]������j
// ��`���ZO(1)�i��p��x���]������j
// ���@O(size_X*size_Y)�i��p��x���]�����Ȃ��j
template <typename U , typename GROUP>
class AbstractTwoDimensionalDifferenceSequence
{

private:
  GROUP m_M;
  int m_size_X;
  int m_size_Y;
  vector<vector<U>> m_a;
  vector<vector<U>> m_lazy_addition;
  bool m_updated;
  
public:
  inline AbstractTwoDimensionalDifferenceSequence( GROUP M , const int& size_X , const int& size_Y );
  inline AbstractTwoDimensionalDifferenceSequence( GROUP M , vector<vector<U>> a = {} );

  template <typename...Args> inline void Initialise( Args&&... args );
  // ��p�̒x���]�����������Ă���l��������B
  inline void Set( const int& i_x , const int& i_y , const U& u );
  // ��p�̒x���]�����������Ă���l���Q�Ƃ���B
  inline const U& Get( const int& i_x , const int& i_y );
  // ��p�̒x���]�������������Ɍ��X�̒l���Q�Ƃ���B
  inline U& Ref( const int& i_x , const int& i_y );

  // (i_x,i_y)�ł̒l��y��x���]�������ɉ��Z����B
  inline void Add( const int& i_x , const int& i_y , const U& u );

  // t��x���]���ŉ��Z����B
  inline void RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const U& u );

  // a��x���]�������ɉ��Z����B
  inline AbstractTwoDimensionalDifferenceSequence<U,GROUP>& operator+=( const vector<U>& a );

  // ��p�̒x���]������������B
  void Update();

};
template <typename GROUP> AbstractTwoDimensionalDifferenceSequence( GROUP M , const int& size_X , const int& size_Y ) -> AbstractTwoDimensionalDifferenceSequence<inner_t<GROUP>,GROUP>;

template <typename U = ll>
class TwoDimensionalDifferenceSequence :
  public AbstractTwoDimensionalDifferenceSequence<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline TwoDimensionalDifferenceSequence( Args&&... args );

};

// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/999929�i�돉�����A��_�擾�A��`���Z�A��`�擾�j
// https://yukicoder.me/submissions/961857�i�돉�����A��_�擾�A��`���Z�j

// �Q�����z���̊K������̍��K���B��{�I�ɂQ����imos�@
// https://imoz.jp/algorithms/imos_method.html
// �ɏ����B�͈͍X�V���s�v�ȏꍇ�͑���Ƀt�@�C���e�ʂ̏������Q�����ݐϘa���g�p�B

// ���͈͓͂̔��ŗv��
// (1) M��U�̉��Q�\���ł���B
// �����藧�ꍇ�ɂ̂݃T�|�[�g�B

// M.Zero()�ɂ�鏉����O(size_X*size_Y)
// �z��ɂ�鏉����O(size_X*size_Y)

// ��_���O(|m_degree|*size_X*size_Y)
// ��_���ZO(|m_degree|*size_X*size_Y)
// �n��`���ZO(|m_degree-1|*size_X*size_Y)
// ��`���ZO(|m_degree-1|*size_X*size_Y)

// ��_�擾O(|m_degree|*size_X*size_Y)
// �n��`�擾O(|m_degree+1|*size_X*size_Y)
// ��`�擾O(|m_degree+1|*size_X*size_Y)

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

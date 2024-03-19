// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/GeometricProgressionMin/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../../Algebra/Monoid/Modulea.hpp"

// verify:
// https://yukicoder.me/submissions/961726

// ���RU���Q�̍\���˂Ɖ��Z�̍���
template <typename U>
class GeometricProgressionMinComposition :
  virtual public PointedSet<vector<U>> ,
  virtual public VirtualRSet<pair<int,U>,vector<U>>
{
  
public:
  inline GeometricProgressionMinComposition( const int& size , const U& infty );
  vector<U> Action( const pair<int,U>& y0 , vector<U> y1 );

};

// ���RU���Q�̍���p�\��
template <typename U , typename N_MODULE>
class GeometricProgressionMinAction :
  virtual public VirtualRSet<vector<U>,pair<U,int>>
{
  
private:
  N_MODULE m_M;
  const vector<U>* m_p_memory;

public:
  inline GeometricProgressionMinAction( N_MODULE M , const vector<U>& memory );
  pair<U,int> Action( const vector<U>& y , pair<U,int> u );

};

#include "a_Alias.hpp"

// ���͈͓͂̔��ŗv��
// (1) M��bool operator<(const U&,const U&)�Ɋւ���U�̑S����N���Q�\���ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// �N�G�����̓��䐔��(r^i y)_i�̌���r�̎�ސ���C�Ƃ����B

// �돉����O(N)
// �z��ɂ�鏉����O(N)

// ��_�擾O(C)

// ��_���O(CN^{1/2})�i�������󋵎����O(1)�j
// ���䐔��(r^i y)_i�ɂ����min��pO(N^{1/2})
template <typename U , typename N_MODULE>
class GeometricProgressionMinDualSqrtDecomposition :
  public BaseOfGeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>
{

private:
  vector<U> m_memory;
  
public:
  template <typename...Args> inline GeometricProgressionMinDualSqrtDecomposition( N_MODULE M , const U& infty , vector<U> memory_r , vector<U> a = {} , Args&&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , U u );
  inline void IntervalAct( const int& i_start , const int& i_final , const vector<U>& f ) = delete;
  inline void IntervalSetMin( const int& i_start , const int& i_final , const int& r_num , const U& y );

  inline U operator[]( const int& i );
  inline U Get( const int& i );

private:
  static vector<pair<U,int>> GetGraph( vector<U> a );
  
};
template <typename N_MODULE , typename...Args> GeometricProgressionMinDualSqrtDecomposition( N_MODULE M , Args&&... args ) -> GeometricProgressionMinDualSqrtDecomposition<inner_t<N_MODULE>,N_MODULE>;

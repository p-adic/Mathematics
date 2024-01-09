// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// verify: https://yukicoder.me/submissions/942441�iNextSubset�j

template <int digit>
class BitExhausiveSearch :
  public BreadthFirstSearch_Body
{

private:
  static unordered_map<int,int> g_v;
  
public:
  // V�͍ő�̏W���ɑΉ����鐮��+1�idigit��㰏W���S�̂Ȃ�1<<digit�j
  inline BitExhausiveSearch( const int& V = 1 << digit );

  // t�ɑΉ����镔���W����1�v�f��ǉ����������W���Ŗ����B�Ȃ��̂��i�[�B
  inline list<int> UnreachedAdjacentSupsetOf( const int& t ) noexcept;
  // t�ɑΉ����镔���W����1�v�f���폜���������W���Ŗ����B�Ȃ��̂��i�[�B
  inline list<int> UnreachedAdjacentSubsetOf( const int& t ) noexcept;

  // t�ɑΉ����镔���W����^�Ɋ܂ޕ����W���Ŗ����B�Ȃ��̂��i�[�B
  inline list<int> UnreachedProperSupsetOf( const int& t ) noexcept;
  // t�ɑΉ����镔���W���̐^�����W���Ŗ����B�Ȃ��̂��i�[�B
  inline list<int> UnreachedProperSubsetOf( const int& t ) noexcept;

  // t�ɑΉ����镔���W����1�v�f��ǉ����������W�����i�[�B
  inline list<int> AdjacentSupsetOf( const int& t ) noexcept;
  // t�ɑΉ����镔���W����^�Ɋ܂ޕ����W�����i�[�B
  inline list<int> ProperSupsetOf( const int& t ) noexcept;

  // t�ɑΉ����镔���W����1�v�f���폜���������W�����i�[�B
  static inline list<int> AdjacentSubsetOf( const int& t ) noexcept;
  // t�ɑΉ����镔���W���̐^�����W�����i�[�B
  static inline list<int> ProperSubsetOf( const int& t ) noexcept;

  // �Ή����镔���W���̔Z�x��ς�����t�������Ō㑱�ɑJ�ڂ�����B
  static inline bool NextSubset( int& t , const int& V = 1 << digit ) noexcept;

  // d<digit����t==1<<d�𖞂���d��Ԃ��B
  static inline const int& ValuationOf( const int& t ) noexcept;

private:
  inline list<int> e( const int& t );
  
};

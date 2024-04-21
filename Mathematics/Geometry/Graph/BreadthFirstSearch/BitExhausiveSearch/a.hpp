// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/976448�iNextSubset�j

class BitExhausiveSearch;

class BitExhausiveEdge
{

  friend class BitExhausiveSearch;
  
private:
  const int* m_p_V;

public:
  inline vector<int> operator()( const int& t );

};

// bit��0����1�ɕύX��������ɗL���ӂ�\�����O���t�ɑ΂���BFS
class BitExhausiveSearch :
  public BreadthFirstSearch<int,Graph<BitExhausiveEdge>>
{

private:
  Graph<BitExhausiveEdge> m_G;
  const int* m_p_V;
  int m_digit;
  
public:
  // V�͍ő�̏W���ɑΉ����鐮��+1�idigit��㰏W���S�̂Ȃ�1<<digit�j
  inline BitExhausiveSearch( const int& V );

  
  // 1+d���ڂ�answer[d]�Ɋi�[����B
  inline vector<int> to_vec( const int& t );
  inline int to_int( const vector<int>& a );
  
  // t�ɑΉ����镔���W����1�v�f��ǉ����������W���Ŗ����B�Ȃ��̂��i�[�����B�ς݂Ƀ}�[�N�B
  inline vector<int> UnreachedAdjacentSupsetOf( const int& t );
  // t�ɑΉ����镔���W����1�v�f���폜���������W���Ŗ����B�Ȃ��̂��i�[�����B�ς݂Ƀ}�[�N�B
  // O(log_2 t)������A���_BFS�ł͂�����g����O(2^digit)�ŗ}������B
  inline vector<int> UnreachedAdjacentSubsetOf( const int& t );

  // t�ɑΉ����镔���W����^�Ɋ܂ޕ����W���Ŗ����B�Ȃ��̂��i�[�����B�ς݂Ƀ}�[�N�B
  inline vector<int> UnreachedProperSupsetOf( const int& t );
  // t�ɑΉ����镔���W���̐^�����W���Ŗ����B�Ȃ��̂��i�[�����B�ς݂Ƀ}�[�N�B
  // t�̃I�[�_�[��������̂ŁA���_BFS�ł�����g���ƍň�3^digit�̃I�[�_�[�ɂȂ邱�Ƃɒ��ӁB
  inline vector<int> UnreachedProperSubsetOf( const int& t );

  // t�ɑΉ����镔���W����1�v�f��ǉ����������W�����i�[�B
  inline vector<int> AdjacentSupsetOf( const int& t );
  // t�ɑΉ����镔���W����^�Ɋ܂ޕ����W�����i�[�B
  inline vector<int> ProperSupsetOf( const int& t );

  // t�ɑΉ����镔���W����1�v�f���폜���������W�����i�[�B
  static inline vector<int> AdjacentSubsetOf( const int& t );
  // t�ɑΉ����镔���W���̐^�����W�����i�[�B
  static inline vector<int> ProperSubsetOf( const int& t );

  // �Ή����镔���W���̔Z�x��ς�����t�������Ō㑱�ɑJ�ڂ�����B
  inline bool NextSubset( int& t );
  inline bool NextSubset( vector<int>& S );

  // t��2�i�\�L�ɂ����錅����Ԃ��B�iO(log_2(log_2(t)))�j
  static inline int DigitOf( const int& t );
  // t��2㰂̎��̂݃T�|�[�g�B
  // t��2�i���@�t�l�����������ĕԂ��B�i���vO(max log_2 t)�j
  static inline const int& ValuationOf( const int& t );
  
};

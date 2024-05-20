// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/AdicExhausiveSearch/a.hpp

#pragma once
//verify:
// https://yukicoder.me/submissions/976478�iNext, Shift�j
// https://yukicoder.me/submissions/976469�iNextPermutation�j
// https://yukicoder.me/submissions/976492�iPower, to_vec�j

#include "../../a.hpp"

class AdicExhausiveSearch;

class AdicExhausiveEdge
{

  friend class AdicExhausiveSearch;
  
private:
  const int* m_p_V;
  const int* m_p_N;
  const int* m_p_N_minus;
  bool m_reversed;

public:
  inline vector<int> operator()( const int& t );

};

// N�i�@�\�L�̌���N-1�����̒l��1���₷�����ɗL���ӂ�\�����O���t�ɑ΂���BFS
class AdicExhausiveSearch :
  public BreadthFirstSearch<int,Graph<AdicExhausiveEdge>>
{

private:
  Graph<AdicExhausiveEdge> m_G;
  const int* m_p_V;
  int m_N;
  int m_N_minus;
  int m_digit;
  vector<int> m_N_power;
  vector<int> m_valuation;
  
public:
  // V�͍ő�̐���+1�iN�i�@�\�L��digit���̐����S�̂Ȃ�N^digit�j
  inline AdicExhausiveSearch( const int& N , const int& V , const bool& reversed = false );
  inline AdicExhausiveSearch( const int& N , const int& digit , const int& dummy , const bool& reversed = false );

  // 1+d���ڂ�answer[d]�Ɋi�[����B
  inline vector<int> to_vec( int t );
  inline int to_int( const vector<int>& a );

  // t��N�i�@�\�L�̌���N-1�����̒l��1���₵�����Ŗ����B�Ȃ��̂��i�[�����B�ς݂Ƀ}�[�N�B
  inline vector<int> UnreachedAdjacentUpperboundOf( const int& t );
  // t��N�i�@�\�L�̌���1�ȏ�̒l��1���炵�����Ŗ����B�Ȃ��̂��i�[�����B�ς݂Ƀ}�[�N�B
  // O(log_N t)������A���_BFS�ł͂�����g����O(N^digit)�ŗ}������B
  inline vector<int> UnreachedAdjacentLowerboundOf( const int& t );

  // t����N�i�@�\�L�̌���^�ɑ��₵�����Ŗ����B�Ȃ��̂��i�[�����B�ς݂Ƀ}�[�N�B
  inline vector<int> UnreachedProperUpperboundOf( const int& t );
  // t����N�i�@�\�L�̌���^�Ɍ��炵�����Ŗ����B�Ȃ��̂��i�[�����B�ς݂Ƀ}�[�N�B
  // t�̃I�[�_�[��������̂ŁA���_BFS�ł�����g���ƍň�3^digit�̃I�[�_�[�ɂȂ邱�Ƃɒ��ӁB
  inline vector<int> UnreachedProperLowerboundOf( const int& t );

  // t��N�i�@�\�L�̌���N-1�����̒l��1���₵�������i�[�B
  inline vector<int> AdjacentUpperboundOf( const int& t );
  // t����N�i�@�\�L�̌���^�ɑ��₵�������i�[�B
  inline vector<int> ProperUpperboundOf( const int& t );

  // t��N�i�@�\�L�̌���N-1�����̒l��1���炵�������i�[�B
  inline vector<int> AdjacentLowerboundOf( const int& t );
  // t����N�i�@�\�L�̌���^�Ɍ��炵�������i�[�B
  inline vector<int> ProperLowerboundOf( const int& t );

  // N�i�@�\�L�̌��̕��z��ς�����t�������Ō㑱�ɑJ�ڂ�����B
  inline bool NextPermutation( int& t );
  inline bool NextPermutation( vector<int>& S );

  // t��N�i�\�L�ɂ����錅����Ԃ��B�iO(log_N(t))�j
  inline int DigitOf( const int& t );
  // t��N㰂̎��̂݃T�|�[�g�B
  // t��N�Ŋ���؂��񐔂����������ĕԂ��B�i���vO(max log_N t)�j
  inline const int& ValuationOf( const int& t );
  inline const int& Power( const int& digit ) const;
  static inline int Power( int N , int digit );
  
};


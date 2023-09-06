// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/HopcroftKarp/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/911317

// (S,T,edge)���񕔃O���t�ł���ꍇ�̂݃T�|�[�g�B
// edge�̃T�C�Y��e�ƒu���B�ő�񕔃}�b�`���O����
// ���Ԍv�Z��O((S+T+e)��(S+T))
// ��Ԍv�Z��O(S+T+e)
// �ŉ����B����
// - e��O(ST)�̎��͎��Ԍv�Z��O(ST��(S+T))
// - e��O(S+T)�̎��͎��Ԍv�Z��O((S+T)��(S+T))
// �ŉ����B
template <int S_max , int T_max>
class HopcroftKarp
{

private:
  // BFS�̃e���v���[�g������Edge��n�����߂ɁAstatic�����o�݂̂��g���B
  static int g_S;
  static int g_T;
  static set<int> g_unchosen_source;
  static list<int> g_edge[S_max];
  static int g_prev[T_max];

public:
  HopcroftKarp() = delete;

  static list<pair<int,int> > Solve( const int& S , const int& T , const list<pair<int,int> >& edge );

  // BFS�̃e���v���[�g�����ɓn���B
  // (1) w=0�̎��́A���I����S�̒��_���X�g��Ԃ��B
  // (2) 0<w<=S�̎��́As=w-1����̗L���ӂ̏I�[�S�̂̃��X�g��Ԃ��B
  // (3) S<w<=S+T�̎��́At=w-S-1�����I���Ȃ�΋󃊃X�g��Ԃ��A
  //     �I���ς݂Ȃ�ΑΉ�����L���ӂ̎n�[s�݂̂���Ȃ郊�X�g��Ԃ��B
  static list<int> Edge( const int& w );

};


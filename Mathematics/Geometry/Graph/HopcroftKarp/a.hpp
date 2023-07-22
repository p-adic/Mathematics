// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/HopcroftKarp/a.hpp

#pragma once

// (S,T,edge)���񕔃O���t�ł���ꍇ�̂݃T�|�[�g�B
// edge�̃T�C�Y��e�ƒu���B�ő�񕔃}�b�`���O����
// O(ST+(e+log_2 S)��(S+T))�ŉ����B
// ����
// - e��O(ST)�̎���O(ST��(S+T))�A
// - e��O(S+T)�̎���O(ST)
// �ŉ����B
template <int S_max , int T_max>
class HopcroftKarp
{

private:
  static int g_S;
  static int g_T;
  static set<int> g_unchosen_source;
  static list<int> g_edge[S_max];
  static int g_prev[T_max];

public:
  HopcroftKarp() = delete;

  static list<pair<int,int> > Solve( const int& S , const int& T , const list<pair<int,int> >& edge );
  static list<int> Edge( const int& w );

};

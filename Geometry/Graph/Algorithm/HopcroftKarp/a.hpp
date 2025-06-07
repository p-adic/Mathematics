// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/HopcroftKarp/a.hpp

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
class HopcroftKarp
{

public:
  template <typename Edge> vector<pair<int,int>> GetMaximumMatching( const int& S , const int& T , Edge edge );

};

// �ӂ̏o���肪�������_������ꍇ�́A�������P�ɂ܂Ƃ߂čő嗬
// ../MaximumFlow/a.hpp
// �ŉ����B

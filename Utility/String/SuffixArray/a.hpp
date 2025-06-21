// c:/Users/user/Documents/Programming/Mathematics/Utility/String/SuffixArray/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1100475

// https://qiita.com/izu_nori/items/3f4a32342fffb755ce5b
// �����ƂɎ����B
// s�̒�����N�Ƃ��As[i,i+2^d)�̔�r�Ɛ����I�Ȕԍ��t����doubling�Ōv�Z���Ă������Ƃ�
// O(N(log N)^2)��suffix array�����߂�B
template <typename STR> vector<int> ManberMyers( const STR& s );

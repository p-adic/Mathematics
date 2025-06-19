// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/CompleteBipartiteMatching/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1099806 (__float128)

// S,T�̒��������ꂼ��N,M�ƒu���B
// O((N+M)log(N+M))�ŒP��f:[0,N)->[0,M)�S�̂�n��sum_{i=0}^{N-1} |T[f(i)]-S[i]|��
// �ŏ��l�����߂�B������f�����݂��Ȃ��ꍇ��-1��Ԃ��B
template <typename RET , typename INT> RET ShortestCompleteBipartiteMatching( const vector<INT>& S , const vector<INT>& T );
// IntervalAddBIT�œ������Ǘ����邽�߁A�������傫������ll�^���ƃI�[�o�[�t���[����\����
// ���邱�Ƃɒ��ӁB�����__float128�Ȃǂ�p����B

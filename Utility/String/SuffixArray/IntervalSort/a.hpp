// c:/Users/user/Documents/Programming/Mathematics/Utility/String/SuffixArray/IntervalSort/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1100475

// ���͈͓͂̔��ŗv��
// (1) operator<(const STR&,const STR&)���S�����ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// ����N�̗�S�ɑ΂��A0<=l<=r<N��n��(S[l,r],l)�S�̂ɂ�����
// ������������k�Ԗڂ̒l�ɑΉ�����l,r�̑g���v�Z����B

// �\�zO(N(log N)^2)
// �����_���A�N�Z�XO(N(log N)^2)
template <typename STR> 
class LexicographicIntervalSort
{

private:
  const STR* m_p_S;
  int m_N;
  vector<int> m_sa;
  vector<ll> m_cs;

public:
  inline LexicographicIntervalSort( const STR& S );

  inline pair<int,int> Get( ll k ) const;
  pair<int,int> operator[]( ll k ) const;

private:
  // sum_{i=l}^{r} (S[m_sa[i],N)�̒���shift+1�ȏ�̕�����̕�����̌�)
  // = sum_{i=l}^{r} ( N - m_sa[i] - shift )
  // ��O(1)�ŋ��߂�B
  inline ll CountIntervals( const int& l , const int r , const int& shift ) const;
  
};

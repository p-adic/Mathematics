// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Mo/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/954977�iGet�j
// https://atcoder.jp/contests/abc174/submissions/50552834�iSolve�j

// ���͈͓͂̔��ŗv��
// (1) F�͎ʑ�f:N^2 -> R�ɑ�������^�ł���B
// (2) DFx�͎ʑ�dfx:R \times N^3 -> R�ɑ�������^�ł���B
// (3) DFy�͎ʑ�dfy:R \times N^3 -> R�ɑ�������^�ł���B
// (4) �����Ȃ�(x,y,x') in N^3�ɑ΂��Ă�f(x',y) = dfx(f(x,y),x,y,x')�ł���B
// (5) �����Ȃ�(x,y,y') in N^3�ɑ΂��Ă�f(x,y') = dfy(f(x,y),x,y,y')�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B

// �돉����O(1)
// �I�t���C���N�G��������O(min(��X+Q,Q log Q))

// �S�N�G���񓚎擾O((��X+Q)sqrt(��Y))
// �i������dfx(r,x,y,x')��dfy(r,x,y,y')�̌v�Z�ʂ�O(|x-x'|+sqrt(��Y))��O(|y-y'|)�Ɖ��肷��j

class Mo
{

private:
  int m_Q;
  int m_Y_d;
  vector<vector<tuple<int,int,int>>> m_query;

public:
  inline Mo() = default;
  inline Mo( const vector<pair<int,int>>& query , int y_dif_sqrt = 0 );

  inline void Set( const vector<pair<int,int>>& query , int y_dif_sqrt = 0 );
  inline const vector<vector<tuple<int,int,int>>>& Get() const noexcept;

  // ���̃A���S���Y���Ŋe�N�G��(x,y)�ɑ΂���f(x,y)���v�Z�B
  template <typename F , typename DFx , typename DFy> vector<ret_t<F,int,int>> Solve( F& f , DFx& dfx , DFy& dfy ) const;

private:
  inline void IntroSort( const vector<pair<int,int>>& query , const int& y_start , const int& y_dif_sqrt );
  inline void BucketSort( const vector<pair<int,int>>& query , const int& x_start , const int& x_dif , const int& y_start , const int& y_dif_sqrt );
  template <typename R , typename DFx , typename DFy> void Solve_Body( vector<R>& answer , R& temp , int& x , int& y , DFx& dfx , DFy& dfy , , const int& d , const int& i_start ) const;
  
};

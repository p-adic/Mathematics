// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Mo/a.hpp

#pragma once
// verify:
// https://atcoder.jp/contests/abc174/submissions/67468053�iGet�j
// https://atcoder.jp/contests/abc174/submissions/50552834�iSolve�j

// ���͈͓͂̔��ŗv��
// (1) F�͎ʑ�f:N^2 -> R1�ɑ�������^�ł���B
// (2) DFx�͎ʑ�dfx:R1 \times N^3 -> R1�ɑ�������^�ł���B
// (3) DFy�͎ʑ�dfy:R1 \times N^3 -> R1�ɑ�������^�ł���B
// (4) �����Ȃ�(x,y,x') in N^3�ɑ΂��Ă�f(x',y) = dfx(f(x,y),x,y,x')�ł���B
// (5) �����Ȃ�(x,y,y') in N^3�ɑ΂��Ă�f(x,y') = dfy(f(x,y),x,y,y')�ł���B
// (6) G�͎ʑ�g:R1 \times N -> R2�ɑ�������^�ł���B
// �𖞂����ꍇ�ɂ̂݃T�|�[�g�B
// DFx,DFy�͎Q�ƕԂ��ɂ����int�^��2.5�{�قǒx���Ȃ�̂Ń��[�u�Z�}�e�B�N�X�ɂ���B

// �돉����O(1)
// �I�t���C���N�G��������O(min(��X+Q,Q log Q))

// �S�N�G���񓚎擾O((��X+Q)sqrt(��Y))
// �i������dfx(r,x,y,x')��dfy(r,x,y,y')�̌v�Z�ʂ�O(|x-x'|+sqrt(��Y))��O(|y-y'|)�Ɖ��肷��j

class Mo
{

private:
  int m_Q;
  // �o�P�b�g���iy�̓�����/y_dif_sqrt+1�j
  int m_Y_d;
  // �o�P�b�g�������\�[�g�ς݂̃N�G��{x,y,q}���i�[����B
  vector<vector<tuple<int,int,int>>> m_query;

public:
  inline Mo() = default;
  // y_dif_sqrt�ݒ莞�͂�����A��ݒ莞��y�̓������̕��������o�P�b�g�T�C�Y�ɂ���B
  template <typename QUERY> inline Mo( const QUERY& query , int y_dif_sqrt = 0 );

  // �N�G����ύX����B�i�ǉ��ł͂Ȃ��j
  template <typename QUERY> inline void Set( const QUERY& query , int y_dif_sqrt = 0 );
  // �o�P�b�g�������\�[�g�ς݂̃N�G����Ԃ��B
  inline const vector<vector<tuple<int,int,int>>>& Get() const noexcept;

  // ���̃A���S���Y���Ŋe�N�G��query[i] = (x,y)�ɑ΂���g(f(x,y),i)���v�Z�B
  template <typename F , typename DFxp , typename DFxm , typename DFyp , typename DFym , typename G> vector<decay_t<ret_t<G,ret_t<F,int,int>,int>>> Solve( F& f , DFxp& dfxp , DFxm& dfxm , DFyp& dfyop , DFym& dfym , G& g ) const;
  // ���̃A���S���Y���Ŋe�N�G��query[i] = (x,y)�ɑ΂���f(x,y)���v�Z�B
  template <typename F , typename DFxp , typename DFxm , typename DFyp , typename DFym> inline vector<ret_t<F,int,int>> Solve( F& f , DFxp& dfxp , DFxm& dfxm , DFyp& dfyp , DFym& dfym ) const;
  // �o�P�b�g�ύX���ɂ�f�łȂ�dfy���Ă΂�邱�Ƃɒ��ӁB
  // �o�P�b�g�ύX����f���Ăт����ꍇ��dfy�̒�`��y���������Ȃ�ۂ�f���ĂԂ悤�ɂ���Ηǂ��B

private:
  // std::sort�ł̃\�[�g���s���B
  template <typename QUERY> inline void IntroSort( const QUERY& query , const int& y_start , const int& y_dif_sqrt );
  template <typename QUERY> inline void BucketSort( const QUERY& query , const int& x_start , const int& x_dif , const int& y_start , const int& y_dif_sqrt );
  template <typename R , typename DFxp , typename DFxm , typename DFyp , typename DFym , typename G> void Solve_Body( vector<R>& answer , R& temp , int& x , int& y , DFxp& dfxp , DFxm& dfxm , DFyp& dfyp , DFym& dfym , const int& d , const int& i_start , G& g ) const;
  
};

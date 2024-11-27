// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/StirlingNumber/SecondKind/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/914264

template <typename T , int length>
class SecondStirlingNumberCalculator
{

private:
  // N���W���̔������󕔕��W��i�ɂ��핢�̌���m_val[N][i]�Ɋi�[����B
  T m_val[length][length];

public:
  // �i�R���p�C�����Ɂj�v�Z��O(length^2)�ō\�z����B
  constexpr inline SecondStirlingNumberCalculator();

  constexpr inline const T ( &operator[]( const int& i ) const )[length];

  // �ȉ�N<length�̏ꍇ�̂݃T�|�[�g�B�ii<length�łȂ��Ă��悢�j

  // N���W���̔������󕔕��W��i�ɂ��핢�̌���Ԃ��B�iO(1)�j
  constexpr inline T CountDisjointCover( const int& N , const int& i ) const;
  // N���W���̔������󕔕��W��i�̌���Ԃ��B�iO(1)�j
  constexpr inline T CountDisjointSubset( const int& N , const int& i ) const;

  // �ȉ�T��������M�ɑ΂���Mod<M>�ƕ\����ꍇ�̂݃T�|�[�g�B

  // N���W���̒���i�̔������󕔕��W����ɂ��핢�̌���Ԃ��B�iO(log min{N,i})�j
  inline T CountDisjointCoverSequence( const int& N , const int& i ) const;
  // N���W���̒���i�̔������󕔕��W����̌���Ԃ��B�iO(log min{N,i})�j
  inline T CountDisjointSubsetSequence( const int& N , const int& i ) const;

  // �ȉ�M��length�ȏ�̑f���ł���ꍇ�̂݃T�|�[�g�B

  // N���W���̗v�f��n�̕����W���̔������󕔕��W��i�ɂ��핢�̌���Ԃ��B�iO(log N)�j
  inline T CountDisjointCover( const int& N , const int& n , const int& i ) const;
  // N���W���̗v�f��n�̕����W���̒���i�̔������󕔕��W����ɂ��핢�̌���Ԃ��B�iO(log N)�j
  inline T CountDisjointCoverSequence( const int& N , const int& n , const int& i ) const;
  
};


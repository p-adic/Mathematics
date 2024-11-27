// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/MahlerTransform/a.hpp

#pragma once

// N_max > 0�̏ꍇ�̂݃T�|�[�g�B
template <int N_max>
class MahlerTransform
{
private:
  const int m_p;
  ll m_fact[N_max];
  ll m_fact_inv[N_max];
  ll m_inv[N_max];

public:
  // p��N_max�ȏ�̑f���ł���ꍇ�̂݃T�|�[�g�B
  // O(N_max)�őO�v�Z�l���i�[����B
  inline MahlerTransform( const int& p );

  // 0 <= i_start <= i_final < N_max�̏ꍇ�̂݃T�|�[�g�B
  // O((i_final-i_start)^2)��(f[i_start],...,f[i_final])�̃}�[���[�ϊ���@p�Ōv�Z��
  // (a[i_start],...,a[i_final])�Ɋi�[����B
  // �v�f���݂̂Ɉˑ�����������@p�ŉ������ƂɑΉ��B
  void Convert( const ll ( &f )[N_max] , ll ( &a )[N_max] , const int& i_start , const int& i_final );
  // O((i_final-i_start)^2)��(a[i_start],...,a[i_final])�̋t�}�[���[�ϊ���@p�Ōv�Z��
  // (f[i_start],...,f[i_final])�Ɋi�[����B
  // �v�f��0,1,...,n�̃f�[�^�Q����v�f��n�ȉ��̃f�[�^�𓾂邱�ƂɑΉ��B
  void InverseConvert( const ll ( &a )[N_max] , ll ( &f )[N_max] , const int& i_start , const int& i_final );

  // 0 <= n < N_max�ł���ꍇ�̂݃T�|�[�g�B
  // �O�v�Z���ꂽ�l��O(1)�ŎQ�Ƃ���B
  inline ll Combination( const int& n , const int& i ) const;
  inline const ll& Factorial( const int& n ) const;
  inline const ll& FactorialInverse( const int& n ) const;
  // 0 < n < N_max�ł���ꍇ�̂݃T�|�[�g�B
  inline const ll& Inverse( const int& n ) const;

};

// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Truncate/FPS/a.hpp

#pragma once

#include "../a.hpp"
// include�W�J��:
// Poynomial/a.hpp
// FormalPowerSeries/a.hpp
// FFT/a.hpp
// FFT/a_Body.hpp
// FormalPowerSeries/a_Body.hpp
// Poynomial/a_Body.hpp

// verify:
// https://judge.yosupo.jp/submission/276540 (�t��)
// https://yukicoder.me/submissions/938613 ���r�E�X�ϊ�
// https://yukicoder.me/submissions/937650 �{�X�^���X

template <typename T>
class FormalPowerSeries :
  public Polynomial<T>
{

private:
  // mod X^{m_N}�Ōv�Z����B
  // m_N > 0 �̎��̂݃T�|�[�g�B
  int m_N;
  
public:
  inline FormalPowerSeries( const int& N = 0 );
  inline FormalPowerSeries( const FormalPowerSeries<T>& f );
  inline FormalPowerSeries( FormalPowerSeries<T>&& f );
  inline FormalPowerSeries( const int& N , T t );
  // N��f�̃T�C�Y�̑召�����f���R�s�[���Ȃ��̂ŗ����̃R���X�g���N�^��p�ӂ���B
  inline FormalPowerSeries( const int& N , const Polynomial<T>& f );
  inline FormalPowerSeries( const int& N , Polynomial<T>&& f );
  inline FormalPowerSeries( const int& N , vector<T>&& f );
  inline FormalPowerSeries( const int& N , const int& i , T t );

  // m_N���������邱�Ƃɒ���
  inline FormalPowerSeries<T>& operator=( FormalPowerSeries<T> f );
  inline FormalPowerSeries<T>& operator=( T n );
  inline FormalPowerSeries<T>& operator=( Polynomial<T> f );

  // m_N�͕ω����Ȃ����Ƃɒ���
  inline FormalPowerSeries<T>& operator+=( const T& t );
  FormalPowerSeries<T>& operator+=( const Polynomial<T>& f );
  inline FormalPowerSeries<T>& operator+=( const FormalPowerSeries<T>& f );

  // m_N�͕ω����Ȃ����Ƃɒ���
  inline FormalPowerSeries<T>& operator-=( const T& t );
  FormalPowerSeries<T>& operator-=( const Polynomial<T>& f );
  inline FormalPowerSeries<T>& operator-=( const FormalPowerSeries<T>& f );

  inline FormalPowerSeries<T>& operator*=( const T& t );

  FormalPowerSeries<T>& operator*=( Polynomial<T> f );
  inline FormalPowerSeries<T>& operator*=( FormalPowerSeries<T> f );

  inline FormalPowerSeries<T>& operator/=( const T& t );
  // Polynomial�Ƃ��Ă̏��łȂ����Ƃɒ��ӁB
  inline FormalPowerSeries<T>& operator/=( const FormalPowerSeries<T>& t );

  template <typename P> inline FormalPowerSeries<T> operator+( const P& f ) const;
  inline FormalPowerSeries<T> operator-() const;
  template <typename P> inline FormalPowerSeries<T> operator-( const P& f ) const;
  template <typename P> inline FormalPowerSeries<T> operator*( const P& f ) const;
  template <typename P> inline FormalPowerSeries<T> operator/( const P& f ) const;

  // f[0]���t�ȏꍇ�̂݃T�|�[�g�B
  FormalPowerSeries<T> Inverse() const;
  
  inline void SetTruncation( const int& N ) noexcept;
  inline const int& GetTruncation() const noexcept;

  // N��������0�ɕύX�B
  inline FormalPowerSeries<T>& TruncateInitial( const int& N ) noexcept;
  // N���ȏ��0�ɕύX�B
  inline FormalPowerSeries<T>& TruncateFinal( const int& N ) noexcept;

};

#include "a_Alias.hpp"

// m_N��1�����邱�Ƃɒ��ӁB
template <typename T> FormalPowerSeries<T> Differential( const FormalPowerSeries<T>& f );
// m_N��n�����邱�Ƃɒ��ӁB
template <typename T> FormalPowerSeries<T> Differential( const int& n , const FormalPowerSeries<T>& f );

// m_N��n-shift�オ�邱�Ƃɒ��ӁB
// T���W��0�܂���f.m_N + n�ȏ�̑̂̏ꍇ�̂݃T�|�[�g�B
// n�K�ϕ���x^{shift}�Ŋ���������Ԃ��B
template <typename T> FormalPowerSeries<T> ShiftedIntegral( const int& n , const FormalPowerSeries<T>& f , const int& shift );
// m_N��1�オ�邱�Ƃɒ��ӁB
// T���W��0�܂���f.m_N + 1�ȏ�̑̂̏ꍇ�̂݃T�|�[�g�B
template <typename T> inline FormalPowerSeries<T> Integral( const FormalPowerSeries<T>& f );
// m_N��n�オ�邱�Ƃɒ��ӁB
// T���W��0�܂���f.m_N + n�ȏ�̑̂̏ꍇ�̂݃T�|�[�g�B
template <typename T> inline FormalPowerSeries<T> Integral( const int& n , const FormalPowerSeries<T>& f );

// T���W��0�܂���f.m_N�ȏ�̑̂ł���f[0] == 0�̏ꍇ�̂݃T�|�[�g�B
template <typename T>
FormalPowerSeries<T> Exp( const FormalPowerSeries<T>& f );

// T���W��0�܂���f.m_N�ȏ�̑̂ł���f[0] == 1�̏ꍇ�̂݃T�|�[�g�B
template <typename T> inline FormalPowerSeries<T> Log( const FormalPowerSeries<T>& f );

template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const FormalPowerSeries<T>& f );

// Power��Cumulative/a_Body.hpp�Œ�`�B

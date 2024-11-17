// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Truncate/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// ���ɂ悭�o�O��̂ŁA�X�V������K��verify���邱�ƁI
// verify:
// https://judge.yosupo.jp/submission/175535 ��ݍ���
// https://judge.yosupo.jp/submission/176529 ��]
// https://judge.yosupo.jp/submission/176829 ���s�ړ�
// https://yukicoder.me/submissions/938613 ���r�E�X�ϊ�
// https://yukicoder.me/submissions/937654 ���_�]��
// https://yukicoder.me/submissions/937650 �{�X�^���X

template <typename T> class TruncatedPolynomial;

template <typename T> TruncatedPolynomial<T> Differential( const uint& n , const TruncatedPolynomial<T>& f );
template <typename T> TruncatedPolynomial<T> TruncatedDifferential( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );
template <typename T> TruncatedPolynomial<T> TruncatedIntegral( const TruncatedPolynomial<T>& f , const uint& N_output_start );

template <typename T>
class TruncatedPolynomial :
  public Polynomial<T>
{

  friend TruncatedPolynomial<T> Differential<T>( const uint& n , const TruncatedPolynomial<T>& f );
  friend TruncatedPolynomial<T> TruncatedDifferential<T>( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );
  friend TruncatedPolynomial<T> TruncatedIntegral<T>( const TruncatedPolynomial<T>& f , const uint& N_output_start );
  
private:
  // mod X^{m_N}�Ōv�Z����B
  // m_N > 0 �̎��̂݃T�|�[�g�B
  uint m_N;
  
public:
  inline TruncatedPolynomial( const uint& N = 0 );
  inline TruncatedPolynomial( const TruncatedPolynomial<T>& f );
  inline TruncatedPolynomial( TruncatedPolynomial<T>&& f );
  inline TruncatedPolynomial( const uint& N , T t );
  // N��f�̃T�C�Y�̑召�����f���R�s�[���Ȃ��̂ŗ����̃R���X�g���N�^��p�ӂ���B
  inline TruncatedPolynomial( const uint& N , const Polynomial<T>& f );
  inline TruncatedPolynomial( const uint& N , Polynomial<T>&& f );
  inline TruncatedPolynomial( const uint& N , vector<T>&& f );
  inline TruncatedPolynomial( const uint& N , const uint& i , T t );

  // m_N���������邱�Ƃɒ���
  inline TruncatedPolynomial<T>& operator=( TruncatedPolynomial<T> f );
  inline TruncatedPolynomial<T>& operator=( T n );
  inline TruncatedPolynomial<T>& operator=( Polynomial<T> f );

  // m_N�͕ω����Ȃ����Ƃɒ���
  inline TruncatedPolynomial<T>& operator+=( const T& t );
  inline TruncatedPolynomial<T>& operator+=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator+=( const TruncatedPolynomial<T>& f );
  
  // N_input_lim <= f.size()�̏ꍇ�̂݃T�|�[�g�B
  // ���g��(N_input_start��0,f[N_input_start],...,f[N_input_lim-1],0,...)�𑫂����l mod X^{ m_N }�Œu��������B
  TruncatedPolynomial<T>& TruncatedPlus( const Polynomial<T>& f , const uint& N_input_start , const uint& N_input_limit );

  // m_N�͕ω����Ȃ����Ƃɒ���
  inline TruncatedPolynomial<T>& operator-=( const T& t );
  inline TruncatedPolynomial<T>& operator-=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator-=( const TruncatedPolynomial<T>& f );

  // N_input_lim <= f.size()�̏ꍇ�̂݃T�|�[�g�B
  // ���g��(N_input_start��0,f[N_input_start],...,f[N_input_lim-1],0,...)���������l mod X^{ m_N }�Œu��������B
  TruncatedPolynomial<T>& TruncatedMinus( const Polynomial<T>& f , const uint& N_input_start , const uint& N_input_limit );

  inline TruncatedPolynomial<T>& operator*=( const T& t );

  TruncatedPolynomial<T>& operator*=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator*=( Polynomial<T>&& f );

  // ���g��FFT�ɂ��f�{ mod X ^ { m_N }���v�Z�����l�Œu��������B
  TruncatedPolynomial<T>& FFT_Multiplication( const Polynomial<T>& f );

  // f != 0�̏ꍇ�̂݃T�|�[�g�B
  // ���g��f�{�����l��h�Ƃ��A����m_N�̔z��
  // (f[0],...,f[N_output_start-1],h[N_output_start],...,h[N_output_lim - 1],0,...)
  // �Ŏ��g��u��������B
  TruncatedPolynomial<T>& TruncatedMultiplication( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim );
    
  // f != 0�̏ꍇ�̂݃T�|�[�g�B
  // ���g��f�{��FFT�ɂ��v�Z�����l��h�Ƃ��A����m_N�̔z��
  // (f[0],...,f[N_output_start-1],h[N_output_start],...,h[N_output_lim - 1],0,...)
  // �Ŏ��g��u��������B
  TruncatedPolynomial<T>& FFT_TruncatedMultiplication( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim );
  TruncatedPolynomial<T>& FFT_TruncatedMultiplication( Polynomial<T>&& f , const uint& N_output_start , const uint& N_output_lim );

  // ���g��f�{�����l��h�Ƃ��A����m_N�̔z��
  // (N_output_start��0,h[N_output_start],...,h[N_output_lim - 1],0,...)
  // ��Ԃ��B
  TruncatedPolynomial<T> TruncatedMultiplication_const( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim ) const;

  // ���g��f�{��FFT�ɂ��v�Z�����l��h�Ƃ��A����m_N�̔z��
  // (N_output_start��0,h[N_output_start],...,h[N_output_lim - 1],0,...)
  // ��Ԃ��B
  TruncatedPolynomial<T> FFT_TruncatedMultiplication_const( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim ) const;
  TruncatedPolynomial<T> FFT_TruncatedMultiplication_const( Polynomial<T>&& f , const uint& N_output_start , const uint& N_output_lim ) const;

  inline TruncatedPolynomial<T>& operator/=( const T& t );
  // Polynomial�Ƃ��Ă̏��łȂ����Ƃɒ��ӁB
  inline TruncatedPolynomial<T>& operator/=( const TruncatedPolynomial<T>& t );
  inline TruncatedPolynomial<T>& operator%=( const T& t );

  template <typename P> inline TruncatedPolynomial<T> operator+( const P& f ) const;
  inline TruncatedPolynomial<T> operator-() const;
  template <typename P> inline TruncatedPolynomial<T> operator-( const P& f ) const;
  template <typename P> inline TruncatedPolynomial<T> operator*( const P& f ) const;
  template <typename P> inline TruncatedPolynomial<T> operator/( const P& f ) const;
  inline TruncatedPolynomial<T> operator%( const T& t ) const;
  
  inline void SetTruncation( const uint& N ) noexcept;
  inline const uint& GetTruncation() const noexcept;

  // N��������0�ɕύX�B
  inline TruncatedPolynomial<T>& TruncateInitial( const uint& N ) noexcept;
  // N���ȏ��0�ɕύX�B
  inline TruncatedPolynomial<T>& TruncateFinal( const uint& N ) noexcept;

};

template <typename T> inline constexpr const uint FFT_Multiplication_border_0 = 17;
template <typename T> inline constexpr const uint FFT_Multiplication_border_1;
template <typename T> inline constexpr const uint FFT_Multiplication_border_1_2;
template <typename T> inline constexpr const uint FFT_Multiplication_border_1_2_exponent;
template <typename T> inline constexpr const uint FFT_Multiplication_border_1_2_inv;

// m_N��1�����邱�Ƃɒ��ӁB
template <typename T> inline TruncatedPolynomial<T> Differential( const TruncatedPolynomial<T>& f );
// m_N��n�����邱�Ƃɒ��ӁB
template <typename T> inline TruncatedPolynomial<T> Differential( const uint& n , const TruncatedPolynomial<T>& f );
// m_N��1�����邱�Ƃɒ��ӁB
// N_output_start_plus_one > 0�̏ꍇ�̂݃T�|�[�g�B
template <typename T> TruncatedPolynomial<T> TruncatedDifferential( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one );

// m_N��1�オ�邱�Ƃɒ��ӁB
// T���W��0�܂���f.m_N + 1�ȏ�̑̂̏ꍇ�̂݃T�|�[�g�B
template <typename T> inline TruncatedPolynomial<T> Integral( const TruncatedPolynomial<T>& f );
// m_N��1�オ�邱�Ƃɒ��ӁB
// N_output_start > 0�̏ꍇ�̂݃T�|�[�g�B
template <typename T>
TruncatedPolynomial<T> TruncatedIntegral( const TruncatedPolynomial<T>& f , const uint& N_output_start );

// f[0]���t�ȏꍇ�̂݃T�|�[�g�B
template <typename T>
TruncatedPolynomial<T> Inverse( const TruncatedPolynomial<T>& f );

// T���W��0�܂���f.m_N�ȏ�̑̂ł���f[0] == 0�̏ꍇ�̂݃T�|�[�g�B
template <typename T>
TruncatedPolynomial<T> Exp( const TruncatedPolynomial<T>& f );

// T���W��0�܂���f.m_N�ȏ�̑̂ł���f[0] == 1�̏ꍇ�̂݃T�|�[�g�B
template <typename T> inline TruncatedPolynomial<T> Log( const TruncatedPolynomial<T>& f );

// Power��Cumulative/a_Body.hpp�Œ�`�B

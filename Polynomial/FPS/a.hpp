// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Truncate/FPS/a.hpp

#pragma once

#include "../a.hpp"
// include展開順:
// Poynomial/a.hpp
// FormalPowerSeries/a.hpp
// FFT/a.hpp
// FFT/a_Body.hpp
// FormalPowerSeries/a_Body.hpp
// Poynomial/a_Body.hpp

// verify:
// https://judge.yosupo.jp/submission/276540 (逆元)
// https://yukicoder.me/submissions/938613 メビウス変換
// https://yukicoder.me/submissions/937650 ボスタン森

template <typename T>
class FormalPowerSeries :
  public Polynomial<T>
{

private:
  // mod X^{m_N}で計算する。
  // m_N > 0 の時のみサポート。
  int m_N;
  
public:
  inline FormalPowerSeries( const int& N = 0 );
  inline FormalPowerSeries( const FormalPowerSeries<T>& f );
  inline FormalPowerSeries( FormalPowerSeries<T>&& f );
  inline FormalPowerSeries( const int& N , T t );
  // Nとfのサイズの大小次第でfをコピーしないので両方のコンストラクタを用意する。
  inline FormalPowerSeries( const int& N , const Polynomial<T>& f );
  inline FormalPowerSeries( const int& N , Polynomial<T>&& f );
  inline FormalPowerSeries( const int& N , vector<T>&& f );
  inline FormalPowerSeries( const int& N , const int& i , T t );

  // m_Nも代入されることに注意
  inline FormalPowerSeries<T>& operator=( FormalPowerSeries<T> f );
  inline FormalPowerSeries<T>& operator=( T n );
  inline FormalPowerSeries<T>& operator=( Polynomial<T> f );

  // m_Nは変化しないことに注意
  inline FormalPowerSeries<T>& operator+=( const T& t );
  FormalPowerSeries<T>& operator+=( const Polynomial<T>& f );
  inline FormalPowerSeries<T>& operator+=( const FormalPowerSeries<T>& f );

  // m_Nは変化しないことに注意
  inline FormalPowerSeries<T>& operator-=( const T& t );
  FormalPowerSeries<T>& operator-=( const Polynomial<T>& f );
  inline FormalPowerSeries<T>& operator-=( const FormalPowerSeries<T>& f );

  inline FormalPowerSeries<T>& operator*=( const T& t );

  FormalPowerSeries<T>& operator*=( Polynomial<T> f );
  inline FormalPowerSeries<T>& operator*=( FormalPowerSeries<T> f );

  inline FormalPowerSeries<T>& operator/=( const T& t );
  // Polynomialとしての商でないことに注意。
  inline FormalPowerSeries<T>& operator/=( const FormalPowerSeries<T>& t );

  template <typename P> inline FormalPowerSeries<T> operator+( const P& f ) const;
  inline FormalPowerSeries<T> operator-() const;
  template <typename P> inline FormalPowerSeries<T> operator-( const P& f ) const;
  template <typename P> inline FormalPowerSeries<T> operator*( const P& f ) const;
  template <typename P> inline FormalPowerSeries<T> operator/( const P& f ) const;

  // f[0]が可逆な場合のみサポート。
  FormalPowerSeries<T> Inverse() const;
  
  inline void SetTruncation( const int& N ) noexcept;
  inline const int& GetTruncation() const noexcept;

  // N次未満を0に変更。
  inline FormalPowerSeries<T>& TruncateInitial( const int& N ) noexcept;
  // N次以上を0に変更。
  inline FormalPowerSeries<T>& TruncateFinal( const int& N ) noexcept;

};

#include "a_Alias.hpp"

// m_Nが1下がることに注意。
template <typename T> FormalPowerSeries<T> Differential( const FormalPowerSeries<T>& f );
// m_Nがn下がることに注意。
template <typename T> FormalPowerSeries<T> Differential( const int& n , const FormalPowerSeries<T>& f );

// m_Nがn-shift上がることに注意。
// Tが標数0またはf.m_N + n以上の体の場合のみサポート。
// n階積分をx^{shift}で割った商を返す。
template <typename T> FormalPowerSeries<T> ShiftedIntegral( const int& n , const FormalPowerSeries<T>& f , const int& shift );
// m_Nが1上がることに注意。
// Tが標数0またはf.m_N + 1以上の体の場合のみサポート。
template <typename T> inline FormalPowerSeries<T> Integral( const FormalPowerSeries<T>& f );
// m_Nがn上がることに注意。
// Tが標数0またはf.m_N + n以上の体の場合のみサポート。
template <typename T> inline FormalPowerSeries<T> Integral( const int& n , const FormalPowerSeries<T>& f );

// Tが標数0またはf.m_N以上の体でかつf[0] == 0の場合のみサポート。
template <typename T>
FormalPowerSeries<T> Exp( const FormalPowerSeries<T>& f );

// Tが標数0またはf.m_N以上の体でかつf[0] == 1の場合のみサポート。
template <typename T> inline FormalPowerSeries<T> Log( const FormalPowerSeries<T>& f );

template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const FormalPowerSeries<T>& f );

// PowerはCumulative/a_Body.hppで定義。

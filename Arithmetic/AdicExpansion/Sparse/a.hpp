// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/AdicExpansion/Sparse/a.hpp

#pragma once

// Z_{(2)}の元をsum_d c_d M^dの形（abs(c_e)<M）で管理する。

// max(1,非自明な桁数)をD、max(1,最高桁)をEと置く。
// - 零初期化O(1)
// - 値取得O(D log E)
// - 1桁加算O(log D)
// - 大小比較O(D)

template <int M , typename INT = int>
class SparseAdicExpansion
{

private:
  // -M<c_d<Mを満たすc_dをd成分に格納し、c_d*M^dとして扱う。
  map<INT,INT> m_digit;

public:
  inline SparseAdicExpansion() = default;

  inline const map<INT,INT>& GetDigit() const noexcept;
  template <typename MODINT> MODINT GetValue() const;
  

  // c*M^dに相当する値を筆算で加算する。
  void Add( INT d , INT c );

  inline bool operator==( const SparseAdicExpansion<M,INT>& n ) const noexcept;
  inline bool operator!=( const SparseAdicExpansion<M,INT>& n ) const noexcept;
  inline bool operator<=( const SparseAdicExpansion<M,INT>& n ) const noexcept;
  inline bool operator<( const SparseAdicExpansion<M,INT>& n ) const noexcept;

private:
  // (-1,0,1) <-> (>,=,<)
  int comp( const SparseAdicExpansion<M,INT>& n ) const noexcept;
  
};

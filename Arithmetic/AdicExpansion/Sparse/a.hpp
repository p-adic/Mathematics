// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/AdicExpansion/Sparse/a.hpp

#pragma once

template <int M , typename INT = int>
class SparseAdicExpansion
{

private:
  // -M<c<M‚ğ–‚½‚·c‚ğd¬•ª‚ÉŠi”[‚µAc*M^d‚Æ‚µ‚Äˆµ‚¤B
  map<INT,INT> m_digit;

public:
  inline SparseAdicExpansion() = default;

  inline const map<INT,INT>& GetDigit() const noexcept;
  template <typename MODINT> MODINT GetValue() const;
  

  // c*M^d‚É‘Š“–‚·‚é’l‚ğ•MZ‚Å‰ÁZ‚·‚éB
  void Add( INT d , INT c );

  inline bool operator==( const SparseAdicExpansion<M,INT>& n ) const noexcept;
  inline bool operator!=( const SparseAdicExpansion<M,INT>& n ) const noexcept;
  inline bool operator<=( const SparseAdicExpansion<M,INT>& n ) const noexcept;
  inline bool operator<( const SparseAdicExpansion<M,INT>& n ) const noexcept;

private:
  // (-1,0,1) <-> (>,=,<)
  int comp( const SparseAdicExpansion<M,INT>& n ) const noexcept;
  
};

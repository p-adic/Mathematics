// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Polytope/ConvexHull/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1145855 (ExtremalPointSize)
// https://yukicoder.me/submissions/1145853 (ExtremalPointIndex,Index,Prev,Next)

template <typename INT>
class ConvexHull
{

private:
  int m_size;
  // 格納順の番号を、反時計回りに格納する。
  vector<int> m_ext;
  Map<int,int> m_ext_inv;
  vector<int> m_non_ext_end;
  vector<int> m_interior;

public:
  // 頂点、辺上の点群、内部を構築する。（O(m_size log m_size)）
  template <template <typename...> typename PAIR> ConvexHull( const vector<PAIR<INT,INT>>& xy );

  inline const int& TotalSize() const noexcept;
  inline int ExtremalPointSize() const noexcept;
  inline int NonExtremalEndPointSize() const noexcept;
  inline int EndPointSize() const noexcept;
  inline int InteriorPointSize() const noexcept;
  
  inline const vector<int>& ExtremalPointIndex() const noexcept;
  inline const vector<int>& NonExtremalEndPointIndex() const noexcept;
  inline const vector<int>& InteriorPointIndex() const noexcept;

  // m_extにおける位置を返す。（expected O(1)）
  inline int Index( const int& i ) const noexcept;
  // m_extにおける前者を返す。（expected O(1)）
  inline int Prev( const int& i ) const noexcept;
  // m_extにおける後者を返す。（expected O(1)）
  inline int Next( const int& i ) const noexcept;

};

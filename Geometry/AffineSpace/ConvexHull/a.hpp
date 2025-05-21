// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/ConvexHull/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1087023 (insert,ExtremalPointSize)

template <typename INT , template <typename...> typename PAIR>
class ConvexHull
{

private:
  int m_size;
  set<tuple<int,INT,INT,int>> m_ext_cyc;
  set<int> m_ext;
  vector<int> m_non_ext_end;
  vector<int> m_interior;

public:
  inline ConvexHull() = default;
  template <template <typename...> typename VEC> inline ConvexHull( const VEC<PAIR<INT,INT>>& xy );

  inline void insert( const Pair<INT,INT>& xy );
  void insert( const INT& x , const INT& y );

  inline const int& TotalSize() const noexcept;
  inline int ExtremalPointSize() const noexcept;
  inline int NonExtremalEndPointSize() const noexcept;
  inline int EndPointSize() const noexcept;
  inline int InteriorPointSize() const noexcept;
  
  inline const set<int>& ExtremalPoints() const noexcept;
  inline const vector<int>& NonExtremalEndPoints() const noexcept;
  inline const vector<int>& InteriorPoints() const noexcept;

};

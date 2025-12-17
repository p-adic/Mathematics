// c:/Users/user/Documents/Programming/Mathematics/Utility/Set/LinearSearch/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1140806 (insert,<<=,find)

// \’z O(2^digit)
// ‘S—v‘fíœ O(2^digit)
// ˆê—v‘f‘}“ü O(1)
// ‹A‘®”»’è •½‹ÏO(—v‘f”/2^digit)
// d•¡“xŒvŽZ •½‹ÏO(—v‘f”/2^digit)
template <int digit>
class LinearSearchMultiset
{

private:
  int m_amb;
  ull m_r;
  ull m_s;
  vector<vector<ull>> m_S;

public:
  inline LinearSearchMultiset() noexcept;
  inline LinearSearchMultiset( ull r , ull s ) noexcept;

  inline void clear() noexcept;
  inline void insert( ull n ) noexcept;
  inline LinearSearchMultiset<digit>& operator<<=( ull n ) noexcept;

  inline bool find( ull n ) const noexcept;
  inline int count( ull n ) const noexcept;
  
};

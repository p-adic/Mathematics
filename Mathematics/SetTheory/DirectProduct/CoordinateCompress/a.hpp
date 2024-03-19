// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a.hpp

#pragma once
#include "../../../Function/Map/a.hpp"

// verify:
// https://yukicoder.me/submissions/961857�imap�AGetOrder�j

template <typename T , template <typename...> typename MAP = Map>
class CoordinateCompress
{

private:
  vector<T> m_a;
  MAP<T,int> m_enum;
  bool m_compressed;
  int m_size;

public:
  inline CoordinateCompress();
  template <typename U> inline CoordinateCompress( const vector<U>& a );

  inline void insert( const T& t );
  template <typename U> inline void insert( const vector<U>& a );

  inline const T& operator[]( const int& i );
  inline const T& GetSmallest( const int& i = 0 );
  inline const T& GetLargest( const int& i = 0 );
  // MAP = map�̎��͑召���AMAP = unordered_map�̎��͊i�[��
  inline int GetOrder( const T& t );
  inline const int& size();

  inline typename MAP<T,int>::iterator begin();
  inline typename MAP<T,int>::iterator end();

private:
  inline void Compress();
  
};

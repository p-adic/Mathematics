// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/Heap/a.hpp

#pragma once

class HeapPrimeEnumeration
{

private:
  int m_val_limit;
  vector<bool> m_is_composite;
  vector<int> m_val;
  int m_length;

public:
  inline HeapPrimeEnumeration( const int& val_limit );

  // 1+n個目の素数を返す。
  inline const int& operator[]( const int& i ) const;
  inline const int& Get( const int& i ) const;

  // val_limit未満の素数までで割り切れる合成数であるか否かを判定する。
  inline bool IsComposite( const int& n ) const;

  // val_limit未満の素数の個数Pi(val_limit)を返す。
  inline const int& length() const noexcept;

};

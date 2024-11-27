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

  // 1+n�ڂ̑f����Ԃ��B
  inline const int& operator[]( const int& i ) const;
  inline const int& Get( const int& i ) const;

  // val_limit�����̑f���܂łŊ���؂�鍇�����ł��邩�ۂ��𔻒肷��B
  inline bool IsComposite( const int& n ) const;

  // val_limit�����̑f���̌�Pi(val_limit)��Ԃ��B
  inline const int& length() const noexcept;

};

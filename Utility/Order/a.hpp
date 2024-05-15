// c:/Users/user/Documents/Programming/Utility/Order/a.hpp

#pragma once
#include "a_Macro.hpp"

// �����𔽓]������B
// Reversed<int>�ł�+1���㑱�łȂ��Ȃ�̂Œʏ�̓񕪒T�����ł��Ȃ��Ȃ邱�Ƃɒ��ӁB
template <typename T>
class Reversed
{

private:
  // T = int�̏ꍇ���������߁A�p���ɂł��Ȃ��B
  T m_t;

public:
  inline Reversed( const Reversed<T>& t );
  inline Reversed( Reversed<T>& t );
  inline Reversed( Reversed<T>&& t );
  template <typename...Args> inline Reversed( Args&&... args );

  inline Reversed<T>& operator=( Reversed<T> t );
  
  DECLARATION_OF_REVERSED_RELATION( == );
  DECLARATION_OF_REVERSED_RELATION( != );
  DECLARATION_OF_REVERSED_RELATION( < );
  DECLARATION_OF_REVERSED_RELATION( > );
  DECLARATION_OF_REVERSED_RELATION( <= );
  DECLARATION_OF_REVERSED_RELATION( >= );

  DECLARATION_OF_REVERSED_ARITHMETIC( + , Reversed<T> );
  inline Reversed<T> operator-() const;
  DECLARATION_OF_REVERSED_ARITHMETIC( - , Reversed<T> );
  DECLARATION_OF_REVERSED_ARITHMETIC( * , Reversed<T> );
  DECLARATION_OF_REVERSED_ARITHMETIC( / , Reversed<T> );
  DECLARATION_OF_REVERSED_ARITHMETIC( % , Reversed<T> );
  DECLARATION_OF_REVERSED_ARITHMETIC( << , int );
  DECLARATION_OF_REVERSED_ARITHMETIC( >> , int );
  
  inline T& Ref() noexcept;
  inline const T& Get() const noexcept;
  inline T&& move() noexcept;
  
};

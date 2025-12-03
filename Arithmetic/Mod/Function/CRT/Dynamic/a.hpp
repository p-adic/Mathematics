// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/CRT/Dynamic/a.hpp

#pragma once

// 構築O(1)
// 合同式末尾追加O(size+log 底)
// 合同式末尾削除O(1)
// 求解O(size)
class DynamicGarner
{

private:
  vector<int> m_base;
  vector<int> m_coef;
  int m_len;

public:
  inline void push_back( int base , int res );
  inline void pop_back();
  // 非負整数解が存在するならばそれを法modで返し、存在しないならば-1を返す。
  inline int Get( const int& mod ) const;

private:
  inline pair<int,int> Solve( const int& mod ) const;
  
};

// c:/Users/user/Documents/Programming/Utility/Set/IntervalScheduling/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/931520

// ��Ԓǉ�O(log m_size)
// ��ԍ폜O(log m_size)
// �擪��Ԏ擾O(1)
// �㑱��Ԏ擾O(log m_size)
// �S�㑱��Ԏ擾O(m_size)
// �ő��r���I��ԗ�擾O(m_size)
template <typename T>
class IntervalScheduling
{
  
private:
  int m_count;
  vector<T> m_l;
  vector<T> m_r;
  vector<bool> m_valid;
  set<tuple<T,T,int>> m_rli;
  int m_size;
  T m_l_max;

public:
  inline void insert( const T& l , const T& r );
  inline void erase( const tuple<T,T,int>& v );

  inline const int& count() const noexcept;
  inline const T& GetL( const int& i ) const;
  inline const T& GetR( const int& i ) const;
  // const�Q�ƂłȂ����Ƃɒ���
  inline bool GetValid( const int& i ) const;
  inline const int& size() const noexcept;

  inline const int& Init() const;
  int Next( const int& i ) const;
  void SetNext( vector<int>& a ) const noexcept;
  void SetMaximal( list<int>& a , const int& i = -1 ) const;
  
};

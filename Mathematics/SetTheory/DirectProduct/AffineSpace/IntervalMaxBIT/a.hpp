// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/IntervalMaxBIT/a.hpp

#pragma once

template <typename T , int N>
class IntervalMaxBIT
{
private:
  T m_init;
  T m_fenwick_0[N + 1];
  T m_fenwick_1[N + 1];
  // �ŏ��l����������false�ɂ���
  bool m_for_max;

public:
  // ���̐���������悤��n�ŏ�����
  inline IntervalMaxBIT( const T& n , const bool& for_max = true );

  // �P�_�݂̂�max���Z�q����p������
  void SetMax( const int& i , const T& n );

  T IntervalMax( const int& i_start , const int& i_final );
  
};


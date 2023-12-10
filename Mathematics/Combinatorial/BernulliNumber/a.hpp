// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/BernulliNumber/a.hpp

#pragma once

// verify:https://judge.yosupo.jp/submission/176740

template <typename T , int length>
class BernulliNumberCalculator
{

private:
  // Bernulli��B_0=1, B_1=-1/2, B_2=1/6, ..., B_{length-1}���i�[����B
  // negative = false�̏ꍇ��B_1�̂�1/2�ɕύX����B
  T m_val[length];

public:
  // �v�Z��O(length log length)�ō\�z����B
  inline BernulliNumberCalculator( const bool& negative = true );
  inline const T& operator[]( const int& i ) const;

};

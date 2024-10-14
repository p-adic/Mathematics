// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Least/a.hpp

#pragma once

// val_limit = 1e4�F�R���p�C������18,371 [ms]
// val_limit = 1e5�F�R���p�C������30,000 [ms]�I�[�o�[�B
// val_limit = 1e6���ƃR���p�C�������[�v�񐔏��262144�I�[�o�[

template <int val_limit>
class LeastDivisor
{

private:
  int m_val[val_limit];

public:
  // O(val_limit log log val_limit)
  inline constexpr LeastDivisor() noexcept;

  inline const int& operator[]( const int& i ) const;
  inline constexpr const int& Get( const int& i ) const;
  inline constexpr int length() const noexcept;

};


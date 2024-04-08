// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/Constexpr/a.hpp

#pragma once

// val_limit = 1e4�F�R���p�C������18,371 [ms]
// val_limit = 1e5�F�R���p�C������30,000 [ms]�I�[�o�[�B
// val_limit = 1e6���ƃR���p�C�������[�v�񐔏��262144�I�[�o�[

template <typename INT , INT val_limit>
class LeastDivisor
{

private:
  INT m_val[val_limit];

public:
  // O(val_limit log log val_limit)
  inline constexpr LeastDivisor() noexcept;

  inline const INT& operator[]( const int& i ) const;
  inline constexpr const INT& Get( const int& i ) const;

};


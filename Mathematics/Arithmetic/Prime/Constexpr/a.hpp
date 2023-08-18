// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Constexpr/a.hpp

#pragma once

// m_length�̒l��
// val_limit = 316 -> 65
// val_limit = 10^3 -> 168
// val_limit = 10^4 -> 1229
// val_limit = 10^5 -> 9592
// val_limit = 2�~10^5 -> 17984
// �ȉ��R���p�C���^�v�Z�̏����262144�𒴉߁B��constexpr�ϐ�������������΂悢�B
// val_limit = 316228 -> 27293�i���s����4[ms]�j
// val_limit = 10^6 -> 78498�i���s����8[ms]�j
// val_limit = 10^7 -> 664579�i���s����93[ms]�j
// val_limit = 10^8 -> 5761455�i���s����2839[ms]�j
template <typename INT , INT val_limit , int length_max = val_limit>
class PrimeEnumeration
{

private:
  bool m_is_composite[val_limit];
  INT m_val[length_max];
  int m_length;

public:
  inline constexpr PrimeEnumeration();

  // 1+n�ڂ̑f����Ԃ��B
  inline constexpr const INT& Get( const int& n ) const;

  // length_max�ڂ̑f���܂łŊ���؂�鍇�����ł��邩�ۂ��𔻒肷��B
  inline constexpr const bool& IsComposite( const int& i ) const;

  // val_limit�����̑f���̌�Pi(val_limit)��Ԃ��B
  inline constexpr const int& length() const noexcept;

};

template <typename INT , INT val_limit , int length_max = val_limit>
class PrimeCounting
{

private:
  int m_val[val_limit];

public:
  inline constexpr PrimeCounting( const PrimeEnumeration<INT,val_limit,length_max>& pe );

  // min(i�ȉ��̑f���̌�,length_max)��Ԃ��B
  inline constexpr const int& Pi( const int& i ) const;

};

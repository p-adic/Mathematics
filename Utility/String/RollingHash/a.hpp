// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a.hpp

#pragma once

template <ll p , ll r , int length_max = 1000000>
class RollingHash
{
  
private:
  ll m_power[length_max + 1];
  ll m_p_inv;

public:
  inline constexpr RollingHash();

  tuple<ll,ll,int> Encode( const string& s ) const;
  inline tuple<ll,ll,int> Concatenate( const tuple<ll,ll,int>& code0 , const tuple<ll,ll,int>& code1 ) const;
  // s��code�ŃR�[�h����镶���񂪘A��������Ƃ��Ċ܂ތ��̐���l��Ԃ��B
  int CountContain( const string& s , const tuple<ll,ll,int>& code ) const;

};

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Residue/a.hpp

#pragma once
#include "../a_Alias.hpp"

template <typename INT1 , typename INT2> inline constexpr INT1 Residue( const INT1& n , const INT2& M ) noexcept;
// n���Q�Ƃœn�����̂�n���ω����邱�Ƃɒ��ӁB
template <typename INT1 , typename INT2> inline constexpr INT1& Residue( INT1& n , const INT2& M ) noexcept;
template <typename INT1 , typename INT2> inline constexpr INT1 Residue( INT1&& n , const INT2& M ) noexcept;

template <INT_TYPE_FOR_MOD M , typename INT> inline constexpr INT Residue( const INT& n ) noexcept;
template <INT_TYPE_FOR_MOD M , typename INT> inline constexpr INT& Residue( INT& n ) noexcept;
template <INT_TYPE_FOR_MOD M , typename INT> inline constexpr INT Residue( INT&& n ) noexcept;

// 0 <= n <= ( 998244353 - 1 ) ^ 2 �̏ꍇ�̂݃T�|�[�g
template <typename INT> inline constexpr INT& Residue998244353( INT& n ) noexcept;

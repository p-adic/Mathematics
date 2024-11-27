// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/Montgomery/a_Body.hpp

#pragma once
#include "Operator/a_Body.hpp"

// �ȉ����R���p�C������ƃN���X�e���v���[�g�̕������ꉻ�ƂȂ�̂ŁA
// �s���S�^�Ƃ��ăR���p�C���G���[�ƂȂ�B

// template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Montgomery<M>::Montgomery( const T& n ) noexcept : m_n( OperatorsForMontgomery<M>::Express( OperatorsForMontgomery<M>::Residue( n ) ) ) {}
// // n�̏���������h�����߂ɖ����I�ɃL���X�g
// template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Montgomery<M>::Montgomery( T&& n ) noexcept : m_n( OperatorsForMontgomery<M>::Express( OperatorsForMontgomery<M>::Residue( decay_t<T>( n ) ) ) ) {}
// template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Montgomery<M>::Montgomery( T&& n ) noexcept : m_n( OperatorsForMontgomery<M>::Express( OperatorsForMontgomery<M>::Residue( move<T>( n ) ) ) ) {}

// // �N���X�̕������ꉻ�ł��邽�ߒl�Ԃ��ɕύX�ł��Ȃ��B
// // �Ԃ�l�����Ӓl�Q�Ƃɒ��ړn������temp��m_n�̕ω��ɒ��ӂ���B
// template <> inline constexpr INT_TYPE_FOR_MOD Montgomery<MODULO>::Represent() const noexcept { return OperatorsForMontgomery<MODULO>::Reduce( m_n ); }
// template <> inline constexpr Montgomery<MODULO> Montgomery<MODULO>::Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept { Montgomery<MODULO> n_copy{}; n_copy.m_n = OperatorsForMontgomery<MODULO>::Express( n ); return n_copy; }

// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/a.hpp

#pragma once
#include "../../Syntax/Basic/a.hpp"

// �n�C�p�[���Z�q
inline const FunctionSymbol<int,int,int,int>& ArrowSymbol() noexcept;
inline ExpressionOfComputableFunction<int> Arrow( const ExpressionOfComputableFunction<int>& a , const ExpressionOfComputableFunction<int>& b , const ExpressionOfComputableFunction<int>& c ) noexcept;

// �`�F�[���\�L
inline const VariadicFunctionSymbol<int,int,int>& ChainSymbol() noexcept;
template <typename... Args> inline ExpressionOfComputableFunction<int> Chain( const ExpressionOfComputableFunction<int>& a , const Args&... args ) noexcept;

// N���n
inline const VariadicFunctionSymbol<string,int,string>& NPrimitiveSymbol_Body_1() noexcept;
inline const FunctionSymbol<int,string,int>& NPrimitiveSymbol_Body_2() noexcept;
template <typename... Args> inline ExpressionOfComputableFunction<int> N( const ExpressionOfComputableFunction<string>& version , const ExpressionOfComputableFunction<int>& a , const Args&... args ) noexcept;


// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a.hpp

#pragma once
#include "Line/Void/a.hpp"

template <typename Ret, typename... Args>
class DefinitionOfComputableFunction :
  public SyntaxOfComputableFunction
{

public:
  template <typename... Rets>
  using Dummy = typename enable_if<IsValidListOfLines<Ret,Rets...>::value,int>::type;

public:
  template <typename... Rets> inline DefinitionOfComputableFunction( const Rets&... lines );
  inline DefinitionOfComputableFunction( const int& dummy , const LineOfDefinitionOfComputableFunction<Ret>& line );
  template <typename... Rets> inline DefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const Rets&... lines );

  inline const string& Name() const;
  void WriteTo( const OperatorSymbol<Ret,Args...>& f , const string& language , const string& style , const string& filename , const ios_base::openmode& open_mode ) const noexcept;

};

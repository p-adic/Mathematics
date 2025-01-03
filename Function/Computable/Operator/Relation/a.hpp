// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Relation/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Separator/a.hpp"
#include "../Totality/a.hpp"
#include "../../Type/Guide/Base/a.hpp"
#include "../../Type/SubType/a.hpp"

// #include "../../Expression/Primitive/bool/a.hpp"
// #include "../../Expression/Variable/Variadic/a.hpp"

template <typename... Args>
class RelationSymbol :
  public SyntaxOfComputableFunction
{

public:
  TotalityOfComputableFunction m_totality;

public:
  inline RelationSymbol( const TotalityOfComputableFunction& totality , const string& r , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );
  RelationSymbol( const TotalityOfComputableFunction& totality , const string& r , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );
  template <typename... Ts> inline RelationSymbol( const string& r , const Ts&... ts );
  inline RelationSymbol( const RelationSymbol<Args...>& r );

  inline void Set( const string& dummy , const string& r );
  template <typename... VA> inline auto Set( const SeparatorOfComputableFunction& dummy1 , const int& dummy2 , const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type;
  inline void Set( const TotalityOfComputableFunction& dummy , const TotalityOfComputableFunction& totality ) noexcept;

  
  inline void SetSymbol( const string& r );
  inline void RomaniseSymbol();
  
  void SetSeparator( const SeparatorOfComputableFunction& s );

  inline const TotalityOfComputableFunction& GetTotality() const noexcept;
  inline void SetTotality( const TotalityOfComputableFunction& totality ) noexcept;

  inline ConditionOfComputableFunction operator()( const ExpressionOfComputableFunction<Args>&... args ) const;

};

#include "a_Alias.hpp"

template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Eq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Neq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Leq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Geq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Lneq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Gneq );

template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Eq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Neq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Leq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Geq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Lneq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Gneq );

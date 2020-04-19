// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../Utility/VLTree/a.hpp"
#include <fstream>

class SyntaxOfComputableFunction
{

private:
  VLTree<string> m_syntax;

public:
  template <typename... ARGS> SyntaxOfComputableFunction( const string& role , const ARGS&... args );
  
  inline const VLTree<string>& Get() const noexcept;
  inline VLTree<string>& Ref() noexcept;
  inline const string& GetRootString() const noexcept;
  inline const string& GetNodeString( const int& n ) const;

  void SetSymbol( const string& symbol );
  void RomaniseSymbol();

  inline string Display() const noexcept;

protected:
  // definition
  void InputDefinition( ofstream& ofs , const SyntaxOfComputableFunction& f , const string& language , const string& style ) const;
  void InputDeclaration( ofstream& ofs , const string& function_name , const string& argument_type_name , const string& argument_name , const string& return_type_name , const string& function_expression_name , const string& language , const string& style ) const;

  // line
  void InputLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const;
  void InputListLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const;
  void InputNonListLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const;
  void InputIndent( ofstream& ofs , const uint depth , const string& language , const string& style ) const noexcept;

  // If
  void InputIfLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const;
  void InputIfListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const;
  void InputIfNonListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const;

  // Put
  void InputPutLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const;
  void InputPutConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& language , const string& style ) const;
  void InputPutNonConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , const string& language , const string& style ) const;

// Print
  void InputPrintLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& language , const string& style ) const;

  //Exit
  void InputExitLine( ofstream& ofs , const string& function_expression_name , const string& language , const string& style ) const;

  // Return
  void InputReturnLine( ofstream& ofs ,const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const;

};

const string& SyntaxToString( VLTree<string>::const_iterator& itr , const int& n );
string ListSyntaxToString( VLTree<VLTree<string>::const_iterator>& t , const int& n );

// �\��args...����\���̕�����̃��X�g���\�z
template <typename... Args> auto ExpressionsToListSyntax( const Args&... args ) -> typename enable_if<conjunction<is_same<Args,VLTree<string> >...>::value,VLTree<string> >::type;

// �֐�f�ƈ����̖�args����\���̕�������\�z
string FunctionExpressionToString( const SyntaxOfComputableFunction& f , const VLTree<string>& args );

// �֐��̃C�e���[�^itr_f�Ǝ������̕�����̖؂̃C�e���[�^itr_args����\���̕�������\�z
string FunctionExpressionToString( VLTree<string>::const_iterator& itr_f , VLTree<string>::const_iterator& itr_args );

// �\���̃C�e���[�^itr����\���̕�������Q��
const string& ExpressionToString( VLTree<string>::const_iterator& itr );

// �����̃C�e���[�^itr��������̕�������\�z
string ConditionToString( VLTree<string>::const_iterator& itr , const string& language , const string& style );

string NegationToString( VLTree<string>::const_iterator& itr , const string& language , const string& style );
string ImplicationToString( VLTree<string>::const_iterator& itr , const string& language , const string& style );
string EquivalenceToString( VLTree<string>::const_iterator& itr , const string& language , const string& style );
string LogicalAndToString( VLTree<string>::const_iterator& itr , const string& language , const string& style );
string LogicalOrToString( VLTree<string>::const_iterator& itr , const string& language , const string& style );


inline string Plainise( const string& s ) noexcept;

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Empty );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Space );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Sub );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Sup );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lparen );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rparen );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lbrace );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Rbrace );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Comma );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Ldots );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Separator );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Nest );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( List );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Expression );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Variable );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Constant );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Function );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Relation );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Minus );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Slash );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Mod );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Power );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neg );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( To );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Equiv );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Plus );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Frown );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Times );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Land );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lor );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Eq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Leq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Geq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lneq );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Gneq );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Line );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( If );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Put );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Print );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Exit );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Return );

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Japanese );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( English );
DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Fandom );

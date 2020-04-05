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

  inline string Display() const noexcept;

protected:
  // definition
  void InputDefinition( ofstream& ofs ) const;

  // line
  void InputLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const;
  void InputListLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const;
  void InputNonListLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const;
  void InputIfLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const;
  void InputPutLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth ) const;
  void InputPrintLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line ) const;
  inline void InputExitLine( ofstream& ofs , const string& function_expression_name ) const noexcept;
  void InputReturnLine( ofstream& ofs ,const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const;
  void InputIndent( ofstream& ofs , const uint depth ) const noexcept;

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

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( List );

// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a_Body.hpp

#pragma once
#include "a.hpp"
#include "Line/Void/a_Body.hpp"

template <typename Ret, typename... Args> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const int& dummy , const FunctionSymbol<Ret,Args...>& f , const LineOfDefinitionOfComputableFunction<Ret>& line ) : SyntaxOfComputableFunction( "" , "definition" , f.Get() , line.Get() ) {}

template <typename Ret, typename... Args> template <typename... Rets> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const FunctionSymbol<Ret,Args...>& f , const Rets&... lines ) : DefinitionOfComputableFunction( dummy , f , LineOfDefinitionOfComputableFunction<Ret>( dummy , lines... ) ) {}

template <typename Ret, typename... Args> inline const string& DefinitionOfComputableFunction<Ret,Args...>::Name() const { return *( Get().LeftMostLeaf() ); }

template <typename Ret, typename... Args>
void DefinitionOfComputableFunction<Ret,Args...>::Display() const noexcept
{

  string filename = "a.txt";
  ofstream ofs( filename , ios::trunc );

  cout << "��`���̖؍\�����o�͂��܂��F" << endl;
  cout << Get().Display() << endl;
  cout << endl;
  cout << "��`���̓��{����" << filename << "�ɏ������݂܂��F" << endl;
  cout << "�c" << endl;
  
  if( !ofs ){
    cout << "�t�@�C�����J���܂���ł����B" << endl;
    cin.get();
    return;
  }

  cout << "�c�c" << endl;

  try{

    InputDefinition( ofs );

  }
  catch( const ErrorType& e ){

    IGNORED_ERR( e );

  }
  
  cout << "�c�c�c" << endl;
  cout << "�������݂��I�����܂����B" << endl;
  return;

}

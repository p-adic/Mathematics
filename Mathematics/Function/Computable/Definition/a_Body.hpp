// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a_Body.hpp

#pragma once
#include "a.hpp"
#include "Line/Void/a_Body.hpp"

template <typename Ret, typename... Args> template <typename... Rets> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const Rets&... lines ) : DefinitionOfComputableFunction( 0 , lines... ) {}

template <typename Ret, typename... Args> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const int& dummy , const LineOfDefinitionOfComputableFunction<Ret>& line ) : SyntaxOfComputableFunction( EmptyString() , DefinitionString() , line.Get() ) {}

template <typename Ret, typename... Args> template <typename... Rets> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const Rets&... lines ) : DefinitionOfComputableFunction( dummy , LineOfDefinitionOfComputableFunction<Ret>( dummy , lines... ) ) {}

template <typename Ret, typename... Args> inline const string& DefinitionOfComputableFunction<Ret,Args...>::Name() const { return *( Get().LeftMostLeaf() ); }

template <typename Ret, typename... Args>
void DefinitionOfComputableFunction<Ret,Args...>::WriteOn( const OperatorSymbol<Ret,Args...>& f , const string& language , const string& style , const string& filename , const ios_base::openmode& open_mode ) const noexcept
{

  ofstream ofs( filename , open_mode );
  const string* p_function_name = nullptr;
  auto itr_f = f.Get().LeftMostNode();

  try{

       p_function_name = &( SyntaxToString( itr_f , 2 ) );
       
  }
  catch( const ErrorType& e ){

    IGNORED_ERR( e );

  }
  
  if( language == JapaneseString() ){

    cout << " " << *p_function_name << " �����ʸ���ڹ�¤����Ϥ��ޤ���" << endl;
    cout << Get().Display() << endl;
    cout << endl;
    cout << " " << *p_function_name << " �����ʸ�����ܸ����� " << filename << " �˽񤭹��ߤޤ���" << endl;
    cout << "��" << endl;
  
    if( !ofs ){
      cout << "�ե����뤬�����ޤ���Ǥ�����" << endl;
      cin.get();
      return;
    }

    cout << "�ġ�" << endl;

    try{

      InputDefinition( ofs , f.GetTotality().Get() , *p_function_name , itr_f , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "�ġġ�" << endl;
    cout << "�񤭹��ߤ���λ���ޤ�����" << endl;
    return;

  }

  if( language == EnglishString() ){

    cout << "Display the tree structure of the definition of " << *p_function_name << ":" << endl;
    cout << Get().Display() << endl;
    cout << endl;
    cout << "Writing an English translation of the definition of " << *p_function_name << " on " << filename << ":" << endl;
    cout << "��" << endl;
  
    if( !ofs ){
      cout << "Error: Cannot open the file." << endl;
      cin.get();
      return;
    }

    cout << "�ġ�" << endl;

    try{

      InputDefinition( ofs , f.GetTotality().Get() , *p_function_name , itr_f , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "�ġġ�" << endl;
    cout << "Finished writing." << endl;
    return;

  }

  if( language == ChineseString() ){

    cout << "����" << *p_function_name << "Ū���Ū�����빽:" << endl;
    cout << Get().Display() << endl;
    cout << endl;
    
    cout << "��" << filename << "����" << *p_function_name << "Ū���Ū��ʸ���:" << endl;
    cout << "��" << endl;
  
    if( !ofs ){
      cout << "����̵ˡ�ǳ�ʸ�" << endl;
      cin.get();
      return;
    }

    cout << "�ġ�" << endl;

    try{

      InputDefinition( ofs , f.GetTotality().Get() , *p_function_name , itr_f , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "�ġġ�" << endl;
    cout << "��λ��" << endl;
    return;

  }

  if( language == FrenchString() ){

    cout << "Affichez l'arborescence de la d���finition de " << *p_function_name << ":" << endl;
    cout << Get().Display() << endl;
    cout << endl;
    cout << "���crire une traduction en anglais de la d���finition de " << *p_function_name << " sur " << filename << ":" << endl;
    cout << "��" << endl;
  
    if( !ofs ){
      cout << "Erreur: impossible d'ouvrir le fichier." << endl;
      cin.get();
      return;
    }

    cout << "�ġ�" << endl;

    try{

      InputDefinition( ofs , f.GetTotality().Get() , *p_function_name , itr_f , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "�ġġ�" << endl;
    cout << "���criture termin���e." << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Definition , definition );

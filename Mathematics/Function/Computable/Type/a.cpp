// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

#include "../Syntax/a_Body.hpp"

void TypeOfComputableFunction::WriteOn( const TypeOfComputableFunction& dummy , const string& language , const string& style , const string& filename , const ios_base::openmode& open_mode ) const noexcept
{

  if( &dummy != this ){

    ERR_CODE;

  }
  
  ofstream ofs( filename , open_mode );

  if( language == JapaneseString() ){

    cout << " " << m_type_name << " �̒�`���̓��{����" << filename << "�ɏ������݂܂��F" << endl;
    cout << "�c" << endl;
  
    if( !ofs ){
      cout << "�t�@�C�����J���܂���ł����B" << endl;
      cin.get();
      return;
    }

    cout << "�c�c" << endl;

    try{

      InputDefinition( ofs , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "�c�c�c" << endl;
    cout << "�������݂��I�����܂����B" << endl;
    return;

  }

  if( language == EnglishString() ){

    cout << "Writing an English translation of the definition to " << filename << ":" << endl;
    cout << "�c" << endl;
  
    if( !ofs ){
      cout << "Error: Cannot open the file." << endl;
      cin.get();
      return;
    }

    cout << "�c�c" << endl;

    try{

      InputDefinition( ofs , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "�c�c�c" << endl;
    cout << "Finished writing." << endl;

    return;

  }

  return;

}

void TypeOfComputableFunction::InputDefinition( ofstream& ofs , const string& language , const string& style ) const noexcept
{

  if( language == JapaneseString() && style == FandomString() ){

    ofs << "�ċA�I�W��\\(" << m_type_name << "\\)��\\(" << m_definition << "\\)�ƒ�߂�B" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "I define a recursive set \\(" << m_type_name << "\\) as \\(" << m_definition << "\\)." << endl;
    return;

  }

  ERR_IMPUT( style );
  return;

}

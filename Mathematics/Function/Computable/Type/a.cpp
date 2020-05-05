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

    cout << "Writing an English translation of the definition of \\(" << m_type_name << "\\) on " << filename << ":" << endl;
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

  if( language == ChineseString() ){

    cout << "��" << filename << "�㛍" << m_type_name << "�I��`�I�����|�:" << endl;
    cout << "�c" << endl;
  
    if( !ofs ){
      cout << "����F���@�ŊJ�����B" << endl;
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
    cout << "�������B" << endl;

    return;

  }

  if( language == FrenchString() ){

    cout << "\\'Ecrire une traduction en anglais de la d\\'efinition de \\(" << m_type_name << "\\) sur " << filename << ":" << endl;
    cout << "�c" << endl;
  
    if( !ofs ){
      cout << "Erreur: impossible d'ouvrir le fichier." << endl;
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
    cout << "\\'Ecriture termin\\'ee." << endl;

    return;

  }

  ERR_IMPUT( language );
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

  if( language == ChineseString() && style == FandomString() ){

    ofs << "�䛒稟d�W��\\(" << m_type_name << "\\)��`��\\(" << m_definition << "\\)�B" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << "Je d\\'efinis un ensemble r\\'ecursif \\(" << m_type_name << "\\) comme \\(" << m_definition << "\\)." << endl;
    return;

  }

  ERR_IMPUT( language , style );
  return;

}

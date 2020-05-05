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

    cout << " " << m_type_name << " �����ʸ�����ܸ�����" << filename << "�˽񤭹��ߤޤ���" << endl;
    cout << "��" << endl;
  
    if( !ofs ){
      cout << "�ե����뤬�����ޤ���Ǥ�����" << endl;
      cin.get();
      return;
    }

    cout << "�ġ�" << endl;

    try{

      InputDefinition( ofs , language , style );

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

    cout << "Writing an English translation of the definition of \\(" << m_type_name << "\\) on " << filename << ":" << endl;
    cout << "��" << endl;
  
    if( !ofs ){
      cout << "Error: Cannot open the file." << endl;
      cin.get();
      return;
    }

    cout << "�ġ�" << endl;

    try{

      InputDefinition( ofs , language , style );

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

    cout << "��" << filename << "����" << m_type_name << "Ū���Ū��ʸ���:" << endl;
    cout << "��" << endl;
  
    if( !ofs ){
      cout << "����̵ˡ�ǳ�ʸ�" << endl;
      cin.get();
      return;
    }

    cout << "�ġ�" << endl;

    try{

      InputDefinition( ofs , language , style );

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

    cout << "���crire une traduction en anglais de la d���finition de \\(" << m_type_name << "\\) sur " << filename << ":" << endl;
    cout << "��" << endl;
  
    if( !ofs ){
      cout << "Erreur: impossible d'ouvrir le fichier." << endl;
      cin.get();
      return;
    }

    cout << "�ġ�" << endl;

    try{

      InputDefinition( ofs , language , style );

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

void TypeOfComputableFunction::InputDefinition( ofstream& ofs , const string& language , const string& style ) const noexcept
{

  if( language == JapaneseString() && style == FandomString() ){

    ofs << "�Ƶ�Ū����\\(" << m_type_name << "\\)��\\(" << m_definition << "\\)�����롣" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "I define a recursive set \\(" << m_type_name << "\\) as \\(" << m_definition << "\\)." << endl;
    return;

  }

  if( language == ChineseString() && style == FandomString() ){

    ofs << "������Ž���\\(" << m_type_name << "\\)�����\\(" << m_definition << "\\)��" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << "Je d���finis un ensemble r���cursif \\(" << m_type_name << "\\) comme \\(" << m_definition << "\\)." << endl;
    return;

  }

  ERR_IMPUT( language , style );
  return;

}

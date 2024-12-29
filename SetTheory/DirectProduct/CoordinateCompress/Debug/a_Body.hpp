// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompress<INT>::CoordinateCompress() : m_r() , m_l()
{

  static bool init = true;

  if( init ){

    DERR( "CoordinateCompress���f�o�b�O���[�h�Ŏ��s���܂��B" );
    DERR( "�G���[�o�͈ȊO�͕ς��܂���B" );
    init = false;

  }

}

template <typename INT> inline void CoordinateCompress<INT>::SetR( INT t )
{

  DERR( "CoordinateCompress::SetR()�ŉE�Ӓl" , t , "��o�^���܂����B" );
  m_r.insert( move( t ) );
  DERR( "�o�^���ꂽ�E�Ӓl�S�̂̏W����" , m_r , "�ł��B" );
  DERR( "" );
  return;

}

template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetR( V<U> a ) { for( auto& t : a ){ SetR( move( t ) ); } }

template <typename INT>
tuple<vector<INT>,unordered_map<INT,int>,int> CoordinateCompress<INT>::GetR()
{

  tuple<vector<INT>,unordered_map<INT,int>,int> answer{};
  auto& [value,value_inv,value_max] = answer;
  value.resize( m_r.size() );

  DERR( "CoordinateCompress::GetR()�ŁA�o�^���ꂽ�E�Ӓl�����W���k���܂��B" );
  DERR( "�E�Ӓl�����������ɂ��ꂼ��ȉ��̂悤�ɕϊ����܂��F" );

  for( auto t : m_r ){

    DERR( t , "->" , value_max );
    value[value_inv[t] = value_max++] = t;

  }

  DERR( "���W���k���I�����܂��B" );
  DERR( "" );
  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearR() { m_r.clear(); }

template <typename INT> inline void CoordinateCompress<INT>::SetL( INT& t )
{

  DERR( "CoordinateCompress::SetL()�ō��Ӓl" , t , "��o�^���܂����B" );
  m_l.push_back( &t );
  const int size = m_l.size();
  DERR( "�o�^���ꂽ�o�^���ꂽ���Ӓl�͓o�^����" );

  for( int i = 0 ; i < size ; i++ ){

    DERRNS( i == 0 ? "[" : "," , *m_l[i] );

  }
  
  DERR( "]" );
  DERR( "�ł��B" );
  DERR( "" );
  return;

}

template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetL( V<U>& a ) { for( auto& t : a ){ SetL( t ); } }

template <typename INT>
pair<vector<INT>,int> CoordinateCompress<INT>::GetL()
{

  pair<vector<INT>,int> answer{ {} , -1 };
  auto& [value,value_max] = answer;
  DERR( "CoordinateCompress::GetL()�ŁA�o�^���ꂽ���Ӓl�����W���k���܂��B" );

  if( m_l.empty() ){

    DERR( "�o�^���ꂽ���Ӓl�͂���܂���ł����B" );

  } else {

    auto comp = []( INT* const& p0 , INT* const& p1 ) { return *p0 < *p1; };
    sort( m_l.begin() , m_l.end() , comp );
    INT temp = *( m_l[0] ) - 1;
    DERR( "���Ӓl�����������ɂ��ꂼ��ȉ��̂悤�ɕϊ����܂��F" );

    for( auto p : m_l ){

      DERRNS( *p , " -> " );
      *p = temp == *p ? value_max : ( value.push_back( temp = *p ) , ++value_max );
      DERR( value_max );

    }

  }

  DERR( "�ϊ��O�̍��Ӓl�S�̂̏W����" );
  DERR( value );
  DERR( "�ł��Bvector�̐��������k�����ꍇ�A�����o�^�ȍ~��push_back��resize��" );
  DERR( "�s���Ă��Ȃ����Ƃ��m�F���Ă��������B" );
  DERR( "���W���k���I�����܂��B" );
  DERR( "" );
  value_max++;
  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearL() { m_l.clear(); }


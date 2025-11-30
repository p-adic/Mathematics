// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/CoordinateCompress/LeftValue/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompressL<INT>::CoordinateCompressL() : m_l() , m_num()
{

  static bool init = true;
  static int num = 0;

  if( init ){

    DERR( "CoordinateCompressLをデバッグモードで実行します。" );
    DERR( "エラー出力以外は変わりません。" );
    init = false;

  }

  m_num = num++;

}

template <typename INT> inline void CoordinateCompressL<INT>::Set( INT& t )
{

  DERRNS( "CoordinateCompressL " , m_num , ": Set()で左辺値 " , t , " を登録しました。\n" );
  m_l.push_back( &t );
  const int size = m_l.size();
  DERR( "登録された登録された左辺値は登録順に" );

  for( int i = 0 ; i < size ; i++ ){

    DERRNS( i == 0 ? "[" : "," , *m_l[i] );

  }
  
  DERR( "]" );
  DERR( "です。" );
  DERR( "" );
  return;

}

template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompressL<INT>::Set( V<U>& a ) { for( auto& t : a ){ Set( t ); } }

template <typename INT>
pair<vector<INT>,int> CoordinateCompressL<INT>::Get()
{

  pair<vector<INT>,int> answer{ {} , -1 };
  auto& [value,value_max] = answer;
  DERRNS( "CoordinateCompressL " , m_num , ": Get()で、登録された左辺値を座標圧縮します。\n" );

  if( m_l.empty() ){

    DERR( "登録された左辺値はありませんでした。" );

  } else {

    auto comp = []( INT* const& p0 , INT* const& p1 ) { return *p0 < *p1; };
    sort( m_l.begin() , m_l.end() , comp );
    INT temp = *( m_l[0] ) - 1;
    DERR( "左辺値を小さい順にそれぞれ以下のように変換します：" );

    for( auto p : m_l ){

      DERRNS( *p , " -> " );
      *p = temp == *p ? value_max : ( value.push_back( temp = *p ) , ++value_max );
      DERR( value_max );

    }

  }

  DERR( "変換前の左辺値全体の集合は" );
  DERR( value );
  DERR( "です。vectorの成分を圧縮した場合、成分登録以降にpush_backやresizeを" );
  DERR( "行っていないことを確認してください。" );
  DERR( "座標圧縮を終了します。" );
  DERR( "" );
  value_max++;
  return answer;

}

template <typename INT> inline void CoordinateCompressL<INT>::clear()
{
  
  m_l.clear();
  DERRNS( "CoordinateCompressL " , m_num , ": clear()で、登録された左辺値を抹消します。\n" );
  DERR( "" );

}


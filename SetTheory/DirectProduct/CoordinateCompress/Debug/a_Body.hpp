// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompress<INT>::CoordinateCompress() : m_r() , m_l()
{

  static bool init = true;

  if( init ){

    DERR( "CoordinateCompressをデバッグモードで実行します。" );
    DERR( "エラー出力以外は変わりません。" );
    init = false;

  }

}

template <typename INT> inline void CoordinateCompress<INT>::SetR( INT t )
{

  DERR( "CoordinateCompress::SetR()で右辺値" , t , "を登録しました。" );
  m_r.insert( move( t ) );
  DERR( "登録された右辺値全体の集合は" , m_r , "です。" );
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

  DERR( "CoordinateCompress::GetR()で、登録された右辺値を座標圧縮します。" );
  DERR( "右辺値を小さい順にそれぞれ以下のように変換します：" );

  for( auto t : m_r ){

    DERR( t , "->" , value_max );
    value[value_inv[t] = value_max++] = t;

  }

  DERR( "座標圧縮を終了します。" );
  DERR( "" );
  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearR() { m_r.clear(); }

template <typename INT> inline void CoordinateCompress<INT>::SetL( INT& t )
{

  DERR( "CoordinateCompress::SetL()で左辺値" , t , "を登録しました。" );
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

template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetL( V<U>& a ) { for( auto& t : a ){ SetL( t ); } }

template <typename INT>
pair<vector<INT>,int> CoordinateCompress<INT>::GetL()
{

  pair<vector<INT>,int> answer{ {} , -1 };
  auto& [value,value_max] = answer;
  DERR( "CoordinateCompress::GetL()で、登録された左辺値を座標圧縮します。" );

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

template <typename INT> inline void CoordinateCompress<INT>::clearL() { m_l.clear(); }


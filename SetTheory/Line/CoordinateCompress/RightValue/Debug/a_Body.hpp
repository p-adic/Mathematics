// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/CoordinateCompress/RightValue/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompressR<INT>::CoordinateCompressR() : m_r()
{

  static bool init = true;

  if( init ){

    DERR( "CoordinateCompressRをデバッグモードで実行します。" );
    DERR( "エラー出力以外は変わりません。" );
    init = false;

  }

}

template <typename INT> inline void CoordinateCompressR<INT>::Set( INT t )
{

  DERR( "CoordinateCompressR::Set()で右辺値" , t , "を登録しました。" );
  m_r.insert( move( t ) );
  DERR( "登録された右辺値全体の集合は" , m_r , "です。" );
  DERR( "" );
  return;

}

template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompressR<INT>::Set( V<U> a ) { for( auto& t : a ){ Set( move( t ) ); } }

template <typename INT>
tuple<vector<INT>,unordered_map<INT,int>,int> CoordinateCompressR<INT>::Get()
{

  tuple<vector<INT>,unordered_map<INT,int>,int> answer{};
  auto& [value,value_inv,value_max] = answer;
  value.resize( m_r.size() );

  DERR( "CoordinateCompressR::Get()で、登録された右辺値を座標圧縮します。" );
  DERR( "右辺値をそれぞれ以下のように変換します：" );

  for( auto t : m_r ){

    DERR( t , "->" , value_max );
    value[value_inv[t] = value_max++] = t;

  }

  DERR( "座標圧縮を終了します。" );
  DERR( "" );
  return answer;

}

template <typename INT> inline void CoordinateCompressR<INT>::clear()
{

  m_r.clear();
  DERR( "CoordinateCompressR::clear()で、登録された右辺値を抹消します。" );
  DERR( "" );

}


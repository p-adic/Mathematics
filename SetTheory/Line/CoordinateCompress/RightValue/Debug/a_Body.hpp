// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/CoordinateCompress/RightValue/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , bool ordered> inline CoordinateCompressR<INT,ordered>::CoordinateCompressR() : m_r() , m_num()
{

  static bool init = true;
  static int num = 0;

  if( init ){

    DERR( "CoordinateCompressRをデバッグモードで実行します。" );
    DERR( "エラー出力以外は変わりません。" );
    DERR( "" );
    init = false;

  }

  m_num = num++;

}

template <typename INT , bool ordered> inline void CoordinateCompressR<INT,ordered>::Set( INT t )
{

  DERRNS( "CoordinateCompressR " , m_num , ": Set()で右辺値" , t , "を登録しました。\n" );
  m_r.insert( move( t ) );
  DERR( "登録された右辺値全体の集合は" , m_r , "です。" );
  DERR( "" );
  return;

}

template <typename INT , bool ordered> template <typename U , template <typename...> typename V > inline void CoordinateCompressR<INT,ordered>::Set( V<U> a ) { for( auto& t : a ){ Set( move( t ) ); } }

template <typename INT , bool ordered>
tuple<vector<INT>,conditional_t<ordered,map<INT,int>,unordered_map<INT,int>>,int> CoordinateCompressR<INT,ordered>::Get()
{

  tuple<vector<INT>,conditional_t<ordered,map<INT,int>,unordered_map<INT,int>>,int> answer{};
  auto& [value,value_inv,value_max] = answer;
  value.resize( m_r.size() );

  DERRNS( "CoordinateCompressR " , m_num , ": Get()で、登録された右辺値を座標圧縮します。\n" );
  DERRNS( "右辺値を" , ordered ? "小さい順に" : "順序を無視して" , "それぞれ以下のように変換します：" );

  for( auto t : m_r ){

    DERR( t , "->" , value_max );
    value[value_inv[t] = value_max++] = t;

  }

  DERR( "座標圧縮を終了します。" );
  DERR( "" );
  return answer;

}

template <typename INT , bool ordered> inline void CoordinateCompressR<INT,ordered>::clear()
{

  m_r.clear();
  DERRNS( "CoordinateCompressR " , m_num , ": clear()で、登録された右辺値を抹消します。\n" );
  DERR( "" );

}


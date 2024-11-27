// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompress<INT>::CoordinateCompress() : m_r() , m_l()
{

  static bool init = true;

  if( init ){

    cerr << "CoordinateCompress���f�o�b�O���[�h�Ŏ��s���܂��B" << endl;
    cerr << "�G���[�o�͈ȊO�͕ς��܂���B" << endl;
    init = false;

  }

}

template <typename INT> inline void CoordinateCompress<INT>::SetR( INT t ) { m_r.insert( move( t ) ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetR( V<U> a ) { for( auto& t : a ){ SetR( move( t ) ); } }

template <typename INT>
pair<vector<INT>,unordered_map<INT,int>> CoordinateCompress<INT>::GetR()
{

  pair<vector<INT>,unordered_map<INT,int>> answer{};
  answer.first.resize( m_r.size() );
  int i = 0;

  cerr << "CoordinateCompress::GetR()�ŁA�o�^���ꂽ�E�Ӓl�����W���k���܂��B" << endl;
  cerr << "�o�^���ꂽ�E�Ӓl�S�̂̏W���� { " << m_r << " } �ł��B" << endl;
  cerr << "���������ɂ��ꂼ��ȉ��̂悤�ɕϊ����܂��F" << endl;

  for( auto t : m_r ){

    cerr << t << " -> " << i << endl;
    answer.first[i] = t;
    answer.second[t] = i++;

  }

  cerr << "���W���k���I�����܂��B" << endl;
  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearR() { m_r.clear(); }

template <typename INT> inline void CoordinateCompress<INT>::SetL( INT& t ) { m_l.push_back( &t ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetL( V<U>& a ) { for( auto& t : a ){ SetL( t ); } }

template <typename INT>
vector<INT> CoordinateCompress<INT>::GetL()
{

  int i = -1;
  vector<INT> answer{};
  cerr << "CoordinateCompress::GetR()�ŁA�o�^���ꂽ���Ӓl�����W���k���܂��B" << endl;

  if( m_l.empty() ){

    cerr << "�o�^���ꂽ���Ӓl�͂���܂���ł����B";

  } else {

    cerr << "�o�^���ꂽ���Ӓl�͓o�^���� ( ";
    int size = m_l.size();
  
    for( int j = 0 ; j < size ; j++ ){

      ( j == 0 ? cerr : cerr << " " ) << *( m_l[j] );

    }
  
    cerr << " ) �ł��B" << endl;
    auto comp = []( INT* const& p0 , INT* const& p1 ) { return *p0 < *p1; };
    sort( m_l.begin() , m_l.end() , comp );
    INT temp = *( m_l[0] ) - 1;
    cerr << "���������ɂ��ꂼ��ȉ��̂悤�ɕϊ����܂��F" << endl;

    for( auto p : m_l ){

      cerr << *p << " -> ";
      *p = temp == *p ? i : ( answer.push_back( temp = *p ) , ++i );
      cerr << i << endl;		    

    }

  }

  cerr << "�ϊ��O�̍��Ӓl�S�̂̏W���� { " << answer << " } �ł��B" << endl;
  cerr << "���W���k���I�����܂��B" << endl;
  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearL() { m_l.clear(); }


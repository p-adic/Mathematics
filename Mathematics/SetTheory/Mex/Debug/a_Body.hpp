// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

inline MexSet::MexSet( const int& QuerySize ) : m_QuerySize( QuerySize ) , m_in( m_QuerySize + 1 ) , m_mex( 0 )
{

  ofs_err << "MexSet���f�o�b�O���[�h�Ŏ��s���܂��B" << endl;
  ofs_err << "�e�폈����O(m_QuerySize)�̌v�Z�ʂ������邱�Ƃɒ��ӂ��Ă��������B" << endl;

}

inline void MexSet::insert( const int& i )
{

  assert( i >= 0 );

  ofs_err << "MexSet�� " << i << " ��ǉ����܂��B" << endl;

  for( int j = 0 ; j < m_QuerySize ; j++ ){

    ofs_err << j << " : ";
    
    if( j == i ){

      ofs_err << m_in << " -> 1" << endl;

    } else {

      ofs_err << m_in << endl;

    }

  }

  ofs_err << "... : ..." << endl;

  if( i < m_QuerySize ){

    m_in[i] = true;

    while( m_in[m_mex] ){

      m_mex++;

    }

  }

}
inline const int& MexSet::mex() const noexcept
{

  ofs_err << "MexSet����mex���擾���܂��B" << endl;

  for( int j = 0 ; j < m_QuerySize ; j++ ){

    ofs_err << j << " : " << m_in;

    if( j == m_mex ){

      ofs_err << " <- mex";

    }
      
    ofs_err << endl;

  }

  ofs_err << "... : ..." << endl;
  return m_mex;

}


// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/FloydWarshall/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../../Algebra/Monoid/Semirng/MeetSemirng/a_Body.hpp"

template <typename U , typename IDEMPOTENT_SEMIRNG> inline AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::AbstractFloydWarshall( IDEMPOTENT_SEMIRNG R , vector<vector<U>> d ) : m_R( move( R ) ) , m_size() , m_weight() , m_prev() { static_assert( is_same_v<U,inner_t<IDEMPOTENT_SEMIRNG>> ); Initialise( move( d ) ); }
template <typename U> inline FloydWarshall<U>::FloydWarshall( U infty_U , vector<vector<U>> d ) : AbstractFloydWarshall<U,AdditiveTropicalSemirng<U>>( move( infty_U ) , move( d ) ) {}

template <typename U , typename IDEMPOTENT_SEMIRNG>
void AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::Initialise( vector<vector<U>> d )
{

  m_weight = move( d );
  m_size = m_weight.size();
  m_prev = vector( m_size , vector( m_size , -1 ) );
  auto& weight_infty = infty();

  for( int i = 0 ; i < m_size ; i++ ){

    assert( int( m_weight[i].size() ) == m_size );

    for( int j = 0 ; j < m_size ; j++ ){

      if( m_weight[i][j] != weight_infty ){

        assert( m_weight[i][j] == m_R.Meet( m_weight[i][j] , weight_infty ) );
        m_prev[i][j] = i;

      }

    }

  }
    
  // [0,k]���o�R�_�ɋ����ꍇ�̍ŒZ�o�H��k�ɂ��čċA�I�Ɍv�Z���Ă����B
  // �ʏ�̍s��ݏ�ƈ���Čo�R�_���Ƃɍl���邨�A��O(V^4)->O(V^3)�ƂȂ�B
  // �o�R�_�̌����w�肳��Ă���ꍇ�͍s��ݏ���g���B
  // m_R�͒P�ʓI�Ƃ͌���Ȃ����A�P�ʓI�łȂ��ꍇ��m_weigtht�̑Ίp������p���Ȃ��̂�
  // �Ίp�����̏ꍇ�����͕s�v�B
  for( int k = 0 ; k < m_size ; k++ ){

    for( int i = 0 ; i < m_size ; i++ ){

      for( int j = 0 ; j < m_size ; j++ ){

        // AbstractTropicalSemirng��Product�̒�`����Ainfty�͋C�ɂ��Ȃ��ėǂ��B
        U weight_curr = m_R.Meet( m_R.Product( m_weight[i][k] , m_weight[k][j] ) , m_weight[i][j] );

        if( m_weight[i][j] != weight_curr ){

          m_weight[i][j] = move( weight_curr );
          m_prev[i][j] = k;

        }

      }

    }

  }

  return;

}

template <typename U , typename IDEMPOTENT_SEMIRNG>
void AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::SetMeet( const int& start , const int& goal , U u )
{

  assert( start != goal );
  u = m_R.Meet( move( u ) , m_weight[start][goal] );
  
  if( u == m_weight[start][goal] ){

    return;

  }

  m_weight[start][goal] = move( u );
  m_prev[start][goal] = start;
  
  for( int i = 0 ; i < m_size ; i++ ){

    for( int j = 0 ; j < m_size ; j++ ){

      U weight_curr = m_R.Meet( i == start ? j == goal ? u : m_R.Product( u , m_weight[goal][j] ) : m_R.Product( m_weight[i][start] , j == goal ? u : m_R.Product( u , m_weight[goal][j] ) ) , m_weight[i][j] );

      if( m_weight[i][j] != weight_curr ){

        m_weight[i][j] = move( weight_curr );
        m_prev[i][j] = m_prev[goal==j?start:goal][j];

      }

    }

  }

  return;
  
}

template <typename U , typename IDEMPOTENT_SEMIRNG> inline const U& AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::Get( const int& start , const int& goal ) const { return m_weight[start][goal]; }

template <typename U , typename IDEMPOTENT_SEMIRNG> inline const int& AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::prev( const int& start , const int& goal ) const { assert( start != goal ); return m_prev[start][goal]; }

template <typename U , typename IDEMPOTENT_SEMIRNG> inline const U& AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::infty() const noexcept { return m_R.Infty(); }

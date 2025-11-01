// c:/Users/user/Documents/Programming/Mathematics/Utility/String/Expand/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../BinarySearch/a_Body.hpp"
#include "../../../Arithmetic/Iteration/a_Body.hpp"
#include "../../../Arithmetic/Iteration/Truncated/a_Body.hpp"

template <template <typename...> typename TUPLE>
string ExpandRandomAccess( const vector<string>& S , const string& source , const vector<int>& trans , vector<TUPLE<int,ll,ll>> query )
{

  ll K = 0;

  for( auto& [i,t,k] : query ){

    SetMax( K , k );

  }

  const int N = S.size() , M = source.size();
  vector count( N , vector( 1 , vector<int>( M + 1 ) ) );

  for( int i = 0 ; i < N ; i++ ){

    const int size = S[i].size();

    for( int p = 0 ; p < size ; p++ ){

      count[i].push_back( count[i][p] );
      bool found = false;

      for( int j = 0 ; !found && j < M ; j++ ){

        if( ( found |= S[i][p] == source[j] ) ){
          
          count[i][p+1][j]++;

        }

      }

      if( !found ){

        count[i][p+1][M]++;

      }

    }

  }
  
  vector A( 2 , vector( M + 1 , vector<ll>( M + 1 , 0 ) ) );

  for( int j = 0 ; j <= M ; j++ ){

    A[0][j][j] = 1;

    if( j < M ){

      for( auto& c : S[trans[j]] ){

        bool found = false;
      
        for( int q = 0 ; !found && q < M ; q++ ){

          if( c == source[q] ){
          
            A[1][q][j]++;
            found = true;

          }

        }

        if( !found ){

          A[1][M][j]++;

        }

      }

    } else {

      A[1][j][M] = 1;

    }

  }

  // over[j]‚ÉA‚Ìj—ñ–Ú‚Ì‘˜a‚ªK‚ð’´‚¦‚é‚©”Û‚©‚ðŠi”[B
  vector<bool> over( M ) , all( M , true );

  auto mult = [&]( const vector<vector<ll>>& B ){

    vector answer( M + 1 , vector<ll>( M + 1 ) );
    vector<ll> sum( M + 1 );

    for( int q = 0 ; q <= M ; q++ ){

      for( int j = 0 ; j <= M ; j++ ){
                 
        for( int r = 0 ; answer[q][j] <= K && r <= M ; r++ ){

          answer[q][j] = TruncatedSum( answer[q][j] , TruncatedProduct( A[1][q][r] , B[r][j] , K ) , K );

        }

        if( j < M ){
          
          over[j] = over[j] || ( sum[j] = TruncatedSum( sum[j] , answer[q][j] , K ) ) > K;

        }
        
      }

    }

    return answer;

  };
  
  while( over != all ){

    A.push_back( mult( A.back() ) );

  }
  
  const int T = len( A );
  ll temp = 0;

  auto eval = [&]( const int& i , const int& p , const ll& t , const ll& k ){

    assert( 0 <= i && i < N && -1 <= p && p < int( S[i].size() ) && 0 <= t && t < T );
    ll answer = 0;

    if( p >= 0 ){
      
      for( int q = 0 ; answer <= K && q <= M ; q++ ){

        const int r_max = q == M ? M : M - 1;
        
        for( int r = 0 ; answer <= K && r <= r_max ; r++ ){

          answer = TruncatedSum( answer , TruncatedProduct( A[t][q][r] , count[i][p+1][r] , K ) , K );

        }

      }

    }

    if( answer < k ){

      SetMax( temp , answer );

    }
    
    return answer;

  };
  
  string answer{};

  for( auto& [i,t,k] : query ){

    assert( 0 <= i && i < N && t >= 0 && k > 0 );
    SetMin( t , T - 1 );
    bool fix = false;

    for( int s = 0 ; !fix && s <= t ; s++ ){

      const int size = S[i].size();
      temp = 0;
      MAX_LEQ( p , -1 , size - 1 , eval( i , p , t - s , k ) , k - 1 );
      assert( -1 <= p && p < size - 1 );
      k -= temp;
      p++;
      fix = true;
      
      for( int j = 0 ; j < M ; j++ ){

        if( S[i][p] == source[j] ){

          if( k > 1 || i == trans[j] ){

            i = trans[j];
            fix = false;

          }

          break;
          
        }

      }

      if( fix ){

        assert( k == 1 );
        answer.push_back( S[i][p] );

      }

    }

    assert( fix );

  }

  return answer;

}

template <template <typename...> typename PAIR> inline string ExpandRandomAccess( const vector<string>& S , const string& source , const vector<int>& trans , const vector<PAIR<ll,ll>>& query ) { vector<Tuple<int,ll,ll>> query_copy{}; for( auto& [t,k] : query ){ query_copy.push_back( {0,t,k} ); } return ExpandRandomAccess( S , source , trans , move( query_copy ) );}

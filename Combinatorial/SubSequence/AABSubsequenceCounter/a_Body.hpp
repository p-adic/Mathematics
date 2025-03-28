// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/AABSubsequenceCounter/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Utility/String/Encode/a_Body.hpp"

template <int n , int AltB>
AABCount AABSubsequenceCounterOperator<n,AltB>::Product( AABCount v0 , const AABCount& v1 )
{

  static_assert( n > 1 );
  auto& [v0A,v0AB,v0AAB] = v0;
  
  if( v0A.empty() ){

    return v1;

  }

  auto& [v1A,v1AB,v1AAB] = v1;

  if( v1A.empty() ){

    return move( v1 );

  }

  if( v0A.size() == 1 ){

    const int i = v0A[0];
    v0A = vector<int>( n );
    v0A[i]++;
    v0AB = vector( n , vector<ll>( n ) );

  }

  if( v1A.size() == 1 ){

    auto& j = v1A[0];

    for( int i = 0 ; i < n ; i++ ){

      const ll v0Ai = v0A[i];
      auto& v0ABi = v0AB[i];
      int j_min = 0 , j_ulim = n;

      if constexpr( AltB == 1 ){
        
        // A<BÇâ€Ç∑èÍçá
        j_min = i + 1;

      } else if constexpr( AltB == -1 ){
        
        // A>BÇâ€Ç∑èÍçá
        j_ulim = i;

      }
      
      // AltB == 0ÇÃèÍçáÇÕv0ABi[i]ÇÃëçòaÇópÇ¢ÇƒçÇë¨âªâ¬î\
      if( j_min <= j && j < j_ulim && j != i ){

        v0AAB += v0ABi[i];
      
      }

      v0ABi[j] += v0Ai;

    }

    v0A[j]++;

  } else {

    v0AAB += v1AAB;
  
    for( int i = 0 ; i < n ; i++ ){

      const ll v0Ai = v0A[i];
      auto& v0ABi = v0AB[i];
      auto& v0ABii = v0ABi[i];
      auto& v1ABi = v1AB[i];
      int j_min = 0 , j_ulim = n;

      if constexpr( AltB == 1 ){
        
        // A<BÇâ€Ç∑èÍçá
        j_min = i + 1;

      } else if constexpr( AltB == -1 ){
        
        // A>BÇâ€Ç∑èÍçá
        j_ulim = i;

      }

      for( int j = j_min ; j < i ; j++ ){

        v0AAB += v0Ai * v1ABi[j] + v0ABii * v1A[j];
      
      }

      for( int j = i + 1 ; j < j_ulim ; j++ ){

        v0AAB += v0Ai * v1ABi[j] + v0ABii * v1A[j];
      
      }

      for( int j = 0 ; j < n ; j++ ){

        v0ABi[j] += v1ABi[j] + v0Ai * v1A[j];
      
      }

      v0A[i] += v1A[i];

    }

  }

  return move( v0 );

}

template <int n , int AltB> inline AABSubsequenceCounter<n,AltB>::AABSubsequenceCounter() : AbstractMonoid<AABCount,AABCount(*)(AABCount,const AABCount&)>( AABSubsequenceCounterOperator<n,AltB>::Product , AABCount{} ) {}

template <int n> inline AABCount ToAABCount( const int& c ) { return { { c } , {} , 0 }; }
template <int n> inline AABCount ToAABCount( const char& c ) { return ToAABCount<n>( CharToInt( c ) ); }

template <int n , int AltB , template <typename...> typename VEC , typename INT>
AABCount ToAABCount( const VEC<INT>& S )
{

  AABSubsequenceCounter<n,AltB> M{};
  AABCount answer{};

  for( auto& c : S ){
    
    answer = M.Product( move( answer ) , ToAABCount<n>( c ) );

  }
  
  return answer;

}

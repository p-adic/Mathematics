// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABSubsequenceCounter/a_Body.hpp

#pragma once
#include "a.hpp"

template <int n , int AltB>
ABCount ABSubsequenceCounterOperator<n,AltB>::Product( ABCount v0 , const ABCount& v1 )
{

  static_assert( n > 1 );
  auto& [v0A,v0AB] = v0;
  
  if( v0A.empty() ){

    return v1;

  }

  auto& [v1A,v1AB] = v1;

  if( v1A.empty() ){

    return move( v1 );

  }

  if( v0A.size() == 1 ){

    const int i = v0A[0];
    v0A = vector<int>( n );
    v0A[i]++;

  }

  if( v1A.size() == 1 ){

    auto& j = v1A[0];
    int i_min = 0 , i_ulim = n;

    if constexpr( AltB == 1 ){
        
      // A<BÇâ€Ç∑èÍçá
      i_ulim = j;

    } else if constexpr( AltB == -1 ){
        
      // A>BÇâ€Ç∑èÍçá
      i_min = j + 1;

    }

    for( int i = i_min ; i < j ; i++ ){

      v0AB += v0A[i];
        
    }

    for( int i = j + 1 ; i < i_ulim ; i++ ){

      v0AB += v0A[i];
        
    }

    v0A[j]++;

  } else {
  
    for( int i = 0 ; i < n ; i++ ){

      const ll v0Ai = v0A[i];
      int j_min = 0 , j_ulim = n;

      if constexpr( AltB == 1 ){
        
        // A<BÇâ€Ç∑èÍçá
        j_min = i + 1;

      } else if constexpr( AltB == -1 ){
        
        // A>BÇâ€Ç∑èÍçá
        j_ulim = i;

      }

      for( int j = j_min ; j < i ; j++ ){

        v0AB += v0Ai * v1A[j];
        
      }

      for( int j = i + 1 ; j < j_ulim ; j++ ){

        v0AB += v0Ai * v1A[j];
        
      }

      v0A[i] += v1A[i];

    }

  }

  return move( v0 );

}

template <int n , int AltB> inline ABSubsequenceCounter<n,AltB>::ABSubsequenceCounter() : AbstractMonoid<ABCount,ABCount(*)(ABCount,const ABCount&)>( ABSubsequenceCounterOperator<n,AltB>::Product , ABCount{} ) {}

template <int n> inline ABCount ToABCount( const int& c ) { return { { c } , 0 }; }
template <int n> inline ABCount ToABCount( const char& c ) { return ToABCount<n>( CharToInt( c ) ); }

template <int n , int AltB , template <typename...> typename VEC , typename INT>
ABCount ToABCount( const VEC<INT>& S )
{

  ABSubsequenceCounter<n,AltB> M{};
  ABCount answer{};

  for( auto& c : S ){
    
    answer = M.Product( move( answer ) , ToABCount<n>( c ) );

  }
  
  return answer;

}

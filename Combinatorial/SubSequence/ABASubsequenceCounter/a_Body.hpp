// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/ABASubsequenceCounter/a_Body.hpp

#pragma once
#include "a.hpp"

template <int n , int AltB>
ABACount ABASubsequenceCounterOperator<n,AltB>::Product( ABACount v0 , const ABACount& v1 )
{

  static_assert( n > 1 );
  auto& [v0A,v0AB,v0ABA] = v0;
  
  if( v0A.empty() ){

    return v1;

  }

  auto& [v1A,v1AB,v1ABA] = v1;

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

    auto& i = v1A[0];
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
      
    for( int j = j_min ; j < i ; j++ ){

      v0ABA += v0ABi[j];
      
    }

    for( int j = i + 1 ; j < j_ulim ; j++ ){

      v0ABA += v0ABi[j];
      
    }

    if constexpr( AltB == 1 ){
        
      // A<BÇâ€Ç∑èÍçá
      j_min = 0 , j_ulim = i;

    } else if constexpr( AltB == -1 ){
        
      // A>BÇâ€Ç∑èÍçá
      j_min = i + 1 , j_ulim = n;

    } else {

      j_min = 0 , j_ulim = n;

    }

    for( int j = j_min ; j < i ; j++ ){

      v0AB[j][i] += v0A[j];
      
    }

    for( int j = j_min ; j < i ; j++ ){

      v0AB[j][i] += v0A[j];
      
    }

    v0A[i]++;

  } else {

    v0ABA += v1ABA;
  
    for( int i = 0 ; i < n ; i++ ){

      const ll v0Ai = v0A[i];
      const ll v1Ai = v1A[i];
      auto& v0ABi = v0AB[i];
      int j_min = 0 , j_ulim = n;

      if constexpr( AltB == 1 ){
        
        // A<BÇâ€Ç∑èÍçá
        j_min = i + 1;

      } else if constexpr( AltB == -1 ){
        
        // A>BÇâ€Ç∑èÍçá
        j_ulim = i;

      }

      for( int j = j_min ; j < i ; j++ ){

        v0ABA += v0Ai * v1AB[j][i] + v0ABi[j] * v1Ai;
      
      }

      for( int j = i + 1 ; j < j_ulim ; j++ ){

        v0ABA += v0Ai * v1AB[j][i] + v0ABi[j] * v1Ai;
      
      }


      if constexpr( AltB == 1 ){
        
        // A<BÇâ€Ç∑èÍçá
        j_min = i + 1 , j_ulim = n;

      } else if constexpr( AltB == -1 ){
        
        // A>BÇâ€Ç∑èÍçá
        j_min = 0 , j_ulim = i;

      } else {

        j_min = 0 , j_ulim = n;

      }

      for( int j = j_min ; j < i ; j++ ){

        v0ABi[j] += v1ABi[j] + v0Ai * v1A[j];
      
      }

      for( int j = i + 1 ; j < j_ulim ; j++ ){

        v0ABi[j] += v1ABi[j] + v0Ai * v1A[j];
      
      }

      v0A[i] += v1Ai;

    }

  }

  return move( v0 );

}

template <int n , int AltB> inline ABASubsequenceCounter<n,AltB>::ABASubsequenceCounter() : AbstractMonoid<ABACount,ABACount(*)(ABACount,const ABACount&)>( ABASubsequenceCounterOperator<n,AltB>::Product , ABACount{} ) {}

template <int n> inline ABACount ToABACount( const int& c ) { return { { c } , {} , 0 }; }
template <int n> inline ABACount ToABACount( const char& c ) { return ToABACount<n>( CharToInt( c ) ); }

template <int n , int AltB , template <typename...> typename VEC , typename INT>
ABACount ToABACount( const VEC<INT>& S )
{

  ABASubsequenceCounter<n,AltB> M{};
  ABACount answer{};

  for( auto& c : S ){
    
    answer = M.Product( move( answer ) , ToABACount<n>( c ) );

  }
  
  return answer;

}

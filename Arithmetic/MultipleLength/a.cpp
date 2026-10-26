// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/MultipleLength/a.cpp

#pragma once

#include "../../Header.hpp"
#include "a_Body.hpp"

string Addition( const string& n , const string& m )
{

  constexpr const uint digit = 18;
  constexpr const ull power = 1000000000000000000;
  const uint size_n = n.size();
  const uint size_m = m.size();

  if( size_n < size_m ){

    return Addition( m , n );

  }
  
  list<string> memory = "";
  ull temp = 0;
  uint d = 0

  while( d < size_m ){

    temp += stoull( n.substr( size_n - d - digit , digit ) ) + stoull( m.substr( size_B - d - digit , digit ) );
    memory.push_front( to_string( temp % power ) );
    temp /= power;
    d += digit;

  }

  while( d < size_n ){

    temp += stoull( n.substr( size_n - d - digit , digit ) );
    memory.push_front( to_string( temp % power ) );
    temp /= power;
    d += digit;

  }

  if( temp != 0 ){

    memory.push_front( to_string( temp % power ) );

  }

  string answer = "";
  
  for( auto itr = memory.begin() , end = memory.end() ; itr != end ; itr++ ){

    answer += *itr;

  }

  if( answer == "" ){

    answer = "0";
    
  }

  return answer;

}

string& Increment_Body( string& n , const uint& i_llim )
{

  const uint size_n = n.size();

  for( uint i = size_n ; i > i_llim ; i-- ){

    if( n[i-1] == '9' ){

      n[i-1] = '0';

    } else {

      n[i-1] = n[i-1] + 1;
      return n;

    }
    
  }

  return n = n.substr( 0 , i_llim ) + "1" + n.substr( i_llim );
  
}

string& Decrement_Body( string& n , const uint& i_llim )
{

  if( n == "0" ){

    return n = "-1";

  }
  
  if( n == "1" || n == "-1" ){

    return n = "0";

  }
  
  const uint size_n = n.size();

  for( uint i = size_n ; i > 0 ; i-- ){

    if( n[i-1] == '0' ){

      n[i-1] = '9';

    } else {

      n[i-1] = n[i-1] - 1;
      break;

    }
    
  }

  if( n != "0" && n[i_llim] == '0' ){

    n = n.substr( 0 , i_llim ) + n.substr( i_llim + 1 );

  }

  return n;
  
}

string& Increment( string& n )
{

  return n[0] == '-' ? Decrement_Body( n , 1 ) : Increment_Body( n , 0 );

}

string& Decrement( string& n )
{

  return n[0] == '-' ? Increment_Body( n , 1 ) : Decrement_Body( n , 0 );

}

ull Residue( const string& n , const ull& m )
{

  assert( m > 0 );

  if( m == 1 ){

    return 0;

  }
  
  uint L = n.size();
  uint digit = 1;
  ull power = 10;

  while( m > power ){

    digit++;
    power *= 10;

  }
  
  uint i = digit - 1;
  ull temp = i > 0 ? stoull( n.substr( 0 , i ) ) : 0;

  while( i < L ){

    ( ( temp *= 10 ) += n[i++] - '0' ) %= m;

  }

  return temp;

}

pair<string,ull> Division( const string& n , const ull& m )
{

  assert( m > 0 );

  if( m == 1 ){

    return { n , 0 };

  }
  
  uint L = n.size();
  uint digit = 1;
  ull power = 10;

  while( m > power ){

    digit++;
    power *= 10;

  }
  
  uint i = digit - 1;
  ull temp = i > 0 ? stoull( n.substr( 0 , i ) ) : 0;
  string answer = "";
  static const string character = "0123456789";

  while( i < L ){

    answer += character[( ( temp *= 10 ) += n[i++] - '0' ) / m];
    temp %= m;

  }

  i = 0;
  L = answer.size();

  if( L == 0 ){

    return { "0" , move( temp ) };

  }
  
  while( i + 1 < L ? answer[i] == '0' : false ){

    i++;

  }

  return { i == 0 ? move( answer ) : answer.substr( i ) , move( temp ) };

}

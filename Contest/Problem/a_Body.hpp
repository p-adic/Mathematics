// c:/Users/user/Documents/Programming/Contest/Problem/a_Body.hpp

#pragma once
#include "a.hpp"

#include "ExecuteSolution/a_Body.hpp"
#include "GenerateSamples/a_Body.hpp"
#include "RearrangeSamples/a_Body.hpp"
#include "WriteInSamples/a_Body.hpp"


// ���o�͗p�֐�
template <class Traits> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicCin( basic_istream<char,Traits>& is , Arg& arg , ARGS&... args ) { return VariadicCin( is >> arg , args... ); }
template <class Traits> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator ) { return is; }
template <class Traits , typename Arg , typename... ARGS> inline basic_istream<char,Traits>& VariadicGetline( basic_istream<char,Traits>& is , const char& separator , Arg& arg , ARGS&... args ) { return VariadicGetline( getline( is , arg , separator ) , separator , args... ); }
template <class Traits , typename Arg> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg& arg ) { return os << arg; }
template <class Traits , typename Arg1 , typename Arg2 , typename... ARGS> inline basic_ostream<char,Traits>& VariadicCout( basic_ostream<char,Traits>& os , const Arg1& arg1 , const Arg2& arg2 , const ARGS&... args ) { return VariadicCout( os << arg1 << " " , arg2 , args... ); }

// �Z�p�p�֐�
template <typename T> inline T Residue( const T& a , const T& p ){ return a >= 0 ? a % p : p - 1 - ( ( - ( a + 1 ) ) % p ); }

#define POWER( ANSWER , ARGUMENT , EXPONENT )				\
  static_assert( ! is_same<TYPE_OF( ARGUMENT ),int>::value && ! is_same<TYPE_OF( ARGUMENT ),uint>::value ); \
  TYPE_OF( ARGUMENT ) ANSWER{ 1 };					\
  {									\
    TYPE_OF( ARGUMENT ) ARGUMENT_FOR_SQUARE_FOR_POWER = ( ARGUMENT );	\
    TYPE_OF( EXPONENT ) EXPONENT_FOR_SQUARE_FOR_POWER = ( EXPONENT );	\
    while( EXPONENT_FOR_SQUARE_FOR_POWER != 0 ){			\
      if( EXPONENT_FOR_SQUARE_FOR_POWER % 2 == 1 ){			\
	ANSWER *= ARGUMENT_FOR_SQUARE_FOR_POWER;			\
      }									\
      ARGUMENT_FOR_SQUARE_FOR_POWER *= ARGUMENT_FOR_SQUARE_FOR_POWER;	\
      EXPONENT_FOR_SQUARE_FOR_POWER /= 2;				\
    }									\
  }									\

#define POWER_MOD( ANSWER , ARGUMENT , EXPONENT , MODULO )		\
  ll ANSWER{ 1 };							\
  {									\
    ll ARGUMENT_FOR_SQUARE_FOR_POWER = ( ( MODULO ) + ( ( ARGUMENT ) % ( MODULO ) ) ) % ( MODULO ); \
    TYPE_OF( EXPONENT ) EXPONENT_FOR_SQUARE_FOR_POWER = ( EXPONENT );	\
    while( EXPONENT_FOR_SQUARE_FOR_POWER != 0 ){			\
      if( EXPONENT_FOR_SQUARE_FOR_POWER % 2 == 1 ){			\
	ANSWER = ( ANSWER * ARGUMENT_FOR_SQUARE_FOR_POWER ) % ( MODULO ); \
      }									\
      ARGUMENT_FOR_SQUARE_FOR_POWER = ( ARGUMENT_FOR_SQUARE_FOR_POWER * ARGUMENT_FOR_SQUARE_FOR_POWER ) % ( MODULO ); \
      EXPONENT_FOR_SQUARE_FOR_POWER /= 2;				\
    }									\
  }									\

#define FACTORIAL_MOD( ANSWER , ANSWER_INV , INVERSE , MAX_INDEX , CONSTEXPR_LENGTH , MODULO ) \
  static ll ANSWER[CONSTEXPR_LENGTH];					\
  static ll ANSWER_INV[CONSTEXPR_LENGTH];				\
  static ll INVERSE[CONSTEXPR_LENGTH];					\
  {									\
    ll VARIABLE_FOR_PRODUCT_FOR_FACTORIAL = 1;				\
    ANSWER[0] = VARIABLE_FOR_PRODUCT_FOR_FACTORIAL;			\
    FOREQ( i , 1 , MAX_INDEX ){						\
      ANSWER[i] = ( VARIABLE_FOR_PRODUCT_FOR_FACTORIAL *= i ) %= ( MODULO ); \
    }									\
    ANSWER_INV[0] = ANSWER_INV[1] = INVERSE[1] = VARIABLE_FOR_PRODUCT_FOR_FACTORIAL = 1; \
    FOREQ( i , 2 , MAX_INDEX ){						\
      ANSWER_INV[i] = ( VARIABLE_FOR_PRODUCT_FOR_FACTORIAL *= INVERSE[i] = ( MODULO ) - ( ( ( ( MODULO ) / i ) * INVERSE[ ( MODULO ) % i ] ) % ( MODULO ) ) ) %= ( MODULO ); \
    }									\
  }									\

// �񕪒T���e���v���[�g
// EXPRESSION��ANSWER�̍L�`�P���֐��̎��AEXPRESSION >= TARGET�̐��������i�[�B
#define BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , DESIRED_INEQUALITY , TARGET , INEQUALITY_FOR_CHECK , UPDATE_U , UPDATE_L , UPDATE_ANSWER ) \
  static_assert( ! is_same<TYPE_OF( TARGET ),uint>::value && ! is_same<TYPE_OF( TARGET ),ull>::value ); \
  ll ANSWER = MINIMUM;							\
  if( MINIMUM <= MAXIMUM ){						\
    ll VARIABLE_FOR_BINARY_SEARCH_L = MINIMUM;				\
    ll VARIABLE_FOR_BINARY_SEARCH_U = MAXIMUM;				\
    ANSWER = ( VARIABLE_FOR_BINARY_SEARCH_L + VARIABLE_FOR_BINARY_SEARCH_U ) / 2; \
    ll VARIABLE_FOR_DIFFERENCE_FOR_BINARY_SEARCH;			\
    while( VARIABLE_FOR_BINARY_SEARCH_L != VARIABLE_FOR_BINARY_SEARCH_U ){ \
      VARIABLE_FOR_DIFFERENCE_FOR_BINARY_SEARCH = ( EXPRESSION ) - ( TARGET ); \
      CERR( "�񕪒T�����F " << VARIABLE_FOR_BINARY_SEARCH_L << "<=" << ANSWER << "<=" << VARIABLE_FOR_BINARY_SEARCH_U << ":" << EXPRESSION << "-" << TARGET << "=" << VARIABLE_FOR_DIFFERENCE_FOR_BINARY_SEARCH ); \
      if( VARIABLE_FOR_DIFFERENCE_FOR_BINARY_SEARCH INEQUALITY_FOR_CHECK 0 ){	\
	VARIABLE_FOR_BINARY_SEARCH_U = UPDATE_U;			\
      } else {								\
	VARIABLE_FOR_BINARY_SEARCH_L = UPDATE_L;			\
      }									\
      ANSWER = UPDATE_ANSWER;						\
    }									\
    CERR( "�񕪒T���I���F " << VARIABLE_FOR_BINARY_SEARCH_L << "<=" << ANSWER << "<=" << VARIABLE_FOR_BINARY_SEARCH_U << ":" << EXPRESSION << ( EXPRESSION > TARGET ? ">" : EXPRESSION < TARGET ? "<" : "=" ) << TARGET ); \
    if( EXPRESSION DESIRED_INEQUALITY TARGET ){				\
      CERR( "�񕪒T������" );						\
    } else {								\
      CERR( "�񕪒T�����s" );						\
      ANSWER = MAXIMUM + 1;						\
    }									\
  } else {								\
    CERR( "�񕪒T�����s�F " << MINIMUM << ">" << MAXIMUM );		\
    ANSWER = MAXIMUM + 1;						\
  }									\

// �P�������̎���EXPRESSION >= TARGET�̍ŏ������i�[�B
#define BS1( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , TARGET )		\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , TARGET , >= , ANSWER , ANSWER + 1 , ( VARIABLE_FOR_BINARY_SEARCH_L + VARIABLE_FOR_BINARY_SEARCH_U ) / 2 ) \

// �P�������̎���EXPRESSION <= TARGET�̍ő�����i�[�B
#define BS2( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , TARGET )		\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , TARGET , > , ANSWER - 1 , ANSWER , ( VARIABLE_FOR_BINARY_SEARCH_L + 1 + VARIABLE_FOR_BINARY_SEARCH_U ) / 2 ) \

// �P�������̎���EXPRESSION >= TARGET�̍ő�����i�[�B
#define BS3( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , TARGET )		\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , TARGET , < , ANSWER - 1 , ANSWER , ( VARIABLE_FOR_BINARY_SEARCH_L + 1 + VARIABLE_FOR_BINARY_SEARCH_U ) / 2 ) \

// �P�������̎���EXPRESSION <= TARGET�̍ŏ������i�[�B
#define BS4( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , TARGET )		\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , TARGET , <= , ANSWER , ANSWER + 1 , ( VARIABLE_FOR_BINARY_SEARCH_L + VARIABLE_FOR_BINARY_SEARCH_U ) / 2 ) \

// t�ȉ��̒l�����݂���΂��̍ő�l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::iterator MaximumLeq( set<T>& S , const T& t ) { const auto end = S.end(); if( S.empty() ){ return end; } auto itr = S.upper_bound( t ); return itr == end ? S.find( *( S.rbegin() ) ) : itr == S.begin() ? end : --itr; }
// t�����̒l�����݂���΂��̍ő�l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::iterator MaximumLt( set<T>& S , const T& t ) { const auto end = S.end(); if( S.empty() ){ return end; } auto itr = S.lower_bound( t ); return itr == end ? S.find( *( S.rbegin() ) ) : itr == S.begin() ? end : --itr; }
// t�ȏ�̒l�����݂���΂��̍ŏ��l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::iterator MinimumGeq( set<T>& S , const T& t ) { return S.lower_bound( t ); }
// t���傫���l�����݂���΂��̍ŏ��l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::iterator MinimumGt( set<T>& S , const T& t ) { return S.upper_bound( t ); }

// �f�[�^�\���p�֐�
template <typename T> inline T Add( const T& t0 , const T& t1 ) { return t0 + t1; }
template <typename T> inline T XorAdd( const T& t0 , const T& t1 ){ return t0 ^ t1; }
template <typename T> inline T Multiply( const T& t0 , const T& t1 ) { return t0 * t1; }
template <typename T> inline const T& Zero() { static const T z = 0; return z; }
template <typename T> inline const T& One() { static const T o = 1; return o; }\
template <typename T> inline T AddInv( const T& t ) { return -t; }
template <typename T> inline T Id( const T& v ) { return v; }
template <typename T> inline T Min( const T& a , const T& b ){ return a < b ? a : b; }
template <typename T> inline T Max( const T& a , const T& b ){ return a < b ? b : a; }

// �O���b�h���p�֐�
int H , W , H_minus , W_minus , HW;
inline pair<int,int> EnumHW( const int& v ) { return { v / W , v % W }; }
inline int EnumHW_inv( const int& h , const int& w ) { return h * W + w; }
const string direction[4] = {"U","R","D","L"};
// (i,j)->(k,h)�̕����ԍ����擾
inline int DirectionNumberOnGrid( const int& i , const int& j , const int& k , const int& h ){return i<k?2:i>k?0:j<h?1:j>h?3:(assert(false),-1);}
// v->w�̕����ԍ����擾
inline int DirectionNumberOnGrid( const int& v , const int& w ){auto [i,j]=EnumHW(v);auto [k,h]=EnumHW(w);return DirectionNumberOnGrid(i,j,k,h);}
// �����ԍ��̔��]U<->D�AR<->L
inline int ReverseDirectionNumberOnGrid( const int& n ){assert(0<=n&&n<4);return(n+2)%4;}

// �f�o�b�O�p�֐�
#ifdef DEBUG
  inline void AlertAbort( int n ) { CERR( "abort�֐����Ă΂�܂����Bassert�}�N���̃��b�Z�[�W���o�͂���Ă��Ȃ��ꍇ�̓I�[�o�[�t���[�̗L�����m�F�����Ă��������B" ); }
  void AutoCheck( bool& auto_checked );
#endif

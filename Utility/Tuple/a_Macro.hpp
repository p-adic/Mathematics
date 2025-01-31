// c:/Users/user/Documents/Programming/Utility/Tuple/a_Macro.hpp

#pragma once
#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#define DECLARATION_OF_ARITHMETIC_FOR_TUPLE( OPR )			\
  template <typename T , typename U , template <typename...> typename PAIR> inline auto operator OPR ## =( PAIR<T,U>& t0 , const PAIR<T,U>& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )&; \
  template <typename T , typename U , typename V , template <typename...> typename TUPLE> inline auto operator OPR ## =( TUPLE<T,U,V>& t0 , const TUPLE<T,U,V>& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )&; \
  template <typename T , typename U , typename V , typename W , template <typename...> typename TUPLE> inline auto operator OPR ## =( TUPLE<T,U,V,W>& t0 , const TUPLE<T,U,V,W>& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )&; \
  template <typename ARG , typename T , typename U , template <typename...> typename PAIR> inline auto operator OPR ## =( PAIR<T,U>& t0 , const ARG& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )&; \
  template <typename ARG , typename T , typename U , typename V , template <typename...> typename TUPLE> inline auto operator OPR ## =( TUPLE<T,U,V>& t0 , const ARG& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )&; \
  template <typename ARG , typename T , typename U , typename V , typename W , template <typename...> typename TUPLE> inline auto operator OPR ## =( TUPLE<T,U,V,W>& t0 , const ARG& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )&; \
  template <template <typename...> typename TUPLE , typename...ARGS , typename ARG> inline auto operator OPR( const TUPLE<ARGS...>& t0 , const ARG& t1 ) -> decldecay_t( ( get<0>( t0 ) , t0 ) ) \

#define DEFINITION_OF_ARITHMETIC_FOR_TUPLE( OPR )			\
  template <typename T , typename U , template <typename...> typename PAIR> inline auto operator OPR ## =( PAIR<T,U>& t0 , const PAIR<T,U>& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )& { get<0>( t0 ) OPR ## = get<0>( t1 ); get<1>( t0 ) OPR ## = get<1>( t1 ); return t0; } \
  template <typename T , typename U , typename V , template <typename...> typename TUPLE> inline auto operator OPR ## =( TUPLE<T,U,V>& t0 , const TUPLE<T,U,V>& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )& { get<0>( t0 ) OPR ## = get<0>( t1 ); get<1>( t0 ) OPR ## = get<1>( t1 ); get<2>( t0 ) OPR ## = get<2>( t1 ); return t0; } \
    template <typename T , typename U , typename V , typename W , template <typename...> typename TUPLE> inline auto operator OPR ## =( TUPLE<T,U,V,W>& t0 , const TUPLE<T,U,V,W>& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )& { get<0>( t0 ) OPR ## = get<0>( t1 ); get<1>( t0 ) OPR ## = get<1>( t1 ); get<2>( t0 ) OPR ## = get<2>( t1 ); get<3>( t0 ) OPR ## = get<3>( t1 ); return t0; } \
  template <typename ARG , typename T , typename U , template <typename...> typename PAIR> inline auto operator OPR ## =( PAIR<T,U>& t0 , const ARG& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )& { get<0>( t0 ) OPR ## = t1; get<1>( t0 ) OPR ## = t1; return t0; } \
  template <typename ARG , typename T , typename U , typename V , template <typename...> typename TUPLE> inline auto operator OPR ## =( TUPLE<T,U,V>& t0 , const ARG& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )& { get<0>( t0 ) OPR ## = t1; get<1>( t0 ) OPR ## = t1; get<2>( t0 ) OPR ## = t1; return t0; } \
    template <typename ARG , typename T , typename U , typename V , typename W , template <typename...> typename TUPLE> inline auto operator OPR ## =( TUPLE<T,U,V,W>& t0 , const ARG& t1 ) -> decltype( ( get<0>( t0 ) , t0 ) )& { get<0>( t0 ) OPR ## = t1; get<1>( t0 ) OPR ## = t1; get<2>( t0 ) OPR ## = t1; get<3>( t0 ) OPR ## = t1; return t0; } \
  template <template <typename...> typename TUPLE , typename...ARGS , typename ARG> inline auto operator OPR( const TUPLE<ARGS...>& t0 , const ARG& t1 ) -> decldecay_t( ( get<0>( t0 ) , t0 ) ) { auto t = t0; return move( t OPR ## = t1 ); } \

#define DECLARATION_OF_INCREMENT_FOR_TUPLE( INCR )			\
  template <typename T , typename U , template <typename...> typename PAIR> inline auto operator INCR( PAIR<T,U>& t ) -> decltype( ( get<0>( t ) , t ) )&; \
  template <typename T , typename U , typename V , template <typename...> typename TUPLE> inline auto operator INCR ( TUPLE<T,U,V>& t ) -> decltype( ( get<0>( t ) , t ) )&; \
  template <typename T , typename U , typename V , typename W , template <typename...> typename TUPLE> inline auto operator INCR ( TUPLE<T,U,V,W>& t ) -> decltype( ( get<0>( t ) , t ) )&; \

#define DEFINITION_OF_INCREMENT_FOR_TUPLE( INCR )			\
  template <typename T , typename U , template <typename...> typename PAIR> inline auto operator INCR( PAIR<T,U>& t ) -> decltype( ( get<0>( t ) , t ) )& { INCR get<0>( t ); INCR get<1>( t ); return t; } \
  template <typename T , typename U , typename V , template <typename...> typename TUPLE> inline auto operator INCR ( TUPLE<T,U,V>& t ) -> decltype( ( get<0>( t ) , t ) )& { INCR get<0>( t ); INCR get<1>( t ); INCR get<2>( t ); return t; } \
  template <typename T , typename U , typename V , typename W , template <typename...> typename TUPLE> inline auto operator INCR ( TUPLE<T,U,V,W>& t ) -> decltype( ( get<0>( t ) , t ) )& { INCR get<0>( t ); INCR get<1>( t ); INCR get<2>( t ); INCR get<3>( t ); return t; } \


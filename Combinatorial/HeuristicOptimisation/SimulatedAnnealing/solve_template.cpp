VO Solve()
{
  #ifdef DEBUG
    ifstream ifs( "in/test_001.txt" );
    auto Input = [&](){ ll n; ifs >> n; return n; };
  #endif
  CEXPR( double , log_temparature_min , 1e-2 );
  CEXPR( int , updatability_scale , 1e5 );
  RCIN( int , N , Input() );
  START_WATCH; // SA.ExecuteÇ…ìnÇ∑CURRENT_TIMEÇ…égÇ§ÅB
  assert( N == SimulatedAnnealing::N );
  SimulatedAnnealing SA{ N };
  CEXPR( int , final_time , 2000 );
  auto score = SA.Execute( log_temparature_min , CURRENT_TIME , final_time , updatability_scale );
  if( score == 0 ){
    COUT( "Yes" );
    COUT_A( 1 , N + 1 , id<int>( N + 1 ) );
    COUT_A( 1 , N + 1 , SA.Q );
  } else {
    COUT( "No" );
  }
}
REPEAT_MAIN(1);

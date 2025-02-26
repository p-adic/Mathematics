VO Solve()
{
  #ifdef DEBUG
    ifstream ifs( "in/test_001.txt" );
    auto Input = [&](){ int n; ifs >> n; return n; };
  #endif
  CEXPR( double , log_temparature_min , 1e-2 );
  CEXPR( int , updatability_scale , 1e5 );
  RCIN( int , N , Input() );
  assert( N == SimulatedAnnealing::N );
  FOR( i , 0 , N ){
    SimulatedAnnealing::a[i].resize( i + 1 );
    FOREQ( j , 0 , i ){
      RSET( SimulatedAnnealing::a[i][j] , Input() );
    }
  }
  START_WATCH;
  SimulatedAnnealing SA{};

  // pre computation
  
  SA.Execute( log_temparature_min , CURRENT_TIME , 1900 , updatability_scale );
  RETURN( SA );
}
REPEAT_MAIN(1);

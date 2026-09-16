VO Solve()
{
  #ifdef DEBUG
    ifstream ifs( "in/test_001.txt" );
    auto Input = [&](){ ll n; ifs >> n; return n; };
  #endif
  RCIN( int , N , Input() );
  START_WATCH; // HC.ExecuteÇ…ìnÇ∑CURRENT_TIMEÇ…égÇ§ÅB
  HillClimbing HC{ N };
  CEXPR( int , final_time , 2000 );
  auto score = HC.Execute( CURRENT_TIME , final_time );
  CERR( score );
}
REPEAT_MAIN(1);

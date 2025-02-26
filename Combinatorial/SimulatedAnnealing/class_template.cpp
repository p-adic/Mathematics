class SimulatedAnnealing
{

public:
  // static data
  static constexpr double log_temparature_min = 1e-2;
  static constexpr int updatability_scale = 1e5;
  static constexpr double log_updatability_scale = log( updatability_scale );
  static int N;
  static constexpr int B = 1e8;
  using MOD = Mod<B>;
  static vector<vector<MOD>> a;
  
  // mode
  int mode;

  // temporary parameter
  vector<MOD> A;

  // optimal parameter
  vector<MOD> A_opt;

  // update memory
  // FORや他の変数と混ざりそうなものはmをつける。
  int mj;
  int md;
  vector<MOD> mA;
  T2<int> mij;
  int diff_max;

  SimulatedAnnealing() : mode{ 0 } , C( a[N-1] ) , C_opt( C ) , mj() , md( -1 ) , mC( C ) , mij() , diff_max()
  {
  }

  void SetOptimal()
  {
    C_opt = C;
  }
  
  void OptimiseTemporary()
  {
    // 必要な部分のみ変更してもよい。
    C = C_opt;
  }
  
  void Increment()
  {
    if( ++md == 26 ){
      md = 0;
      int down = N - 1 - mij[O];
      mj = GetRand( max( 0 , mij[I] - down ) , min( N - 1 , mij[I] + down ) );
    }
  }

  void Shift1()
  {
    swap( mC , C );
    FOR( j , 0 , N ){
      C[j] = GetRand( 0 , B - 1 );
    }
  }

  void Revert1()
  {
    swap( C , mC );
  }

  void Shift2()
  {
    Increment();
    mC[mj] = C[mj];
    C[mj] += 1 << md;
  }

  void Revert2()
  {
    C[mj] = mC[mj];
  }

  void Shift3()
  {
    // Increment();
    // mC[mj] = C[mj];
    // C[mj] = GetRand( 0 , 1000 );
  }

  void Revert3()
  {
    // C[mj] = mC[mj];
  }

  void Shift( const double& current_time )
  {
    int mode_num = 0;
    if( mode == mode_num++ ){
      if( current_time > 1600 ){
        OptimiseTemporary();
        CERR( "" );
        CERR( "Changed mode:" , mode , "->" , mode_num );
        CERR( "Current score:" , ComputeScore() );
        CERR( "" );
        mode = mode_num;
      }
    } else if( mode == mode_num++ ){
      // if( current_time > 1900 ){
      //   OptimiseTemporary();
      //   CERR( "" );
      //   CERR( "Changed mode:" , mode , "->" , mode_num );
      //   CERR( "Current score:" , ComputeScore() );
      //   CERR( "" );
      //   mode = mode_num;
      // }
    } else if( mode == mode_num++ ){
      // if( current_time > 1900 ){
      //   OptimiseTemporary();
      //   CERR( "" );
      //   CERR( "Changed mode:" , mode , "->" , mode_num );
      //   CERR( "Current score:" , ComputeScore() );
      //   CERR( "" );
      //   mode = mode_num;
      // }
    } else {
      abort();
    }
    mode_num = 0;
    if( mode == mode_num++ ){
      Shift1();
    } else if( mode == mode_num++ ){
      Shift2();
    } else if( mode == mode_num++ ){
      // Shift3();
    } else {
      abort();
    }
    return;
  }

  void Revert()
  {
    int mode_num = 0;
    if( mode == mode_num++ ){
      Revert1();
    } else if( mode == mode_num++ ){
      Revert2();
    } else if( mode == mode_num++ ){
      // Revert3();
    } else {
      abort();
    }
    return;
  }

  using score_type = ll;
  
  score_type ComputeScore()
  {
    score_type score = 0;
    diff_max = 0;
    vector<MOD> A = C;
    FOREQINV( i , N - 1 , 0 ){
      if( i < N - 1 ){
        FOREQ( j , 0 , i ){
          A[j] += A[j+1];
        }
        pop( A );
      }
      auto& a_i = a[i];
      FOREQ( j , 0 , i ){
        int diff = ( A[j] - a_i[j] ).Represent();
        diff = min( diff , B - diff );
        if( diff_max < diff ){
          diff_max = diff;
          mij = {i,j};
          #ifdef DEBUG
            score = -( ll( diff_max ) * 10000 );
          #else
            score = -( ll( diff_max ) << 12 );
          #endif
        } else if ( diff_max == diff ){
          score--;
        }
      }
    }
    return score;
  }

  double Temparature( const double& log_temparature_min , const double& time , const int& time_lim )
  {
    return exp( ( log_temparature_min * time ) / time_lim );
  }
  
  bool Updatable( const int& updatability_scale , const score_type& score , const score_type& score_local_opt , const double& log_temparature_min , const double& time , const int& time_lim )
  {
    return score > score_local_opt || GetRand( 0 , updatability_scale ) < exp( ( score - score_local_opt ) / Temparature( log_temparature_min , time , time_lim ) + log_updatability_scale );
  }

  void Execute( const double& log_temparature_min , const double& start_time , const double& final_time , const int& updatability_scale )
  {
    START_WATCH;
    const double time_lim = final_time - start_time;
    score_type score_opt = ComputeScore() , score_local_opt = score_opt;
    while( CHECK_WATCH( time_lim ) ){
      Shift( current_time );
      const score_type score = ComputeScore();
      if( Updatable( updatability_scale , score , score_local_opt , log_temparature_min , current_time , time_lim ) ){
        if( score > score_opt ){
          CERR( "Updated the optimal score:" , score_opt , "->" , score );
          SetOptimal();
          score_opt = score_local_opt = score;
        } else {
          if( score > score_local_opt ){
            CERR( "Updated the local optimal score:" , score_local_opt , "->" , score );
          } else if( score < score_local_opt ){
            CERR( "Changed the local optimal score:" , score_local_opt , "->" , score );
          } else {
            CERR( "Kept the local optimal score:" , score_local_opt );
          }
          score_local_opt = score;
        }
      } else {
        CERR( "Declined the last score:" , score );
        Revert();
      }
    }
    OptimiseTemporary();
    #ifdef DEBUG
      CERR( "The last score is:" , score_opt );
      assert( score_opt == ComputeScore() );
    #endif
    return;
  }
};

int SimulatedAnnealing::N = 50;
vector<vector<SimulatedAnnealing::MOD>> SimulatedAnnealing::a = vector( SimulatedAnnealing::N , vector<MOD>() );

template <class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const SimulatedAnnealing& SA ) { return os << SA.C; }

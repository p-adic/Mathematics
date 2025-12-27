class HillClimbing
{

public:
  // constexpr data
  static constexpr double time_threshold0 = 2100;
  static constexpr double time_threshold1 = 2100;
  static constexpr double time_threshold2 = 2100;

  // mode
  int mode; // 現在どの最適化を進めている段階か。
  int mode_temp; // mode確認用の変数。
  double start_time; // Execute開始時刻。

  // stable parameter
  int N;

  // temporary/optimal parameter
  vector<int> P,P_opt;
  ll sum = 0;

  // 近傍探索用memory (先頭にmをつけて衝突を避ける)
  // ComputeScore()に計算コストがかかる場合は差分計算用の変数もここに用意する。
  int mi;
  int mj;

  // score
  using score_type = ll;
  score_type score,score_opt,score_local_opt;

  HillClimbing( const int& N ) : N( N )
  {
    mode = 0;
    P = id<int>( N );
    // 単発の貪欲法など、繰り返しをともなわない前処理を以下に行う。
    // VVV

    // AAA
    SetOptimal();
  }

  void SetOptimal()
  {
    P_opt = P;
  }
  
  void OptimiseTemporary()
  {
    // 必要な部分のみ変更してもよい。
    P = P_opt;
  }

  // 近傍探索用memoryの変更。
  // small testのインクリメント、random testの乱択に相当。
  void Increment0( const double& current_time )
  {
    // double rate = time_threshold0 - 0.001 < start_time ? 1.0 : ( current_time - start_time ) / ( time_threshold0 - start_time );
  }

  // 近傍探索用memoryを用いたtemporary parameterの変更。
  void Shift0( const double& current_time )
  {
    Increment0( current_time );
  }

  // 近傍探索用memoryを用いたtemporary parameterの復元。
  void Revert0()
  {
  }

  void Increment1( const double& current_time )
  {
    // double rate = time_threshold1 - 0.001 < start_time ? 1.0 : ( current_time - start_time ) / ( time_threshold1 - start_time );
    // int bound = max( 1 , min( N , int( N * ( 1.1 - rate ) ) ) );
    // mi = GetRand( 1 , bound );
    // mj = GetRand( 1 , bound );
  }

  void Shift1( const double& current_time )
  {
    // Increment1( current_time );
    // sum -= ll( Q[mi] ) * mi;
    // sum -= ll( Q[mj] ) * mj;
    // swap( Q[mi] , Q[mj] );
    // sum += ll( Q[mi] ) * mi;
    // sum += ll( Q[mj] ) * mj;
  }

  void Revert1()
  {
    // sum -= ll( Q[mi] ) * mi;
    // sum -= ll( Q[mj] ) * mj;
    // swap( Q[mi] , Q[mj] );
    // sum += ll( Q[mi] ) * mi;
    // sum += ll( Q[mj] ) * mj;
  }

  void Increment2( const double& current_time )
  {
    // double rate = time_threshold2 - 0.001 < start_time ? 1.0 : ( current_time - start_time ) / ( time_threshold2 - start_time );
  }
  
  void Shift2( const double& current_time )
  {
    Increment2( current_time );
  }

  void Revert2()
  {
  }
  
  void ModeChange()
  {
    OptimiseTemporary();
    CERR( "" );
    CERR( "Changed mode:" , mode , "->" , mode_temp );
    CERR( "Current score:" , ComputeScore() );
    CERR( "" );
    mode = mode_temp;
  }

  void Shift( const double& current_time )
  {
    mode_temp = 0;
    if( mode == mode_temp++ ){
      // time_threshold0がfinal_time以上の時はmodeをこれ以上更新しない。
      if( current_time > time_threshold0 ){
        ModeChange();
      }
    } else if( mode == mode_temp++ ){
      if( current_time > time_threshold1 ){
        ModeChange();
      }
    } else if( mode == mode_temp++ ){
      if( current_time > time_threshold2 ){
        ModeChange();
      }
    } else {
      abort();
    }
    mode_temp = 0;
    if( mode == mode_temp++ ){
      Shift0( current_time );
    } else if( mode == mode_temp++ ){
      Shift1( current_time );
    } else if( mode == mode_temp++ ){
      Shift2( current_time );
    } else {
      abort();
    }
  }

  void Revert()
  {
    mode_temp = 0;
    if( mode == mode_temp++ ){
      Revert0();
    } else if( mode == mode_temp++ ){
      Revert1();
    } else if( mode == mode_temp++ ){
      Revert2();
    } else {
      abort();
    }
  }

  // コストではなくスコア。大きいほど良い。
  const score_type& ComputeScore()
  {
    return score;
  }

  const score_type& Execute( const double& executed_time , const double& final_time )
  {
    START_WATCH;
    start_time = executed_time;
    const double time_lim = final_time - start_time;
    score_opt = ComputeScore(); score_local_opt = score_opt;
    while( CHECK_WATCH( time_lim ) ){
      // if( score_opt == 100000000 ){
      //   CERR( "Reached the maximum:" , score_opt );
      //   break;
      // }
      Shift( current_time );
      const score_type score = ComputeScore();
      if( score > score_local_opt ){
        if( score > score_opt ){
          CERR( "Updated the optimal score:" , score_opt , "->" , score );
          SetOptimal();
          score_opt = score_local_opt = score;
        } else {
          CERR( "Updated the local optimal score:" , score_local_opt , "->" , score );
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
    return score_opt;
  }
};

class SimulatedAnnealing
{

public:
  // constexpr data
  static constexpr double log_temparature_min = 1e-2;
  static constexpr int updatability_scale = 1e5;
  static constexpr double log_updatability_scale = log( updatability_scale );

  // 山登りを行わない場合はtime_threshold0を-1にする。
  static constexpr double time_threshold0 = -1;
  static constexpr double time_threshold1 = 1600;
  static constexpr double time_threshold2 = 1900;

  // mode
  int mode; // 現在どの最適化を進めている段階か。mode==0の時は山登りを行う。
  int mode_temp; // mode確認用の変数。
  double start_time; // Execute開始時刻。

  // stable parameter
  int N;
  ll K;

  // temporary/optimal parameter
  vector<int> Q,Q_opt;
  ll sum,sum_opt;

  // 近傍探索用memory (先頭にmをつけて衝突を避ける)
  // ComputeScore()に計算コストがかかる場合は差分計算用の変数もここに用意する。
  int mi;
  int mj;

  // score
  using score_type = ll;
  score_type score,score_opt,score_local_opt;

  SimulatedAnnealing( const int& N , const ll& K ) : N( N ) , K( K )
  {
    mode = 0;
    Q = id<int>( N + 1 );
    sum = N * ll( N + 1 ) * ( 2 * N + 1 ) / 6;
    // 単発の貪欲法など、繰り返しをともなわない前処理を以下に行う。
    // VVV

    // AAA
    SetOptimal();
  }

  void SetOptimal()
  {
    Q_opt = Q;
    sum_opt = sum;
  }
  
  void OptimiseTemporary()
  {
    // 必要な部分のみ変更してもよい。
    Q = Q_opt;
    sum = sum_opt;
  }

  // 近傍探索用memoryの変更。
  // small testのインクリメント、random testの乱択に相当。
  void Increment0( const double& current_time )
  {
    // mode==0は山登り用。山登りが不要ならば実装は空で良い。
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
    // mode>0から焼き鈍す。
    // double rate = time_threshold1 - 0.001 < start_time ? 1.0 : ( current_time - start_time ) / ( time_threshold1 - start_time );
    // int bound = max( 1 , min( N , int( N * ( 1.1 - rate ) ) ) );
    // mi = GetRand( 1 , bound );
    // mj = GetRand( 1 , bound );
  }

  void Shift1( const double& current_time )
  {
    Increment1( current_time );
    // sum -= ll( Q[mi] ) * mi;
    // sum -= ll( Q[mj] ) * mj;
    // swap( Q[mi] , Q[mj] );
    // sum += ll( Q[mi] ) * mi;
    // sum += ll( Q[mj] ) * mj;
  }

  void Revert1()
  {
    sum -= ll( Q[mi] ) * mi;
    sum -= ll( Q[mj] ) * mj;
    swap( Q[mi] , Q[mj] );
    sum += ll( Q[mi] ) * mi;
    sum += ll( Q[mj] ) * mj;
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

  double Temparature( const double& log_temparature_min , const double& time , const int& time_lim )
  {
    return exp( ( log_temparature_min * time ) / time_lim );
  }
  
  bool Updatable( const int& updatability_scale , const score_type& score , const score_type& score_local_opt , const double& log_temparature_min , const double& time , const int& time_lim )
  {
    return score > score_local_opt || ( mode > 0 && GetRand( 0 , updatability_scale ) < exp( ( score - score_local_opt ) / Temparature( log_temparature_min , time , time_lim ) + log_updatability_scale ) );
  }

  const score_type& Execute( const double& log_temparature_min , const double& executed_time , const double& final_time , const int& updatability_scale )
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
    return score_opt;
  }
};


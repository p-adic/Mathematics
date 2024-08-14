// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleAnalyser/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

// �f�o�b�O���[�h�łȂ��Ɩ|��P�ʂ��ƂɈقȂ������DynamicMod�������Ă��܂���̂Ŏ��s����
// Segmentation Fault�ƂȂ�B
#include "../../../Mathematics/Arithmetic/Mod/DynamicModulo/Debug/a_Body.hpp"
#include "../../../Mathematics/Arithmetic/Mod/Function/DiscreteLog/a_Body.hpp"
#include "../../../Mathematics/Combinatorial/Loop/a_Body.hpp"

AC( SampleAnalyser )
{
  ASK_YES_NO( "�����グ�̖@��998244353�ł����H" );
  int P = 998244353;
  if( reply != "y" ){
    cerr << "�����グ�̖@: "; cin >> P;
  }
  DynamicMod::SetModulo( P );
  int sample_count = 3;
  ASK_YES_NO( "�T���v���̌���3�ł����H" );
  if( reply != "y" ){
    cerr << "�T���v���̌�: "; cin >> sample_count;
  }
  vector<vector<ll>> input( sample_count );
  vector<DynamicMod> output( sample_count );
  int var = 0;
  bool const_var = false;
  ASK_YES_NO( "�T���v�����͒��̐��l�̌��͈��ł����H" );
  if( reply == "y" ){
    cerr << "�T���v�����͒��̐��l�̌�: "; cin >> var;
    CERR( "" );
    const_var = true;
  }
  FOR( sample_num , 0 , sample_count ){
    const string sample_num_str = to_string( sample_num + 1 );
    if( !const_var ){
      cerr << "�T���v��" << sample_num_str << "�̓��͒��̐��l�̌�: "; cin >> var;
    }
    cerr << "�T���v��" << sample_num_str << "�̓��͒��̐��l: ";
    CIN_A( ll , 0 , var , A );
    input[sample_num] = move( A );
    cerr << "�T���v��" + sample_num_str + "�o��: "; cin >> output[sample_num];
    CERR( "" );
  }
  const string P_str = to_string( P );
  int scale = 1;
  while( true ){
    PowerAnalysis( sample_count , output , scale , P , P_str );
    if( const_var && 0 < var && var <= 4 ){
      if( var == 1 ){
	InputPolynomialAnalysis1( sample_count , input , output , scale , P , P_str );
      } else if( var == 2 ){
	InputPolynomialAnalysis2( sample_count , input , output , scale , P , P_str );
	InputExponentialAnalysis2( sample_count , input , output , scale , P , P_str );
      } else if( var == 3 ){
	InputPolynomialAnalysis3( sample_count , input , output , scale , P , P_str );
      } else {
	assert( var == 4 );
	InputLinearAnalysis4( sample_count , input , output , scale , P , P_str );
      }
    }
    ASK_YES_NO( "��͔͈͂��L���܂����H" );
    if( reply == "y" ){
      while( true ){
	int rate = 0;
	CERR( "�e�W���̒T���͈͂̊g��{��: " ); cin >> rate;
	if( rate <= 1 ){
	  CERR( "�{����2�ȏ�̐����ɂ��Ă��������B" );
	} else {
	  scale *= rate;
	  break;
	}
      }
    } else {
      break;
    }
  }
  CERR( "�T���v���̉�͂��I�����܂��B");
}

void PowerAnalysis( const int& sample_count , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , diff_bound , 10 );
  const int diff_max = diff_bound * scale;
  const vector bases{2,3,5,6,7};
  RUN( bases , base ){
    cerr << "�T���v��";
    FOR( sample_num , 0 , sample_count ){
      ( sample_num == 0 ? cerr : cerr << ", " ) << sample_num + 1;
    }
    cerr << "�̏o�̖͂@" + P_str + "�ɂ������" + to_string( base ) + "�̗��U�ΐ������߂܂��B\n";
    FOREQ( diff , - diff_max , diff_max ){
      cerr << "�o��" << ( diff > 0 ? "+" : "" ) << ( diff == 0 ? "" : to_string( diff ) ) << ": ";
      bool small = true;
      FOR( sample_num , 0 , sample_count ){
	int dl = DiscreteLog( int( output[sample_num].Represent() ) + diff , base , P );
	small &= 0 <= dl && ll( dl ) * dl < P;  
	cerr << ( dl < 0 ? "NaN" : to_string( dl ) ) << ( sample_num == sample_count - 1 ? "" : ", " );
      }
      ( small ? cerr << " <- �L�ӂɏ������l�ł��B" : cerr ) << "\n";
    }
    CERR( "" );
  }
}

void InputPolynomialAnalysis1( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "�T���v���o�̖͂@" + P_str + "�ɂ�����1�ϐ���������Ԃ����݂܂��B" );
  CEXPR( int , size , 4 );
  CEXPR( int , length , size );
  CEXPR( int , denom , 12 );
  CEXPR( int , numer_bound , 50 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_count * size;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "�i�\�z��͎���: " << time / 16000000 << "�b�j\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] };
      DynamicMod temp{};
      FOR( i , 0 , size ){
	temp += DynamicMod( index[i] ) * x_power;
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "��Ԑ���:" );
    FOR( i , 0 , size ){
      cerr << "(" << index[i] << "/" << denom << ") (����1)^" << i << ( i == size - 1 ? "\n" : " + " );
    }
  } else {
    CERR( "��Ԏ��s�B" );
  }
  cerr << "��͎���: " << int( CURRENT_TIME / 1000 ) << "�b\n";
  CERR( "" );
}

void InputPolynomialAnalysis2( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "�T���v���o�̖͂@" + P_str + "�ɂ�����2�ϐ���������Ԃ����݂܂��B" );
  CEXPR( int , size , 3 );
  CEXPR( int , length , size * size );
  CEXPR( int , denom , 2 );
  CEXPR( int , numer_bound , 3 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_count * size * size;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "�i�\�z��͎���: " << time / 16000000 << "�b�j\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] };
      DynamicMod temp{};
      FOR( dx , 0 , size ){
	DynamicMod xy_power = x_power;
	FOR( dy , 0 , size ){
	  int i = size * dx + dy;
	  temp += DynamicMod( index[i] ) * xy_power;
	  xy_power *= y;
	}
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "��Ԑ���:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	int i = size * dx + dy;
	cerr << "(" << index[i] << "/" << 2 * index[i+size*size] - 1 << ") (����1)^" << dx << " (����2)^" << dy << ( dx == size - 1 && dy == size - 1 ? "\n" : " + " );
      }
    }
  } else {
    CERR( "��Ԏ��s�B" );
  }
  cerr << "��͎���: " << int( CURRENT_TIME / 1000 ) << "�b\n";
  CERR( "" );
}

void InputPolynomialAnalysis3( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "�T���v���o�̖͂@" + P_str + "�ɂ�����3�ϐ���������Ԃ����݂܂��B" );
  CEXPR( int , size , 2 );
  CEXPR( int , length , size * size * size );
  CEXPR( int , denom , 2 );
  CEXPR( int , numer_bound , 4 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_count * size * size * size;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "�i�\�z��͎���: " << time / 16000000 << "�b�j\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] } , z{ input[sample_num][2] };
      DynamicMod temp{};
      FOR( dx , 0 , size ){
	DynamicMod xy_power = x_power;
	FOR( dy , 0 , size ){
	  DynamicMod xyz_power = xy_power;
	  FOR( dz , 0 , size ){
	    int i = size * size * dx + size * dy + dz;
	    temp += DynamicMod( index[i] ) * xyz_power;
	    xyz_power *= z;
	  }
	  xy_power *= y;
	}
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "��Ԑ���:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	FOR( dz , 0 , size ){
	  int i = size * size * dx + size * dy + dz;
	  cerr << "(" << index[i] << "/" << denom << ") (����1)^" << dx << " (����2)^" << dy << " (����3)^" << dz << ( dx == size - 1 && dy == size - 1 && dz == size - 1 ? "\n" : " + " );
	}
      }
    }
  } else {
    CERR( "��Ԏ��s�B" );
  }
  cerr << "��͎���: " << int( CURRENT_TIME / 1000 ) << "�b\n";
  CERR( "" );
}

void InputLinearAnalysis4( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "�T���v���o�̖͂@" + P_str + "�ɂ�����4�ϐ����`��Ԃ����݂܂��B" );
  CEXPR( int , var , 4 );
  CEXPR( int , length , var + 1 );
  CEXPR( int , denom , 12 );
  CEXPR( int , numer_bound , 24 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound{ length , numer_max };
  vector<int> index = lower_bound;
  ll time = sample_count * var;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "�i�\�z��͎���: " << time / 16000000 << "�b�j\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod temp = index[var];
      FOR( i , 0 , var ){
	temp += DynamicMod( index[i] ) * input[sample_num][i];
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "��Ԑ���:" );
    cerr << "(" << index[var] << "/" << denom << ") + ";
    FOR( i , 0 , var ){
      cerr << "(" << index[i] << "/" << denom << ") (����" << i << ")" << ( i == var - 1 ? "\n" : " + " );
    }
  } else {
    CERR( "��Ԏ��s�B" );
  }
  cerr << "��͎���: " << int( CURRENT_TIME / 1000 ) << "�b\n";
  CERR( "" );
}

void InputExponentialAnalysis2( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "�T���v���o�̖͂@" + P_str + "�ɂ�����w���֐��̈ꎟ�����ɂ���Ԃ����݂܂��B" );
  CEXPR( int , size , 3 );
  CEXPR( int , var , 2 );
  CEXPR( int , length , var * ( var - 1 ) * size + 1 );
  CEXPR( int , denom , 2 );
  CEXPR( int , numer_bound , 5 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_count * size * 2;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "�i�\�z��͎���: " << time / 16000000 << "�b�j\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod x{ input[sample_num][0] } , y{ input[sample_num][1] } , x_power = Power( x , input[sample_num][1] - 1 ) , y_power = Power( y , input[sample_num][0] - 1 );
      DynamicMod temp = DynamicMod( index[length-1] );
      FOR( dy , 0 , size ){
	int i = dy;
	temp += DynamicMod( index[i] ) * x_power;
	x_power *= x;
      }
      FOR( dx , 0 , size ){
	int i = size + dx;
	temp += DynamicMod( index[i] ) * y_power;
	y_power *= y;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "��Ԑ���:" );
      cerr << "(" << index[length-1] << "/" << denom << ") + ";
    FOR( dy , 0 , size ){
      int i = dy;
      cerr << "(" << index[i] << "/" << denom << ") (����1)^{(����2)" << ( dy > 0 ? "+" : "" ) << ( dy == 0 ? "" : to_string( dy ) ) << "} + ";
    }
    FOR( dx , 0 , size ){
      int i = size + dx;
      cerr << "(" << index[i] << "/" << denom << ") (����2)^{(����1)" << ( dx > 0 ? "+" : "" ) << ( dx == 0 ? "" : to_string( dx ) ) << ( dx == size - 1 ? "}" : "} + " );
    }
  } else {
    CERR( "��Ԏ��s�B" );
  }
  cerr << "��͎���: " << int( CURRENT_TIME / 1000 ) << "�b\n";
  CERR( "" );
}

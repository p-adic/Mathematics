// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/IntervalSumMaximisation/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT1 , typename INT2 , typename FUNC>
vector<pair<INT1,INT2>> IntervalSumMaximisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min , INT2 length_max )
{

  static_assert( is_invocable_r_v<INT1,FUNC,const INT1&> );
  ofs_err << "IntervalSumMaximisation���f�o�b�O���[�h�Ŏ��s���܂��B" << endl;
  ofs_err << "������[" << i_start << "," << i_final << "]�͈̔́A������[" << length_min << "," << length_max << "]�͈̔͂�" << endl;
  ofs_err << lim << "�����̍ő�l�����߂܂��B" << endl;

  if( length_max == -1 ){

    length_max = i_final - i_start + 1;

  }

  assert( length_min <= length_max );
  vector<pair<INT1,INT2>> answer( length_max - length_min + 1 , { lim , i_start - 1 } );
  INT1 iss{};

  for( INT2 L = 1 ; L < length_min ; L++ ){

    iss += func( i_start + L - 1 );

  }

  if( length_min == 0){

    ofs_err << "����" << 0 << ": ";

    if( 0 >= lim ){

      ofs_err << lim << "�����̒l�͌��t����܂���ł����B" << endl;

    } else {

      answer[0] = { 0 , i_start };
      ofs_err << 0 << "���ő�l�ŁA�֋X��̍��[��" << i_start << "�ɐݒ肵�܂����B" << endl;

    }

  }

  for( INT2 L = max( INT2( 1 ) , length_min ) ; L <= length_max ; L++ ){

    INT1 temp = iss += func( i_start + L - 1 );
    pair<INT1,INT2>& answer_L = answer[L - length_min];

    for( INT2 i = i_start + L - 1 ; i <= i_final ; i++ ){

      if( ( answer_L.first == lim || answer_L.first < temp ) && temp < lim ){

	answer_L = { temp , i - L + 1 };

      }

      if( i < i_final ){

	temp += func( i + 1 ) - func( i - L + 1 );

      }

    }

    ofs_err << "����" << L << ": ";

    if( answer_L.first == lim ){

      ofs_err << lim << "�����̒l�͌��t����܂���ł����B" << endl;

    } else {

      ofs_err << answer_L.first << "���ő�l�ŁA���̎��̍��[�̍ŏ��l��" << answer_L.second << "�ł��B" << endl;

    }

  }

  ofs_err << endl;
  return answer;

}

template <typename INT1 , typename INT2 , typename FUNC>
vector<pair<INT1,INT2>> IntervalSumMinimisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min , INT2 length_max )
{

  static_assert( is_invocable_r_v<INT1,FUNC,const INT1&> );
  ofs_err << "IntervalSumMinimisation���f�o�b�O���[�h�Ŏ��s���܂��B" << endl;
  ofs_err << "������[" << i_start << "," << i_final << "]�͈̔́A������[" << length_min << "," << length_max << "]�͈̔͂�" << endl;
  ofs_err << lim << "���傫���ŏ��l�����߂܂��B" << endl;

  if( length_max == -1 ){

    length_max = i_final - i_start + 1;

  }

  assert( length_min <= length_max );
  vector<pair<INT1,INT2>> answer( length_max - length_min + 1 , { lim , i_start - 1 } );
  INT1 iss{};

  for( INT2 L = 1 ; L < length_min ; L++ ){

    iss += func( i_start + L - 1 );

  }

  if( length_min == 0){

    ofs_err << "����" << 0 << ": ";

    if( 0 <= lim ){

      ofs_err << lim << "���傫���l�͌��t����܂���ł����B" << endl;

    } else {

      answer[0] = { 0 , i_start };
      ofs_err << 0 << "���ŏ��l�ŁA�֋X��̍��[��" << i_start << "�ɐݒ肵�܂����B" << endl;

    }

  }
  
  for( INT2 L = max( INT2( 1 ) , length_min ) ; L <= length_max ; L++ ){

    INT1 temp = iss += func( i_start + L - 1 );
    pair<INT1,INT2>& answer_L = answer[L - length_min];

    for( INT2 i = i_start + L - 1 ; i <= i_final ; i++ ){

      if( ( answer_L.first == lim || answer_L.first > temp ) && temp > lim ){

	answer_L = { temp , i - L + 1 };

      }

      if( i < i_final ){

	temp += func( i + 1 ) - func( i - L + 1 );

      }

    }

    ofs_err << "����" << L << ": ";

    if( answer_L.first == lim ){

      ofs_err << lim << "���傫���l�͌��t����܂���ł����B" << endl;

    } else {

      ofs_err << answer_L.first << "���ŏ��l�ŁA���̎��̍��[�̍ŏ��l��" << answer_L.second << "�ł��B" << endl;

    }
    
  }

  ofs_err << endl;
  return answer;

}


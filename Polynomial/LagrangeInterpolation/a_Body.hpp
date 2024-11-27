// c:/Users/user/Documents/Programming/Mathematics/Polynomial/LagrangeInterpolation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../MultipointEvaluation/a_Body.hpp"

template <typename T>
Polynomial<T> LagrangeInterpolation( const vector<T>& arg , const vector<T>& val )
{

  const int size = arg.size();
  assert( size > 0 && int( val.size() ) == size );

  // SetDifferenceProduct���̂��̂����Atop.front()�𗬗p���邽�߂Ɏ������R�s�[����B
  list<vector<Polynomial<T> > > pt{};
  SetPointTree( arg , pt );
  const vector<Polynomial<T> >& top = pt.front();
  auto& f = top.front();
  Polynomial<T> g{ Differential( 1 , f ) };
  vector<T> coef{};
  SetPointTreeEvaluation( g , pt , coef );

  Polynomial<T> answer{};
  auto itr = pt.back().begin();
  
  for( int i = 0 ; i < size ; i++ ){

    // 1�����ɂ�鏤�Ȃ̂ŋ𒼂̕����������o�O�����o���₷���悤��
    // ���������Z�̈�ʂ̃A���S���Y����p����B
    answer += f / *( itr++ ) * ( val[i] / coef[i] );

  }

  answer.RemoveRedundantZero();
  return answer;

}

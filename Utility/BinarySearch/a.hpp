// c:/Users/user/Documents/Programming/Utility/BinarySearch/a.hpp

#pragma once
#include "a_Macro.hpp"

//verify:
// https://yukicoder.me/submissions/977275�iMaximumLeq, MinimumGeq�j

// t�ȉ��̒l�����݂���΂��̍ő�l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::iterator MaximumLeq( set<T>& S , const T& t );

// t�����̒l�����݂���΂��̍ő�l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::iterator MaximumLt( set<T>& S , const T& t );

// t�ȏ�̒l�����݂���΂��̍ŏ��l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::iterator MinimumGeq( set<T>& S , const T& t );

// t���傫���l�����݂���΂��̍ŏ��l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::iterator MinimumGt( set<T>& S , const T& t );


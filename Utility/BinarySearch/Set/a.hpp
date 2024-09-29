// c:/Users/user/Documents/Programming/Utility/BinarySearch/Set/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1002390�iset��MaximumLeq, set��MinimumGeq�j
// https://yukicoder.me/submissions/1002389�imap��MaximumLeq�j

// t�ȉ��̒l�����݂���΂��̍ő�l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::const_iterator MaximumLeq( const set<T>& S , const T& t );
// t�ȉ���key�����݂���΂��̍ő�l�ɑΉ�����iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T , typename U> inline typename map<T,U>::iterator MaximumLeq( map<T,U>& f , const T& t );

// t�����̒l�����݂���΂��̍ő�l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::const_iterator MaximumLt( const set<T>& S , const T& t );
// t������key�����݂���΂��̍ő�l�ɑΉ�����iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T , typename U> inline typename map<T,U>::iterator MaximumLt( map<T,U>& f , const T& t );

// t�ȏ�̒l�����݂���΂��̍ŏ��l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::const_iterator MinimumGeq( const set<T>& S , const T& t );
// t�ȏ��key�����݂���΂��̍ŏ��l�ɑΉ�����iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T , typename U> inline typename map<T,U>::iterator MaximumGeq( map<T,U>& f , const T& t );

// t���傫���l�����݂���΂��̍ŏ��l��iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T> inline typename set<T>::const_iterator MinimumGt( const set<T>& S , const T& t );
// t���傫��key�����݂���΂��̍ŏ��l�ɑΉ�����iterator�A���݂��Ȃ����end()��Ԃ��B
template <typename T , typename U> inline typename map<T,U>::iterator MaximumGt( map<T,U>& f , const T& t );


// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/a.hpp

#pragma once

// (T,m_T:T^2->T,e_T:1->T)�����m�C�h�ł���ꍇ�ɂ̂݃T�|�[�g�B
// T�̗v�f�̗��m_T�Ɋւ��鑍��𕪊������Ōv�Z���A���̌��ʂ��1�����Ɋi�[���ĎQ�ƕԂ�����B
// V<T>��erase�����K�v������B
template <typename T , template <typename...> typename V , T m_T(const T&,const T&) , const T& e_T()>
T& MonoidalProd( V<T>& f );
template <typename T , template <typename...> typename V>
T& Sum( V<T>& f );
template <typename T , template <typename...> typename V>
T& Prod( V<T>& f );

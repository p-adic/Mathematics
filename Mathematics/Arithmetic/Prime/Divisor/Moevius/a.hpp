// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/Moevius/a.hpp

#pragma once

// O(��n)
template <typename INT> int Moevius( const INT& n ) noexcept;
// sqrt( n )�ȉ��̍ő�̑f�� < val_limit�ipe�̃e���v���[�g�����j�̎��̂݃T�|�[�g�B
// O(��n/(log n))
template <typename PE , typename INT> int Moevius( const PE& pe , INT n ) noexcept;
// n < val_limit�ild�̃e���v���[�g�����j �̎��̂݃T�|�[�g�B
// O(d(n)) = O(log n / log log n)
template <typename LD , typename INT> int Moevius( const LD& ld , INT n );

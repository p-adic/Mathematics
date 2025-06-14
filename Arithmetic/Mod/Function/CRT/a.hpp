// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/CRT/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/1099258 (Garner)

// GCD��LCM��../../../Prime/Divisor/GCD�Œ�`�B

// u_0,u_1��u_0*b_0+u_1*b_1==GCD(b_0,b_1)�𖞂����l���i�[���A
// GCD(b_0,b_1)��Ԃ��B�iO(log min(b_0,b_1))�j
template <typename INT> INT PartitionOfUnity( const INT& b_0 , const INT& b_1 , INT& u_0 ,  INT& u_1 );

// GCD(b,c)==1�ł���ꍇ�ɂ̂݃T�|�[�g�B
// c�̖@b�t����Ԃ��B�iO(log b)�j
template <typename INT> inline INT ModularInverse( const INT& b , const INT& c );

// LCM(b_0,b_1)^2��INT�ŃI�[�o�[�t���[���Ȃ��ꍇ�ɂ̂݃T�|�[�g�B
// (x-c_0)%b_0==0����(x-c_1)%b_1==0�𖞂����񕉐���x�����݂���΂��̂悤��x��Ԃ��A
// ���݂��Ȃ��Ȃ��-1��Ԃ��B�iO(log min(b_0,b_1))�j
template <typename INT> INT ChineseRemainderTheorem( const INT& b_0 , const INT& c_0 , const INT& b_1 , const INT& c_1 );

// b���݂��ɑf�����悪�I�[�o�[�t���[���Ȃ��ꍇ�ɂ̂݃T�|�[�g�B
// b,c�̃T�C�Y��size�Ƃ��āAsize�����̔C�ӂ̔񕉐���i�ɑ΂�(x-c[i])%b[i]==0�𖞂���
// �ŏ��̔񕉐���x��Ԃ��B�iO(size(size+log max(b)))�j
template <typename INT> INT Garner( const vector<INT>& b , const vector<INT>& c );


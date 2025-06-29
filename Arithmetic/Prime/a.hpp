// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once

// �O�v�Z�̍��v�v�Z��O((p_i/log p_i)^2) = O(i^2)��1+i�Ԗڂ̑f��p_i��O(1)�Ԃ��B
// ���ɑO�v�Z�̍��v�v�Z��O((L/log L)^2)��L�ȉ��̑f����񋓂���B
// https://math.stackexchange.com/a/1744146
int GetPrime( const int& i );

// T=20�ȂǂƂ��AO(T log n)�Ō딻�藦��4^{-T}�ɗ}����B
// ��������Z�̌v�Z�ʂ�O(1)�Ƃ݂Ȃ����B
bool MillerRabin( const int& n );

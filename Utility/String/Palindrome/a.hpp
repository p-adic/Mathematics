// c:/Users/user/Documents/Programming/Utility/String/Palindrome/a.hpp

#pragma once

// reversed=false�̎���S[0,r]�i0<=r<N�j���񕶂��ۂ���answer[r]�ɁA
// reversed=true�̎���S[l,N-1]�i0<=l<N�j���񕶂��ۂ���answer[l]��
// O(N)�Ŋi�[�B�i�m���I����j
vector<bool> Palindrome( const string& S , const bool& reversed = false );

// S[l,r]�i0<=l<=r+1<=N�j���񕶂��ۂ���O(N^2)��answer[r][l]�Ɋi�[�B
// answer[l][r]�ɂ���ƃ������̖��ʌ����ƂȂ�̂ŋt�ł��邱�Ƃɒ��ӁB
vector<vector<bool>> TotalPalindrome( const string& S );

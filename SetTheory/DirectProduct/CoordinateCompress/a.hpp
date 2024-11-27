// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/996898�ill�AR�j
// https://yukicoder.me/submissions/994770�ill�AL�j
// https://yukicoder.me/submissions/972421�ituple<int,int,int>�AR�j

// Set�񐔂�Q�ASet���ꂽ���̎�ސ���N�ƒu���B

// �E�Ӓl�o�^O(log N)
// �E�Ӓl���k���ʎ擾O(N)
// �E�Ӓl���k���ʎg�pO(1)�iexpected�j
// ���vO(Q log N)�iexpected�j

// ���Ӓl�o�^O(1)
// ���Ӓl���kO(Q log Q)
// ���vO(Q log Q)

// ��E�̕]���͉E�Ӓl���k�̕������������AN��Q�ɋ߂����͍��Ӓl���k�̕����y���B
template <typename INT = ll>
class CoordinateCompress
{

private:
  set<INT> m_r;
  vector<INT*> m_l;

public:
  inline CoordinateCompress();

  inline void SetR( INT t );
  template <typename U , template <typename...> typename V > inline void SetR( V<U> a );
  pair<vector<INT>,unordered_map<INT,int>> GetR();
  // �E�Ӓl�̈��k�f�[�^��Ԃ��B
  inline void clearR();

  inline void SetL( INT& t );
  template <typename U , template <typename...> typename V > inline void SetL( V<U>& a );
  // ���Ӓl�����k���ă\�[�g�ς݂̔z���Ԃ��B
  vector<INT> GetL();
  inline void clearL();

};

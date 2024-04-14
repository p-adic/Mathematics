// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/971107�iR�j
// https://yukicoder.me/submissions/971181�iL�j

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
  // ���Ӓl�����k���Ď�ސ���Ԃ��B
  int GetL();
  inline void clearL();

};

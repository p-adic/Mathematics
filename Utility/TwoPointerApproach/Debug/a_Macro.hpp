// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/Debug/a_Macro.hpp

#pragma once
#include "../../../../Utility/StdStream/a_Macro.hpp"

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#ifndef TPA
/* // �ڎ��@�p
VAR_TPA�͎ڎ��@�p�̕ϐ����̐ړ����ŁA���ۂ̕ϐ����ł͂Ȃ��A_L��_R��_info�����B
ANSWER ## _temp = {VAR_TPA ## _L,VAR_TPA ## _R,VPA_TPA ## _info}��{INIT,INIT,INFO_init}�ŏ���������BVPA_TPA ## _info�͋�Ԙa�ȂǁB
ANSWER ## _temp��CONTINUE_CONDITION�𖞂�������AANSWER ## _temp������ON_CONDITION�𖞂������ۂ��𔻒肵�A
���ꂪtrue�ɂȂ邩VAR_TAR ## _L��VAR_TAR ## _R�ɒǂ��t���܂�VAR_TPA ## _L��VPA_TPA ## _info�̍X�V����UPDATE_L���J��Ԃ��A
���̌�VAR_TPA ## _R��VPA_TPA ## _info�̍X�V����UPDATE_R���s���B�i�}�N���ƃR���}�̐����A�֐��I�u�W�F�N�g��p����j
ON_CONDITION��true�ƂȂ�ɑ��ԂƂ��̎��_�ł�info��ANSWER�Ɋi�[����B
�Ⴆ�Β���N�̔񕉐����l�z��A�ŋɑ�Ȑ��l��ԂƂ����ł̑��a���擾�������ꍇ
auto update_L = [&]( int& i_L , auto& i_info ){ i_info -= A[i_L++]; };
auto update_R = [&]( int& i_R , auto& i_info ){ if( ++i_R < N ){ i_info += A[i_R]; } };
TPA( interval , i , 0 , i_R < N , update_L( i_L , i_info ) , update_R( i_R , i_info ) , A[i_L] > 0 && A[i_R] > 0 , ll( A[0] ) );
�Ƃ����tuple<int,int,ll>�l�z��interval��{���[,�E�[,���a}�̗񂪊i�[�����B
VAR_TPA ## _info��interval�ɃR�s�[�����̂ŁAset��vector�Ȃǂ̃R�s�[�̃R�X�g��
�傫���f�[�^��p����on,off���肷�鎞��TPA���O�ɐ錾���Ďg���B*/
#define TPA( ANSWER , VAR_TPA , INIT , CONTINUE_CONDITION , UPDATE_L , UPDATE_R , ON_CONDITION , INFO_init ) \
  vector<tuple<decldecay_t( INIT ),decldecay_t( INIT ),decldecay_t( INFO_init )>> ANSWER{}; \
  {									\
    auto init_TPA = INIT;						\
    decldecay_t( ANSWER.front() ) ANSWER ## _temp = { init_TPA , init_TPA , INFO_init }; \
    auto ANSWER ## _prev = ANSWER ## _temp;				\
    auto& VAR_TPA ## _L = get<0>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _R = get<1>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _info = get<2>( ANSWER ## _temp );			\
    bool on_TPA_prev = false;						\
    while( true ){                                                      \
      bool continuing = CONTINUE_CONDITION;				\
      bool on_TPA = continuing && ( ON_CONDITION );			\
      DERR( continuing ? "�ڎ�蒆" : "�ڎ��I��" , ": [L,R] = [" , VAR_TPA ## _L , "," , VAR_TPA ## _R , "] ," , on_TPA_prev ? "on" : "off" , "->" , on_TPA ? "on" : "off" , ", info =" , VAR_TPA ## _info ); \
      if( on_TPA_prev && ! on_TPA ){					\
	ANSWER.push_back( ANSWER ## _prev );				\
	DERR( #ANSWER , "��" , ANSWER ## _prev , "���i�[���܂��B" );	\
      }									\
      if( continuing ){							\
	if( on_TPA || VAR_TPA ## _L == VAR_TPA ## _R ){			\
	  ANSWER ## _prev = ANSWER ## _temp;				\
	  UPDATE_R;							\
	} else {							\
	  UPDATE_L;							\
	}								\
      } else {								\
	break;								\
      }									\
      on_TPA_prev = on_TPA;						\
    }									\
  }									\

#endif


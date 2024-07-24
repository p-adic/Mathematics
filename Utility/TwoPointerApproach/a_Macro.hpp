// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/a_Macro.hpp

#pragma once
#include "../StdStream/a_Macro.hpp"

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#ifndef TPA
// �ڎ��@�p
// VAR_TPA�͎ڎ��@�p�̕ϐ����̐ړ����ŁA���ۂ̕ϐ����ł͂Ȃ��A_L��_R��_info�����B
// ANSWER ## _temp = {VAR_TPA ## _L,VAR_TPA ## _R,,VPA_TPA ## _info}��{INIT,INIT,INFO_init}�ŏ���������BVPA_TPA ## _info�͋�Ԙa�ȂǁB
// ANSWER ## _temp��CONTINUE_CONDITION�𖞂�������AANSWER ## _temp������ON_CONDITION�𖞂������ۂ��𔻒肵�A
// ���ꂪtrue�ɂȂ邩VAR_TAR ## _L��VAR_TAR ## _R�ɒǂ��t���܂�VAR_TPA ## _L��VPA_TPA ## _info�̍X�V����UPDATE_L���J��Ԃ��A
// ���̌�VAR_TPA ## _R��VPA_TPA ## _info�̍X�V����UPDATE_R���s���B�i�}�N���ƃR���}�̐����A�֐��I�u�W�F�N�g��p����j
// ON_CONDITION��true�ƂȂ�ɑ��ԂƂ��̎��_�ł�info��ANSWER�Ɋi�[����B
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
    while( true ){								\
      bool continuing = CONTINUE_CONDITION;				\
      bool on_TPA = continuing && ( ON_CONDITION );			\
      CERR( continuing ? "�ڎ�蒆" : "�ڎ��I��" , "�F [L,R] = [" , VAR_TPA ## _L , "," , VAR_TPA ## _R , "] ," , on_TPA_prev ? "on" : "off" , "->" , on_TPA ? "on" : "off" , ", info =" , VAR_TPA ## _info );	\
      if( on_TPA_prev && ! on_TPA ){					\
	ANSWER.push_back( ANSWER ## _prev );				\
	CERR( #ANSWER , "��" , ANSWER ## _prev , "���i�[���܂��B" );	\
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

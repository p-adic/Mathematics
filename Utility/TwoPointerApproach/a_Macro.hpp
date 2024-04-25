// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/a_Macro.hpp

#pragma once

#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#ifndef TPA
// �ڎ��@�p
// VAR_TPA_L��VAR_TPA_R��INIT�ŏ��������AVAR_TPA_R��CONTINUE_CONDITION�𖞂�������A
// ���[VAR_TPA_L,VAR_TPA_R]������ON_CONDITION�𖞂������ۂ��𔻒肵�A
// true�ɂȂ邩VAR_TAR_L��VAR_TAR_R�ɒǂ��t���܂�VAR_TPA_L�̍X�V����UPDATE_L���J��Ԃ��A
// ���̌�VAR_TPA_R�̍X�V����UPDATE_R���s���B
// ON_CONDITION��true�ƂȂ�ɑ��ԂƂ��̎��_�ł�INFO��ANSWER�Ɋi�[����B
#define TPA( ANSWER , VAR_TPA , INIT , CONTINUE_CONDITION , UPDATE_L , UPDATE_R , ON_CONDITION , INFO ) \
  vector<tuple<decldecay_t( INIT ),decldecay_t( INIT ),decldecay_t( INFO )>> ANSWER{}; \
  {									\
    auto init_TPA = INIT;						\
    decldecay_t( ANSWER.front() ) ANSWER ## _temp = { init_TPA , init_TPA , INFO }; \
    auto ANSWER ## _prev = ANSWER ## _temp;				\
    auto& VAR_TPA ## _L = get<0>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _R = get<1>( ANSWER ## _temp );			\
    auto& VAR_TPA ## _info = get<2>( ANSWER ## _temp );			\
    bool on_TPA_prev = false;						\
    while( true ){							\
      bool continuing = CONTINUE_CONDITION;				\
      bool on_TPA = continuing && ( ON_CONDITION );			\
      CERR( continuing ? "�ڎ�蒆" : "�ڎ��I��" , "�F [L,R] = [" , VAR_TPA ## _L , "," , VAR_TPA ## _R , "] ," , on_TPA_prev ? "on" : "off" , "->" , on_TPA ? "on" : "off" , ", info =" , VAR_TPA ## _info );	\
      if( on_TPA_prev && ! on_TPA ){					\
	ANSWER.push_back( ANSWER ## _prev );				\
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

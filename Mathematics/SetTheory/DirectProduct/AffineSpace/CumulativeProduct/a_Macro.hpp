// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/a_Macro.hpp

#pragma once
// static_assert�ł�U=ll�̎���int���n���ꂽ���ɃR���p�C���G���[�ƂȂ�B
#define SFINAE_FOR_CP_BS enable_if_t<is_invocable_r_v<bool,F,U,int>>*

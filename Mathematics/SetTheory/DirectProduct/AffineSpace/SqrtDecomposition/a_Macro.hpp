// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/a_Macro.hpp

#pragma once

// static_assert�ł�U=ll�̎���int���n���ꂽ���ɃR���p�C���G���[�ƂȂ�B
#define SFINAE_FOR_SD_S enable_if_t<is_invocable_r_v<bool,F,U,int>>*

// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a.hpp

#pragma once

// ‡ŒvŒvZ—ÊO(p_i) = O(i log i)‚Å1+i”Ô–Ú‚Ì‘f”p_i‚ğ•Ô‚·
int GetPrime( const int& i );

// T=20‚È‚Ç‚Æ‚µAO(T(log n)^3)‚ÅŒë”»’è—¦‚ğ4^{-T}‚É—}‚¦‚é
bool MillerRabin( const int& n );

/*
 * =====================================================================================
 *
 *       Filename: focustype.hpp
 *        Created: 06/27/2017 11:39:59
 *  Last Modified: 07/06/2017 11:55:43
 *
 *    Description: 
 *
 *        Version: 1.0
 *       Revision: none
 *       Compiler: gcc
 *
 *         Author: ANHONG
 *          Email: anhonghe@gmail.com
 *   Organization: USTC
 *
 * =====================================================================================
 */

#pragma once
enum FocusType: int
{
    FOCUS_NONE   = 0,
    FOCUS_MOUSE,
    FOCUS_ATTACK,
    FOCUS_MAGIC,
    FOCUS_MAX,
};
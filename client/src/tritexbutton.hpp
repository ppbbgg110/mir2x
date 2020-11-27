/*
 * =====================================================================================
 *
 *       Filename: tritexbutton.hpp
 *        Created: 08/26/2016 13:20:23
 *    Description: button with three texture, it has a position shift when
 *                 state changes.
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
#include <cstdint>
#include <functional>
#include "buttonbase.hpp"

class TritexButton: public ButtonBase
{
    private:
        uint32_t m_texID[3];

    public:
        TritexButton(
                int argX,
                int argY,

                const uint32_t (&texID)[3],

                const std::function<void()> &fnOnOverIn  = nullptr,
                const std::function<void()> &fnOnOverOut = nullptr,
                const std::function<void()> &fnOnClick   = nullptr,

                int offXOnOver  = 0,
                int offYOnOver  = 0,
                int offXOnClick = 0,
                int offYOnClick = 0,

                bool    bOnClickDone = true,
                Widget *pwidget      = nullptr,
                bool    bFreewidget  = false,
                void   *dataPtr      = nullptr)
            : ButtonBase
              {
                  argX,
                  argY,
                  0,
                  0,

                  fnOnOverIn,
                  fnOnOverOut,
                  fnOnClick,

                  offXOnOver,
                  offYOnOver,
                  offXOnClick,
                  offYOnClick,

                  bOnClickDone,
                  pwidget,
                  bFreewidget,
                  dataPtr,
              }
            , m_texID
              {
                  texID[0],
                  texID[1],
                  texID[2],
              }
        {
            // hide PNGTexDB and SDLDevice
            // query texture size and setup the button size
            initButtonSize();
        }

    public:
        void drawEx(int,        // dst x on the screen coordinate
                int,            // dst y on the screen coordinate
                int,            // src x on the widget, take top-left as origin
                int,            // src y on the widget, take top-left as origin
                int,            // size to draw
                int) override;  // size to draw
    private:
        void initButtonSize();

    public:
        void setTexID(const uint32_t (&texID)[3])
        {
            for(int i: {0, 1, 2}){
                m_texID[i] = texID[i];
            }
        }
};

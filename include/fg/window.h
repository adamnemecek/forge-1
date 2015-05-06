/*******************************************************
 * Copyright (c) 2015-2019, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#pragma once
#include <fg/defines.h>
#include <fg/font.h>
#include <fg/image.h>
#include <fg/plot2d.h>
#include <fg/histogram.h>
#include <map>

namespace fg
{

class FGAPI Window {
    private:
        ContextHandle   mCxt;
        DisplayHandle   mDsp;
        int             mID;

        int             mWidth;
        int             mHeight;
        GLFWwindow*     mWindow;
        Font*           mFont;
        int             mRows;
        int             mCols;
        uint            mCellWidth;
        uint            mCellHeight;

        /* single context for all windows */
        GLEWContext* mGLEWContext;

    protected:
        Window() {}

    public:
        Window(int pWidth, int pHeight, const char* pTitle, const Window* pWindow=NULL);
        ~Window();

        ContextHandle context() const { return mCxt; }
        DisplayHandle display() const { return mDsp; }
        int width() const { return mWidth; }
        int height() const { return mHeight; }
        GLFWwindow* window() const { return mWindow; }
        GLEWContext* glewContext() const { return mGLEWContext; }

        void setFont(Font* pFont) { mFont = pFont; }

        /* draw functions */
        void draw(const Image& pImage);
        void draw(const Plot& pPlot);
        void draw(const Histogram& pHist);

        /* if the window render area is used to display
         * multiple Forge objects such as Image, Histogram, Plot etc
         * the following functions have to be used */
        void grid(int pRows, int pCols);
        void draw(int pColId, int pRowId,
                  const void* pRenderablePtr, Renderable pType,
                  const char* pTitle);
        void show();
};

FGAPI void makeCurrent(Window* pWindow);

}

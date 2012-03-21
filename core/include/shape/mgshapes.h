//! \file mgshapes.h
//! \brief 定义图形列表接口 MgShapes
// Copyright (c) 2004-2012, Zhang Yungui
// License: LGPL, https://github.com/rhcad/graph2d

#ifndef __GEOMETRY_MGSHAPES_H_
#define __GEOMETRY_MGSHAPES_H_

#include <mgshape.h>

//! 图形列表接口
/*! \ingroup _GEOM_SHAPE_
*/
struct MgShapes : public MgObject
{
    static UInt32 Type() { return 1; }

    virtual UInt32 getShapeCount() const = 0;
    virtual MgShape* getFirstShape(void*& it) const = 0;
    virtual MgShape* getNextShape(void*& it) const = 0;
    virtual MgShape* findShape(UInt32 id) const = 0;
    virtual Box2d getExtent() const = 0;

    virtual MgShape* hitTest(const Box2d& limits, Point2d& ptNear, Int32& segment) const = 0;
    virtual void draw(GiGraphics& gs, const GiContext *ctx = NULL) const = 0;

    virtual void clear() = 0;
    virtual MgShape* addShape(const MgShape& src) = 0;
};

#endif // __GEOMETRY_MGSHAPES_H_
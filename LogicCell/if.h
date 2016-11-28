/*
 * if.h
 *
 * Copyright (c) Thomas - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Thomas <tkchen@gmail.com>, Feb 6, 2016
 */

#ifndef LOGICCELL_IF_H_
#define LOGICCELL_IF_H_

#include <Engine/kernel.h>
#include <logiccell_config.h>

namespace Quantum {
namespace LogicCell {

class LOGICCELL_API If
{
public:
    If();
    static void declare_params(CellSockets&);
    static void declare_io(const CellSockets&, CellSockets&, CellSockets&);
    //void configure(const CellSockets&, const CellSockets&, const CellSockets&);
    ReturnCode process(const CellSockets&, const CellSockets&);
    const std::string return_msg(){return ret_msg_;}
private:
    std::string ret_msg_;
};

class LOGICCELL_API Print
{
public:
    Print();
    static void declare_params(CellSockets&);
    static void declare_io(const CellSockets&, CellSockets&, CellSockets&);
    //void configure(const CellSockets&, const CellSockets&, const CellSockets&);
    ReturnCode process(const CellSockets&, const CellSockets&);
    const std::string return_msg(){return ret_msg_;}
private:
    std::string ret_msg_;
};

class LOGICCELL_API Start
{
public:
    Start();
    static void declare_params(CellSockets &p){}
    static void declare_io(const CellSockets &p, CellSockets &i, CellSockets &o);
    //void configure(const CellSockets&, const CellSockets&, const CellSockets&);
    ReturnCode process(const CellSockets&, const CellSockets&);
    const std::string return_msg(){return ret_msg_;}
private:
    std::string ret_msg_;
};
}//namespace LogicCell
}//namespace Quantum



#endif /* LOGICCELL_IF_H_ */

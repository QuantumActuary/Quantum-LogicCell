/*
 * if.cpp
 *
 * Copyright (c) Thomas - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Thomas <tkchen@gmail.com>, Feb 6, 2016
 */

#include "LogicCell/if.h"

namespace Quantum {
namespace LogicCell {

If::If():ret_msg_("")
{}

void If::declare_params(CellSockets &p)
{}

void If::declare_io(const CellSockets &p, CellSockets &i, CellSockets &o)
{
    i.declare<bool>("condition", "A true or false condition");
    i["condition"]->required(true);
    i.declare<ReturnCode>(">>", "Execution flow");
    i[">>"]->required(true);
    i[">>"]->internal_use(true);

    o.declare<ReturnCode>("true >>", "Execute if true");
    o.declare<ReturnCode>("false >>", "Else execute if false");
}
/*
void If::configure(const CellSockets &p, const CellSockets &i,
        const CellSockets &o)
{}*/

ReturnCode If::process(const CellSockets& i, const CellSockets& o)
{
    if(i.get<bool>("condition"))
    {
        o["true >>"] << Quantum::OK;
    }
    else
    {
        o["false >>"] << Quantum::OK;
    }
    return Quantum::OK;
}

Print::Print():ret_msg_(""){}

void Print::declare_params(CellSockets &p){}

void Print::declare_io(const CellSockets &p, CellSockets &i, CellSockets &o)
{
    i.declare<ReturnCode>(">>", "", Quantum::UNKNOWN);
    i[">>"]->required(true);
    i[">>"]->internal_use(true);
    i.declare<std::string>("msg", "", "Hello World!");

    o.declare<ReturnCode>(">>", "", Quantum::UNKNOWN);
}

ReturnCode Print::process(const CellSockets &i, const CellSockets &o)
{
    std::cout<<i.get<std::string>("msg")<<std::endl;
    o[">>"] << Quantum::OK;
    return Quantum::OK;
}

Start::Start():ret_msg_(""){}

void Start::declare_io(const CellSockets &p, CellSockets &i, CellSockets &o)
{
    o.declare<ReturnCode>(">>", "", Quantum::OK);
}

ReturnCode Start::process(const CellSockets &i, const CellSockets &o)
{
    o[">>"] << Quantum::OK;
    return Quantum::OK;
}

}//namespace SymCell
}//namespace Quantum



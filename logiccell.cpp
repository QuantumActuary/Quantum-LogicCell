/*
 * Copyright (c) Thomas Chen - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Thomas Chen <tkchen@gmail.com>, August 2015
 *
 * logiccell.cpp
 */

#include "logiccell.h"

#include "LogicCell/if.h"

extern "C" LOGICCELL_API int getEngineVersion()
{
    return 1;
}

extern "C" LOGICCELL_API void registerPlugin(Quantum::Kernel &kernel)
{
    using namespace Quantum;
    std::vector<cell_ptr> cells_to_add;

    Cell_<LogicCell::If>::SHORT_DOC = "If/Else";
    Cell_<LogicCell::If>::MODULE_NAME = "LogicCellPlugin";
    Cell_<LogicCell::If>::CELL_NAME = "If";
    cells_to_add.push_back(std::shared_ptr<Cell>(new Cell_<LogicCell::If>()));
    cells_to_add[0]->categories.push_back("Flow Control");

    Cell_<LogicCell::Print>::SHORT_DOC = "Printer";
    Cell_<LogicCell::Print>::MODULE_NAME = "LogicCellPlugin";
    Cell_<LogicCell::Print>::CELL_NAME = "Print";
    cells_to_add.push_back(std::shared_ptr<Cell>(new Cell_<LogicCell::Print>()));
    cells_to_add[1]->categories.push_back("Utility");

    Cell_<LogicCell::Start>::SHORT_DOC = "Starter";
    Cell_<LogicCell::Start>::MODULE_NAME = "LogicCellPlugin";
    Cell_<LogicCell::Start>::CELL_NAME = "Start";
    cells_to_add.push_back(std::shared_ptr<Cell>(new Cell_<LogicCell::Start>()));
    cells_to_add[2]->categories.push_back("Flow Control");

    for(cell_ptr c: cells_to_add)
    {
        c->init();
        kernel.getCellRegistry().addCell(c, c->metadata["name"]->get<std::string>());
    }
    //setup gtest parameters
    /*
    int argc = 2;
    char file[] = "dummy.dylib"; //this doesn't do anything
    char arg[] = "--gtest_color=true";
    char* option[2] = {file, arg};
    ::testing::InitGoogleTest(&argc, option);
    */
}

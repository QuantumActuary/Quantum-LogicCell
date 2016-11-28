/*
 * test_flow_control.hpp
 *
 * Copyright (c) Thomas - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Thomas <tkchen@gmail.com>, Feb 6, 2016
 */

#ifndef TESTS_TEST_FLOW_CONTROL_HPP_
#define TESTS_TEST_FLOW_CONTROL_HPP_

#include "Engine/all.hpp"
#include "Engine/omp_scheduler.hpp"
#include "gtest/gtest.h"

#include "LogicCell/if.h"

namespace Quantum{

TEST(LogicCell, If_cell)
{
    cell_ptr iffy = std::make_shared<Cell_<LogicCell::If>>();
    iffy->declare_params();
    iffy->declare_io();
    iffy->inputs[">>"] << Quantum::OK;
    iffy->inputs["condition"] << true;
    iffy->process();
    EXPECT_EQ(Quantum::OK, iffy->outputs.get<ReturnCode>("true >>"));
    iffy->inputs["condition"] << false;
    iffy->process();
    EXPECT_EQ(Quantum::OK, iffy->outputs.get<ReturnCode>("false >>"));
}
}//Quantum namespace



#endif /* TESTS_TEST_FLOW_CONTROL_HPP_ */

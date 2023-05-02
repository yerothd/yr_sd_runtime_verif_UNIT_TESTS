/*
 * yr_monitor_test_1.cpp
 *
 *      Author: PROF. DR.-ING. XAVIER NOUMBISSI NOUNDOU
 */

#include <QtTest/QtTest>

#include <QtCore/QDebug>

#include "YR_UTILS_GENERATOR_MONITOR_TEST.hpp"


int main(int argc, char *argv[])
{
	YR_UTILS_GENERATOR_MONITOR_TEST test_YR;

	int test_YR_ret_value = QTest::qExec (&test_YR, argc, argv);

	qDebug() << "Test_YerothUtils" << test_YR_ret_value;

	return 0;
}


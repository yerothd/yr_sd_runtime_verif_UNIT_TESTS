/*
 * YR_UTILS_GENERATOR_MONITOR_TEST.hpp
 *
 *      Author: PROF. DR.-ING. XAVIER NOUMBISSI NOUNDOU
 */


#ifndef YR_SD_RUNTIME_VERIF_UNIT_TEST_GENERATOR_TEST_HPP_
#define YR_SD_RUNTIME_VERIF_UNIT_TEST_GENERATOR_TEST_HPP_


#include "../yr_sd_runtime_verif/src/YR_CPP_MONITOR_EDGE.hpp"

#include "../yr_sd_runtime_verif/src/YR_CPP_MONITOR.hpp"


#include <QtTest/QtTest>

#include <QtCore/QObject>

#include <QtCore/QDebug>


class YR_UTILS_GENERATOR_MONITOR_TEST : public QObject
{
	Q_OBJECT

public:

	void initTestCase();

	void cleanupTestCase();

	YR_UTILS_GENERATOR_MONITOR_TEST()
	{
	}

	virtual ~YR_UTILS_GENERATOR_MONITOR_TEST();

private slots:

	void CREATE_A_RUNTIME_MONITOR_TEST();

	void CREATE_A_RUNTIME_MONITOR_EDGE_TEST();

	void CREATE_A_RUNTIME_MONITOR_STATE_TEST();

	void FIND_A_RUNTIME_MONITOR_EDGE_TEST();

	void _YR_TRIGGER_guarded_condition_EDGE_TEST();

	void _YR_TRIGGER_A_RUNTIME_MONITOR_EDGE_TEST();

	void DOT_PRINT_VIEW_RUNTIME_MONITOR_TEST();

	void DOT_PRINT_2_VIEW_RUNTIME_MONITOR_TEST();

	void _YR_EXPORT_CLASSES_headers_TEST();

	void _YR_EXPORT_CLASSES_SOURCES_TEST();

protected:

	static QString C_STATE;

	static QString D_STATE;

	static QString E_STATE;

	static QString C_D_state_transition_EVENT_TOKEN;

	static QString D_E_state_transition_EVENT_TOKEN;

	static YR_CPP_MONITOR_STATE *_a_root_STATE;

	static YR_CPP_MONITOR_EDGE *_an_edge_TEST;

	static YR_CPP_MONITOR *_A_RUNTIME_MONITOR_FOR_TESTING;
};


#define YR_QVERIFY2_QSTRING(B, QS) QVERIFY2(B, GET_C_STR_FROM_QSTRING(QS))


#endif //YR_SD_RUNTIME_VERIF_UNIT_TEST_GENERATOR_TEST_HPP_



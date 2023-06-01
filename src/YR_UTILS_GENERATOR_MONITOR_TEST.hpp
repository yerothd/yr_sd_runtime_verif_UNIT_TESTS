/*
 * YR_UTILS_GENERATOR_MONITOR_TEST.hpp
 *
 *      Author: PROF. DR.-ING. XAVIER NOUMBISSI NOUNDOU
 */

#include "../yr_sd_runtime_verif/src/YR_CPP_MONITOR_EDGE.hpp"

#include "../yr_sd_runtime_verif/src/YR_CPP_MONITOR.hpp"


#include <QtTest/QtTest>

#include <QtCore/QObject>

#include <QtCore/QDebug>


class YR_UTILS_GENERATOR_MONITOR_TEST : public QObject
{
	Q_OBJECT

public:

	YR_CPP_CLASS_OPERATORS

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

	void _YR_TRIGGER_A_RUNTIME_MONITOR_EDGE_TEST();

	void DOT_PRINT_VIEW_RUNTIME_MONITOR_TEST();

	void DOT_PRINT_2_VIEW_RUNTIME_MONITOR_TEST();

	void _YR_EXPORT_CLASSES_headers_TEST();

	void _YR_EXPORT_CLASSES_SOURCES_TEST();

protected:

	static QString D_STATE;

	static QString E_STATE;

	static QString AN_EDGE_EVENT_TOKEN;

	static YR_CPP_MONITOR_STATE *_a_root_STATE;

	static YR_CPP_MONITOR_EDGE *_an_edge_TEST;

	static YR_CPP_MONITOR *_A_RUNTIME_MONITOR_FOR_TESTING;
};



/*
 * YR_UTILS_GENERATOR_MONITOR_TEST.cpp
 *
 *      Author: PROF. DR.-ING. XAVIER NOUMBISSI NOUNDOU
 */

#include "YR_UTILS_GENERATOR_MONITOR_TEST.hpp"

#include "../yr_sd_runtime_verif/src/YR_CPP_MONITOR_STATE.hpp"

QString YR_UTILS_GENERATOR_MONITOR_TEST::D_STATE = "D";

QString YR_UTILS_GENERATOR_MONITOR_TEST::E_STATE = "E";


YR_CPP_MONITOR_STATE *YR_UTILS_GENERATOR_MONITOR_TEST::_a_root_STATE = 0;

YR_CPP_MONITOR_EDGE *YR_UTILS_GENERATOR_MONITOR_TEST::_an_edge_TEST = 0;


YR_CPP_MONITOR *YR_UTILS_GENERATOR_MONITOR_TEST::_A_RUNTIME_MONITOR_FOR_TESTING = 0;


void YR_UTILS_GENERATOR_MONITOR_TEST::initTestCase()
{
	QVERIFY (0 != _A_RUNTIME_MONITOR_FOR_TESTING);
}


void YR_UTILS_GENERATOR_MONITOR_TEST::cleanupTestCase()
{
}


YR_UTILS_GENERATOR_MONITOR_TEST::~YR_UTILS_GENERATOR_MONITOR_TEST()
{
	if (0 != _A_RUNTIME_MONITOR_FOR_TESTING)
	{
		delete _A_RUNTIME_MONITOR_FOR_TESTING;

		_A_RUNTIME_MONITOR_FOR_TESTING = 0;
	}
}


void YR_UTILS_GENERATOR_MONITOR_TEST::CREATE_A_RUNTIME_MONITOR_TEST()
{
	//qDebug() << "START YR MONITOR TEST";

	QString YR_RUNTIME_3 = "YR_RUNTIME_3";

	_A_RUNTIME_MONITOR_FOR_TESTING = YR_CPP_MONITOR::CREATE_MONITOR(YR_RUNTIME_3);

	QVERIFY (0 != _A_RUNTIME_MONITOR_FOR_TESTING);

	QString ERROR_MESSAGE_WHEN_TEST_FAILS =
			QString("%1 VS. %2")
				.arg(YR_RUNTIME_3,
					 _A_RUNTIME_MONITOR_FOR_TESTING->get_RUNTIME_MONITOR_NAME());

	bool RUNTIME_MONITOR_NAME_FINE =
			YR_CPP_UTILS::isEqualCaseInsensitive(YR_RUNTIME_3,
					_A_RUNTIME_MONITOR_FOR_TESTING->get_RUNTIME_MONITOR_NAME());

	QVERIFY2 (RUNTIME_MONITOR_NAME_FINE, ERROR_MESSAGE_WHEN_TEST_FAILS.toStdString().c_str());
}


void YR_UTILS_GENERATOR_MONITOR_TEST::CREATE_A_RUNTIME_MONITOR_EDGE_TEST()
{
	//qDebug() << "RUNTIME MONITOR INSTANTIATED";

	_an_edge_TEST = 0;

	_an_edge_TEST = _A_RUNTIME_MONITOR_FOR_TESTING->create_yr_monitor_edge(E_STATE, D_STATE);

	QVERIFY (0 != _an_edge_TEST);

	YR_CPP_MONITOR_EVENT *an_event = _an_edge_TEST->set_EDGE_EVENT("'yeroth()'");

	QVERIFY (0 != an_event);

	_a_root_STATE = _an_edge_TEST->get_SOURCE_STATE();

	QVERIFY (0 != _a_root_STATE);

	_a_root_STATE->set_START_STATE(true);

	if (_an_edge_TEST->get_TARGET_STATE())
	{
		_an_edge_TEST->get_TARGET_STATE()->set_FINAL_STATE(true);
	}

	YR_CPP_MONITOR_EDGE * a_root_edge =
			_A_RUNTIME_MONITOR_FOR_TESTING
						->create_yr_monitor_edge(YR_CPP_UTILS::EMPTY_STRING,
												 _a_root_STATE->get_MONITOR_STATE_NAME());

	QVERIFY2 (0 != a_root_edge, "a_root_edge = 0");

	_A_RUNTIME_MONITOR_FOR_TESTING->set_yr_root_edge(a_root_edge);

	QVERIFY2 (0 != _A_RUNTIME_MONITOR_FOR_TESTING->get_current_triggered_EDGE(),
			  "CURRENT TRIGGERED EDGE IS 0 (NULL) !");

	QVERIFY2 (_A_RUNTIME_MONITOR_FOR_TESTING->get_current_triggered_EDGE() == a_root_edge,
			  "CURRENT TRIGGERED EDGE IS NOT MATCHING !");
}


void YR_UTILS_GENERATOR_MONITOR_TEST::CREATE_A_RUNTIME_MONITOR_STATE_TEST()
{
	YR_CPP_MONITOR_STATE *_a_test_ut_state;

	_a_test_ut_state =
		_A_RUNTIME_MONITOR_FOR_TESTING->create_yr_monitor_state(E_STATE);

	YR_QVERIFY2_QSTRING(0 != _a_test_ut_state,
						QString("NO EXISTING STATE: '%1' found !").arg(E_STATE));


	YR_QVERIFY2_QSTRING(YR_CPP_UTILS::isEqualCaseInsensitive(E_STATE,
							_a_test_ut_state->get_MONITOR_STATE_NAME()),
						QString("RETURNED A WRONG EXISTING STATE: '%1'!")
							.arg(_a_test_ut_state->get_MONITOR_STATE_NAME()));
}


void YR_UTILS_GENERATOR_MONITOR_TEST::_YR_TRIGGER_A_RUNTIME_MONITOR_EDGE_TEST()
{
	QList<YR_CPP_MONITOR_EDGE *> resulting_edges;

	_A_RUNTIME_MONITOR_FOR_TESTING
		->find_yr_monitor_edges(E_STATE,
						  	    D_STATE,
								resulting_edges);

	QVERIFY2 (resulting_edges.size() > 0, "COULDN'T FIND A 'yeroth()' EDGE");

	QVERIFY (0 != resulting_edges.at(0));

	bool TRIGGERED =
	_A_RUNTIME_MONITOR_FOR_TESTING
		->YR_trigger_an_edge_event("'yeroth()'",
								   resulting_edges.at(0)->get_guarded_CONDITION_expression());

	QVERIFY2 (true == TRIGGERED, "EDGE COULDLN'T BE TRIGGERED");

	YR_CPP_MONITOR_STATE *a_current_state = _A_RUNTIME_MONITOR_FOR_TESTING->get_current_MONITOR_STATE();

	QVERIFY2 (0 != a_current_state, "[2] CURRENT STATE IS 0 (NULL) !");

	QVERIFY2 (YR_CPP_UTILS::isEqualCaseInsensitive(a_current_state->get_MONITOR_STATE_NAME(), D_STATE),
			  QString("CURRENT STATE IS NOT: '%1'")
			  	  .arg(D_STATE).toStdString().c_str());
}


void YR_UTILS_GENERATOR_MONITOR_TEST::DOT_PRINT_VIEW_RUNTIME_MONITOR_TEST()
{
	QString dot_file_content = _A_RUNTIME_MONITOR_FOR_TESTING->print_TO_dot_FILE();

	QVERIFY (!dot_file_content.isEmpty());
}


void YR_UTILS_GENERATOR_MONITOR_TEST::DOT_PRINT_2_VIEW_RUNTIME_MONITOR_TEST()
{
	QString dot_file_content = _A_RUNTIME_MONITOR_FOR_TESTING->print_TO_dot_FILE("YR_RUNTIME_TEST_DOT_PRINT");

	QVERIFY (!dot_file_content.isEmpty());
}


void YR_UTILS_GENERATOR_MONITOR_TEST::_YR_EXPORT_CLASSES_headers_TEST()
{
	QString header_FILE_content =
			_A_RUNTIME_MONITOR_FOR_TESTING
				->YR_generate_cplusplus_headers_files__AND__SAVE__TO__DISK();

//	qDebug() << "header file content: "
//			 << header_FILE_content;
}


void YR_UTILS_GENERATOR_MONITOR_TEST::_YR_EXPORT_CLASSES_SOURCES_TEST()
{
	QString SOURCE_FILE_content =
			_A_RUNTIME_MONITOR_FOR_TESTING
				->YR_generate_cplusplus_sources_files__AND__SAVE__TO__DISK();

//	qDebug() << "SOURCE FILE CONTENT: "
//			 << SOURCE_FILE_content;
}


void YR_UTILS_GENERATOR_MONITOR_TEST::FIND_A_RUNTIME_MONITOR_EDGE_TEST()
{
	QVERIFY (0 != _an_edge_TEST);

	QList<YR_CPP_MONITOR_EDGE *> resulting_edges;

	_A_RUNTIME_MONITOR_FOR_TESTING->find_yr_monitor_edges(*_an_edge_TEST, resulting_edges);

	//qDebug() << "resulting_edges.size(): " << resulting_edges.size();

	QVERIFY (1 == resulting_edges.size());
}




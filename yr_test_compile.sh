#!/bin/bash


./yr_DEPLOY_FOR_lang_UNIT_TESTS-development.sh

TEST_YR_FILE_OUTPUT="TEST_YR_RESULTS.TXT"

CUR_DIR="$(pwd)"

YR_LIB_MONITOR_GENERATION_DIR="${CUR_DIR}/yr_sd_runtime_verif"

YR_TEST_DIR="${CUR_DIR}"

cd "${YR_LIB_MONITOR_GENERATION_DIR}" 

yr_compile_TESTING_j8.sh

if [ ! $? ]; then
	echo "compilation of yr_sd_runtime_verif FAILED !"
	exit 1
fi

cd "${YR_TEST_DIR}"

clear && qmake && make clean && make -j2 && \
	cd "${CUR_DIR}" && \
	bin/yr_monitor_test_1 > "${TEST_YR_FILE_OUTPUT}" 2>&1 && \
  run-test-yr-coverage-gen-html.sh 


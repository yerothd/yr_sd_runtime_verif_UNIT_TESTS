#!/bin/sh
#@author: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU

############################################################################################################
# You should edit the following 3 paths when necessary
############################################################################################################

# Get the path to the current folder
SCRIPT_DIR=$(dirname $0)

# SRC_DIR is the directory containing the .gcno files (%{buildDir} in Qt Creator)
SRC_DIR="${HOME}/yr_sd_runtime_verif_UNIT_TESTS/yr_sd_runtime_verif"

# COV_DIR is the directory where the coverage results will be stored
COV_DIR="${SRC_DIR}/yr-tests-coverage-information"

############################################################################################################

# Path where the HTML files should be saved
HTML_RESULTS="${COV_DIR}""/html"

rm -rf "${COV_DIR}"

# Create the html folder if it does not exists
mkdir -p ${HTML_RESULTS}

# Generate our initial info
lcov \
	--rc lcov_branch_coverage=1 \
	-d "${SRC_DIR}" \
	-c -o "${COV_DIR}/yr-tests-coverage.info"
 
# Remove some paths/files which we don't want to calculate the code coverage (e.g. third party libraries) and generate a new coverage file filtered (feel free to edit it when necessary)
lcov -r "${COV_DIR}/yr-tests-coverage.info" \
	"*Qt*.framework*" \
	"*.h" \
	"*/tests/*" "*.moc" "moc_*" "*moc_*.cpp" "*/test/*" "*/build*/*" \
	--rc lcov_branch_coverage=1 \
	-o "${COV_DIR}/yr-tests-coverage-filtered.info"

# Generate the HTML files
genhtml -o "${HTML_RESULTS}" \
	--title "JH_NISSI_COVERAGE" \
	--demangle-cpp \
	--num-spaces 2 \
	--sort \
	--rc genhtml_branch_coverage=1 \
	--function-coverage \
	--branch-coverage \
	--legend \
	"${COV_DIR}/yr-tests-coverage-filtered.info"
 
# Reset our counts
lcov -d "${COV_DIR}" -z
 
# Open the index.html
firefox-esr "${HTML_RESULTS}/index.html"&

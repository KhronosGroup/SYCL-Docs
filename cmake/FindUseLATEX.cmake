find_path(USE_LATEX_DIR UseLATEX.cmake)

if(USE_LATEX_DIR)
	file(STRINGS "${USE_LATEX_DIR}/UseLATEX.cmake" USE_LATEX_VERSION_LINE REGEX "^#[ \t]+Version:[ \t]+")
	string(REGEX REPLACE "# Version: ([0-9]+\\.[0-9]+\\.[0-9]+)$" "\\1" USE_LATEX_VERSION "${USE_LATEX_VERSION_LINE}")
	unset(USE_LATEX_VERSION_LINE)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(UseLATEX
	REQUIRED_VARS USE_LATEX_DIR
	VERSION_VAR USE_LATEX_VERSION)

if(UseLATEX_FOUND)
	include("${USE_LATEX_DIR}/UseLATEX.cmake")
	mark_as_advanced(USE_LATEX_DIR)
endif()

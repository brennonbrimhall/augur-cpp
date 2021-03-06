cmake_minimum_required (VERSION 3.1)

project (augur VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

include(FindOpenMP)

if(OPENMP_FOUND)
	option(USE_OPENMP "Use OpenMP to parallelize the computation." ON)
	if(USE_OPENMP)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
	endif(USE_OPENMP)
endif(OPENMP_FOUND)

add_executable(augur main.cpp Parser.cpp Event.cpp Match.cpp Node.cpp Root.cpp Team.cpp)

install(TARGETS augur
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

install(FILES "${CMAKE_SOURCE_DIR}/License.txt"
	DESTINATION license
	PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)

install(FILES "${CMAKE_SOURCE_DIR}/tvr_matches.csv" "${CMAKE_SOURCE_DIR}/tvr_teams.csv"
	DESTINATION examples
	PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)

SET(CPACK_PACKAGE_VENDOR "Brennon Brimhall")

set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 1)

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/License.txt")

include(CPack)

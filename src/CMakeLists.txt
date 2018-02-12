add_executable(augur main.cpp Parser.cpp Event.cpp Match.cpp Node.cpp Root.cpp Team.cpp)

install(TARGETS augur
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
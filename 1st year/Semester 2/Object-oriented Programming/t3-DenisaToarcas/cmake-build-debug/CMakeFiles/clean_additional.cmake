# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\test3-DenisaToarcas_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\test3-DenisaToarcas_autogen.dir\\ParseCache.txt"
  "test3-DenisaToarcas_autogen"
  )
endif()

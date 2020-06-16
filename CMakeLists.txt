set(qhidapi_files
   hidapi.h
   qhidapi_global.h
   qhidapi.cpp qhidapi.h
   qhidapi_p.cpp qhidapi_p.h
   qhiddeviceinfomodel.cpp qhiddeviceinfomodel.h
   qhiddeviceinfoview.cpp qhiddeviceinfoview.h
)
set(unix_files linux/hid.c)
set(mac_files mac/hid.c)
set(win_files windows/hid.c)
set(other_os_files libusb/hid.c)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
   set(src_files "${qhidapi_files};${unix_files}")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
   set(src_files "${qhidapi_files};${win_files}")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
   set(src_files "${qhidapi_files};${mac_files}")
else()
   set(src_files "${qhidapi_files};${other_os_files}")
endif()

# yaml-cpp library
find_library(yamlcpp NAMES yaml-cpp)
find_library(qyamlcpp NAMES qyamlcpp)

add_library(qhidapi STATIC
   "${src_files}"
   )

# Not including doxygen stuff here because the original yaml-cpp
# doesn't have any either so in the same way I included a README.md
# file instead
# DOxygen stuff
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_MAN NO)

include(FindDoxygen)
doxygen_add_docs(
  docs
  ${CMAKE_SOURCE_DIR}
  COMMENT "Generate HTML documentation"
  )

target_link_libraries(qhidapi sm_widgets Qt5::Core Qt5::Gui Qt5::Widgets)
target_include_directories(qhidapi PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)


file(GLOB doxy_body/* DOXY_SRC)

add_custom_command(OUTPUT ${goby_SHARE_DIR}/doc/goby-dev.pdf
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/doxy2pdf.sh
  ARGS ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${goby_SHARE_DIR}/doc/goby-dev.pdf
  DEPENDS goby_acomms goby_util goby_common goby_moos goby-dev.doxy.in ${DOXY_SRC}
)

add_custom_command(OUTPUT ${goby_SHARE_DIR}/doc/html/index.html
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/doxy2html.sh
  ARGS ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS goby_acomms goby_util goby_common goby_moos goby-dev.doxy.in ${DOXY_SRC}
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/goby-dev.doxy.in ${CMAKE_CURRENT_BINARY_DIR}/goby-dev.doxy @ONLY)

option(build_doc_pdf "Build PDF Developers Documentation" OFF)

if(build_doc_pdf)
  add_custom_target(dev-pdf ALL DEPENDS ${goby_SHARE_DIR}/doc/goby-dev.pdf)
endif()

option(build_doc_html "Build HTML Developers Documentation" ON)

if(build_doc_html)
  add_custom_target(dev-html ALL DEPENDS ${goby_SHARE_DIR}/doc/html/index.html)
endif()

set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${goby_SHARE_DIR}/doc/html)

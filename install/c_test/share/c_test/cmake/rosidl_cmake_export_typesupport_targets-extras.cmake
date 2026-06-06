# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:c_test__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:c_test__rosidl_typesupport_fastrtps_c;__rosidl_generator_cpp:c_test__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:c_test__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_c:c_test__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:c_test__rosidl_typesupport_c;__rosidl_typesupport_introspection_cpp:c_test__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:c_test__rosidl_typesupport_cpp;__rosidl_generator_py:c_test__rosidl_generator_py")

# populate c_test_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "c_test::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'c_test' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND c_test_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()

# function(add_sanitizer_flags enable_sanitize_addr enable_sanitize_undef)
#     if (NOT enable_sanitize_addr AND NOT enable_sanitize_undef)
#         message(STATUS "Sanitizers deactivated.")
#         return()
#     endif()

#     if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
#         add_compile_options("-fno-omit-frame-pointer")
#         add_link_options("-fno-omit-frame-pointer")

#         if(enable_sanitize_addr)
#             add_compile_options("-fsanitize=address")
#             add_link_options("-fsanitize=address")
#         endif()

#         if(enable_sanitize_undef)
#             add_compile_options("-fsanitize=undefined")
#             add_link_options("-fsanitize=undefined")
#         endif()

#         if(ENABLE_THREAD_SANITIZER)
#             add_compile_options("-fsanitize=thread")
#             add_link_options("-fsanitize=thread")
#             message(STATUS "Thread sanitizer enabled")
#         else()
#             message(STATUS "Thread sanitizer not enabled")
#         endif()

#     elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
#         if(enable_sanitize_addr)
#             add_compile_options("/fsanitize=address")
#         endif()

#         if(enable_sanitize_undef)
#             message(STATUS "Undefined sanitizer not impl. for MSVC!")
#         endif()
#     else()
#         message(STATUS "Sanitizer not supported in this environment!")
#     endif()
# endfunction(add_sanitizer_flags)





function(add_sanitizer_flags)
    if(NOT ENABLE_ADDRESS_SANITIZER AND NOT ENABLE_UNDEFINED_SANITIZER)
        return()
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES
                                                "GNU")
        add_compile_options("-fno-omit-frame-pointer")
        add_link_options("-fno-omit-frame-pointer")

        if(ENABLE_ADDRESS_SANITIZER)
            message(STATUS "Activating Address Sanitizer")
            add_compile_options("-fsanitize=address")
            add_link_options("-fsanitize=address")
        endif()

        if(ENABLE_UNDEFINED_SANITIZER)
            message(STATUS "Activating Undefined Sanitizer")
            add_compile_options("-fsanitize=undefined")
            add_link_options("-fsanitize=undefined")
        endif()

        if(ENABLE_LEAK_SANITIZER)
            add_compile_options("-fsanitize=leak")
            add_link_options("-fsanitize=leak")
        endif()

        if(ENABLE_THREAD_SANITIZER)
            if(ENABLE_ADDRESS_SANITIZER OR ENABLE_LEAK_SANITIZER)
                message(WARNING "thread does not work with: address and leak")
            endif()
            message(STATUS "Activating Thread Sanitizer")
            add_compile_options("-fsanitize=thread")
            add_link_options("-fsanitize=thread")
        endif()
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        if(ENABLE_ADDRESS_SANITIZER)
            message(STATUS "Activating Address Sanitizer")
            add_compile_options("/fsanitize=address")
        endif()

        if(ENABLE_UNDEFINED_SANITIZER)
            message(STATUS "sanitize=undefined not available for MSVC")
        endif()

        if(ENABLE_LEAK_SANITIZER)
            message(STATUS "sanitize=leak not available for MSVC")
        endif()

        if(ENABLE_THREAD_SANITIZER)
            message(STATUS "sanitize=thread not available for MSVC")
        endif()
    else()
        message(WARNING "This sanitizer not supported in this environment")
        return()
    endif()
endfunction(add_sanitizer_flags)

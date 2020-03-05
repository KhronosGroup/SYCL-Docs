# Copyright (c) 2011-2020 The Khronos Group, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

find_package(Git)
if(GIT_FOUND)
    execute_process(COMMAND ${GIT_EXECUTABLE} describe --all --dirty --long
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE git_tag_description
        OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

latex_get_output_path(output_dir)
configure_file(version_config.tex.in "${output_dir}/version_config.tex" @ONLY)
configure_file(git_description.tex.in "${output_dir}/git_description.tex" @ONLY)

set(headers
    accessMode.h
    accessorBuffer.h
    accessorImage.h
    accessorLocal.h
    accessTarget.h
    atomic.h
    atomicoperations.h
    buffer.h
    commandGroup.h
    commandGroupHandler.h
    common-byval.h
    common-reference.h
    context.h
    contextInfo.h
    deviceEvent.h
    device.h
    deviceInfo.h
    deviceSelector.h
    deviceSelectorInterface.h
    event.h
    eventInfo.h
    exception.h
    group.h
    hitem.h
    id.h
    image.h
    item.h
    kernelInfo.h
    kernelWIP.h
    multipointer.h
    nditem.h
    ndRange.h
    openclcInterop.h
    parallelFor.h
    paramTraits.h
    platform.h
    platformInfo.h
    pointer.h
    priv.h
    programInfo.h
    programWIP.h
    properties.h
    queue.h
    queueInfo.h
    range.h
    sampler.h
    stlclasses.h
    stream.h
    synchronization.h
    vec.h
)
list(TRANSFORM headers PREPEND "headers/")

set(code
    anatomy.cpp
    basicparallelfor.cpp
    basicParallelForItem.cpp
    explicitcopy.cpp
    largesample.cpp
    myfunctor.cpp
    mykernel.cpp
    myprogram.cpp
    myprogramlink.cpp
    parallelforbarrier.cpp
    parallelfor.cpp
    parallelforworkgroup2.cpp
    parallelforworkgroup.cpp
    propertyExample.cpp
    singletask.cpp
    syclkernel.cpp
)
list(TRANSFORM code PREPEND code/)

foreach(dep ${headers} ${code})
    add_custom_command(
        OUTPUT ${dep}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/${dep}
            ${output_dir}/${dep}
    )
endforeach()

set(latex_dep_headers ${headers})
set(latex_dep_code ${code})
list(TRANSFORM latex_dep_headers PREPEND "${CMAKE_CURRENT_BINARY_DIR}/")
list(TRANSFORM latex_dep_code PREPEND "${output_dir}/")

add_latex_document(
    sycl-1.2.1.tex
    INPUTS
        accessors.tex
        acknowledgements.tex
        architecture.tex
        builtin_functions.tex
        compiler_abi.tex
        conf.tex
        descriptors.tex
        device_class.tex
        device_to_device.tex
        expressingParallelism.tex
        extensions.tex
        glossary.tex
        host_acc.tex
        introduction.tex
        overlap.tex
        programming_interface.tex
        queue_class.tex
        sycl_explicit_memory.tex
        three_cg_one_queue.tex
        three_cg_three_queue.tex
        vec_class.tex
    BIBFILES
        references.bib
    IMAGES
        logos/Khronos_Tagline_500px_June18.png
        logos/SYCL_RGB_June16-inkscape-1500.png
    DEPENDS
        ${latex_dep_headers} ${latex_dep_code}
        "${output_dir}/version_config.tex"
        "${output_dir}/git_description.tex"
)

install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sycl-1.2.1.pdf" DESTINATION share/doc/sycl/${SYCLVERSION}
    RENAME sycl-${SYCLVERSION}-${SYCLREVISION}.pdf
)

function(install_symlink from to)
    install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink \
        ${from} ${to} WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX})")
    install(CODE "message(STATUS \"Install symlink: ${from} -> ${to}\")")
endfunction()

install_symlink(sycl-${SYCLVERSION}-${SYCLREVISION}.pdf
                share/doc/sycl/${SYCLVERSION}/sycl-${SYCLVERSION}.pdf)
install_symlink(${SYCLVERSION}/sycl-${SYCLVERSION}.pdf
                share/doc/sycl/sycl.pdf)

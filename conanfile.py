from conans import ConanFile, CMake, tools
from conans.tools import load
import re


def get_version():
    try:
        content = load("sycl_version.txt")
        version = re.search("SYCLVERSION=(.*)", content).group(1)
        revision = re.search("SYCLREVISION=(.*)", content).group(1)
        return f"{version.strip()}-{revision.strip()}"
    except Exception as e:
        return None


class SYCLSpecificationConan(ConanFile):
    name = "sycl"
    version = get_version()
    license = "CC-BY-4.0"
    author = "Khronos Group"
    url = "https://github.com/KhronosGroup/SYCL-Docs"
    default_user = "khronos"
    default_channel = "master"
    scm = {
        "type": "git",
        "url": "auto",
        "revision": "auto",
        "subfolder": "SYCL-Docs"
    }
    description = "SYCL API, Extensions, and Environment Spec sources"
    topics = ("khronos", "sycl", "spec", "specification", "gpu", "c++")
    generators = "cmake_paths"
    no_copy_source = True

    build_requires = "uselatex/2.4.9@mmha/stable"

    def system_requirements(self):
        pack_names = []
        os_info = tools.OSInfo()
        if os_info.with_apt:
            pack_names = [
                "texlive-latex-extra", "texlive-fonts-recommended",
                "texlive-generic-recommended", "texlive-publishers"
            ]
        elif os_info.with_pacman:
            pack_names = ["texlive-latexextra", "texlive-publishers"]
        elif os_info.with_yum:
            pack_names = [
                "texlive-collection-latexextra", "texlive-wasysym",
                "tex(ulem.sty)", "texlive-collection-publishers"
            ]

        for package in pack_names:
            installer = tools.SystemPackageTool()
            installer.install(package)

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure(source_folder=self.scm["subfolder"] if self.
                        in_local_cache else None)
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_id(self):
        self.info.header_only()

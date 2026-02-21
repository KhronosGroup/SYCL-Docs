#!/usr/bin/python3 -i
#
# Copyright 2013-2026 The Khronos Group Inc.
#
# SPDX-License-Identifier: Apache-2.0

# Working-group-specific style conventions,
# used in generation.

import re
import os

from spec_tools.conventions import ConventionsBase

class SYCLConventions(ConventionsBase):
    @property
    def null(self):
        """Preferred spelling of NULL."""
        return '`NULL`'

    @property
    def structtype_member_name(self):
        """Return name of the structure type member"""
        return None

    @property
    def nextpointer_member_name(self):
        """Return name of the structure pointer chain member"""
        return None

    @property
    def xml_api_name(self):
        """Return the name used in the default API XML registry for the default API"""
        return None

    def generate_structure_type_from_name(self, structname):
        """Generate a structure type name"""

        return structname

    @property
    def warning_comment(self):
        """Return warning comment to be placed in header of generated Asciidoctor files"""
        return ''

    @property
    def file_suffix(self):
        """Return suffix of generated Asciidoctor files"""
        return '.adoc'

    def api_name(self, spectype='api'):
        """Return API or specification name for citations in ref pages.
                    i
           spectype is the spec this refpage is for.
        """
        return 'SYCL'

    @property
    def api_prefix(self):
        """Return API token prefix"""
        return ''

    def extension_file_path(self, name):
        """Return file path to an extension appendix relative to a directory
           containing all such appendices."""

        return f'{name}{self.file_suffix}'

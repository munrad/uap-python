#!/usr/bin/env python
# flake8: noqa
from contextlib import suppress
from os import fspath
from pathlib import Path
from typing import Optional, List, Dict

from setuptools import setup, Command, find_namespace_packages
from setuptools.command.build import build, SubCommand
from setuptools.command.editable_wheel import editable_wheel
from pybind11.setup_helpers import Pybind11Extension, build_ext


build.sub_commands.insert(0, ("compile-uap-cpp", None))


class CompileUapCpp(Command, SubCommand):
    def initialize_options(self) -> None:
        pass

    def finalize_options(self) -> None:
        pass

    def get_source_files(self) -> List[str]:
        return []

    def get_outputs(self) -> List[str]:
        return []

    def get_output_mapping(self) -> Dict[str, str]:
        return dict(zip(self.get_source_files(), self.get_outputs()))

    def run(self) -> None:
        pass


setup(
    cmdclass={
        "compile-uap-cpp": CompileUapCpp,
    }
)

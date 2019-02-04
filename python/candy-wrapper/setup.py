from setuptools import setup
import os
import sys

_here = os.path.abspath(os.path.dirname(__file__))
_pkg_name = "candy-wrapper"
_read_me = "README.md"

if sys.version_info[0] < 3:
    with open(os.path.join(_here, _read_me)) as readme:
        long_description = readme.read()
else:
    with open(os.path.join(_here, _read_me), encoding="utf-8") as readme:
        long_description = readme.read()

version = {}
with open(os.path.join(_here, _pkg_name, "version.py")) as f:
    exec(f.read(), version)

setup(
    name=_pkg_name,
    version=version["__version__"],
    description=("Wrapper to interface with the CAN-D firmware."),
    long_description=long_description,
    author="Brad Ofrim",
    author_email="ofrim@ualberta.cq",
    url="https://github.com/CAN-D/CAN-D",
    packages=[_pkg_name],
    #   install_requires=[
    #       'dependency==1.2.3',
    #   ],
    #   scripts=['bin/a-script'],
    include_package_data=True,
    classifiers=[
        "Development Status :: 5 - Production/Stable",
        "Intended Audience :: Science/Research",
        "Programming Language :: Python :: 3.7",
    ],
)
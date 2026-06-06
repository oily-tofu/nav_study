from setuptools import find_packages
from setuptools import setup

setup(
    name='c_test',
    version='0.0.0',
    packages=find_packages(
        include=('c_test', 'c_test.*')),
)

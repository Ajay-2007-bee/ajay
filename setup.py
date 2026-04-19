from setuptools import setup, find_packages

setup(
    name="ajay",
    version="1.0.0",
    packages=find_packages(),
    include_package_data=True,
    package_data={
        "ajay": ["*.c"],   # include all C files
    },
    entry_points={
        'console_scripts': [
            'ajay=ajay.__main__:main'
        ]
    }
)
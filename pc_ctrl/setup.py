from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'pc_ctrl'
submodules = "pc_ctrl/submodules"

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name, submodules],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),    
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yeseo',
    maintainer_email='oooiooop9988@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'robot_ctrl=pc_ctrl.robot_ctrl:main',
        ],
    },
)

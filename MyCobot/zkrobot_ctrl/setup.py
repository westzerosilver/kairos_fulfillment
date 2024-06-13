from setuptools import find_packages, setup

package_name = 'zkrobot_ctrl'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
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
            'ChatServer=zkrobot_ctrl.ChatServer:main',
            'zkrobot_client=zkrobot_ctrl.zkrobot_client:main',
            'zkrobot_mqtt_client=zkrobot_ctrl.zkrobot_mqtt_client:main'
        ],
    },
)
